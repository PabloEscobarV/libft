/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getmarkprimes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 19:02:57 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/08/19 19:15:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*initarray(unsigned long num)
{
	char	*tmp;

	tmp = malloc((num + 1) * sizeof(char));
	if (!tmp)
	{
		ft_perror("ERROR: Bad alocation mammory");
		exit(-1);
	}
	*tmp = 0;
	tmp[1] = 0;
	return (tmp);
}

char	*ft_getmarkprimes(unsigned long num)
{
	unsigned long		j;
	unsigned long		i;
	char				*tmp;

	if (num < 2)
		return (NULL);
	tmp = initarray(num);
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
