/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:01 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 14:17:29 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist	*dllistnewnode(int pid, void *data)
{
	t_dllist	*tmp;

	if (!data)
		return (NULL);
	tmp = malloc(sizeof(t_dllist));
	if (!tmp)
		return (NULL);
	tmp->pid = pid;
	tmp->data = data;
	tmp->next = NULL;
	tmp->previous = NULL;
	return (tmp);
}

int	dllistsize(t_dllist *dllst)
{
	int			size;

	if (!dllst)
		return (0);
	size = 0;
	while (dllst)
	{
		dllst = dllst->next;
		++size;
	}
	return (size);
}
