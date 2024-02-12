/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 22:47:16 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/09 23:07:57 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ascending(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->index != -1)
	{
		if (tmp->index > tmp->next->index && tmp->next->index != -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_descending(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	while (tmp->index != -1)
	{
		if (tmp->index < tmp->next->index && tmp->next->index != -1)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
