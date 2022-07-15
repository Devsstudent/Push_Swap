/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_parse_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 22:37:40 by odessein          #+#    #+#             */
/*   Updated: 2022/07/10 03:03:49 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps.h"

t_bool	ps_count(char *elems, int *size)
{
	int	i;

	i = 0;
	if (*elems == ' ' || *elems == 0)
		return (FALSE);
	while (elems[i] != '\0')
	{
		if (!ft_is_digit(elems[i]) && elems[i] != ' ' && elems[i] != '-')
			return (FALSE);
		if (elems[i] == '-')
		{
			i++;
			if (!ps_check_neg(elems, size, &i))
				return (FALSE);
		}
		else if (ft_is_digit(elems[i]))
			if (!ps_check_number(elems, size, &i))
				return (FALSE);
		i++;
	}
	return (TRUE);
}

t_bool	ps_check_number(char *char_to_num, int *size, int *index)
{
	if (!ps_check_size(char_to_num, index))
		return (FALSE);
	(*size)++;
	return (TRUE);
}

t_bool	ps_check_neg(char *char_to_num, int *size, int *index)
{
	if (char_to_num[*index] == 0 || !ft_is_digit(char_to_num[*index]))
		return (FALSE);
	if (!ps_check_size(char_to_num, index))
		return (FALSE);
	(*size)++;
	return (TRUE);
}

t_bool	ps_check_size(char *char_to_num, int *index)
{
	int		size_nb;
	int		start;

	start = *index;
	size_nb = 0;
	while (char_to_num[*index] == '0' && char_to_num[(*index) + 1] != 0)
		(*index)++;
	while (char_to_num[*index] != '\0' && ft_is_digit(char_to_num[*index]))
	{
		if (size_nb == 10)
			return (FALSE);
		(*index)++;
		size_nb++;
	}
	if (char_to_num[*index] == ' ' && (!ft_is_digit(char_to_num[(*index) + 1])
			&& char_to_num[(*index) + 1] != '-'))
		return (FALSE);
	(*index)--;
	if (size_nb == 10)
		if (!ps_check_size_max(char_to_num, start))
			return (FALSE);
	return (TRUE);
}

t_bool	ps_check_size_max(char *char_to_num, int start)
{
	if (char_to_num[start - 1] && char_to_num[start - 1] == '-')
	{
		if (ft_atoi(&char_to_num[start]) * (-1) < INT_MIN)
			return (FALSE);
	}
	else if (ft_atoi(&char_to_num[start]) > INT_MAX)
		return (FALSE);
	return (TRUE);
}
