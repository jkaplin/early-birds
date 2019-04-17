/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 08:25:42 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 22:52:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	stricpy(char *s1, char *s2, int *i)
{
	while (s2[*i] != '\0')
	{
		s1[*i] = s2[*i];
		*i = *i + 1;
	}
}

t_list	*add_link(t_list *list, char *buf)
{
	t_list	*link;
	int		i;

	i = 0;
	link = malloc(sizeof(t_list));
	if (link != NULL)
	{
		if (list != NULL)
		{
			stricpy(link->str, buf, &i);
			link->str[i] = '\0';
			list->next = link;
			link->next = NULL;
		}
		else
		{	
			stricpy(link->str, buf, &i);
			link->str[i] = '\0';
			link->next = NULL;
		}
	}
	return (link);
}

int		input_to_list(t_list **begin_list, int *count_buf)
{
	int		buf_len;
	char	buf[BUF_SIZE + 1];
	int 	is_begin = 1;
	t_list	*link;
	t_list	*prev;
	
	prev = *begin_list;
	while ((buf_len = read(0, buf, BUF_SIZE)) > 0)
	{
		buf[buf_len] = '\0';
		link = add_link(prev, buf);
		if (is_begin)
		{
			*begin_list = link;
			is_begin = 0;
		}
		prev = link;
		link = link->next;
		*count_buf += 1;
	}
	if (buf_len == -1)
		return (-1);
	else
		return (0);
}

void	list_to_str(t_list *begin_list, char *str)
{
	int		i;
	t_list	*link;

	link = begin_list;
	i = 0;
	while (link != NULL)
	{
		stricpy(str, link->str, &i);
		link = link->next;
	}
	str[i] = '\0';
}
