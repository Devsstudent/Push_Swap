/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_init_stack_b_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:29:54 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:33:21 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

t_bool	ps_check_half_pushed(t_list **stack_a, t_list *mid)
{
	t_list	*buff;
	t_list	*max;
	int		val;

	buff = *stack_a;
	max = ps_find_max(stack_a);
	while (buff != NULL)
	{
		val = *((int *) buff->content);
		if (buff != max && val >= *((int *) mid->content))
			return (FALSE);
		buff = buff->next;
	}
	return (TRUE);
}

void	ps_fill_coast_half_b(int index, t_coast *coast, t_list **stack)
{
	int	size;

	size = ft_lstsize(*stack);
	coast->bc = 0;
	if (index > (size / 2))
	{
		coast->ac = (size - index);
		coast->rra = TRUE;
		coast->ra = FALSE;
	}
	else
	{
		coast->ac = index;
		coast->rra = FALSE;
		coast->ra = TRUE;
	}
}

void	ps_exec_st(t_list **stack_a, t_list **stack_b, t_coast *coast)
{
	int	rr;
	int	rrr;

	rr = ps_opti_rr(coast);
	rrr = ps_opti_rrr(coast);
	ps_loop_rr(rr, stack_a, stack_b);
	ps_loop_rrr(rrr, stack_a, stack_b);
	if (coast->ra)
		ps_loop_ra(coast->ac, stack_a);
	if (coast->rra)
		ps_loop_rra(coast->ac, stack_a);
	if (coast->rb)
		ps_loop_rb(coast->bc, stack_b);
	if (coast->rrb)
		ps_loop_rrb(coast->bc, stack_b);
}
