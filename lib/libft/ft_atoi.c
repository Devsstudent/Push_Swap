/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:12:19 by odessein          #+#    #+#             */
/*   Updated: 2022/07/08 22:56:17 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	ft_skip(const char *nptr, int *i, long long *res,
long long *neg_sign)
{
	*i = 0;
	*res = 0;
	*neg_sign = 1;
	while (nptr[*i] == '\v' || nptr[*i] == '\t' || nptr[*i] == '\r'
		|| nptr[*i] == '\n' || nptr[*i] == '\f' || nptr[*i] == ' ')
		*i = *i + 1;
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	res;
	long long	neg_sign;

	ft_skip(nptr, &i, &res, &neg_sign);
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			neg_sign = -1;
		i++;
	}
	while (nptr[i] != '\0' && nptr[i] != ' ' && ft_isdigit(nptr[i]))
	{
		res *= 10;
		res += (long long)(nptr[i] - 48);
		i++;
	}
	res *= neg_sign;
	return (res);
}
