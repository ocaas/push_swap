/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:28:04 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/21 22:31:37 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define AC_ERROR 1

typedef	struct	s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
} t_stack;

//utils
int		ft_content(char **av);
void	ft_add_node_end(t_stack **stack, t_stack *new);
//int		empty_input(char *s);
void	stack_index(t_stack **stack);
t_stack	*ft_newstack(int data);



//parse
char	**ft_split_args(char **av);
int		final_parse(char **av, t_stack **a, int ac);
void	ft_free_split(char **arr);
//parse2
void	ft_free_s(t_stack **stack);
int	parse_stack(t_stack *a);

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

//exceptions
void	three_nums(t_stack **stack);
void	four_nums(t_stack **a, t_stack **b);
void	five_nums(t_stack **a, t_stack **b);
int		smallest(t_stack *stack);
void	six_nums(t_stack **a, t_stack **b);

//algorithm
void	ft_sort_groups(t_stack **a, t_stack **b, int n_arg);
void	ft_sort_back(t_stack **a, t_stack **b);



#endif
