/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:21:49 by afraccal          #+#    #+#             */
/*   Updated: 2023/01/27 10:33:50 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

size_t	ft_nbrlen_base(unsigned long long int n, size_t base)
{
	size_t	i;

	i = 1;
	while (n >= (unsigned long long int)base)
	{
		n /= base;
		i++;
	}
	return (i);
}

int	ft_putnbr_fd(long int n, int fd)
{
	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775807", 20);
		return (20);
	}
	else if (n < 0)
	{
		ft_putstr_fd("-", fd);
		ft_putnbr_fd(-n, fd);
	}
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(48 + n % 10, fd);
	}
	return (1);
}

int	ft_putnbr_hex(unsigned long long int n, char format)
{
	unsigned int		base_len;
	int					n_len;
	char				*digit;

	n_len = 0;
	digit = "0123456789abcdef";
	if (format == 'p')
	{
		write(1, "0x", 2);
		n_len += 2;
	}
	if (format == 'X')
		digit = "0123456789ABCDEF";
	base_len = ft_strlen(digit);
	if (n >= base_len)
	{
		ft_putnbr_base(n / 16, digit);
		ft_putnbr_base(n % 16, digit);
	}
	else
		write (1, &digit[n], 1);
	n_len = n_len + ft_nbrlen_base(n, base_len);
	return (n_len);
}

int	ft_putnbr_base(unsigned long long int n, const char *base)
{
	unsigned long long int	base_len;
	int						n_len;

	n_len = 0;
	base_len = ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n_len += ft_putnbr_base(-n, base);
	}
	if (n >= base_len)
	{
		ft_putnbr_base(n / base_len, base);
		ft_putnbr_base(n % base_len, base);
	}
	else
		write(1, &base[n], 1);
	n_len += ft_nbrlen_base(n, base_len);
	return (n_len);
}
