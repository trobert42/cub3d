# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 15:01:19 by ldinaut           #+#    #+#              #
#    Updated: 2022/12/13 18:04:57 by ldinaut          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		cub3D

BNAME	=		cub3D_bonus

SRCS_FILES	=	main.c \
				init_var.c \
				init_mlx.c \
				check_config_file.c \
				check_map.c \
				check_instr.c \
				check_texture.c \
				launch_game.c \
				raycasting.c \
				hook.c \
				moves.c \
				moves_cam.c \
				draw.c \
				textures.c \
				display.c \
				free_functions.c \
				error_exit_functions.c \
				get_next_line.c \
				get_next_line_utils.c \
				utils_parsing.c

BSRCS_FILES	=	main_bonus.c \
				init_mlx_bonus.c \
				init_var_bonus.c \
				check_config_file_bonus.c \
				check_map_bonus.c \
				check_instr_bonus.c \
				check_texture_bonus.c \
				launch_game_bonus.c \
				init_player_bonus.c \
				raycasting_bonus.c \
				hook_bonus.c \
				moves_bonus.c \
				moves_cam_bonus.c \
				draw_bonus.c \
				textures_bonus.c \
				minimap_bonus.c \
				anim_bonus.c \
				doors_bonus.c \
				display_bonus.c \
				error_exit_functions_bonus.c \
				free_functions_bonus.c \
				free_functions_mlx_bonus.c \
				get_next_line_bonus.c \
				get_next_line_utils_bonus.c \
				utils_parsing_bonus.c \

INC_FILES	= cubed.h get_next_line.h

BINC_FILES	= cubed_bonus.h get_next_line.h

SRCS	=	$(addprefix srcs/, $(SRCS_FILES))

BSRCS	=	$(addprefix srcs_bonus/, $(BSRCS_FILES))

INCS	=	$(addprefix includes/, $(INC_FILES))

BINCS	=	$(addprefix includes/, $(BINC_FILES))

CC		=	clang

CFLAGS	=	-Wall -Wextra -Werror -I./includes -g3

INCLUDES	= -I. -Iminilibx-linux/.

LIB		= -Lminilibx-linux -lmlx -lXext -lX11 -Llibft -lft -lm

OBJS_FILES	=	$(SRCS_FILES:%.c=%.o)

BOBJS_FILES	=	$(BSRCS_FILES:%.c=%.o)

OBJS	=		$(addprefix objs/, $(OBJS_FILES))

BOBJS	=		$(addprefix bobjs/, $(BOBJS_FILES))

DEP		=		$(OBJS:%.o=%.d)

all		:		$(NAME)

bonus	:		$(BNAME)

$(NAME)	:	$(OBJS)
	make -C libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJS) $(LIB)

$(BNAME) : $(BOBJS) ./includes/cubed_bonus.h
	make -C libft
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(INCLUDES) -o $(BNAME) $(BOBJS) $(LIB)

clean	:
	make -C libft clean
	make -C minilibx-linux clean
	rm -rf $(OBJS) $(BOBJS) $(DEP)
	rm -rf objs/ bobjs/

fclean	:	clean
	rm -rf $(NAME)
	rm -rf $(BNAME)

re		:	fclean all

objs/%.o	: srcs/%.c $(INCS)
	mkdir -p objs
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

bobjs/%.o	: srcs_bonus/%.c $(BINCS)
	mkdir -p bobjs
	$(CC) $(CFLAGS) -MMD -o $@ -c $<

.PHONY: all clean fclean re
