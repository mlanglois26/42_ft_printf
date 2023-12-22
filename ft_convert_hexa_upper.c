/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hexa_upper.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 17:09:54 by malanglo          #+#    #+#             */
/*   Updated: 2023/11/30 11:42:10 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_convert_hexa_upper(unsigned int n)
{
	char	*hexa;
	int		count;

	hexa = "0123456789ABCDEF";
	count = 0;
	if (n < 16)
		count += write(1, hexa + n, 1);
	else if (n >= 16)
	{
		count += ft_convert_hexa_upper(n / 16);
		count += ft_convert_hexa_upper(n % 16);
	}
	return (count);
}
