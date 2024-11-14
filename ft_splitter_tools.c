/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitter_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:28:44 by black             #+#    #+#             */
/*   Updated: 2024/11/14 15:32:07 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cmp_strv(const char *str, const char **spltrs)
{
	while (*spltrs && !ft_strlcmp(str, *spltrs))
		++spltrs;
	return (ft_strlen(*spltrs));
}
