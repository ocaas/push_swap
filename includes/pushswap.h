/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:28:04 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/30 15:34:05 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define AC_ERROR 1

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
} t_stack;



//utils
int		ft_content(char **av);
void	ft_add_node_end(t_stack **stack, t_stack *new);

//parse
t_stack	*ft_newstack(int data);
char	**ft_split_args(char **av);


//swap
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);

//rotate
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//reverse
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rr(t_stack **a, t_stack **b);

//push
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);

//delete
void	print_stack(t_stack **stack);

#endif
