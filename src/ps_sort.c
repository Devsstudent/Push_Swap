/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:20:49 by odessein          #+#    #+#             */
/*   Updated: 2022/07/10 00:03:03 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	ps_sort(t_list **stack_a, t_list **stack_b)
{
	t_coast	coast;

	while (!ps_is_sorted(stack_a, stack_b))
	{
		coast = ps_coast(stack_a, stack_b);
		ps_exec(stack_a, stack_b, &coast);
	}
}

t_bool	ps_sorted_start(t_list **stack_a)
{
	t_list	*buff;
	int		val;

	buff = *stack_a;
	val = *((int *) buff->content);
	while (buff != NULL)
	{
		if (*((int *) buff->content) < val)
			return (FALSE);
		val = *((int *) buff->content);
		buff = buff->next;
	}
	return (TRUE);
}

void	ps_exec(t_list **stack_a, t_list **stack_b, t_coast *coast)
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
	ps_pa(stack_a, stack_b);
}

int	ps_opti_rrr(t_coast *coast)
{
	int	value;

	if (coast->rra && coast->rrb)
	{
		if (coast->ac > coast->bc)
		{
			coast->ac = coast->ac - coast->bc;
			value = coast->bc;
			coast->bc = 0;
			return (value);
		}
		else
		{
			coast->bc = coast->bc - coast->ac;
			value = coast->ac;
			coast->ac = 0;
			return (value);
		}
	}
	return (0);
}

int	ps_opti_rr(t_coast *coast)
{
	int	value;

	if (coast->ra && coast->rb)
	{
		if (coast->ac > coast->bc)
		{
			coast->ac = coast->ac - coast->bc;
			value = coast->bc;
			coast->bc = 0;
			return (value);
		}
		else
		{
			coast->bc = coast->bc - coast->ac;
			value = coast->ac;
			coast->ac = 0;
			return (value);
		}
	}
	return (0);
}
