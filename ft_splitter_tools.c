/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:28:44 by black             #+#    #+#             */
/*   Updated: 2024/11/14 20:47:22 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_cmp_strv(const char *str, const char **spltrs)
{
	while (*spltrs && !ft_strlcmp(str, *spltrs))
		++spltrs;
	return (ft_strlen(*spltrs));
}
