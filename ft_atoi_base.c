/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:15:25 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/02 23:06:35 by blackrider       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*getprefix(const char *num, int size)
{
	if (size != 16 && size != 8)
		return (num);
	while (*num == '0')
		++num;
	if (*num == 'X' || *num == 'x')
		return (num + 1);
	return (num);
}

int	number(const char *base, char ch)
{
	int	num;

	num = 0;
	while (base[num] != ch)
		++num;
	return (num);
}

long	ft_atoi_base(const char *nptr, const char *base)
{
	long	result;
	int		sign;
	int		size_b;

	sign = 1;
	result = 0;
	if (*nptr == '\0')
		return (0);
	size_b = ft_strlen(base);
	while (ft_isspace(*nptr))
		++nptr;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	nptr = getprefix(nptr, size_b);
	while (*nptr && ft_strchr(base, *nptr))
	{
		result = result * size_b + number(base, *nptr);
		++nptr;
	}
	return (result * (long)sign);
}
