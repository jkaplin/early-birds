/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:35:06 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 23:01:21 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int		main(void)
{	
	char	*str;
	int		count_buf;
	int		input_width;
	int		input_height;
	t_list	*begin_list;

	count_buf = 42424242;
	while (count_buf > 0)
	{
		count_buf--;
	}
	begin_list = NULL;
	count_buf = 0;
	if (input_to_list(&begin_list, &count_buf) == -1)
	{
		write(2, "aucune\n", 7);
		return (0);
	}
	str = (char *)malloc(sizeof(char) * (count_buf * BUF_SIZE + 1));
	list_to_str(begin_list, str);
	calculate_dimensions(str, &input_width, &input_height);
	print(str, input_width, input_height);
	write(1, "\n", 1);
	return (0);
}
