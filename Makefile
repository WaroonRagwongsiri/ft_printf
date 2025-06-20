NAME			:=	libftprintf.a

CC				:=	cc
CFLAG			:=	-Wall -Wextra -Werror -g3

SRCS_FILES		:=	ft_printf.c

SRC_DIR			:=	srcs/
INC_DIR			:=	includes/

SRCS			:=	$(SRCS_FILES:%.c=$(SRC_DIR)%.c)
OBJS			:=	$(SRCS:%.c=%.o)

all				:	$(NAME)

$(NAME)			:	$(OBJS) Makefile
	ar rcs -o $@ $^

$(OBJS)			:	%.o : %.c
	$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@

clean			:
	rm -rf $(OBJS) $(BONUS_OBJS)

fclean			:	clean
	rm -rf $(NAME)

re				:	fclean all

.PHONY			:	all clean fclean re