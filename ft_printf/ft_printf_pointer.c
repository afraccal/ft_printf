/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_pointer.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afraccal <afraccal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 20:00:50 by afraccal          #+#    #+#             */
/*   Updated: 2023/01/27 10:34:17 by afraccal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_pointer(size_t n)
{
	unsigned int		base_len;
	int					n_len;
	char				*digit;

	n_len = 0;
	digit = "0123456789abcdef";
	write(1, "0x", 2);
	n_len += 2;
	if (n == 0)
	{
		write (1, "0", 1);
		return (3);
	}
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
