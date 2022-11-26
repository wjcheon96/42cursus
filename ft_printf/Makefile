NAME = libftprintf.a

SRCS = ft_printf_utils.c \
	   ft_printf_formats.c \
	   ft_printf.c \

OBJS = $(SRCS:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

%.o : %.c ft_printf.h
	cc $(FLAGS) -c $< -o $@ -I.

$(NAME) : $(OBJS)
	ar rc $(NAME) $^

all	: $(NAME)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re :
	make fclean
	make all

.PHONY : all clean fclean re
