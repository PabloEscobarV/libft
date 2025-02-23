/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:22:31 by polenyc           #+#    #+#             */
/*   Updated: 2025/02/23 01:22:24 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

const char	*ft_strlcmp(const char *str, const char *cmp)
{
	if (str && cmp)
	{
		while (*str && (*str == *cmp))
		{
			++str;
			++cmp;
		}
		if (!(*str) || !(*cmp))
			return (str);
	}
	return (NULL);
}
