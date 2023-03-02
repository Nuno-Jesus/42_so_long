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
CFLAGS	= -Wall -Wextra -Werror -fsanitize=address #-g
MK		= --no-print-directory
MLX		= -L ./mlx -lmlx -Ilmlx -lXext -lX11 -lm 
LIBFT	= -L ./libft -lft
GNL		= -L ./get_next_line -lgnl
PRINTF	= -L ./ft_printf -lftprintf

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FOLDERS _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
DEPS			= includes 
SRCS			= srcs
SRCS_BONUS		= srcs_bonus
LIBFT_PATH		= libft
GNL_PATH		= get_next_line
PRINTF_PATH		= ft_printf
MLX_PATH 		= mlx
_SUBFOLDERS		= map move render utils
VPATH			= srcs_bonus $(addprefix $(SRCS_BONUS)/, $(_SUBFOLDERS))
OBJ_DIR			= objs
OBJ_DIR_BONUS	= objs_bonus

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ FILES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
NAME			= so_long
_FILES			= destroy map utils validator render init algorithms move_player
OBJS			= $(_FILES:%=%.o)
TARGET			= $(addprefix $(OBJ_DIR)/, $(OBJS))

NAME_BONUS		= so_long_bonus
_FILES_BONUS	= move_enemies move_player strategy algorithms map_validator read_map animate \
					binary_wall_map destroy load_sprites render_walls render utils debug init 
OBJS_BONUS		= $(_FILES_BONUS:%=%.o)
TARGET_BONUS	= $(addprefix $(OBJ_DIR_BONUS)/, $(OBJS_BONUS))

#_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_ RULES _/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_/=\_
all: $(NAME)

$(NAME): $(OBJ_DIR) $(TARGET)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MK) -C $(LIBFT_PATH)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
	make $(MK) -C $(GNL_PATH)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)ft_printf/*$(RESET)"
	make $(MK) -C $(PRINTF_PATH)

	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)mlx/*$(RESET)"
	make $(MK) -sC $(MLX_PATH)
	
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET) $(LIBFT) $(GNL) $(MLX) $(PRINTF) -o $(NAME) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"
	
$(OBJ_DIR)/%.o : $(SRCS)/%.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR) :
	mkdir -p $(OBJ_DIR)

clean:
	make clean $(MK) -C $(LIBFT_PATH)
	make clean $(MK) -C $(GNL_PATH)
	make clean $(MK) -C $(PRINTF_PATH)	
	make clean $(MK) -C $(MLX_PATH)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_DIR)$(RESET)"
	$(RM) $(OBJ_DIR)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(OBJ_DIR_BONUS)$(RESET)"
	$(RM) $(OBJ_DIR_BONUS)

fclean: clean
	make fclean $(MK) -C $(LIBFT_PATH)
	make fclean $(MK) -C $(GNL_PATH)
	make fclean $(MK) -C $(PRINTF_PATH)	
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME)$(RESET)"
	$(RM) $(NAME)
	
	echo "[$(RED) Deleted $(RESET)] $(GREEN)$(NAME_BONUS)$(RESET)"
	$(RM) $(NAME_BONUS) 

$(OBJ_DIR_BONUS)/%.o : %.c 
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)$<$(RESET)"
	$(CC) $(CFLAGS) -c $< -o $@ -I $(DEPS)

$(OBJ_DIR_BONUS) :
	mkdir -p $(OBJ_DIR_BONUS)

bonus: $(NAME_BONUS) 

$(NAME_BONUS): $(OBJ_DIR_BONUS) $(TARGET_BONUS)
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)libft/*$(RESET)"
	make $(MK) -C $(LIBFT_PATH)
	
	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)get_next_line/*$(RESET)"
	make $(MK) -C $(GNL_PATH)

	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)ft_printf/*$(RESET)"
	make $(MK) -C $(PRINTF_PATH)

	echo "[$(CYAN)Compiling$(RESET)] $(CFLAGS) $(GREEN)mlx/*$(RESET)"
	make $(MK) -C $(MLX_PATH) 
	
	echo "[$(CYAN) Linking $(RESET)] $(GREEN)*$(RESET)"
	$(CC) $(CFLAGS) main.c $(TARGET_BONUS) $(LIBFT) $(GNL) $(MLX) $(PRINTF) -o $(NAME_BONUS) -I $(DEPS)
	
	echo "$(GREEN)Done.$(RESET)"

re: fclean all

run: 
	./$(NAME_BONUS) maps/valid8.ber

reb: fclean bonus run

.SILENT:
