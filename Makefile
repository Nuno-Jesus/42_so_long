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
RM = rm -rf
AR = ar -rcs

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FLAGS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
CFLAGS		= -Wall -Wextra -Werror
MKFLAGS		= --no-print-directory
MLXFLAGS	= -L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm 
LIBFTFLAGS	= -L ./libft -lft
GNLFLAGS	= -L ./get_next_line -lgnl

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS			= includes 
SRCS			= srcs
SRCS_BONUS		= srcs_bonus
LIBFT			= libft
GNL				= get_next_line
MLX 			= mlx
PRINTF			= ft_printf
VPATH			= srcs_bonus
OBJ_DIR			= objs
OBJ_DIR_BONUS	= objs_bonus

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
OBJS			= destroy.o map.o utils.o validator.o render.o init.o algorithms.o move_player.o
OBJS_BONUS		= destroy.o map.o utils.o validator.o render.o init.o algorithms.o move_player.o \
					load_rest.o load_walls.o render_walls.o binary_wall_map.o
NAME			= so_long
NAME_BONUS		= so_long_bonus
TARGET			= $(addprefix $(OBJ_DIR)/, $(OBJS))
TARGET_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(OBJS_BONUS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
	make $(MKFLAGS) -C $(GNL)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)mlx/*$(RESET)"
	make $(MKFLAGS) -sC $(MLX)
	
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFTFLAGS) $(GNLFLAGS) $(MLXFLAGS) -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"
	
$(OBJ_DIR)/%.o : $(SRCS)/%.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)


clean:
	make clean $(MKFLAGS) -C $(LIBFT)
	make clean $(MKFLAGS) -C $(GNL)
	make clean $(MKFLAGS) -C $(MLX)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_DIR)$(RESET)"
	$(RM) $(OBJ_DIR)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_DIR_BONUS)$(RESET)"
	$(RM) $(OBJ_DIR_BONUS)

fclean: clean
	make fclean $(MKFLAGS) -C $(LIBFT)
	make fclean $(MKFLAGS) -C $(GNL)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME_BONUS)$(RESET)"
	$(RM) $(NAME_BONUS) 

$(OBJ_DIR_BONUS)/%.o : $(SRCS_BONUS)/%.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR_BONUS) :
	mkdir -p $(OBJ_DIR_BONUS)

bonus: $(NAME_BONUS) 

$(NAME_BONUS): $(OBJ_DIR_BONUS) $(TARGET_BONUS)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MKFLAGS) -C $(LIBFT)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
	make $(MKFLAGS) -C $(GNL)

	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)mlx/*$(RESET)"
	make $(MKFLAGS) -C $(MLX) 
	
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET_BONUS) $(LIBFTFLAGS) $(GNLFLAGS) $(MLXFLAGS) -o $(NAME_BONUS) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"

.SILENT:
re: fclean all
