/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguediri <aguediri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 20:37:05 by aguediri          #+#    #+#             */
/*   Updated: 2023/05/14 23:32:07 by aguediri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int		ft_tohex_x(unsigned int n, char c);
int		ft_tohex_p(unsigned long n);
int		ft_tohex_x(unsigned int n, char c);
int		ft_putnbru(unsigned int n, int fd);
int		ft_digitciu( unsigned int n);
int		ft_digitc(int n);
int		ft_putnbr(int n, int fd);
int		ft_putchar(char c, int fd);
int		ft_putstr(char *s, int fd);
int		ft_formatter(char c, va_list arg);
void	ft_va_arg(va_list l, char i);
int		ft_printf(const char *format, ...);
#endif