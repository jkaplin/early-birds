/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:05:16 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/25 15:03:22 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*trimmed;
	int		start;
	int		end;
	int		i;

	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = 0;
	while (s[end])
		end++;
	end--;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	trimmed = ft_strnew(end - start + 1);
	i = 0;
	while (start <= end)
	{
		trimmed[i] = s[start];
		i++;
		start++;
	}
	trimmed[i] = '\0';
	return (trimmed);
}
