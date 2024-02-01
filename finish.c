/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:50:35 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/01/30 15:23:30 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_node *node)
{
	t_node	*tmp;

	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
}

int	arg_free(char **arg_list, t_stacks *stacks, int return_value)
{
	int	i;

	i = 0;
	if (stacks->malloc_flag == 1)
	{
		while (arg_list[i])
		{
			free(arg_list[i]);
			i++;
		}
		free(arg_list);
		return (return_value);
	}
	else
	{
		free(arg_list);
		return (return_value);
	}
}
