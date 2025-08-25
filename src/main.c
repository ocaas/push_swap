/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 06:38:29 by olopez-s          #+#    #+#             */
/*   Updated: 2025/08/21 22:28:17 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pushswap.h"
#include "../libft/libft.h"

static void	sort(t_stack **a, t_stack **b, int n)
{
	n = ft_stksize(*a);
	if (n == 2)
		sa(a);
	else if (n == 3)
		three_nums(a);
	else if (n == 4)
		four_nums(a, b);
	else if (n == 5)
		five_nums(a, b);
	else if (n == 6)
		six_nums(a, b);
	else
	{
		stack_index(a);
		ft_sort_groups(a, b, n);
		ft_sort_back(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		p_stack;

	a = NULL;
	b = NULL;
	if (ac < 2)
		return (ft_free_s(&a), 1);
	if (final_parse(av, &a, ac) == 0)
		return (ft_free_s(&a), 1);
	p_stack = parse_stack(a);
	if (p_stack == -1)
		return (ft_free_s(&a), 1);
	sort(&a, &b, 0);
	ft_free_s(&a);
	ft_free_s(&b);
	return (0);
}
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

/* int	main (int ac, char **av)
{
	int	ac_count = ft_content(ac);
	int	parse_stack;
	int	parsed_args;

	parsed_args = ft_split_args(av);
	
	return (0);
} */