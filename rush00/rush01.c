/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 17:50:03 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/28 17:27:31 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	rush(int x, int y)
{
	int w;
	int h;

	w = x;
	h = y;
	while (y > 0)
	{
		x = w;
		while (x > 0)
		{
			if ((x == w && y == h) || (x == 1 && y == 1 && h != 1 && w != 1))
				ft_putchar('/');
			else if ((x == w && y == 1) || (x == 1 && y == h))
				ft_putchar('\\');
			else if (x == w || x == 1 || y == h || y == 1)
				ft_putchar('*');
			else
				ft_putchar(' ');
			x--;
		}
		if (w != 0 && h != 0)
			ft_putchar('\n');
		y--;
	}
}
