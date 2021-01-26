NAME =libftprintf.a

SRCS= srcs/abs.c \
	  srcs/ft_strlcpy.c \
	  srcs/display_c.c \
	  srcs/display_i.c \
	  srcs/display_p.c \
	  srcs/display_s.c \
	  srcs/display_u.c \
	  srcs/display_x.c \
	  srcs/display_percent.c \
	  srcs/ft_printf.c \
	  srcs/hexa.c \
	  srcs/precision.c \
	  srcs/putnbr_i.c \
	  srcs/utility.c \
	  srcs/xhexa.c

OBJS =$(SRCS:.c=.o)


CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.

RM = rm -rf

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean: 
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
