NAME		= workshop

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -g

SRC_PATH 	= src
OBJ_PATH 	= obj

SRC			= 	main.c

SRCS 		= $(addprefix $(SRC_PATH)/, $(SRC))
OBJ 		= $(SRC:.c=.o)
OBJS 		= $(addprefix $(OBJ_PATH)/, $(OBJ))

LIBFT_DIR 	= libft
LIBFT 		= $(LIBFT_DIR)/libft.a

.PHONY: all  clean fclean re val

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) 

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)

#Malloc tester_________________________________________________________________________
malloc_test: $(OBJ_PATH) $(NAME)
	$(CC) $(CFLAGS) -fsanitize=undefined -rdynamic -o $@ ${OBJS} -L./libft/ -l:libft.a -L. -lmallocator

#General______________________________________________________________________________
clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(MAGENTA)Obj directory removed.$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(MAGENTA)Make clean in directory "$(LIBFT_DIR)" invoked.$(NC)"

fclean:
	@rm -rf $(OBJ_PATH)
	@echo "$(MAGENTA)Obj directory removed.$(NC)"
	@rm -f $(NAME)
	@echo "$(MAGENTA)Deleted executable named: $(NAME)$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(MAGENTA)Make fclean in directory "$(LIBFT_DIR)" invoked.$(NC)"

re: fclean all
	@echo "$(GREEN)Recompilation successfully done!$(NC)"

#Extra______________________________________________________________________________
val: all
	valgrind \
	--leak-check=full \
	--show-leak-kinds=all \
	--track-origins=yes \
	./$(NAME)


#--------COLORS---------------------------------#
RED			=	\033[0;31m
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
BLUE 		=	\033[0;34m
MAGENTA 	=	\033[0;35m
CYAN 		=	\033[0;36m
WHITE		=	\033[0;37m
NC			=	\033[0m


#-------BOLD COLORS-----------------------------#
BRED		=	\033[1;31m
BGREEN		=	\033[1;32m
BYELLOW		=	\033[1;33m
BBLUE 		=	\033[1;34m
BMAGENTA 	=	\033[1;35m
BCYAN 		=	\033[1;36m
BWHITE		=	\033[1;37m
