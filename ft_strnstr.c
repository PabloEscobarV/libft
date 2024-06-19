/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 21:05:43 by polenyc           #+#    #+#             */
/*   Updated: 2024/06/19 15:19:36 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnstr(const char *str, const char *s, size_t len)
{
	size_t	j;
	size_t	len_str;

	if (*s == '\0')
		return ((char *)str);
	len_str = ft_strlen(str);
	if (len_str < len)
		len = len_str;
	while (*str != '\0' && len > 0)
	{
		j = 0;
		while (s[j] != '\0' && *(str + j) == s[j] && j < len)
			++j;
		if (s[j] == '\0')
			return ((char *)str);
		++str;
		--len;
	}
	return (NULL);
}
