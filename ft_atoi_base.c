/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blackrider <blackrider@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 23:15:25 by polenyc           #+#    #+#             */
/*   Updated: 2024/04/03 13:30:47 by blackrider       ###   ########.fr       */
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

int	number(const char *base, int size_b, char ch)
{
	char	*base_tmp;
	int		num;
	int		base_chang;

	num = 0;
	if (size_b > 10 && base[10] >= 'A' && base[10] <= 'Z')
		base_chang = 32;
	if (size_b > 10 && base[10] >= 'a' && base[10] <= 'z')
		base_chang = -32;
	while (base[num] != ch || (base[num] + base_chang) != ch)
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
		result = result * size_b + number(base, size_b, *nptr);
		++nptr;
	}
	return (result * (long)sign);
}
