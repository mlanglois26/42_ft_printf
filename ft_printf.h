/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:36:12 by malanglo          #+#    #+#             */
/*   Updated: 2023/12/15 15:20:42 by malanglo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

int		ft_convert_char(char c);
int		ft_convert_nbr(int n);
int		ft_convert_str(char *s);
int		ft_convert_pointer(unsigned long n);
int		ft_convert_unsigned(unsigned int n);
int		ft_convert_hexa_lower(unsigned int n);
int		ft_convert_hexa_upper(unsigned int n);
int		ft_search_format(va_list ap, char specifier);
size_t	ft_strlen(const char *s);
int		ft_printf(const char *format, ...);
int		ft_putnbr_base(unsigned long n, char *base, int size);
int		ft_check_base(char *base);

#endif
