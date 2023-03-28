/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:54 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/28 11:56:30 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_free(t_ldata *list)
{
	t_node	*temp;
	t_node	*next;

	next = list->first;
	while (next)
	{
		temp = next;
		next = next->next;
		free(temp);
	}
	list->first = NULL;
	list->last = NULL;
}

void	dbl_lst_free_content(t_ldata *list)
{
	t_node	*temp;
	t_node	*next;

	next = list->first;
	while (next)
	{
		temp = next;
		next = next->next;
		free(temp->content);
		free(temp);
	}
	list->first = NULL;
	list->last = NULL;
}
