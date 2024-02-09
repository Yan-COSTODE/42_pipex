CC = clang
NAME = pipex
INCPATH = includes/
SRCPATH = srcs/
SRCS = pipex.c utils.c split.c fork.c
SRCSBNS = pipex_bonus.c utils_bonus.c split_bonus.c fork_bonus.c
HEADER = pipex.h libft.h
SRCSINC = $(addprefix $(SRCPATH), $(SRCS))
HEADINC = $(addprefix $(INCPATH), $(HEADER))
SRCSINCBNS = $(addprefix $(SRCPATH), $(SRCSBNS))
OBJS = $(SRCSINC:.c=.o)
OBJSBNS = $(SRCSINCBNS:.c=.o)
CFLAGS = -Wall -Wextra -Werror -g
LDFLAGS = -L./$(INCPATH)

all:$(NAME)

bonus: $(OBJSBNS)
	@printf "\033[1;37m"
	make bonus -j 40 --no-print-directory -C libft
	cp libft/libft.a ./$(INCPATH)
	$(CC) $(OBJSBNS) $(LDFLAGS) -lft -o $(NAME)
	@printf "\033[1;32mBonus Compilation Finished !\n\033[0m"

$(NAME): $(OBJS)
	@printf "\033[1;37m"
	make bonus -j 40 --no-print-directory -C libft
	cp libft/libft.a ./$(INCPATH)
	$(CC) $(OBJS) $(LDFLAGS) -lft -o $(NAME)
	@printf "\033[1;32mCompilation Finished !\n\033[0m"

%.o : %.c $(HEADINC)
	@printf "\033[1;37m"
	$(CC) $(CFLAGS) -I./$(INCPATH)  $< -c -o $@

fclean: clean
	@printf "\033[1;37m"
	rm -f $(NAME)
	rm -f ./$(INCPATH)libft.a
	make fclean --no-print-directory -C libft
	@printf "\033[1;31mProgram Deleted !\n\033[0m"

clean:
	@printf "\033[1;37m"
	rm -f $(OBJS) $(OBJSBNS)
	make clean --no-print-directory -C libft
	@printf "\033[1;31mObjects Deleted !\n\033[0m"

re: fclean all

.PHONY: all fclean clean re bonus
