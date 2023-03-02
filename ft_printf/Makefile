CC = cc
FLAGS = -Wall -Wextra -Werror
DEPS = ../includes
RM = rm -f
AR = ar -rc

TARGET = 	ft_printf.o ft_printf_utils.o ft_convert_char.o ft_convert_string.o ft_convert_integer.o \
			ft_convert_hexa.o ft_convert_module.o ft_convert_pointer.o ft_convert_unsigned.o \
			flags.o
NAME = libftprintf.a

%.o : %.c 
	$(CC) $(FLAGS) -c $< -o $@ -I $(DEPS)

all: $(NAME)

$(NAME): $(TARGET)
	cp ../libft/libft.a $(NAME)
	$(AR) $(NAME) $(TARGET)

clean:
	$(RM) $(TARGET) $(BONUS_TARGET)

fclean: clean
	$(RM) $(NAME) $(BONUS_TARGET)

bonus: all

re: fclean all

.SILENT: