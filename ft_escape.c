/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_escape.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 23:23:40 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/03/11 23:34:07 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_uchar	ft_escape(t_cchar *str, t_uint crd)
{
	int	tmp;

	tmp = crd - 1;
	while (tmp >= 0 && str[tmp] == FT_ESCAPE)
		--tmp;
	if (tmp < 0)
		tmp = 1;
	return (!((crd - tmp) % 2));
}
