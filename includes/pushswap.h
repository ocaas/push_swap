/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:28:04 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/16 04:57:17 by olopez-s         ###   ########.fr       */
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
	int				*content;
	struct s_stack	*next;
} t_stack;



//utils
int		ft_content(char **av);
void	ft_add_node_end(t_stack **stack, t_stack *new);

$//parse
t_stack	*ft_newstack(int data);


//delete
void	print_stack(t_stack **stack);

#endif
