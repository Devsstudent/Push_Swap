/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_3_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:38:42 by odessein          #+#    #+#             */
/*   Updated: 2022/07/13 18:53:55 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"

void	ps_split_atoi(int **arr, char *char_to_num, int *index)
{
	int	i;

	i = 0;
	while (char_to_num[i])
	{
		(*arr)[(*index)++] = ft_atoi(&char_to_num[i]);
		if (char_to_num[i] == ' ')
			i++;
		while (ft_is_digit(char_to_num[i]) || char_to_num[i] == '-')
			i++;
	}
}

int	ps_size(int ac, char **av)
{
	int	n;
	int	size;

	n = 1;
	size = 0;
	while (n < ac)
	{
		if (!ps_count(av[n], &size))
			return (0);
		n++;
	}
	return (size);
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
