/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 20:56:41 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/16 04:26:54 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"

static void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void sa(t_stack **a)
{
	ft_swap(a);
	ft_putstr_fd("sa\n", 1);
}

void sb(t_stack **b)
{
	ft_swap(b);
	ft_putstr_fd("sb\n", 1);
}

void ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_putstr_fd("ss\n", 1); 
}

int main(int ac, char **av)
{
	t_stack *a;
	int num;
	int i = 1;
	
	while(av[i])
	{
		num = ft_atoi(av[i]);
		ft_add_node_end(a, ft_newstack(num));
		i++;
	}
	
	print_stack(a);
	ft_swap(a);
	print_stack(a);
	return (0);
}
