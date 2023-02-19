/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 13:39:42 by afraccal          #+#    #+#             */
/*   Updated: 2023/01/27 10:33:15 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdarg.h"
# include "stdlib.h"
# include "unistd.h"
# include "limits.h"

size_t	ft_strlen(const char *str);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
int		ft_putnbr_fd(long int n, int fd);
int		ft_putnbr_base(unsigned long long int n, const char *base);
int		ft_putnbr_hex(unsigned long long int n, char format);
size_t	ft_nbrlen_base(unsigned long long int n, size_t base);
int		ft_printf(const char *s, ...);
int		ft_var(va_list argptr, char a);
int		lenght(int nb);
char	*ft_itoa(int n);
int		ft_printnbr(int n);
int		ft_pointer(size_t pointer);
#endif
