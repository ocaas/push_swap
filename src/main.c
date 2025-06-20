/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:38:29 by olopez-s          #+#    #+#             */
/*   Updated: 2025/06/16 06:38:20 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

int main(int ac, char **av)
{
	t_stack *a;
	int num;
	int i = 1;
	
	if(ac)
	{
		while(av[i])
		{
			num = ft_atoi(av[i]);
			ft_add_node_end(&a, ft_newstack(num));
			i++;
		}
		
		print_stack(&a);
		ft_swap(&a);
		print_stack(&a);
		return (0);
	}
}

/* int	main (int ac, char **av)
{
	int	ac_count = ft_content(ac);
	int	parse_stack;
	int	parsed_args;

	parsed_args = ft_split_args(av);
	
	return (0);
} */