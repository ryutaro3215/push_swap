/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:33:24 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/01/31 10:39:19 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stacks *stacks, int index)
{
	t_node	*new_stack;

	if (!(new_stack = (t_node *)malloc(sizeof(t_node))))
		return (0);
	new_stack->index = index;
	new_stack->next = stacks->stack_a;
	new_stack->prev = stacks->stack_a->prev;
	stacks->stack_a->prev = new_stack;
	stacks->stack_a = new_stack;
	return (1);
}

int	get_index(char **arg_list, char *arg_num)
{
	int	index;
	int	j;

	index = 0;
	j = 0;
	while (arg_list[j] != NULL)
	{
		if (ft_atoi(arg_list[j]) < ft_atoi(arg_num))
			index++;
		j++;
	}
	return (index);
}

int	make_stack_a(t_stacks *stacks, char **arg_list)
{
	int	count;

	count = stacks->arg_count - 1;
	if (!(stacks->stack_a = (t_node *)malloc(sizeof(t_node))))
		return (0);
	stacks->stack_a->index = -1;
	stacks->stack_a->next = stacks->stack_a;
	stacks->stack_a->prev = stacks->stack_a;
	while (arg_list[count] != NULL)
	{
		if (!push_stack(stacks, get_index(arg_list,  arg_list[count])))
		{
			stack_free(stacks->stack_a);
			return (0);
		}
		count--;
	}
	return (1);
}
