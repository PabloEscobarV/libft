/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:27:33 by black             #+#    #+#             */
/*   Updated: 2025/02/23 13:27:46 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	get_str_crd(const char *str, t_crd *crd, const char **spltrs)
{
	t_cchar	*tmp;

	while (crd->i < crd->size)
	{
		tmp = ft_cmp_strv(str + crd->i, spltrs);
		if (tmp)
			break ;
		++crd->i;
	}
	return (ft_strlen(tmp));
}

static char	*get_str(const char *str, t_crd *crd, const char **spltrs)
{
	int		i;
	int		tmp;
	char	*result;

	tmp = crd->i;
	i = get_str_crd(str, crd, spltrs);
	if (tmp < crd->i)
		result = ft_strldup(str + tmp, crd->i - tmp);
	else
		result = NULL;
	crd->i += i;
	return (result);
}

static t_llist	*get_data_list(const char *str, t_crd *crd, const char **spltrs)
{
	char	*tmp;
	t_llist	*llst;

	llst = NULL;
	while (crd->i < crd->size)
	{
		tmp = get_str(str, crd, spltrs);
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

char	**ft_splitter(const char *str, const char **spltrs)
{
	char	**strv;
	t_llist	*llst;
	t_crd	crd;

	if (!str || !spltrs)
		return (NULL);
	crd.i = 0;
	crd.size = ft_strlen(str);
	llst = get_data_list(str, &crd, spltrs);
	strv = get_strv_from_llst(llst);
	llistclear(&llst, ft_void);
	return (strv);
}
