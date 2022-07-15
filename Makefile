FLAG = -Werror -Wextra -Wall -g -MMD -O3
OBJ = $(addprefix obj/, ps_parse.o ps_parse_2.o ps_parse_3.o ps_algo_coast.o ps_push.o ps_swap.o ps_reverse.o ps_rotate.o ps_sort.o ps_sort_2.o ps_easy_instr.o ps_easy_instr_2.o ps_do_instruction.o ps_do_instruction_2.o ps_init_stack_b.o ps_init_stack_b_2.o ps_tools_algo.o ps_utils.o main.o)
D_LIST = $(addprefix obj/, ps_parse.d ps_parse_2.d ps_parse_3.d ps_algo_coast.d ps_push.d ps_swap.d ps_reverse.d ps_rotate.d ps_sort.d ps_sort_2.d ps_easy_instr.d ps_easy_instr_2.d ps_do_instruction.d ps_do_instruction_2.c ps_init_stack_b.c ps_init_stack_b_2.d ps_tools_algo.d ps_utils.d main.d)
NAME = push_swap
LIB = lib/libft
BONUSPATH = bonus_dir

all : $(NAME)

bonus : 
	@make -C $(BONUSPATH)

$(NAME): $(OBJ)
	@make -s bonus -C $(LIB)
	$(CC) $(FLAG) $(OBJ) -L $(LIB) -lft -o $(NAME)

obj/%.o: src/%.c | object
	$(CC) $(FLAG) -I $(LIB) -I ./includes -c $< -o $@

object :
	@mkdir -p obj

fclean :
	rm -f $(OBJ)
	rm -f $(D_LIST)
	rm -rf obj
	rm -f $(NAME)
	@make fclean -s -C $(LIB)
	@make fclean -C $(BONUSPATH)

clean :
	rm -f $(NAME)
	@make clean -s -C $(LIB)
	@make clean -C $(BONUSPATH)

re : fclean all

.PHONY: re all clean fclean
-include $(D_LIST)
