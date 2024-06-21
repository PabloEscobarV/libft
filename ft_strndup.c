/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 15:52:33 by blackrider        #+#    #+#             */
/*   Updated: 2024/06/21 17:56:35 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strndup(const char *src, int n)
{
	char	*tmp;

	tmp = malloc(++n * sizeof(char));
	if (!tmp)
		return (NULL);
	if (ft_strncpy(tmp, src, n))
	{
		free(tmp);
		ft_putstr("ERROR!!!:\tft_strndup\n");
		return (NULL);
	}
	return (tmp);
}
