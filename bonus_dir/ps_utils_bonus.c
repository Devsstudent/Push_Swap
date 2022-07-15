/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 02:39:18 by odessein          #+#    #+#             */
/*   Updated: 2022/07/15 20:05:26 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"

void	ps_free_end(t_list **stack_a, t_list **stack_b, int *arr, t_list **lst)
{
	t_list	*tmp;

	while (stack_a && *stack_a != NULL)
	{
		tmp = (*stack_a)->next;
		free(*stack_a);
		*stack_a = tmp;
	}
	while (stack_b && *stack_b != NULL)
	{
		tmp = (*stack_b)->next;
		free(*stack_b);
		*stack_b = tmp;
	}
	if (arr)
		free(arr);
	ft_lstclear(lst, free);
}

void	ps_check_instruction_2(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		ps_sa(stack_a);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		ps_sb(stack_b);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ps_ss(stack_a, stack_b);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ps_sa(stack_a);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		ps_sb(stack_b);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		ps_pa(stack_a, stack_b);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		ps_pb(stack_a, stack_b);
}
