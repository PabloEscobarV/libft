/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:28:44 by black             #+#    #+#             */
/*   Updated: 2025/03/18 20:01:26 by Pablo Escob      ###   ########.fr       */
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

int	ft_cmp_strv_crd(const char *str, const char **strv)
{
	int	i;

	if (!strv)
		return (E_ERR);
	i = 0;
	while (strv[i] && !ft_strlcmp(str, strv[i]))
		++i;
	if (!strv[i])
		return (E_ERR);
	return (i);
}
