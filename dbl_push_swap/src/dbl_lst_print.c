/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:56 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/29 10:21:10 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_print(t_pile *list)
{
	t_node	*shown;

	shown = list->first;
	printf("-----List-----\n");
	while (shown)
	{
		printf("node%d:[%d]\n", shown->index, shown->content);
		shown = shown->next;
	}
}
