NAME = cub3D

CC = gcc

CFLAGS	= -Wall -Wextra -Werror

MLX =  -lmlx -framework OpenGL -framework AppKit

FILES = hole_move.c destroy.c get_next_line.c check_map.c\
	move.c respone_obj.c respone.c cub3D.c

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

PU = git push origin master

commit = git log --graph --oneline --decorate HEAD^..HEAD

push :
	@$(commit)
	@$(ADD)
	$(read)
	$(PU)