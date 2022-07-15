/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:53:48 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 19:54:35 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	ps_ra(t_list **stack_a)
{
	t_list	*buff;

	if (!stack_a || !(*stack_a))
		return ;
	if (!(*stack_a)->next)
		return ;
	buff = *stack_a;
	ft_lstadd_back(stack_a, buff);
	*stack_a = (*stack_a)->next;
	buff->next = NULL;
	ft_printf("ra\n");
}

void	ps_rb(t_list **stack_b)
{
	t_list	*buff;

	if (!stack_b || !(*stack_b))
		return ;
	if (!(*stack_b)->next)
		return ;
	buff = *stack_b;
	ft_lstadd_back(stack_b, buff);
	*stack_b = (*stack_b)->next;
	buff->next = NULL;
	ft_printf("rb\n");
}

static void	ps_ra_m(t_list **stack_a)
{
	t_list	*buff;

	if (!stack_a || !(*stack_a))
		return ;
	if (!(*stack_a)->next)
		return ;
	buff = *stack_a;
	ft_lstadd_back(stack_a, buff);
	*stack_a = (*stack_a)->next;
	buff->next = NULL;
}

static void	ps_rb_m(t_list **stack_b)
{
	t_list	*buff;

	if (!stack_b || !(*stack_b))
		return ;
	if (!(*stack_b)->next)
		return ;
	buff = *stack_b;
	ft_lstadd_back(stack_b, buff);
	*stack_b = (*stack_b)->next;
	buff->next = NULL;
}

void	ps_rr(t_list **stack_a, t_list **stack_b)
{
	ps_ra_m(stack_a);
	ps_rb_m(stack_b);
	ft_printf("rr\n");
}
