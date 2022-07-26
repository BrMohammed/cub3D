NAME = cub3D

CC = gcc

CFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g

MLX =  -lmlx -framework OpenGL -framework AppKit

FILES = src/destroy.c src/get_next_line.c src/check_map.c\
		src/move.c src/respone_obj.c src/respone.c src/ray_colesion.c cub3D.c\
		src/movement.c\

LIBFT = libft/libft.a

RM = @rm -f

all :$(NAME)

$(NAME):
		@make -C libft && make bonus -C libft
		$(CC) $(CFLAGS) $(MLX) $(LIBFT) $(FILES) -o $(NAME) 
		@make clean -C libft
		@echo "CUB3D CREATED"
clean :
		@make clean -C libft

fclean : clean
		@make fclean -C libft
		$(RM) $(NAME)
		@echo "CUB3D DELETED"

re : fclean all

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