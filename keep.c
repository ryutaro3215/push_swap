/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ryutaro320515 <ryutaro320515@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:04:02 by ryutaro3205       #+#    #+#             */
/*   Updated: 2024/02/01 22:05:43 by ryutaro3205      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	keep_result(t_stacks *stacks, char *str)
{
	char	*tmp;

	tmp = stacks->result_list;
	stacks->result_list = ft_strjoin(tmp, str);
	if (stacks->result_list == NULL)
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
