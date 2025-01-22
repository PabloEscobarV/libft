/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Pablo Escobar <sataniv.rider@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 22:48:54 by Pablo Escob       #+#    #+#             */
/*   Updated: 2025/01/22 22:50:24 by Pablo Escob      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_get_env(const char *name, const char **envp)
{
	char	*env;

	env = NULL;
	if (envp && *envp && name)
	{
		while (*envp)
		{
			if (ft_strlcmp(*envp, name))
				break ;
			++envp;
		}
		env = ft_strdup(*envp);
	}
	return (env);
}
