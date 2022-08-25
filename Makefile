NAME = cub3D

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -std=c99 -fsanitize=address -g ##-Ofast

MLX =   -framework OpenGL -framework AppKit

FILES = src/get_next_line.c src/draw_lines.c\
		src/move.c src/respone_obj.c src/respone.c src/colesion_of_ray/ray_colesion.c  src/colesion_of_ray/one_ray.c src/colesion_of_ray/init_for_draw.c cub3D.c\
		src/movement.c src/rander_image.c src/ray_colesion_sprite.c src/initialization.c src/mouse_fun.c src/colesion_of_ray/x_colesion.c src/colesion_of_ray/y_colesion.c\
		src/check_cub_file/check_file.c\
		src/check_cub_file/check_tex_f_c_utils.c src/check_cub_file/check_file_utils.c\
		src/check_cub_file/check_file_utils01.c src/check_cub_file/check_map.c\
		src/check_cub_file/check_map_utils.c\

LIBFT = libft/libft.a
MINILIBX = minilibx_opengl/libmlx.a

RM = @rm -f


all :$(NAME)

$(NAME):
		@make -C libft && make bonus -C libft
		@make -C minilibx_opengl
		$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(MINILIBX)  $(FILES) -o $(NAME) 
		@make clean -C libft
		@echo "CUB3D CREATED"
clean :
		@make clean -C libft

fclean : clean
		@make fclean -C libft
		$(RM) $(NAME)
		@echo "CUB3D DELETED"

re : fclean all

exp = export DYLD_LIBRARY_PATH="${PWD}/minilibx_mms"

check:
	@$(exp)

#  github bigin
# system("leaks a.out");

ADD = git add .

read :=	@echo "${C_GREEN}Add Commit Plz !!${C_RES}" && read -p "-> " enter \
		&& git commit -m $${enter}

PU = git push

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)