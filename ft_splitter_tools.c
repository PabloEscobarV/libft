/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:28:44 by black             #+#    #+#             */
/*   Updated: 2025/02/23 01:37:36 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_cmp_strv(const char *str, const char **strv)
{
	if (!strv)
		return (NULL);
	while (*strv && !ft_strlcmp(str, *strv))
		++strv;
	return (*strv);
}
