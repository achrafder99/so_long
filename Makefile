# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adardour <adardour@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/02 15:59:35 by adardour          #+#    #+#              #
#    Updated: 2023/02/16 21:57:16 by adardour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

SRC =  utils/ft_memset.c  utils/ft_strrchr.c  utils/ft_itoa.c utils/ft_strcmp.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_calloc.c utils/ft_bzero.c utils/ft_putnbr_fd.c utils/ft_putchar_fd.c  \
get_next_line/get_next_line_utils.c get_next_line/get_next_line.c check_file_ber.c check_is_rectangular.c check_walls.c get_lines.c check_every_line.c \
check_exit_and_player.c get_column.c fill.c init_imgs.c position_x.c position_y.c get_number_of_fish.c \
check_is_valid_path.c so_long.c check_if_position_is_valid.c key_event.c show_info.c ./utils/ft_putstr_fd.c start_drawing.c \
./directions/up.c ./directions/down.c ./directions/right.c ./directions/left.c check_symbols.c exit_the_game.c init_visited.c backtracking.c \
./load_images/collectibles.c ./load_images/floor.c ./load_images/player.c ./load_images/exit.c ./load_images/walls.c ./load_images/enemy.c
 
BONUS_SRC = ./bonus/so_long_bonus.c ./bonus/src/check_file_ber.c ./bonus/src/check_exit_and_player.c \
./bonus/animation.c ./bonus/start_drawing_bonus.c ./bonus/src/key_event.c ./bonus/src/check_is_valid_path.c \
./bonus/src/check_is_rectangular.c ./bonus/src/backtracking.c ./bonus/src/check_symbols.c \
./bonus/src/ft_putnbr_fd.c ./bonus/src/ft_putchar_fd.c  ./bonus/src/ft_putstr_fd.c \
./bonus/src/ft_strdup.c ./bonus/src/get_lines.c ./bonus/src/get_column.c ./bonus/src/position_x.c ./bonus/src/position_y.c \
./bonus/src/init_visited.c ./bonus/src/get_number_of_fish.c ./bonus/src/init_imgs.c ./utils/ft_strrchr.c \
./bonus/src/fill.c ./get_next_line/get_next_line.c ./get_next_line/get_next_line_utils.c \
./bonus/src/ft_strcmp.c ./bonus/src/ft_memset.c ./bonus/src/ft_itoa.c ./bonus/src/ft_calloc.c \
./bonus/src/check_walls.c ./bonus/src/check_every_line.c ./bonus/src/ft_bzero.c \
./bonus/src/show_info.c ./bonus/src/exit_the_game.c ./bonus/kill.c ./bonus/show_moves.c \
./load_images/enemy.c ./load_images/floor.c ./load_images/player.c ./load_images/walls.c ./load_images/collectibles.c ./load_images/exit.c \
./directions/up.c ./directions/down.c ./directions/right.c ./directions/left.c


OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(BONUS_SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRC) $(OBJ) so_long.h
	$(CC) $(CFLAGS)  -lmlx -framework OpenGl -framework AppKit $(SRC) -o $(NAME) 
	
$(NAME_BONUS): $(BONUS_SRC) $(OBJ_BONUS) so_long.h
	$(CC) $(CFLAGS)  -lmlx -framework OpenGl -framework AppKit $(BONUS_SRC) -o $(NAME_BONUS)
	@mv so_long_bonus ./bonus
	
%.o: %.c
	$(CC) $(CFLAGS)  -c $^ -o $@

bonus: $(OBJ) $(OBJ_BONUS)
	$(MAKE) $(NAME_BONUS)
	@rm -rf $(NAME)

clean:
	rm -rf $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -rf $(NAME)
	cd bonus && rm -rf $(NAME_BONUS)
	
re: fclean all