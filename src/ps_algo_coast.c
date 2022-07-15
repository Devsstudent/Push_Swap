/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_algo_coast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:03:48 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 23:19:17 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

//fill la struct pour b
//Comparer chaque value de b a toutes les valeurs de a
//Au final on a bien une struct avec les bonnes value

t_coast	ps_coast(t_list **stack_a, t_list **stack_b)
{
	t_list	*buff;
	t_coast	coast;
	int		i;
	int		val_elem;

	i = 0;
	buff = *stack_b;
	ps_init_coast(&coast);
	coast.size_b = ft_lstsize(*stack_b);
	while (buff != NULL)
	{
		val_elem = *((int *) buff->content);
		ps_coast_pos_a(stack_a, val_elem, &coast, i);
		buff = buff->next;
		i++;
	}
	return (coast);
}

void	ps_coast_pos_a(t_list **stack_a, int elem_val, t_coast *coast,
int ind_b)
{
	t_list	*buff;
	int		i;
	int		size;

	i = 0;
	size = ft_lstsize(*stack_a);
	buff = *stack_a;
	if (ps_check_insert(buff, i, stack_a, elem_val)
		&& ps_check_coast(i, ind_b, coast, size))
		ps_fill_coast(i, ind_b, coast, size);
	while (buff->next != NULL)
	{
		if (ps_check_insert(buff, i + 1, stack_a, elem_val)
			&& ps_check_coast(i + 1, ind_b, coast, size))
			ps_fill_coast(i + 1, ind_b, coast, size);
		i++;
		buff = buff->next;
	}
}

t_bool	ps_check_coast(int index, int index_b, t_coast *coast, int size)
{
	t_coast	buff_coast;

	ps_init_coast(&buff_coast);
	buff_coast.size_b = coast->size_b;
	ps_fill_coast(index, index_b, &buff_coast, size);
	if (buff_coast.total < coast->total)
		return (TRUE);
	return (FALSE);
}

void	ps_fill_coast(int index, int index_b, t_coast *coast, int size)
{
	if (index > (size / 2))
	{
		coast->ac = (size - index);
		coast->rra = TRUE;
		coast->ra = FALSE;
	}
	else
	{
		coast->ac = index;
		coast->ra = TRUE;
		coast->rra = FALSE;
	}
	if (index_b > (coast->size_b / 2))
	{
		coast->bc = (coast->size_b - index_b);
		coast->rrb = TRUE;
		coast->rb = FALSE;
	}
	else
	{
		coast->bc = index_b;
		coast->rb = TRUE;
		coast->rrb = FALSE;
	}
	ps_fill_total(coast);
}

void	ps_fill_total(t_coast *coast)
{
	if (coast->rra && coast->rrb)
	{
		if (coast->bc > coast->ac)
			coast->total = coast->ac + (coast->bc - coast->ac);
		else
			coast->total = coast->bc + (coast->ac - coast->bc);
	}
	if (coast->ra && coast->rb)
	{
		if (coast->bc > coast->ac)
			coast->total = coast->ac + (coast->bc - coast->ac);
		else
			coast->total = coast->bc + (coast->ac - coast->bc);
	}
	else
		coast->total = coast->bc + coast->ac;
}
