/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 20:54:23 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/21 16:58:54 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (size <= 0)
		return (src_len);
	if (size > src_len)
		size = src_len + 1;
	dest[--size] = '\0';
	while (--size)
		dest[size] = src[size];
	dest[size] = src[size];
	return (src_len);
}

size_t	ft_strncpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;

	src_len = 0;
	while (src[src_len])
		++src_len;
	if (size <= 0)
		return (src_len);
	if (size > src_len)
		size = src_len + 1;
	dest[--size] = '\0';
	while (--size)
		dest[size] = src[size];
	dest[size] = src[size];
	return (0);
}
