/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:57:07 by vrabaib           #+#    #+#             */
/*   Updated: 2018/11/11 20:39:19 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

int		main(int argc, char **argv)
{
	int		i;
	int		x;
	int		y;
	char	*result;


	if (argc == 3)
	{
		i = 0;
		x = ft_atoi(argv[1]);
		y = ft_atoi(argv[2]);
		if (x <= 0 || y <= 0)
		{
			write(2, "ERROR\n", 6);
			return (1);
		}
		result = rush_to_str(x, y, &rush00);
		while (result[i] != '\0')
		{
			write(1, &result[i], 1);
			i++;
		}
	}
	return (0);
}
