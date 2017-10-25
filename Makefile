# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vboivin <marvin42.fr>                     +#+   +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/17 14:50:04 by vboivin           #+#    #+#              #
#    Updated: 2017/10/25 09:33:03 by vboivin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= fractol
HPATH		= includes
MLXPATH		= minilibx_macos
INC			= -I$(HPATH) -Ilibft/includes -I$(MLXPATH)
FLAGS		= -Wall -Werror -Wextra
FLAGSMLX	= -framework OpenGL -framework Appkit
FLAGSX11	= -lXext -lX11 -lm 
COMP		= gcc
LIBFT		= -Llibft -lft
MLX			= -L$(MLXPATH) -lmlx

SRCS 		= main.c image_manage.c events.c event_keys.c hub.c \
			  calls.c mandel.c julia.c devil.c bship.c batman.c moth.c \
			  rising_bug.c ray_manta.c
DIR_SRC		= $(addprefix $(SRCPATH)/, $(SRCS))
SRCPATH		= src

OBJ 		= $(SRCS:.c=.o)
DIR_OBJ		= $(addprefix $(OBJPATH)/, $(OBJ))
OBJPATH		= obj

all: $(NAME)

$(OBJPATH)/%.o: $(SRCPATH)/%.c
	@printf "Compiling $<\r"
	@$(COMP) $(FLAGS) -c $< -o $@ $(INC)

$(NAME): $(DIR_OBJ)
	@printf "\r                                                             \r"
	@printf "mlx:\tdone\n"
	@make -C libft
	@make -C $(MLXPATH)
	@$(COMP) $(DIR_OBJ) -o $(NAME) $(INCMAC) $(LIBFT) $(FLAGS) $(MLX) $(FLAGSMLX)

clean:
	@make clean -C $(MLXPATH)
	@make clean -C libft
	@rm -rf $(OBJ)

fclean:
	@make clean -C $(MLXPATH)
	@make fclean -C libft
	@rm -rf $(DIR_OBJ)
	@rm -rf $(NAME)

re: fclean all

mk:
	@rm $(DIR_OBJ)
	@make all
