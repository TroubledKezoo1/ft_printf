NAME	= libftprintf.a
LIBFTNAME = libft.a

CC		= cc
FLAGS	= -Wall -Wextra -Werror

RM		= rm -f

AR		= ar rc

LIBFTDIR = ./Libft

SRC		= ft_printf.c \

OBJ		= $(SRC:%.c=%.o)

CP		= cp

CD		= cd

MV		= mv

MAKE	= make

MAKEBONUS = bonus

makelibft:
		@$(MAKE) -C $(LIBFTDIR)
		@$(CP) $(LIBFTDIR)/$(LIBFTNAME) ./$(LIBFTNAME)
		@$(MV) $(LIBFTNAME) $(NAME)

$(NAME):
	makelibft
	@$(CC) $(FLAGS) -c $(SRC)
	@$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	@$(RM) $(OBJ)
	@$(CD) $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	@$(RM) $(NAME)
	@$(CD) $(LIBFTDIR) && $(MAKE) fclean

re: fclean all




