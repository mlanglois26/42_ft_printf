/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:52:20 by malanglo          #+#    #+#             */
/*   Updated: 2023/11/30 11:43:16 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_nbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0 && n != -2147483648)
	{
		count += ft_convert_char('-');
		n = -n;
	}
	if (n >= 10)
	{
		count += ft_convert_nbr(n / 10);
		count += ft_convert_char(n % 10 + 48);
	}
	else
	{
		count += ft_convert_char(n + 48);
	}
	return (count);
}
