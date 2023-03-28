/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_extension_libft.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:22 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/28 12:05:42 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_EXTENSION_LIBFT_H
# define DBL_EXTENSION_LIBFT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

typedef struct s_node
{
	void			*content;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

typedef struct s_ldata
{
	t_node	*first;
	t_node	*last;
}			t_ldata;

void	dbl_lst_add_back(t_ldata *list, void *elem);
void	dbl_lst_add_front(t_ldata *list, void *elem);
void	dbl_lst_free(t_ldata *list);
void	dbl_lst_free_content(t_ldata *list);
void	dbl_lst_print(t_ldata list);
void	dbl_lst_rm_node(t_ldata *list, t_node *node);

#endif