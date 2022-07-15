/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_swap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:56:35 by odessein          #+#    #+#             */
/*   Updated: 2022/07/13 18:05:39 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"

void	ps_sa(t_list **stack_a)
{
	t_list	*buffer;
	t_list	*next;

	if (!(*stack_a))
		return ;
	buffer = (*stack_a)->next;
	next = buffer->next;
	buffer->next = (*stack_a);
	(*stack_a)->next = (*stack_a);
	(*stack_a)->next = next;
	(*stack_a) = buffer;
}

void	ps_sb(t_list **stack_b)
{
	t_list	*buffer;
	t_list	*next;

	if (!(*stack_b))
		return ;
	buffer = (*stack_b)->next;
	next = buffer->next;
	buffer->next = (*stack_b);
	(*stack_b)->next = (*stack_b);
	(*stack_b)->next = next;
	(*stack_b) = buffer;
}

void	ps_ss(t_list **stack_a, t_list **stack_b)
{
	ps_sa(stack_a);
	ps_sb(stack_b);
}
