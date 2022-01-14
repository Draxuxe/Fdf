# COLORS
NOC         = \033[0m
BOLD        = \033[1m
UNDERLINE   = \033[4m
BLACK       = \033[1;30m
RED         = \033[1;31m
GREEN       = \033[1;32m
YELLOW      = \033[1;33m
BLUE        = \033[1;34m
VIOLET      = \033[1;35m
CYAN        = \033[1;36m
WHITE       = \033[1;37m

# SYMBOLS
INFO = $(WHITE)[$(BLUE)ℹ️$(WHITE)] $(NOC)
SUCCESS = $(WHITE)[$(GREEN)✅$(WHITE)] $(GREEN)
WARNING = $(WHITE)[$(YELLOW)⚠️$(WHITE)] $(YELLOW)
ERROR = $(WHITE)[$(RED)❌$(WHITE)] $(RED)

# Binary
NAME=fdf
BONUS=fdf_bonus

# Path
SRC_PATH = ./Sources/
BONUS_PATH = ./Bonus/
OBJ_PATH = ./objs/
BONUS_OBJS_PATH = ./bonus_objs/
INCDIR = ./Includes/fdf.h
INCDIR_BONUS = ./Includes/fdf_bonus.h

# Name
SRC_NAME = main.c                               \
		Parsing/parser.c                        \
		Vectors/vectors.c                       \
		Convert/convert.c                       \
		Init/init_settings.c                    \
		Init/init_controls.c                    \
		Init/init_keys.c                        \
		Display/display_map.c                   \
		Display/print_image.c                   \
		Display/projection.c                    \
		Utils/parsing_utils.c                   \
		Utils/check_utils.c                     \
		Utils/z_utils.c                         \
		Utils/free_utils.c                      \
		Utils/draw_utils.c                      \
		../Get_next_line/get_next_line.c        \
		../Get_next_line/get_next_line_utils.c

BONUS_NAME = main_bonus.c                       \
		Parsing/parser.c                        \
		Vectors/vectors.c                       \
		Convert/convert.c                       \
		Init/init_settings.c                    \
		Init/init_controls.c                    \
		Init/init_keys.c                        \
		Maths/rotations.c                       \
		Display/display_map.c                   \
		Display/print_image.c                   \
		Display/projection.c                    \
		Utils/parsing_utils.c                   \
		Utils/check_utils.c                     \
		Utils/z_utils.c                         \
		Utils/free_utils.c                      \
		Utils/color_utils.c                     \
		Utils/draw_utils.c                      \
		../Get_next_line/get_next_line.c        \
		../Get_next_line/get_next_line_utils.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_NAME_BONUS = $(BONUS_NAME:.c=.o)

# Files
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

BNS = $(addprefix $(BONUS_PATH)/,$(BONUS_NAME))
OBJ_BNS = $(addprefix $(BONUS_OBJS_PATH)/,$(OBJ_NAME_BONUS))

# Libft
FT		= ./libft/
FT_LIB	= $(addprefix $(FT),libft.a)
FT_INC	= -I ./libft
FT_LNK	= -L ./libft -l ft

# MinilibX
MLX		= ./mlx/
MLX_LIB	= $(addprefix $(MLX),libmlx.a)
MLX_INC	= -I ./mlx
MLX_LNK	= -L ./mlx -l mlx -I /usr/X11/include -framework OpenGL -framework AppKit

# Flags
CC = gcc $(CFLAGS)
CFLAGS = -Wall -Wextra -Werror -ofast -o3

all: obj $(FT_LIB) $(MLX_LIB) $(NAME)

obj:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/utils
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/vectors
	@mkdir -p $(OBJ_PATH)/convert
	@mkdir -p $(OBJ_PATH)/display
	@mkdir -p $(OBJ_PATH)/init
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

$(OBJ_PATH)%.o:$(SRC_PATH)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@echo "$(INFO)Building libft library...$(NOC)"
	@make -C $(FT)
	@echo "$(SUCCESS)Libft library built successfully!$(NOC)"

$(MLX_LIB):
	@echo "$(INFO)Building minilibx library...$(NOC)"
	@make -C $(MLX)
	@echo "$(SUCCESS)Minilibx library built successfully!$(NOC)"

$(NAME):obj $(FT_LIB) $(MLX_LIB) $(OBJ)
	@echo "$(INFO)Building $(NAME)...$(NOC)"
	@$(CC) $(OBJ) $(FT_LNK) $(MLX_LNK) -o $@
	@echo "$(SUCCESS)$(NAME) built successfully!$(NOC)"
	@echo "				$(VIOLET)$(BOLD)$(UNDERLINE)$(NAME) Ready to be launch!$(NOC)"


$(BONUS_OBJS_PATH)%.o:$(BONUS_PATH)%.c
	@$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) -I $(INCDIR_BONUS) -o $@ -c $<

$(BONUS): obj_bonus $(FT_LIB) $(MLX_LIB) $(OBJ_BNS)
	@echo "$(INFO)Building $(BONUS)...$(NOC)"
	@$(CC) $(OBJ_BNS) $(FT_LNK) $(MLX_LNK) -o $@
	@echo "$(SUCCESS)$(BONUS) built successfully!$(NOC)"
	@echo "				$(VIOLET)$(BOLD)$(UNDERLINE)$(BONUS) Ready to be launch!$(NOC)"

obj_bonus:
	@echo "$(INFO)Creating objects folder... $(NOC)"
	@mkdir -p $(BONUS_OBJS_PATH)
	@mkdir -p $(BONUS_OBJS_PATH)/utils
	@mkdir -p $(BONUS_OBJS_PATH)/parsing
	@mkdir -p $(BONUS_OBJS_PATH)/vectors
	@mkdir -p $(BONUS_OBJS_PATH)/convert
	@mkdir -p $(BONUS_OBJS_PATH)/display
	@mkdir -p $(BONUS_OBJS_PATH)/init
	@mkdir -p $(BONUS_OBJS_PATH)/maths
	@echo "$(SUCCESS)Objects folder created successfully$(NOC)"

clean_bonus:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(BONUS_OBJS_PATH)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting minilibx files..."
	@make -C $(MLX) clean
	@echo "$(SUCCESS)Minilibx files deleted successfully!$(NOC)"

clean:
	@echo "$(INFO)Deleting .o files...$(NOC)"
	@rm -rf $(OBJ_PATH)
	@echo "$(SUCCESS).o files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting libft files..."
	@make -C $(FT) clean
	@echo "$(SUCCESS)Libft files deleted successfully!$(NOC)"
	@echo "$(INFO)Deleting minilibx files..."
	@make -C $(MLX) clean
	@echo "$(SUCCESS)Minilibx files deleted successfully!$(NOC)"

fclean: clean
	@echo "$(INFO)Deleting $(NAME)...$(NOC)"
	@rm -rf $(NAME)
	@echo "$(SUCCESS)$(NAME) deleted successfully!$(NOC)"
	@make -C $(FT) fclean

fclean_bonus: clean_bonus
	@echo "$(INFO)Deleting $(BONUS)...$(NOC)"
	@rm -rf $(BONUS)
	@echo "$(SUCCESS)$(BONUS) deleted successfully!$(NOC)"
	@make -C $(FT) fclean

re: fclean all

re_bonus: fclean_bonus $(BONUS)

.PHONY:	all obj clean fclean re