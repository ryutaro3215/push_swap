/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_many.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 23:17:19 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/13 15:10:15 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	judge_range(t_node *stack, int min_index, int max_index)
{
	t_node *tmp;
	t_node *tmp2;
	int next;
	int	prev;

	tmp = stack;
	tmp2 = stack;
	next = 0;
	prev = -1;
	while (!(tmp->index >= min_index && tmp->index <= max_index))
	{
		next++;
		tmp = tmp->next;
	}
	while (!(tmp2->index >= min_index && tmp2->index <= max_index))
	{
		prev++;
		tmp2 = tmp2->prev;
	}
	if (next <= prev)
		return (1);
	else
		return (0);
}

int	judge_r_or_rr(t_node *stack, int max_index)
{
	t_node *tmp;
	t_node *tmp2;
	int next;
	int	prev;

	tmp = stack;
	tmp2 = stack;
	next = 0;
	prev = -1;
	while (tmp->index != max_index)
	{
		next++;
		tmp = tmp->next;
	}
	while (tmp2->index != max_index)
	{
		prev++;
		tmp2 = tmp2->prev;
	}
	if (next <= prev)
		return (1);
	else
		return (0);
}

void	return_to_a(t_stacks *stacks, int max_index)
{
	while (stacks->stack_b->index != -1)
	{
		if (stacks->stack_b->index == max_index)
		{
			push_a(stacks);
			max_index--;
		}
		else if (stacks->stack_b->index == max_index - 1
			&& stacks->stack_b->next->index == max_index)
			swap_b(stacks);
		else
		{
			if (judge_r_or_rr(stacks->stack_b, max_index) == 1)
				rotate_b(stacks);
			else
				r_rotate_b(stacks);
		}
	}
}

void	about_sort(t_stacks *stacks, int quarter, int counter, int i)
{
	while (stacks->stack_a->index != -1)
	{
		if (stacks->stack_a->index >= quarter * i && stacks->stack_a->index <= quarter * (i + 1) - 1)
		{
			push_b(stacks);
			counter++;
			if (counter == quarter)
			{
				counter = 0;
				i++;
			}
		}
		else
		{
			if (judge_range(stacks->stack_a, quarter * i, quarter * (i + 1) - 1) == 1)
				rotate_a(stacks);
			else
				r_rotate_a(stacks);
		}
	}
}

int	sort_many(t_stacks *stacks)
{
	int	quarter;
	int counter;
	int	max_index;
	int	i;

	max_index = get_max_index(stacks->stack_a);
	i = 0;
	counter = 0;
	quarter = stacks->stack_a_count / 8;
	about_sort(stacks, quarter, counter, i);
	return_to_a(stacks, max_index);
	return (1);
}
