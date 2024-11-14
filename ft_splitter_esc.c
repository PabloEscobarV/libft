/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter_esc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 20:29:38 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/14 20:44:53 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_str_crd(t_cchar *str, t_crd *crd, t_cchar **spltrs, t_cchar esc)
{
	int	i;

	while (crd->i < crd->size)
	{
		i = ft_cmp_strv(str + crd->i, spltrs);
		if (i && (!crd->i || str[crd->i - 1] != esc))
			break ;
		++crd->i;
	}
	return (i);
}

static char	*get_str(t_cchar *str, t_crd *crd, t_cchar **spltrs, t_cchar esc)
{
	int		i;
	int		tmp;
	char	*result;

	tmp = crd->i;
	i = get_str_crd(str, crd, spltrs, esc);
	if (tmp < crd->i)
		result = ft_strldup(str + tmp, crd->i - tmp);
	else
		result = NULL;
	crd->i += i;
	return (result);
}

static t_llist	*get_list(t_cchar *str, t_crd *crd, t_cchar **splt, t_cchar esc)
{
	char	*tmp;
	t_llist	*llst;

	llst = NULL;
	while (crd->i < crd->size)
	{
		tmp = get_str(str, crd, splt, esc);
		if (tmp)
			llistadd_back(&llst, llistnewnode(tmp));
	}
	return (llst);
}

static char	**get_strv_from_llst(t_llist *llst)
{
	int		sizev;
	char	**strv;

	sizev = llistsize(llst);
	if (!sizev)
		return (NULL);
	strv = malloc((sizev + 1) * sizeof(char *));
	if (!strv)
	{
		ft_perror("ERROR!!! Bad mammory allocation");
		exit(-1);
	}
	strv[sizev] = NULL;
	sizev = 0;
	while (llst)
	{
		strv[sizev] = llst->data;
		++sizev;
		llst = llst->next;
	}
	return (strv);
}

char	**ft_splitter_esc(const char *str, const char **spltrs, const char esc)
{
	char	**strv;
	t_llist	*llst;
	t_crd	crd;

	if (!str || !spltrs)
		return (NULL);
	crd.i = 0;
	crd.size = ft_strlen(str);
	llst = get_list(str, &crd, spltrs, esc);
	strv = get_strv_from_llst(llst);
	llistclear(&llst, ft_void);
	return (strv);
}
