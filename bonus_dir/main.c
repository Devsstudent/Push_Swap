/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:07:50 by odessein          #+#    #+#             */
/*   Updated: 2022/07/15 19:51:37 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*lst;
	int		*arr;

	stack_a = NULL;
	stack_b = NULL;
	lst = NULL;
	if (!ps_parse_start(ac, av, &arr, &stack_a))
		return (0);
	if (!ps_read_instruction(&lst))
	{
		ps_free_end(&stack_a, &stack_b, arr, &lst);
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	ps_exec_instruction(&lst, &stack_a, &stack_b);
	ps_check_sort(&lst, &stack_a, &stack_b, arr);
}
