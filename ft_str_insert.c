/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:17:58 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/01/22 22:02:46 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static t_uint	get_insrt_size(t_cchar *str, t_uint size_d, t_cchar ch)
{
	t_uint	str_size;

	str_size = 0;
	if (size_d)
	{
		while (*str)
		{
			if (*str == ch)
				str_size += size_d;
			++str;
		}
	}
	return (str_size);
}

static void	_str_insert(char *result, t_cchar *str, t_cchar *data, t_cchar ch)
{
	while (*str)
	{
		if (*str == ch)
			result = ft_strcpy(result, data);
		else
		{
			*result = *str;
			++result;
		}
		++str;
	}
}

char	*ft_str_insert(const char *str, const char *data, const char ch)
{
	t_uint	result_size;
	t_uint	size_d;
	char	*result;

	if (!str || !data || !(*data))
		return (NULL);
	size_d = ft_strlen(data);
	result_size = get_insrt_size(str, size_d, ch);
	if (!result_size)
		return (NULL);
	result_size += ft_strlen(str) - result_size / size_d;
	result = malloc((result_size + 1) * sizeof(char));
	if (!result)
	{
		ft_perror("ERROR!!! (malloc)");
		exit(-1);
	}
	result[result_size] = '\0';
	_str_insert(result, str, data, ch);
	return (result);
}
