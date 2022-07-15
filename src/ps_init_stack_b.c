/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:28:18 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 23:19:54 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	ps_init_b(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	t_coast	coast;
	t_list	*mid;

	mid = ps_find_mid(stack_a);
	min = ps_find_min(stack_a);
	while (!ps_check_minus(stack_a, min, mid))
	{
		ps_check_move_min(stack_a, min, &coast, mid);
		ps_exec_st(stack_a, stack_b, &coast);
		ps_pb(stack_a, stack_b);
	}
	ps_push_half(stack_a, stack_b, mid);
}

void	ps_check_move_min(t_list **stack_a, t_list *min, t_coast *coast,
t_list *mid)
{
	t_list	*buff;
	int		i;
	int		val;

	ps_init_coast(coast);
	i = 0;
	buff = *stack_a;
	while (buff != NULL)
	{
		val = *((int *) buff->content);
		if (val < *((int *) mid->content) && buff != min)
		{
			ps_fill_coast_half_b(i, coast, stack_a);
			return ;
		}
		i++;
		buff = buff->next;
	}
}

t_bool	ps_check_minus(t_list **stack, t_list *min, t_list *mid)
{
	t_list	*buff;
	int		val;

	buff = *stack;
	while (buff != NULL)
	{
		val = *((int *) buff->content);
		if (buff != min && val < *((int *) mid->content))
			return (FALSE);
		buff = buff->next;
	}
	return (TRUE);
}

void	ps_push_half(t_list **stack_a, t_list **stack_b, t_list *mid)
{
	t_coast	coast;

	while (!ps_check_half_pushed(stack_a, mid))
	{
		ps_check_move(stack_a, &coast);
		ps_exec_st(stack_a, stack_b, &coast);
		ps_pb(stack_a, stack_b);
	}
}

void	ps_check_move(t_list **stack_a, t_coast *coast)
{
	t_list	*buff;
	int		i;
	t_list	*min;
	t_list	*max;

	ps_init_coast(coast);
	i = 0;
	buff = *stack_a;
	min = ps_find_min(stack_a);
	max = ps_find_max(stack_a);
	while (buff != NULL)
	{
		if (buff != min && buff != max)
		{
			ps_fill_coast_half_b(i, coast, stack_a);
			return ;
		}
		i++;
		buff = buff->next;
	}
}
