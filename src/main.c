/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:28:24 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:36:07 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

int	main(int ac, char **av)
{
	int		*arr;
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!ps_parse_start(ac, av, &arr, &stack_a))
		return (0);
	if (ps_sorted_start(&stack_a))
	{
		ps_free_end(&stack_a, arr);
		return (0);
	}
	if (ps_do_till_five(&stack_a, &stack_b))
	{
		ps_free_end(&stack_a, arr);
		return (0);
	}
	ps_init_b(&stack_a, &stack_b);
	ps_sort(&stack_a, &stack_b);
	ps_free_end(&stack_a, arr);
}
