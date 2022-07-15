/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:54:49 by odessein          #+#    #+#             */
/*   Updated: 2022/07/15 19:39:06 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"
//Shift down element by one
void	ps_rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*buff;

	if (!stack_a || !(*stack_a) || !(*stack_a)->next)
		return ;
	last = ft_lstlast(*stack_a);
	buff = *stack_a;
	while (buff->next != last)
		buff = buff->next;
	buff->next = NULL;
	ft_lstadd_front(stack_a, last);
}

void	ps_rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*buff;

	if (!stack_b || !(*stack_b) || !(*stack_b)->next)
		return ;
	last = ft_lstlast(*stack_b);
	buff = *stack_b;
	while (buff->next != last)
		buff = buff->next;
	buff->next = NULL;
	ft_lstadd_front(stack_b, last);
}

void	ps_rrr(t_list **stack_a, t_list **stack_b)
{
	ps_rrb(stack_b);
	ps_rra(stack_a);
}
