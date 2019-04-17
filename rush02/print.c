/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 07:58:21 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 21:41:54 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush00.h"
#include "rush02.h"

void	jk_putchar(char c)
{
	write(1, &c, 1);
}

void	assign_funs(t_rush *f_ptr)
{
	f_ptr[0].rush = &rush00;
	f_ptr[1].rush = &rush01;
	f_ptr[2].rush = &rush02;
	f_ptr[3].rush = &rush03;
	f_ptr[4].rush = &rush04;
}

void	ft_write(int i, int width, int height, int count)
{
	if (count == 0 || count > 2)
	{
		write(1, "[colle-0", 7);
		jk_putchar('0' + i);
		write(1, "] [", 3);
		jk_putchar('0' + width);
		write(1, "] [", 3);
		jk_putchar('0' + height);
		write(1, "]", 1);
	}
	else
	{
		write(1, "[rush-0", 7);
		jk_putchar('0' + i);
		write(1, "] [", 3);
		jk_putchar('0' + width);
		write(1, "] [", 3);
		jk_putchar('0' + height);
		write(1, "]", 1);
	}
}

int		str_match(char *input_str, void (*f_ptr)(int, int, char*, int*),
		int input_width, int input_height)
{
	char	*rush_str;
	int		i;

	rush_str = rush_to_str(input_width, input_height, f_ptr);
	i = 0;
	while (rush_str[i] != '\0')
	{
		if (input_str[i] != rush_str[i])
			return (0);
		i++;
	}
	free(rush_str);
	if (input_str[i] == '\0')
		return (1);
	else
		return (0);
}

void	print(char *input_str, int input_width, int input_height)
{
	int		i;
	int		is_not_valid;
	t_rush	f_ptr[NUM_RUSHES];

	i = 0;
	is_not_valid = 1;
	assign_funs(f_ptr);
	while (i < NUM_RUSHES)
		if (str_match(input_str, f_ptr[i++].rush, input_width, input_height))
			is_not_valid++;
	while (i < NUM_RUSHES)
	{
		if (str_match(input_str, f_ptr[i].rush, input_width, input_height))
		{
			ft_write(i, input_width, input_height, is_not_valid);
			is_not_valid = 0;
		}
		i++;
		if (i < NUM_RUSHES && str_match(input_str, f_ptr[i].rush,
			input_width, input_height))
			write(1, " || ", 4);
	}
	free(input_str);
	if (is_not_valid)
		write(1, "aucune\n", 7);
}
