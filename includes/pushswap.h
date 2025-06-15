/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:28:04 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/15 04:08:22 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>

# define AC_ERROR 1

typedef struct s_stack
{
	int				*content;
	struct s_stack	*next;
} t_stack;



//utils
int	ft_content(char **av);

#endif
