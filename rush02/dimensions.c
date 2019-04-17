/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dimensions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 07:37:43 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 21:09:00 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		calculate_width(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int		calculate_height(char *str)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

void	calculate_dimensions(char *str, int *input_width, int *input_height)
{
	*input_width = calculate_width(str);
	*input_height = calculate_height(str);
}
