/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:13:53 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/21 06:14:18 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"


static int	count_tokens(char **sp)
{
	int	t;
	int	c;

	t = 0;
	c = 0;
	while (sp && sp[t])
	{
		if (sp[t][0] != '\0')
			c++;
		t++;
	}
	return (c);
}

int	ft_content(char **av)
{
	int		i;
	int		c;
	char	**sp;

	i = 1;
	c = 0;
	while (av[i])
	{
		sp = ft_split(av[i], ' ');
		if (!sp)
			return (c);
		c += count_tokens(sp);
		ft_free_split(sp);
		i++;
	}
	return (c);
}

t_stack	*ft_newstack(int data)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = data;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	ft_add_node_end(t_stack **stack, t_stack *new)
{
	t_stack	*tmp;

	if (!stack || !new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	new->next = NULL;
	tmp->next = new;
}

void	print_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		ft_putnbr_fd(tmp->content, 1);
		ft_putchar_fd('\n', 1);
		tmp = tmp->next;
	}
}

static int	rank_of(t_stack *s, int val)
{
	int	idx;

	idx = 0;
	while (s)
	{
		if (val > s->content)
			idx++;
		s = s->next;
	}
	return (idx);
}

void	stack_index(t_stack **stack)
{
	t_stack	*p;

	p = *stack;
	while (p)
	{
		p->index = rank_of(*stack, p->content);
		p = p->next;
	}
}

/*
int	empty_input(char *s)
{
	int	i;

	i = 0;
	if(!s[i] || !s)
		return (0);
	while(s[i])
	{
		if(s[i] != ' ' && !(s[i] >= 9 && s[i] <= 13))
			return (1);
		i++;
	}
	return (0);
} */