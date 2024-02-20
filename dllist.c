/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dllistadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 12:21:01 by blackrider        #+#    #+#             */
/*   Updated: 2024/02/20 13:16:18 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_dllist	*dllistadd_back(t_dllist **dllst, t_dllist *newnode)
{
	if (!newnode)
		return (NULL);
	if (!(*dllst))
	{
		*dllst = newnode;
		return (newnode);
	}
	if ((*dllst)->previous)
	{
		newnode->previous = (*dllst)->previous;
		(*dllst)->previous->next = newnode;
	}
	else
	{
		newnode->previous = *dllst;
		(*dllst)->next = newnode;
	}
	(*dllst)->previous = newnode;
	return (*dllst);
}

t_dllist	*dllistadd_front(t_dllist **dllst, t_dllist *newnode)
{
	if (!newnode)
		return (NULL);
	if (!(*dllst))
	{
		*dllst = newnode;
		return (newnode);
	}
	newnode->next = *dllst;
	if ((*dllst)->previous)
		newnode->previous = (*dllst)->previous;
	else
		newnode->previous = *dllst;
	(*dllst)->previous = newnode;
	*dllst = newnode;
	return (*dllst);
}

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
