NAME = ft_ls

SRC = ft_ls.c opt_a_l.c opt_sort.c print.c print_help.c usage_error.c validate.c libft/libft.a

HEADER = ft_ls.h

$(NAME):
	gcc -Wall -Wextra -Werror -o $(NAME) -g $(SRC)

fclean:
	rm -rf ft_ls ft_ls.dSYM

re: fclean
	make
