/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   llist_concatenate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 20:32:43 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/10/06 20:33:38 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	add_if_previous(t_llist *llst, t_llist *to_llst)
{
	t_llist	*tmp_llst_previous;

	while (llst->previous->next)
		llst = llst->previous;
	tmp_llst_previous = llst->previous;
	llst->previous->next = to_llst;
	if (to_llst->previous)
		llst->previous = to_llst->previous;
	else
		llst->previous = to_llst;
	to_llst->previous = tmp_llst_previous;
}

static void	add_if_no_previous(t_llist *llst, t_llist *to_llst)
{
	llst->next = to_llst;
	if (to_llst->previous)
		llst->previous = to_llst->previous;
	else
		llst->previous = to_llst;
	to_llst->previous = llst;
}

t_llist	*llist_concatenate(t_llist **llst, t_llist *to_llst)
{
	if (!to_llst)
		return (*llst);
	if (!*llst)
	{
		*llst = to_llst;
		return (*llst);
	}
	if ((*llst)->previous)
		add_if_previous(*llst, to_llst);
	else
		add_if_no_previous(*llst, to_llst);
	return (*llst);
}
