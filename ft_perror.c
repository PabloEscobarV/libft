/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perror.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 21:34:26 by blackrider        #+#    #+#             */
/*   Updated: 2024/07/22 14:42:00 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_perror(const char *msg)
{
	ft_putstr(msg);
	ft_putchar('\n');
	return (NULL);
}
