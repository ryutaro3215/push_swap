/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:50:35 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/02 00:37:27 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stacks(t_stacks *stacks)
{
	free_stack_a(stacks);
	free_stack_b(stacks);
	free(stacks->result_list);
}

void free_stack_b(t_stacks *stacks) {
    t_node *current;

	current = stacks->stack_b;
    while (current->index != -1) {
        current = current->next;
		free(current->prev);
    }
	free(current);
}

void free_stack_a(t_stacks *stacks)
{
    t_node *current;

	current = stacks->stack_a;
    while (current->index != -1) {
        current = current->next;
		free(current->prev);
    }
	free(current);
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
