/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_pointer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:53:43 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/01 11:18:01 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_check_base(char *base)
{
	int	symbol;
	int	j;

	symbol = 0;
	while (base[symbol])
	{
		if (base[symbol] == '+' || base[symbol] == '-')
			return (0);
		j = symbol + 1;
		while (base[j])
		{
			if (base[symbol] == base[j])
				return (0);
			j++;
		}
		symbol++;
	}
	if (symbol < 2)
		return (0);
	return (1);
}

int	ft_putnbr_base(unsigned long n, char *base, int size)
{
	char	res;
	int		len;

	len = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		len++;
	}
	else
	{
		if (n >= (unsigned int)size)
			len += ft_putnbr_base(n / size, base, size);
		res = base[n % size];
		write(1, &res, 1);
		len++;
	}
	return (len);
}

int	ft_convert_pointer(unsigned long n)
{
	char			*base;
	int				symbol;
	unsigned int	prefix;
	unsigned int	len;

	len = 0;
	prefix = n;
	base = "0123456789abcdef";
	symbol = 0;
	if (!n)
		return (write(1, "(nil)", 5));
	if ((ft_check_base(base)) == 1)
		prefix += write(1, "0x", 2);
	{
		while (base[symbol])
			symbol++;
		len = ft_putnbr_base(n, base, symbol);
		return (len + 2);
	}
	return (0);
}
