NAME = ft_ls

SRCS_PATH = src/
LIBFT_PATH = libft/

FLAGS = -Wall -Werror -Wextra
INC = -I ./includes/ -I ./$(LIBFT_PATH)

SRCS_NAME = ft_ls.c \
	 		extract.c \
			make_lines.c \
			measure_l.c \
			opt_l.c \
			opt_sort_a.c \
			opt_u.c \
			permission.c \
			print.c \
			recursion.c \
			usage_error.c \
			util_clean.c \
			util_etc.c \
			util_etc2.c \
			util_print.c \
			validate.c

SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS = $(SRCS_NAME:.c=.o)

.PHONY: all, clean, fclean, re

all: $(NAME)

$(NAME):
	make -C $(LIBFT_PATH)
	gcc -c $(FLAGS) $(INC) $(SRCS)
	gcc $(FLAGS) -g $(OBJS) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)

clean:
	make -C $(LIBFT_PATH) clean
	/bin/rm -rf $(OBJS)

fclean: clean
	make -C $(LIBFT_PATH) fclean
	/bin/rm -rf $(NAME)

re: fclean all

