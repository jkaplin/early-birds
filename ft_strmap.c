/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 15:17:22 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/21 19:20:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh_s;
	int		i;

	fresh_s = ft_strnew(ft_strlen(s));
	i = 0;
	while (s[i])
	{
		fresh_s[i] = f(s[i]);
		i++;
	}
	fresh_s[i] = '\0';
	return (fresh_s);
}
