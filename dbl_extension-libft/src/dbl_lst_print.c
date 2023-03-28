/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:56 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/28 12:03:08 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_print(t_ldata list)
{
	t_node	*shown;
	int		i;

	i = 1;
	shown = list.first;
	while (shown)
	{
		printf("-----List-----\n");
		printf("node%d:[%s]\n", i++, (char *)shown->content);
		shown = shown->next;
	}
}
