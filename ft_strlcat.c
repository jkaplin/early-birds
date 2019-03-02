/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 18:46:07 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/20 10:58:34 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	int		j;
	int		real_dstsize;

	i = ft_strlen(dst);
	real_dstsize = i;
	j = 0;
	while (src[j] && i < dstsize - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	if (i < dstsize)
		dst[i] = '\0';
	return (ft_min(real_dstsize, dstsize) + ft_strlen(src));
}
