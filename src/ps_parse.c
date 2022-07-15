/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:10:22 by odessein          #+#    #+#             */
/*   Updated: 2022/07/10 00:02:51 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

t_bool	ps_check_double(int **arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if ((*arr)[i] == (*arr)[j] && i != j)
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}

t_bool	ps_fill_stack_a(int **arr, int size, t_list **stack_a)
{
	int		i;
	t_list	*elem;

	i = 0;
	while (i < size)
	{
		elem = ft_lstnew(&(*arr)[i]);
		if (!elem)
			return (FALSE);
		ft_lstadd_back(stack_a, elem);
		i++;
	}
	return (TRUE);
}

t_bool	ps_parse_input(int ac, char **av, int **arr, t_list **stack_a)
{
	int	size;

	if (!arr)
		return (FALSE);
	size = ps_size(ac, av);
	if (size == 0)
		return (FALSE);
	*arr = (int *) malloc(sizeof(**arr) * size);
	if (!(*arr))
		return (FALSE);
	if (size == 0)
	{
		free(arr);
		return (FALSE);
	}
	ps_fill_arr(ac, av, arr);
	if (!ps_check_double(arr, size) || !ps_fill_stack_a(arr, size, stack_a))
	{
		ps_free_end(stack_a, *arr);
		return (FALSE);
	}
	return (TRUE);
}

t_bool	ps_fill_arr(int ac, char **av, int **arr)
{
	int	n;
	int	index;

	n = 1;
	index = 0;
	while (n < ac)
	{
		if (ps_check_one_elem(av[n]))
			(*arr)[index++] = ft_atoi(av[n]);
		else
			ps_split_atoi(arr, av[n], &index);
		n++;
	}
	return (TRUE);
}

t_bool	ps_check_one_elem(char *num_or_nums)
{
	int	i;

	i = 0;
	while (num_or_nums[i])
	{
		if (num_or_nums[i] == ' ')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
