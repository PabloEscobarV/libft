/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_qts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:12:18 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/04/12 22:15:19 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_qts(char ch)
{
	if (ch == FT_DQTS || ch == FT_SQTS)
		return (E_TRUE);
	return (E_FALSE);
}
