/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:33:27 by odessein          #+#    #+#             */
/*   Updated: 2022/07/15 20:10:44 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	ps_init_coast(t_coast *coast)
{
	coast->ac = INT_MAX;
	coast->bc = INT_MAX;
	coast->rra = FALSE;
	coast->rrb = FALSE;
	coast->ra = FALSE;
	coast->rb = FALSE;
	coast->total = INT_MAX;
}

t_bool	ps_parse_start(int ac, char **av, int **arr, t_list **stack_a)
{
	if (ac == 1)
		return (FALSE);
	if (!ps_parse_input(ac, av, arr, stack_a))
	{
		ft_putstr_fd("Error\n", 2);
		return (FALSE);
	}
	return (TRUE);
}

void	ps_free_end(t_list **stack_a, int *arr)
{
	t_list	*tmp;

	while (stack_a && *stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	free(arr);
}

t_bool	ps_do_till_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2)
	{
		ps_two(stack_a);
		return (TRUE);
	}
	if (size == 3)
	{
		ps_three(stack_a);
		return (TRUE);
	}
	if (size == 4)
	{
		ps_four(stack_a, stack_b);
		return (TRUE);
	}
	if (size == 5)
	{
		ps_five(stack_a, stack_b);
		return (TRUE);
	}
	return (FALSE);
}

void	ps_fill_arr_find_mid(int **arr, t_list *buff)
{
	int	i;

	i = 0;
	while (buff != NULL)
	{
		(*arr)[i] = *((int *) buff->content);
		buff = buff->next;
		i++;
	}
}
