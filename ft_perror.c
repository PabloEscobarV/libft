/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: black <black@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:34:26 by blackrider        #+#    #+#             */
/*   Updated: 2024/10/07 16:55:23 by black            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_perror(const char *msg)
{
	ft_putstr(P_C_RED);
	ft_putstr(msg);
	ft_putstr(P_C_WHITE);
	ft_putchar('\n');
	return (NULL);
}
