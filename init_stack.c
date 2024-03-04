/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 20:33:24 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 17:05:59 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	make_stack_a(t_stacks *stacks, int index, char *arg_num)
{
	t_node	*new_stack;

	new_stack = (t_node *)malloc(sizeof(t_node));
	if (!new_stack)
		return (0);
	if (stacks->stack_a->index == -1)
	{
		new_stack->index = index;
		new_stack->number = ft_atoi(arg_num);
		new_stack->next = stacks->stack_a;
		new_stack->prev = stacks->stack_a;
		stacks->stack_a->next = new_stack;
		stacks->stack_a->prev = new_stack;
		stacks->stack_a = new_stack;
		return (1);
	}
	new_stack->index = index;
	new_stack->number = ft_atoi(arg_num);
	new_stack->next = stacks->stack_a;
	new_stack->prev = stacks->stack_a->prev;
	stacks->stack_a->prev->next = new_stack;
	stacks->stack_a->prev = new_stack;
	stacks->stack_a = new_stack;
	return (1);
}

int	get_index(char **arg_list, char *arg_num)
{
	int		index;
	int		j;
	char	*current_num;

	index = 0;
	j = 0;
	current_num = arg_num;
	while (arg_list[j] != NULL)
	{
		if (arg_list[j] != NULL && ft_atoi(arg_list[j]) < ft_atoi(current_num))
			index++;
		j++;
	}
	return (index);
}

int	malloc_stacks(t_stacks *stacks)
{
	stacks->stack_a = (t_node *)malloc(sizeof(t_node));
	stacks->stack_b = (t_node *)malloc(sizeof(t_node));
	if (!(stacks->stack_a) || !(stacks->stack_b))
		return (0);
	stacks->stack_a->index = -1;
	stacks->stack_a->next = stacks->stack_a;
	stacks->stack_a->prev = stacks->stack_a;
	stacks->stack_b->index = -1;
	stacks->stack_b->next = stacks->stack_b;
	stacks->stack_b->prev = stacks->stack_b;
	return (1);
}

int	init_stack(t_stacks *stacks, char **arg_list)
{
	int	count;

	count = stacks->arg_count;
	stacks->stack_a_count = stacks->arg_count;
	stacks->stack_b_count = 0;
	stacks->result_list = (char *)malloc(sizeof(char) * 1);
	if (!(stacks->result_list))
		return (0);
	if (!malloc_stacks(stacks))
		return (0);
	while (count > 0)
	{
		if (!make_stack_a(stacks, get_index(arg_list, arg_list[count - 1]),
				arg_list[count - 1]))
		{
			free_stack_a(stacks);
			return (0);
		}
		count--;
	}
	return (1);
}
