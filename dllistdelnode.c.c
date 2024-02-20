/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistdelnode.c.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:01 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 16:36:43 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist    *dllistdelnode(t_dllist **dllst, void (*del)(void *))
{
    t_dllist    *tmp;

	if (!(*dllst))
		return (NULL);
	tmp = *dllst;
	if ((*dllst)->previous && (*dllst)->previous->next)
		(*dllst)->previous->next = (*dllst)->next;
	if ((*dllst)->next && (*dllst)->previous != (*dllst)->next)
		(*dllst)->next->previous = (*dllst)->previous;
	*dllst = (*dllst)->next;
	del(tmp->data);
	free(tmp);
	return (*dllst);
}
