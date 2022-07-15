/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:54:49 by odessein          #+#    #+#             */
/*   Updated: 2022/07/13 19:23:42 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"
//Shift down element by one
void	ps_rra(t_list **stack_a)
{
	t_list	*last;
	t_list	*buff;

	if (!(*stack_a)->next | !(stack_a) || !(*stack_a))
		return ;
	last = ft_lstlast(*stack_a);
	buff = *stack_a;
	while (buff->next != last)
		buff = buff->next;
	buff->next = NULL;
	ft_lstadd_front(stack_a, last);
	ft_printf("rra\n");
}

void	ps_rrb(t_list **stack_b)
{
	t_list	*last;
	t_list	*buff;

	if (!(*stack_b)->next || !stack_b || !(*stack_b))
		return ;
	last = ft_lstlast(*stack_b);
	buff = *stack_b;
	while (buff->next != last)
		buff = buff->next;
	buff->next = NULL;
	ft_lstadd_front(stack_b, last);
	ft_printf("rrb\n");
}

static void	ps_rra_m(t_list **stack_a)
{
	t_list	*last;
	t_list	*buff;

	if (!(*stack_a)->next || !(*stack_a) || !(stack_a))
		return ;
	last = ft_lstlast(*stack_a);
	buff = *stack_a;
	while (buff->next != last)
		buff = buff->next;
	buff->next = NULL;
	ft_lstadd_front(stack_a, last);
}

static void	ps_rrb_m(t_list **stack_b)
{
	t_list	*last;
	t_list	*buff;

	if (!(*stack_b)->next)
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
	ps_rrb_m(stack_b);
	ps_rra_m(stack_a);
	ft_printf("rrr\n");
}
