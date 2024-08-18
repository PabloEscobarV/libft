/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getprimes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 19:46:03 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/18 20:44:24 by Pablo Escob      ###   ########.fr       */
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

static char	*markprime(unsigned long num)
{
	unsigned long		j;
	unsigned long		i;
	char				*tmp;

	tmp = malloc((num + 1) * sizeof(char));
	*tmp = 0;
	tmp[1] = 0;
	i = 1;
	while (++i <= num)
		tmp[i] = 1;
	i = 1;
	while (++i <= num)
	{
		if (tmp[i])
		{
			j = i * i;
			while (j <= num)
			{
				tmp[j] = 0;
				j += i;
			}
		}
	}
	return (tmp);
}

t_llist	*ft_getprimes(unsigned long num)
{
	unsigned long	i;
	char			*tmp;
	t_llist			*primenums;

	if (num < 2)
		return (NULL);
	tmp = markprime(num);
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
