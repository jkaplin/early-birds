/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:29:35 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/28 19:17:41 by jkaplin          ###   ########.fr       */
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
			if ((x == w && y == h) || (x == w && y == 1))
				ft_putchar('A');
			else if ((x == 1 && y == h) || (x == 1 && y == 1))
				ft_putchar('C');
			else if (x == w || x == 1 || y == h || y == 1)
				ft_putchar('B');
			else
				ft_putchar(' ');
			x--;
		}
		if (w != 0 && h != 0)
			ft_putchar('\n');
		y--;
	}
}
