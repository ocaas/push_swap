/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olopez-s <olopez-s@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 02:51:05 by olopez-s          #+#    #+#             */
/*   Updated: 2025/07/17 15:51:15 by olopez-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *str, int fd);
void ft_putchar_fd(char c, int fd);
int	ft_strlen(const char *str);
char	**ft_split(char const *s, char c);
int	ft_atoi(const char *str);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strdup(const char *s);
int	ft_isdigit(int c);



#endif