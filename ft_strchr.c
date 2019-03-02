/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:16:18 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 07:49:39 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ptr_s;

	ptr_s = (char *)s;
	i = 0;
	while (ptr_s[i])
	{
		if (ptr_s[i] == (char)c)
			return (&ptr_s[i]);
		i++;
	}
	if (c == '\0')
		return (&ptr_s[i]);
	return (NULL);
}
