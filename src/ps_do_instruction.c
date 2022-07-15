/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_instruction.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:06:12 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:27:45 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_loop_rr(int turn, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < turn)
	{
		ps_rr(stack_a, stack_b);
		i++;
	}
}

void	ps_loop_rrb(int turn, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < turn)
	{
		ps_rrb(stack_b);
		i++;
	}
}

void	ps_loop_rb(int turn, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < turn)
	{
		ps_rb(stack_b);
		i++;
	}
}

void	ps_loop_ra(int turn, t_list **stack_a)
{
	int	i;

	i = 0;
	while (i < turn)
	{
		ps_ra(stack_a);
		i++;
	}
}

void	ps_loop_rra(int turn, t_list **stack_a)
{
	int	i;

	i = 0;
	while (i < turn)
	{
		ps_rra(stack_a);
		i++;
	}
}
