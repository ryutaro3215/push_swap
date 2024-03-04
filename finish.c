/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:50:35 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 17:05:23 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	my_error(t_stacks *stacks, int er_num, char *str)
{
	if (er_num == 2)
	{
		if (stacks->collect_arg == 0)
		{
			ft_putstr_fd(str, 2);
			return (1);
		}
		else
		{
			ft_putstr_fd(str, 2);
			free_stacks(stacks);
			return (1);
		}
	}
	else
	{
		ft_printf(str);
		free_stacks(stacks);
		return (0);
	}
}

void	free_stacks(t_stacks *stacks)
{
	free_stack_a(stacks);
	free_stack_b(stacks);
	free(stacks->result_list);
}

void	free_stack_b(t_stacks *stacks)
{
	t_node	*current;

	current = stacks->stack_b;
	while (current->index != -1)
	{
		current = current->next;
		free(current->prev);
	}
	free(current);
}

void	free_stack_a(t_stacks *stacks)
{
	t_nod	*current;

	current = stacks->stack_a;
	while (current->index != -1)
	{
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
