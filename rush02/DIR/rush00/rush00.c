/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrabaib <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 10:02:57 by vrabaib           #+#    #+#             */
/*   Updated: 2018/11/11 20:56:54 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"

void	rush00(int x, int y, char *str, int *i)
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
				ft_putchar('o', str, i);
			else if (x == w || x == 1)
				ft_putchar('|', str, i);
			else if (y == h || y == 1)
				ft_putchar('-', str, i);
			else
				ft_putchar(' ', str, i);
			x--;
		}
		ft_putchar('\n', str, i);
		y--;
	}
}

void	rush01(int x, int y, char *str, int *i)
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
				ft_putchar('/', str, i);
			else if ((x == w && y == 1) || (x == 1 && y == h))
				ft_putchar('\\', str, i);
			else if (x == w || x == 1 || y == h || y == 1)
				ft_putchar('*', str, i);
			else
				ft_putchar(' ', str, i);
			x--;
		}
		ft_putchar('\n', str, i);
		y--;
	}
}

void	rush02(int x, int y, char *str, int *i)
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
			if ((x == w && y == h) || (x == 1 && y == h))
				ft_putchar('A', str, i);
			else if ((x == w && y == 1) || (x == 1 && y == 1))
				ft_putchar('C', str, i);
			else if (x == w || x == 1 || y == h || y == 1)
				ft_putchar('B', str, i);
			else
				ft_putchar(' ', str, i);
			x--;
		}
		ft_putchar('\n', str, i);
		y--;
	}
}

void	rush03(int x, int y, char *str, int *i)
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
				ft_putchar('A', str, i);
			else if ((x == 1 && y == h) || (x == 1 && y == 1))
				ft_putchar('C', str, i);
			else if (x == w || x == 1 || y == h || y == 1)
				ft_putchar('B', str, i);
			else
				ft_putchar(' ', str, i);
			x--;
		}
		ft_putchar('\n', str, i);
		y--;
	}
}

void	rush04(int x, int y, char *str, int *i)
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
				ft_putchar('A', str, i);
			else if ((x == w && y == 1) || (x == 1 && y == h))
				ft_putchar('C', str, i);
			else if (x == w || x == 1 || y == h || y == 1)
				ft_putchar('B', str, i);
			else
				ft_putchar(' ', str, i);
			x--;
		}
		ft_putchar('\n', str, i);
		y--;
	}
}
