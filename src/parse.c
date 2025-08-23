/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:27:22 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/14 06:12:50 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

char	**ft_split_args(char **av)
{
	int		i;
	char	**split_args;
	int		j;
	int		k;
	char	**temp;

	i = 1;
	j = 0;
	split_args = malloc(sizeof(char *) * (ft_content(av) + 1));
	if (!split_args)
		return (0);
	while (av[i])
	{
		temp = ft_split(av[i], ' ');
		k = 0;
		while (temp[k])
			split_args[j++] = ft_strdup(temp[k++]);
		ft_free_split(temp);
		i++;
	}
	split_args[j] = NULL;
	return (split_args);
}
/* 
int	ft_spaces(char *av)
{
	int	i;

	i = 0;
	if(!av[i])
		return (1);
	while(av[i] >= 9 && av[i] <= 13 && av[i])
	{
		if(av[i] != ' ' && !(av[i] >= 9 && av[i] <= 13))
			return(1);
		i++;
	}
	return(0);
} */

static int	empty_input(char *s)
{
	int	i;

	i = 0;
	if (!s[i] || !s)
		return (1);
	while (s[i])
	{
		if (s[i] != ' ' && !(s[i] >= 9 && s[i] <= 13))
			return (0);
		i++;
	}
	return (1);
}

static int	valid_input(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (s[i] == '-' || s[i] == '+')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	doubles(t_stack *stack, char *s)
{
	int	num;
	int	overflow;

	overflow = 0;
	num = ft_atoi(s, &overflow);
	if (!valid_input(s))
		return (0);
	while (stack)
	{
		if (stack->content == num)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	final_parse(char **av, t_stack **a, int ac)
{
	int		i;
	int		num;
	int		overflow;
	char	**arg;

	i = 1;
	overflow = 0;
	arg = ft_split_args(av);
	while (ac > i)
	{
		if (empty_input(av[i]))
			return (ft_putstr_fd("Error\n", 2), 0);
		i++;
	}
	i = 0;
	while (arg[i])
	{
		num = ft_atoi(arg[i], &overflow);
		if (!doubles(*a, arg[i]) || (overflow))
			return (ft_putstr_fd("Error\n", 2), ft_free_split(arg), 0);
		i++;
		ft_add_node_end(a, ft_newstack(num));
	}
	ft_free_split(arg);
	return (1);
}

/* void	ft_free(char *a)
{
	int	i;

	i = 0;
	while(a[i])
	{
		free(a[i]);
		i++;
	}
	free(a);
} */

// no int max or int min (in atoi)
//no spaces , there has to be numbers 
//at least one number 
//no letters 
// no tenga dos signos solo uno 
// overflow
//no same two numbers 
//stack is ramdomized 
