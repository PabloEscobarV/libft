/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:17:18 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 14:17:30 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*dllistclear(t_dllist **dllst, void (*del)(void *d))
{
	if (!(*dllst))
		return (NULL);
	dllistclear(&((*dllst)->next), del);
	del((*dllst)->data);
	free(*dllst);
	*dllst = NULL;
	return (NULL);
}
