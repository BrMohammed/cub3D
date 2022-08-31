NAME = cub3D_bonus

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

MLX =   -framework OpenGL -framework AppKit

FILES = src/get_next_line.c src/drawlines/draw_lines.c src/drawlines/v3.c\
		src/move/move.c src/move/move2.c src/move/move3.c\
		src/respone_obj.c src/respone.c src/colesion_of_ray/ray_colesion.c \
		src/colesion_of_ray/one_ray.c src/colesion_of_ray/init_for_draw.c cub3D.c\
		src/movement2.c src/movement.c  src/movement3.c src/rander_image.c src/initialization.c src/initialization2.c \
		src/mouse_fun.c src/colesion_of_ray/x_colesion.c src/colesion_of_ray/y_colesion.c\
		src/colesion_of_sprite/ray_colesion_sprite.c src/colesion_of_sprite/x_and_y_colesion.c\
		src/check_cub_file/check_file.c\
		src/check_cub_file/check_tex_f_c_utils.c src/check_cub_file/check_file_utils.c\
		src/check_cub_file/check_file_utils01.c src/check_cub_file/check_map.c\
		src/check_cub_file/check_map_utils.c src/check_cub_file/check_map_utils02.c\

LIBFT = src/libft/libft.a
MINILIBX = minilibx_opengl/libmlx.a

RM = @rm -f


all :$(NAME)

$(NAME): $(FILES)
		@make -C src/libft && make bonus -C src/libft
		@make -C minilibx_opengl
		$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(MINILIBX)  $(FILES) -o $(NAME) 
		@make clean -C src/libft
		@echo "CUB3D CREATED"
clean :
		@make clean -C src/libft

fclean : clean
		@make fclean -C src/libft
		$(RM) $(NAME)
		@echo "CUB3D DELETED"

re : fclean all