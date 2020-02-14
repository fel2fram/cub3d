# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fde-fram <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/22 14:09:57 by fde-fram          #+#    #+#              #
#    Updated: 2019/11/09 14:21:13 by simoulin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = gcc

WALL = -Wall -Wextra -Werror

INCLUDE = cub3d.h

SRC = testfelsprite.c get_next_line.c get_next_line_utils.c ft_memcpy.c ft_strdup.c main.c map.c direction.c key.c ft_atoi.c ft_split.c init.c save_bmp.c ft_strncmp.c util.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) -I $(INCLUDE) $(WALL) -c $< -o $@

$(NAME) : $(OBJ)
	cc  -o $(NAME) -I /usr/x11/include $(OBJ) -lmlx -framework OpenGL -framework AppKit

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
