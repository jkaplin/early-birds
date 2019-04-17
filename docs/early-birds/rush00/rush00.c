/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/28 14:28:49 by jkaplin           #+#    #+#             */
/*   Updated: 2018/10/28 17:31:13 by jkaplin          ###   ########.fr       */
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
			if ((x == w || x == 1) && (y == h || y == 1))
				ft_putchar('o');
			else if (x == w || x == 1)
				ft_putchar('|');
			else if (y == h || y == 1)
				ft_putchar('-');
			else
				ft_putchar(' ');
			x--;
		}
		if (w != 0 && h != 0)
			ft_putchar('\n');
		y--;
	}
}
