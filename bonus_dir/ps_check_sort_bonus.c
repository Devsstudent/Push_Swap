/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:08:15 by odessein          #+#    #+#             */
/*   Updated: 2022/07/13 18:29:31 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"

void	ps_check_sort(t_list **lst, t_list **stack_a, t_list **stack_b,
int *arr)
{
	t_list	*tmp;

	if (*stack_b)
	{
		ft_printf("KO\n");
		while (*stack_b)
		{
			tmp = (*stack_b)->next;
			free(*stack_b);
			*stack_b = tmp;
		}
		ps_free_end(stack_a, stack_b, arr, lst);
		return ;
	}
	if (!ps_sorted_start(stack_a))
	{
		ft_printf("KO\n");
		ps_free_end(stack_a, stack_b, arr, lst);
		return ;
	}
	ft_printf("OK\n");
	ps_free_end(stack_a, stack_b, arr, lst);
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
