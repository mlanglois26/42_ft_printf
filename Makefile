# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: malanglo <malanglo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/19 14:56:26 by malanglo          #+#    #+#              #
#    Updated: 2023/12/15 15:20:25 by malanglo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SOURCES = 	ft_convert_char.c \
			ft_convert_hexa_lower.c \
			ft_convert_hexa_upper.c \
			ft_convert_nbr.c \
			ft_convert_pointer.c \
			ft_convert_str.c \
			ft_convert_unsigned.c \
			ft_printf.c \
			ft_utils.c \

OBJECTS = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME):		${OBJECTS}
		ar rcs ${NAME} ${OBJECTS}

.c.o:
	${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	rm -f $(OBJECTS)

fclean:		clean
		rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re