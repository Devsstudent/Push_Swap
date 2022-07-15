/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_easy_instr_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:39:36 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:39:58 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	ps_five(t_list **stack_a, t_list **stack_b)
{
	ps_push_min(stack_a, stack_b);
	ps_push_min(stack_a, stack_b);
	ps_three(stack_a);
	if (*((int *)(*stack_b)->content) < *((int *)(*stack_b)->next->content))
		ps_sb(stack_b);
	ps_pa(stack_a, stack_b);
	ps_pa(stack_a, stack_b);
}

void	ps_push_min(t_list **stack_a, t_list **stack_b)
{
	t_list	*min;
	t_list	*buff;
	int		i;
	int		j;

	i = 0;
	j = -1;
	min = ps_find_min(stack_a);
	buff = *stack_a;
	while (buff != NULL)
	{
		if (buff == min)
		{
			while (++j < i && i < 3)
				ps_ra(stack_a);
			while (++j < i && i >= 3)
				ps_rra(stack_a);
			ps_pb(stack_a, stack_b);
			return ;
		}
		buff = buff->next;
		i++;
	}
}
