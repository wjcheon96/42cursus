CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

SRCS = deque.c main.c push_swap.c validity_check.c instructions1.c instructions2.c instructions3.c greedy.c sort.c
OBJS = $(SRCS:.c=.o)

NAME = push_swap

RM	 = rm -rf

.c.o :
	@cc $(CFLAGS) -c $< -o $@ -I.

$(NAME) : $(SRCS)
	@make -C libft all
	@echo "Compiling pushswap..."
	@make $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) libft/libft.a -o $(NAME)
	@echo "Done!"

libft :
	@make -C libft

all :
	@make $(NAME)

clean :
	@make -C libft clean
	@echo "Erasing object files..."
	@$(RM) $(OBJS)

fclean : 
	@make -C libft fclean
	@make clean
	@echo "Erasing exec file..."
	@$(RM) $(NAME)
	@echo "Done!"

re :
	@make fclean
	@make all

.PHONY : all clean fclean re
