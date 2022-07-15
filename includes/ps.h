/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 23:27:35 by odessein          #+#    #+#             */
/*   Updated: 2022/07/10 03:12:33 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PS_H
# define PS_H

# include "libft.h"
# include "limits.h"

typedef struct s_coast {
	int		ac;
	int		bc;
	t_bool	rra;
	t_bool	rrb;
	t_bool	ra;
	t_bool	rb;
	int		total;
	int		size_b;
}			t_coast;

/*----------------------Parsing-------------------*/

t_bool	ps_check_size_max(char *char_to_num, int start);
t_bool	ps_check_size(char *char_to_num, int *index);
t_bool	ps_check_neg(char *char_to_num, int *size, int *index);
t_bool	ps_check_number(char *char_to_num, int *size, int *index);

t_bool	ps_parse_input(int ac, char **av, int **arr, t_list **stack_a);
t_bool	ps_fill_arr(int ac, char **av, int **arr);
t_bool	ps_check_one_elem(char *num_or_nums);
void	ps_split_atoi(int **arr, char *char_to_num, int *index);
int		ps_size(int ac, char **av);
t_bool	ps_count(char *elems, int *size);
t_bool	ps_check_double(int **arr, int size);
t_bool	ps_fill_stack_a(int **arr, int size, t_list **stack_a);

/*--------------------Instruc----------------------*/

void	ps_pa(t_list **stack_a, t_list **stack_b);
void	ps_pb(t_list **stack_a, t_list **stack_b);
void	ps_rra(t_list **stack_a);
void	ps_rrb(t_list **stack_b);
void	ps_rrr(t_list **stack_a, t_list **stack_b);
void	ps_ra(t_list **stack_a);
void	ps_rb(t_list **stack_b);
void	ps_rr(t_list **stack_a, t_list **stack_b);
void	ps_sa(t_list **stack_a);
void	ps_sb(t_list **stack_b);
void	ps_ss(t_list **stack_a, t_list **stack_b);

/*--------------------Algo------------------*/

void	ps_init_b(t_list **stack_a, t_list **stack_b);
void	ps_check_move_min(t_list **stack_a, t_list *min, t_coast *coast,
			t_list *mid);
void	ps_push_half(t_list **stack_a, t_list **stack_b, t_list *mid);
void	ps_init_coast(t_coast *coast);
t_list	*ps_find_min(t_list **stack_b);
t_list	*ps_find_max(t_list **stack);
t_bool	ps_check_minus(t_list **stack, t_list *min, t_list *mid);
t_bool	ps_check_half_pushed(t_list **stack_a, t_list *mid);
void	ps_fill_coast_half_b(int index, t_coast *coast, t_list **stack);
void	ps_check_move(t_list **stack_a, t_coast *coast);;
void	ps_exec_st(t_list **stack_a, t_list **stack_b, t_coast *coast);
int		ps_check_last_elem(t_list **stack_a);

/*-------------------Easy_Sort-------------------*/

void	ps_three(t_list **stack_a);
void	ps_four(t_list **stack_a, t_list **stack_b);
void	ps_insert_and_sort(t_list **stack_a, t_list **stack_b);
void	ps_push_min(t_list **stack_a, t_list **stack_b);
void	ps_five(t_list **stack_a, t_list **stack_b);
void	ps_two(t_list **stack_a);
void	ps_conditional_sorting(int val_one, int val_two, int val_three,
			t_list **stack_a);

/*------------------Algo2-----------------*/

t_coast	ps_coast(t_list **stack_a, t_list **stack_b);
void	ps_coast_pos_a(t_list **stack_a, int elem_val, t_coast *coast,
			int ind_d);
t_bool	ps_check_coast(int index, int index_b, t_coast *coast, int size);
void	ps_fill_coast(int index, int index_b, t_coast *coast, int size);
void	ps_fill_total(t_coast *coast);
t_bool	ps_check_insert(t_list *node, int index, t_list **stack_a,
			int elem_val);

/*--------------------Sort + Exec -----------------*/

void	ps_loop_sort_a(t_list *buff, int size, int val, t_list **stack_a);
void	ps_sort(t_list **stack_a, t_list **stack_b);
void	ps_exec(t_list **stack_a, t_list **stack_b, t_coast *coast);
int		ps_opti_rrr(t_coast *coast);
int		ps_opti_rr(t_coast *coast);
t_bool	ps_is_sorted(t_list **stack_a, t_list **stack_b);
void	ps_sort_a(t_list **stack_a);

/*-----------------UTILS----------------*/

t_bool	ps_do_till_five(t_list **stack_a, t_list **stack_b);
void	ps_display_stack(t_list **stack);
t_list	*ps_find_mid(t_list **stack);
void	ps_fill_arr_find_mid(int **arr, t_list *buff);
t_bool	ps_sorted_start(t_list **stack_a);
void	ps_free_end(t_list **stack_a, int *arr);
t_bool	ps_parse_start(int ac, char **av, int **arr, t_list **stack_a);

/*------------------LOOP------------------*/

void	ps_loop_rr(int turn, t_list **stack_a, t_list **stack_b);
void	ps_loop_rrb(int turn, t_list **stack_b);
void	ps_loop_rb(int turn, t_list **stack_b);
void	ps_loop_ra(int turn, t_list **stack_a);
void	ps_loop_rra(int turn, t_list **stack_a);
void	ps_loop_rrr(int turn, t_list **stack_a, t_list **stack_b);

#endif
