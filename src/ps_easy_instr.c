/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_easy_instr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:07:11 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 23:20:09 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_two(t_list **stack_a)
{
	t_list	*buff;
	int		buffer;

	buff = *stack_a;
	buffer = *((int *) buff->content);
	while (buff != NULL)
	{
		if (buffer > *((int *) buff->content))
			ps_sa(stack_a);
		buffer = *((int *) buff->content);
		buff = buff->next;
	}
}

void	ps_three(t_list **stack_a)
{
	int	val_one;
	int	val_two;
	int	val_three;

	val_one = *((int *)(*stack_a)->content);
	val_two = *((int *)(*stack_a)->next->content);
	val_three = *((int *)(*stack_a)->next->next->content);
	ps_conditional_sorting(val_one, val_two, val_three, stack_a);
}

void	ps_conditional_sorting(int val_one, int val_two, int val_three,
t_list **stack_a)
{
	if (val_one < val_two && val_three < val_one && val_three < val_one)
		ps_rra(stack_a);
	if (val_one < val_two && val_three < val_two && val_three > val_one)
	{
		ps_sa(stack_a);
		ps_ra(stack_a);
	}
	if (val_one > val_two && val_three < val_one && val_three > val_two)
		ps_ra(stack_a);
	if (val_one > val_two && val_three > val_one && val_three > val_two)
		ps_sa(stack_a);
	if (val_one > val_two && val_two > val_three && val_three < val_one)
	{
		ps_sa(stack_a);
		ps_rra(stack_a);
	}
}

void	ps_four(t_list **stack_a, t_list **stack_b)
{
	ps_pb(stack_a, stack_b);
	ps_three(stack_a);
	ps_insert_and_sort(stack_a, stack_b);
	if (*stack_b)
	{
		ps_pa(stack_a, stack_b);
		ps_ra(stack_a);
	}
}

void	ps_insert_and_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*buff;
	int		i;
	int		j;
	int		val_a;
	int		val_b;

	i = 0;
	j = -1;
	buff = *stack_a;
	val_b = *((int *)((*stack_b)->content));
	while (buff != NULL)
	{
		val_a = *((int *)((buff)->content));
		if (val_b < val_a)
		{
			while (++j < i)
				ps_ra(stack_a);
			ps_pa(stack_a, stack_b);
			ps_sort_a(stack_a);
			return ;
		}
		i++;
		buff = buff->next;
	}
}
