/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmatsuba <rmatsuba@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 22:51:01 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/03/04 16:50:05 by rmatsuba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(char **arg_list)
{
	int	i;
	int	j;

	i = 0;
	while (arg_list[i] != NULL)
	{
		j = i + 1;
		while (arg_list[j] != NULL)
		{
			if (ft_atoi(arg_list[i]) == ft_atoi(arg_list[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

char	**make_arg_list(t_stacks *stacks, int argc, char **argv)
{
	char	**arg_list;
	int		i;

	stacks->malloc_flag = 0;
	if (argc == 2)
	{
		arg_list = ft_split(argv[1], ' ');
		if (!arg_list)
			return (NULL);
		i = 0;
		while (arg_list[i])
			i++;
		stacks->arg_count = i;
		stacks->malloc_flag = 1;
	}
	else
	{
		arg_list = (char **)ft_calloc(argc, sizeof(char *));
		if (!arg_list)
			return (NULL);
		stacks->arg_count = argc - 1;
		ft_memcpy(arg_list, &argv[1], sizeof(char *) * argc - 1);
	}
	return (arg_list);
}

int	check_arg(t_stacks *stacks, int argc, char **argv)
{
	char	**arg_list;

	arg_list = make_arg_list(stacks, argc, argv);
	if (!arg_list)
		return (0);
	if (!is_number(arg_list) || !is_duplicate(arg_list))
		return (arg_free(arg_list, stacks, 0));
	if (!init_stack(stacks, arg_list))
		return (arg_free(arg_list, stacks, 0));
	stacks->collect_arg = 1;
	return (arg_free(arg_list, stacks, 1));
}
