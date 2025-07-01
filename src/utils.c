/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 17:13:53 by olopez-s          #+#    #+#             */
/*   Updated: 2025/07/01 11:33:16 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

int	ft_content(char **av)
{
	int		i;
	char	**temp;
	int		t;
	int		c;

	i = 1;
	while (av[i])
	{
		temp = ft_split_args(&av[i]);
		while (*temp[t])
		{
			c++;
			t++;
		}
		t = 0;
		free (*temp);
		i++;
	}
	return (t);
}

t_stack	*ft_newstack(int data)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return(NULL);
	new->content = data;
	new->next = NULL;
	return (new);
}

void	ft_add_node_end(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	if(!(*stack))
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while(temp->next)
	{
		temp = temp->next;
	}
	temp->next = new;
}

void	print_stack(t_stack **stack)
{
	t_stack *temp;
	
	temp = *stack;
	while(temp)
	{
		ft_putnbr_fd(temp->content, 1);
		ft_putchar_fd('\n', 1);
		temp = temp->next;
	}
}
