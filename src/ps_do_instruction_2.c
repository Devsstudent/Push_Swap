/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_do_instruction_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:27:18 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:27:43 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

void	ps_loop_rrr(int turn, t_list **stack_a, t_list **stack_b)
{
	int	i;

	i = 0;
	while (i < turn)
	{
		ps_rrr(stack_a, stack_b);
		i++;
	}
}
