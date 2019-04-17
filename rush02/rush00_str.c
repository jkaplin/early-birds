/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 11:44:24 by vrabaib           #+#    #+#             */
/*   Updated: 2018/11/11 21:11:25 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		ft_atoi(char *str)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' ') || (str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	return (num);
}

void	ft_putchar(char c, char *str, int *i)
{
	str[*i] = c;
	*i += 1;
}

char	*rush_to_str(int x, int y, void (*f_ptr)(int, int, char*, int*))
{
	char	*str;
	int		i;

	i = 0;
	if (x < 0 || y < 0)
	{
		x = 0;
		y = 0;
	}
	str = (char *)malloc(sizeof(char) * (x * y + y + 1));
	f_ptr(x, y, str, &i);
	str[i] = '\0';
	return (str);
}
