/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_tools_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:57:23 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 23:24:20 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

t_bool	ps_check_insert(t_list *node, int index, t_list **stack_a, int elem_val)
{
	int	val;
	int	val_next;

	val = *((int *) node->content);
	val_next = *((int *) node->next->content);
	if (index == 0)
	{
		if (elem_val < val && elem_val > ps_check_last_elem(stack_a))
			return (TRUE);
		return (FALSE);
	}
	if (elem_val > val && elem_val < val_next)
		return (TRUE);
	return (FALSE);
}

t_list	*ps_find_mid(t_list **stack)
{
	int		*arr;
	t_list	*buff;

	arr = (int *) malloc(sizeof(int) * ft_lstsize(*stack));
	if (!arr)
		return (NULL);
	buff = *stack;
	ps_fill_arr_find_mid(&arr, buff);
	ft_sort_int_tab(arr, ft_lstsize(*stack));
	buff = *stack;
	while (buff != NULL)
	{
		if (*((int *) buff->content) == arr[ft_lstsize(*stack) / 2])
		{
			free(arr);
			return (buff);
		}
		buff = buff->next;
	}
	free(arr);
	return (NULL);
}

t_list	*ps_find_max(t_list **stack)
{
	int		max;
	t_list	*buff;

	buff = *stack;
	max = INT_MIN;
	while (buff != NULL)
	{
		if (*((int *) buff->content) > max)
			max = *((int *) buff->content);
		buff = buff->next;
	}
	buff = *stack;
	while (buff != NULL)
	{
		if (*((int *) buff->content) == max)
			return (buff);
		buff = buff->next;
	}
	return (NULL);
}

t_list	*ps_find_min(t_list **stack_b)
{
	int		min;
	t_list	*buff;

	buff = *stack_b;
	min = INT_MAX;
	while (buff != NULL)
	{
		if (*((int *) buff->content) < min)
			min = *((int *) buff->content);
		buff = buff->next;
	}
	buff = *stack_b;
	while (buff != NULL)
	{
		if (*((int *) buff->content) == min)
			return (buff);
		buff = buff->next;
	}
	return (NULL);
}

int	ps_check_last_elem(t_list **stack_a)
{
	t_list	*buff;
	int		val;

	buff = *stack_a;
	while (buff->next != NULL)
		buff = buff->next;
	val = *((int *) buff->content);
	return (val);
}
