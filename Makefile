#! Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

#! Commands
CC = cc
RM = rm -f
AR = ar -rc

#! Flags
CFLAGS = -Wall -Wextra -Werror
MKFLAGS = --no-print-directory

#! Folders
DEPS = includes
SRCS = srcs
LIBFT = libft
GNL = get_next_line
PRINTF = ft_printf

#! Files
OBJS = game.o
NAME = so_long
TARGET = $(addprefix $(SRCS)/, $(OBJS))

#! Rules
all: $(NAME)

$(NAME): $(TARGET)
	@make $(MKFLAGS) -C $(LIBFT)
	@make $(MKFLAGS) -C $(GNL)
	@echo "[${CYAN}Linking${RESET}] ${GREEN}libft, get_next_line, *.o${RESET}"
	@$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFT)/libft.a $(GNL)/gnl.a -o $(NAME) -I $(DEPS)

%.o : %.c 
	@echo "[${CYAN}Compiling${RESET}] $(CFLAGS) ${GREEN}$<${RESET}"
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	@make clean $(MKFLAGS) -C $(LIBFT)
	@make clean $(MKFLAGS) -C $(GNL)
	@echo "[${CYAN}Cleaning${RESET}] ${GREEN}so_long *.o${RESET}"
	@$(RM) $(TARGET)

fclean: clean
	@make fclean $(MKFLAGS) -C $(LIBFT)
	@make fclean $(MKFLAGS) -C $(GNL)
	@echo "[${CYAN}Cleaning${RESET}] ${GREEN}so_long${RESET}"
	@$(RM) $(NAME)

re: fclean all