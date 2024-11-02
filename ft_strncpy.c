/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:30:24 by polenyc           #+#    #+#             */
/*   Updated: 2024/11/02 17:15:42 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	if (!dest)
		return (NULL);
	if (len <= 0 || !src)
		return (dest);
	dest[len] = '\0';
	if (src)
	{
		i = -1;
		while (++i < len && src[i])
			dest[i] = src[i];
	}
	return (dest + len);
}
