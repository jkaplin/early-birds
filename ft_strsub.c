/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:55:07 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/22 11:14:12 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;

	sub = ft_strnew(len);
	i = 0;
	while (s[start] && i < (unsigned int)len)
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	return (sub);
}
