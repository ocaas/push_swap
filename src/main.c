/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:38:29 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/12 01:06:55 by olopez-s         ###   ########.fr       */
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
	t_stack	*a;
	int	arg;

	if (ac < 2)
		return (0);
	a = NULL;
	arg = final_parse(av, &a);
	if(arg == 0)
		return 0;
	print_stack(&a);
}


/* int	main (int ac, char **av)
{
	int	ac_count = ft_content(ac);
	int	parse_stack;
	int	parsed_args;

	parsed_args = ft_split_args(av);
	
	return (0);
} */