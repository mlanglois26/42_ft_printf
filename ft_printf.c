/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:45:28 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/15 15:29:19 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_search_format(va_list ap, char specifier)
{
	int	res;

	res = 0;
	if (specifier == 'c')
		res += ft_convert_char(va_arg(ap, int));
	else if (specifier == 's')
		res += ft_convert_str(va_arg(ap, char *));
	else if (specifier == 'p')
		res += ft_convert_pointer(va_arg(ap, unsigned long));
	else if (specifier == 'd')
		res += ft_convert_nbr(va_arg(ap, int));
	else if (specifier == 'i')
		res += ft_convert_nbr(va_arg(ap, unsigned int));
	else if (specifier == 'u')
		res += ft_convert_unsigned(va_arg(ap, unsigned int));
	else if (specifier == 'x')
		res += ft_convert_hexa_lower(va_arg(ap, unsigned int));
	else if (specifier == 'X')
		res += ft_convert_hexa_upper(va_arg(ap, unsigned int));
	else if (specifier == '%')
		res += ft_convert_char('%');
	else
		return (0);
	return (res);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		specifier_count;
	int		i;

	va_start(ap, format);
	specifier_count = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			specifier_count += ft_search_format(ap, (format[i + 1]));
			i++;
		}
		else
			specifier_count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (specifier_count);
}

int main(void)
{
	char *str;
	
	str = "hello";
	ft_printf("my printf = %c / %p / %d / %i / %u / %x / %X / %%", 'a', str, 6, 6, 6, 6, 7);
	printf("real printf = %c / %p / %d / %i / %u / %x / %X / %%", 'a', str, 6, 6, 6, 6, 7);
}