/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 09:57:16 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/29 14:27:01 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_indexed(t_pile *any)
{
	t_node	*temp;

	temp = any->first;
	while (temp)
	{
		if (temp->index == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}

void	indexer(t_pile *any)
{
	t_node	*temp;
	t_node	*smolguy;
	int		index;

	smolguy = any->first;
	while (smolguy)
	{
		temp = any->first;
		index = 1;
		while (temp)
		{
			if (smolguy->content > temp->content)
				index++;
			temp = temp->next;
		}
		smolguy->index = index;
		smolguy = smolguy->next;
	}
}
