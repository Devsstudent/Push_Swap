FLAG = -Wextra -Wall -Werror -MMD -g -O3
OBJ = ps_parse_bonus.o ps_check_sort_bonus.o ps_parse_2_bonus.o ps_parse_3_bonus.o ps_read_exec_instruction_bonus.o ps_push_bonus.o ps_rotate_bonus.o ps_reverse_bonus.o ps_swap_bonus.o ps_utils_bonus.o main.o
D_FILE = ps_parse_bonus.d ps_check_sort_bonus.d ps_parse_2_bonus.d ps_parse_3_bonus.d ps_read_exec_instruction_bonus.d ps_push_bonus.d ps_rotate_bonus.d ps_reverse_bonus.d ps_swap_bonus.d ps_utils_bonus.d main.d
LIBPATH = ../lib/libft
NAME = ../checker

all : $(NAME)

$(NAME) : $(OBJ)
	@make -s bonus -C $(LIBPATH)
	$(CC) $(FLAG) $(OBJ) -L $(LIBPATH) -lft -o $(NAME)

%.o: %.c
	$(CC) $(FLAG) -I $(LIBPATH) -c $< -o $@

clean :
	rm -f $(NAME)
	@make clean -s -C $(LIBPATH)

fclean :
	rm -f $(NAME)
	rm -f $(OBJ)
	rm -f $(D_FILE)
	@make fclean -s -C $(LIBPATH)

re : fclean all

.PHONY: re all clean fclean
-include $(D_FILE)
