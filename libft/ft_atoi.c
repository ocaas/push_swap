/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 04:11:21 by olopez-s          #+#    #+#             */
/*   Updated: 2025/07/01 13:28:12 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		if ((num > 2147483647 && sign == 1) || (num > 2147483648))
			break;
		i++;
	}
	return ((int)(num * sign));
}

/*
int		main()
{
	
    const char *str1 = "123";
    const char *str2 = "-456";
    const char *str3 = "   789";
    const char *str4 = "   +987";
    const char *str5 = "   -654";
    const char *str6 = "   123abc";

    printf("'%s' convertido a entero: %d\n", str1, ft_atoi(str1));
    printf("'%s' convertido a entero: %d\n", str2, ft_atoi(str2));
    printf("'%s' convertido a entero: %d\n", str3, ft_atoi(str3));
    printf("'%s' convertido a entero: %d\n", str4, ft_atoi(str4));
    printf("'%s' convertido a entero: %d\n", str5, ft_atoi(str5));
    printf("'%s' convertido a entero: %d\n", str6, ft_atoi(str6));

    return 0;
}
*/