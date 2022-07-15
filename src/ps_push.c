/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:56:14 by odessein          #+#    #+#             */
/*   Updated: 2022/07/13 19:00:55 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	ps_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_b;

	if (!stack_b || !stack_a || !(*stack_b))
		return ;
	top_b = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, top_b);
	ft_printf("pa\n");
}

void	ps_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*top_a;

	if (!stack_a || !stack_b || !(*stack_a))
		return ;
	top_a = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, top_a);
	ft_printf("pb\n");
}
