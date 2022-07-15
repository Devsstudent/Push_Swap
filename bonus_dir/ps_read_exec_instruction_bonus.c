/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_read_exec_instruction_bonus.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: odessein <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 19:09:02 by odessein          #+#    #+#             */
/*   Updated: 2022/07/15 20:01:49 by odessein         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ps_bonus.h"

t_bool	ps_read_instruction(t_list **lst)
{
	t_list	*new;

	while (!ps_check_content(lst))
	{
		new = ft_lstnew(get_next_line(0));
		if (!new)
			return (FALSE);
		if (new->content && !ps_check_wrong_input(new->content))
		{
			free(new->content);
			free(new);
			return (FALSE);
		}
		ft_lstadd_back(lst, new);
	}
	return (TRUE);
}

t_bool	ps_check_wrong_input(char *str)
{
	if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "sa\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "sb\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "ss\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "pa\n", ft_strlen(str)))
		return (TRUE);
	else if (!ft_strncmp(str, "pb\n", ft_strlen(str)))
		return (TRUE);
	return (FALSE);
}

t_bool	ps_check_content(t_list	**lst)
{
	t_list	*buff;

	buff = *lst;
	while (buff != NULL)
	{
		if (buff->content == NULL)
			return (TRUE);
		buff = buff->next;
	}
	return (FALSE);
}

void	ps_exec_instruction(t_list **lst, t_list **stack_a, t_list **stack_b)
{
	t_list	*buff;

	buff = *lst;
	while (buff->next != NULL)
	{
		ps_check_instruction(buff->content, stack_a, stack_b);
		buff = buff->next;
	}
}

void	ps_check_instruction(char *str, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(str, "rra\n", ft_strlen(str)))
		ps_rra(stack_a);
	else if (!ft_strncmp(str, "rrb\n", ft_strlen(str)))
		ps_rrb(stack_b);
	else if (!ft_strncmp(str, "rb\n", ft_strlen(str)))
		ps_rb(stack_b);
	else if (!ft_strncmp(str, "ra\n", ft_strlen(str)))
		ps_ra(stack_a);
	else if (!ft_strncmp(str, "rr\n", ft_strlen(str)))
		ps_rr(stack_a, stack_b);
	else if (!ft_strncmp(str, "rrr\n", ft_strlen(str)))
		ps_rrr(stack_a, stack_b);
	ps_check_instruction_2(str, stack_a, stack_b);
}
