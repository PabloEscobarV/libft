/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 17:17:58 by Pablo Escob       #+#    #+#             */
/*   Updated: 2024/11/02 23:09:24 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_str_insert(const char *str, const char *str_to, int front, int rear)
{
	char	*tmp;
	char	*result;

	if (!str_to || front > rear)
		return (NULL);
	result = malloc((front + ft_strlen(str + rear) + ft_strlen(str_to) + 1)
			* sizeof(char));
	tmp = ft_strncpy(result, str, front);
	tmp = ft_strcpy(tmp, str_to);
	ft_strcpy(tmp, str + rear);
	return (result);
}

char	*ft_str_insert_ch_ind(const char *str, const char *str_to, char insrt)
{
	int	front;
	int	rear;

	if (!str_to || !insrt)
		return (NULL);
	front = 0;
	rear = 0;
	if (str)
	{
		while (str[front] && str[front] != insrt)
			++front;
		rear = front;
		while (str[rear] && !ft_isspace(str[rear]))
			++rear;
	}
	return (ft_str_insert(str, str_to, front, rear));
}
