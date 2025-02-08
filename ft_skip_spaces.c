/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:42 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/02/08 21:36:44 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_skip_spaces(const char *str)
{
	if (str)
	{
		while (*str && ft_isspace(*str))
			++str;
	}
	return ((char *)str);
}
