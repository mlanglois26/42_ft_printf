/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:15:48 by malanglo          #+#    #+#             */
/*   Updated: 2023/11/30 11:45:42 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_unsigned(unsigned int n)
{
	unsigned int	count;

	count = 0;
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
