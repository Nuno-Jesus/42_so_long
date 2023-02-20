#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COLORS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
RESET	= \033[0m
BLACK 	= \033[1;30m
RED 	= \033[1;31m
GREEN 	= \033[1;32m
YELLOW 	= \033[1;33m
BLUE	= \033[1;34m
PURPLE 	= \033[1;35m
CYAN 	= \033[1;36m
WHITE 	= \033[1;37m

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ COMMANDS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CC = cc
RM = rm -f
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror
MKFLAGS		= --no-print-directory
MLXFLAGS	= -L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm 
LIBFTFLAGS	= -L ./libft -lft
GNLFLAGS	= -L ./get_next_line -lgnl

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS		= includes 
SRCS		= srcs
SRCS_BONUS	= srcs_bonus
LIBFT		= libft
GNL			= get_next_line
MLX 		= mlx
PRINTF		= ft_printf

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
OBJS			= destroy.o map.o utils.o validator.o render.o init.o algorithms.o move_player.o
OBJS_BONUS		= destroy.o map.o utils.o validator.o render.o init.o algorithms.o move_player.o
NAME			= so_long
NAME_BONUS		= so_long
TARGET			= $(addprefix $(SRCS)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(SRCS_BONUS)/, $(OBJS_BONUS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
	make $(MKFLAGS) -C $(GNL)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)mlx/*$(RESET)"
	make $(MKFLAGS) -sC $(MLX)
	
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFTFLAGS) $(GNLFLAGS) $(MLXFLAGS) -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"
	
%.o : %.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

clean:
	make clean $(MKFLAGS) -C $(LIBFT)
	make clean $(MKFLAGS) -C $(GNL)
	make clean $(MKFLAGS) -C $(MLX)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)*/*.o$(RESET)"
	$(RM) $(TARGET) $(TARGET_BONUS)

fclean: clean
	make fclean $(MKFLAGS) -C $(LIBFT)
	make fclean $(MKFLAGS) -C $(GNL)
	echo "[$(RED) Deleted $(RESET)] $(GREEN)so_long$(RESET)"
	$(RM) $(NAME) 

bonus: $(TARGET_BONUS)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
	make $(MKFLAGS) -C $(GNL)

	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)mlx/*$(RESET)"
	make $(MKFLAGS) -C $(MLX) 
	
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET_BONUS) $(LIBFTFLAGS) $(GNLFLAGS) $(MLXFLAGS) -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"

.SILENT:
re: fclean all
