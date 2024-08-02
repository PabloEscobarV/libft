/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 12:30:24 by polenyc           #+#    #+#             */
/*   Updated: 2024/08/02 14:46:54 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t size)
{
	if (!dest)
		return (NULL);
	if (size <= 0 || !src)
		return (dest);
	dest[--size] = '\0';
	while (size)
	{
		--size;
		dest[size] = src[size];
	}
	return (dest);
}
