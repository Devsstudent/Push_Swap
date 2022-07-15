/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:36:44 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:37:12 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

t_bool	ps_is_sorted(t_list **stack_a, t_list **stack_b)
{
	t_list	*buff;
	int		val;

	if (*stack_b)
		return (FALSE);
	else
		ps_sort_a(stack_a);
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

void	ps_sort_a(t_list **stack_a)
{
	t_list	*buff;
	int		size;
	int		val;

	size = ft_lstsize(*stack_a);
	buff = *stack_a;
	val = *((int *) buff->content);
	ps_loop_sort_a(buff, size, val, stack_a);
}

void	ps_loop_sort_a(t_list *buff, int size, int val, t_list **stack_a)
{
	int		i;
	int		j;

	j = -1;
	i = 0;
	while (buff != NULL)
	{
		if (*((int *) buff->content) < val)
		{
			if (i < size / 2)
			{
				while (++j < i)
					ps_ra(stack_a);
			}
			else
			{
				while (++j < (size - i))
					ps_rra(stack_a);
			}
		}
		val = *((int *) buff->content);
		buff = buff->next;
		i++;
	}
}
