/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 19:50:09 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/15 07:52:44 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	int		i;
	int		j;
	int		k;
	char	*ptr;

	i = 0;
	while (haystack[i] && i < (int)len)
	{
		j = 0;
		k = i;
		ptr = &((char *)haystack)[k];
		while (needle[j] == haystack[k] && k < (int)len)
		{
			if (needle[j + 1] == '\0')
				return (ptr);
			j++;
			k++;
		}
		i++;
	}
	ptr = NULL;
	if (needle[0] == '\0')
		ptr = (char *)haystack;
	return (ptr);
}
