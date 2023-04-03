/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_lst_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:10:56 by meltremb          #+#    #+#             */
/*   Updated: 2023/04/03 13:06:28 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../include/dbl_extension_libft.h"

void	dbl_lst_print(t_pile *a, t_pile *b)
{
	t_node	*node_a;
	t_node	*node_b;
	int		i;
	int		j;

	i = 0;
	j = 0;
	node_a = a->first;
	node_b = b->first;
	printf("---List A----------List B---\n");
	while (i++ < (a->size + b->size) && node_a)
	{
		printf("node%d:[%d]----------", i, node_a->index);
		if (j++ < b->size)
		{
			printf("node%d:[%d]\n", j, node_b->index);
			node_b = node_b->next;
		}
		else
			printf("node%d:[0]\n", j);
		node_a = node_a->next;
	}
}
