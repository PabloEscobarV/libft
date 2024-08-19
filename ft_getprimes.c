/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprimes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:46:03 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/19 19:30:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

static void	*crtint(unsigned long num)
{
	unsigned long	*tmp;

	tmp = malloc(sizeof(unsigned long));
	*tmp = num;
	return ((void *)tmp);
}

t_llist	*ft_getprimes(unsigned long num)
{
	unsigned long	i;
	t_uchar			*tmp;
	t_llist			*primenums;

	if (num < 2)
		return (NULL);
	tmp = ft_getmarkprimes(num);
	if (!tmp)
		return (NULL);
	primenums = NULL;
	i = 1;
	while (++i <= num)
		if (tmp[i])
			llistadd_back(&primenums, llistnewnode(crtint(i)));
	free(tmp);
	return (primenums);
}
