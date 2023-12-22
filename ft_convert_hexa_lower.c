/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa_lower.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:03:16 by malanglo          #+#    #+#             */
/*   Updated: 2023/11/30 11:41:39 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hexa_lower(unsigned int n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789abcdef";
	count = 0;
	if (n < 16)
		count += write(1, hexa + n, 1);
	else if (n >= 16)
	{
		count += ft_convert_hexa_lower(n / 16);
		count += ft_convert_hexa_lower(n % 16);
	}
	return (count);
}
