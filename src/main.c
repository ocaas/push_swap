/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:38:29 by olopez-s          #+#    #+#             */
/*   Updated: 2025/07/01 12:03:34 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

int main(int ac, char **av)
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
		ft_add_node_end(&a, new);
		i++;
	}
	
	print_stack(&a);
	print_stack(&a);
	return (0);
}

/* int	main (int ac, char **av)
{
	int	ac_count = ft_content(ac);
	int	parse_stack;
	int	parsed_args;

	parsed_args = ft_split_args(av);
	
	return (0);
} */