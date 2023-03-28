/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_rm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:59 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/28 11:56:35 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_rm_node(t_ldata *list, t_node *node)
{
	t_node	*temp;

	temp = node;
	if (!node->prev && !node->next)
		return ;
	else if (!node->prev)
	{
		node->next->prev = NULL;
		list->first = node->next;
	}
	else if (!node->next)
	{
		node->prev->next = NULL;
		list->last = node->prev;
	}
	else
	{
		node->prev->next = node->next;
		node->next->prev = node->prev;
	}
	free(temp);
}
