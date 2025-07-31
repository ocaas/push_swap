/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:38:29 by olopez-s          #+#    #+#             */
/*   Updated: 2025/07/31 02:13:18 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

//remember to fix libft.a 

/* int main(int ac, char **av)
{
	t_stack *a = NULL;
	t_stack *new;
	int num;
	int i = 1;
	
	if (ac < 2)
		return (0);
	while(av[i])
	{
		num = ft_atoi(av[i]);
		new = ft_newstack(num);
		if(!new)
		{
			ft_putstr_fd("Error: ft_newstack failed\n", 2);
			return (1);
		}
		ft_putnbr_fd(new->content, 1);
		ft_putchar_fd('\n', 1);
		//ft_putstr_fd(", ", 1);
		ft_add_node_end(&a, new);
		i++;
	}
	return (0);
} */

 int main(int ac, char **av)
{
	int	i;
	int	num;
	char	**arg;
	t_stack	*stack;
	
	if (ac < 2)
		return (0);
	arg = ft_split_args(av);
	stack = NULL;
	i = 0;
	while(arg[i])
	{
		if(doubles(stack, arg[i]))
		{
			num = ft_atoi(arg[i]);
			ft_add_node_end(&stack, ft_newstack(num));
		}
		else
		{
			ft_putstr_fd("input error\n", 1);
			return (1);
		}
		i++;
	}
	print_stack(&stack);
} 

/* int	main (int ac, char **av)
{
	int	ac_count = ft_content(ac);
	int	parse_stack;
	int	parsed_args;

	parsed_args = ft_split_args(av);
	
	return (0);
} */