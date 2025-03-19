/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_spaces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 21:33:42 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/19 00:57:45 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_skip_spaces(const char *str)
{
	if (str)
	{
		while (*str && ft_isspace(*str))
			++str;
	}
	return (str);
}

const char	*ft_skip_spaces_end(const char *str, int end)
{
	if (str)
	{
		while (str + end > str)
		{
			--end;
			if (!ft_isspace(str[end]))
				break ;
		}
	}
	return (str + end);
}
