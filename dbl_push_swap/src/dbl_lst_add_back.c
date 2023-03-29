/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:48 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/29 14:29:36 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_add_back(t_pile *list, int elem)
{
	t_node	*temp;

	temp = ft_calloc(1, sizeof(t_node));
	if (!temp)
		return ;
	temp->content = elem;
	temp->prev = list->last;
	temp->next = NULL;
	if (list->last)
		list->last->next = temp;
	else
		list->first = temp;
	list->last = temp;
}
