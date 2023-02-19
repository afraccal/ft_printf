/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:48:56 by afraccal          #+#    #+#             */
/*   Updated: 2023/01/27 10:28:49 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_var(va_list argptr, char a)
{
	size_t	ptr;

	if (a == 'c')
		return (ft_putchar_fd (va_arg(argptr, int), 1));
	if (a == 's')
		return (ft_putstr_fd (va_arg(argptr, char *), 1));
	if (a == 'i' || a == 'd')
		return (ft_printnbr (va_arg(argptr, int)));
	if (a == 'X' || a == 'x')
		return (ft_putnbr_hex (va_arg(argptr, unsigned int), a));
	if (a == 'p')
	{
		ptr = va_arg(argptr, unsigned long);
		if (ptr != '\0')
			return (ft_pointer (ptr));
		return (ft_putstr_fd(("0x0"), 1));
	}
	if (a == 'u')
		return (ft_putnbr_base (va_arg(argptr, unsigned int), "0123456789"));
	if (a == '%')
		return (ft_putchar_fd('%', 1));
	else
		return (-1);
}

int	ft_printf(const char *s, ...)
{
	int		n;
	int		var;
	va_list	argptr;

	n = 0;
	var = 0;
	va_start(argptr, s);
	while (s[n])
	{
		if (s[n] == '%')
		{
			var = var + ft_var(argptr, s[n + 1]);
			n = n + 2;
		}
		else
		{
			var = var + ft_putchar_fd(s[n], 1);
			n++;
		}
	}
	va_end(argptr);
	return (var);
}
