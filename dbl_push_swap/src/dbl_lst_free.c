/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:54 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/29 14:30:16 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_free(t_pile *list)
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
