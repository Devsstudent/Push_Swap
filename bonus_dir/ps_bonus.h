/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:09:28 by odessein          #+#    #+#             */
/*   Updated: 2022/07/10 03:19:00 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "libft.h"
# include "limits.h"

void	ps_sa(t_list **stack_a);
void	ps_sb(t_list **stack_b);
void	ps_ss(t_list **stack_a, t_list **stack_b);
void	ps_pa(t_list **stack_a, t_list **stack_b);
void	ps_pb(t_list **stack_a, t_list **stack_b);
void	ps_rra(t_list **stack_a);
void	ps_ra(t_list **stack_a);
void	ps_rb(t_list **stack_b);
void	ps_rrb(t_list **stack_b);
void	ps_rrr(t_list **stack_a, t_list **stack_b);
void	ps_rr(t_list **stack_a, t_list **stack_b);

t_bool	ps_count(char *elems, int *size);
t_bool	ps_check_number(char *char_to_num, int *size, int *index);
t_bool	ps_check_neg(char *char_to_num, int *size, int *index);
t_bool	ps_check_size(char *char_to_num, int *index);
t_bool	ps_check_size_max(char *char_to_num, int start);
t_bool	ps_check_double(int **arr, int size);
t_bool	ps_fill_stack_a(int **arr, int size, t_list **stack_a);
t_bool	ps_parse_input(int ac, char **av, int **arr, t_list **stack_a);
t_bool	ps_fill_arr(int ac, char **av, int **arr);
t_bool	ps_check_one_elem(char *num_or_nums);
void	ps_split_atoi(int **arr, char *char_to_num, int *index);
int		ps_size(int ac, char **av);

void	ps_check_sort(t_list **lst, t_list **stack_a, t_list **stack_b,
			int *arr);
void	ps_free_end(t_list **stack_a, t_list **stack_b, int *arr,
			t_list **lst);
t_bool	ps_read_instruction(t_list **lst);
t_bool	ps_check_wrong_input(char *str);
t_bool	ps_check_content(t_list	**lst);
void	ps_exec_instruction(t_list **lst, t_list **stack_a, t_list **stack_b);
void	ps_check_instruction(char *str, t_list **stack_a, t_list **stack_b);
void	ps_check_instruction_2(char *str, t_list **stack_a, t_list **stack_b);
t_bool	ps_sorted_start(t_list **stack_a);
t_bool	ps_parse_start(int ac, char **av, int **arr, t_list **stack_a);

#endif
