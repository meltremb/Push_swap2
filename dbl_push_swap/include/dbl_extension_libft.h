/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dbl_extension_libft.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:55:22 by meltremb          #+#    #+#             */
/*   Updated: 2023/03/30 10:39:15 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DBL_EXTENSION_LIBFT_H
# define DBL_EXTENSION_LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

typedef struct s_node
{
	int				content;
	struct s_node	*next;
	struct s_node	*prev;
	int				index;
}				t_node;

typedef struct s_pile
{
	t_node	*first;
	t_node	*last;
	int		size;
}			t_pile;

void	*ft_calloc(size_t count, size_t size);
void	dbl_lst_add_back(t_pile *list, int elem);
void	dbl_lst_add_front(t_pile *list, int elem);
void	dbl_lst_free(t_pile *list);
void	dbl_lst_print(t_pile *a, t_pile *b);
void	dbl_lst_rm_node(t_pile *list, t_node *node);

#endif