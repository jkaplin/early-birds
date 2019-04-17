/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:37:40 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 22:24:30 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H

# define BUF_SIZE 4096
# define NUM_RUSHES 5

# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_list	t_list;

typedef struct	s_rush	t_rush;

struct	s_list
{
	char	str[BUF_SIZE + 1];
	t_list	*next;
};

struct	s_rush
{
	void (*rush)(int, int, char *str, int *i);
};

void	stricpy(char *s1, char *s2, int *i);
t_list	*add_link(t_list *list, char *buf);
int		input_to_list(t_list **begin_list, int *count_buf);
void	list_to_str(t_list *begin_list, char *str);
int		calculate_width(char *str);
int		calculate_height(char *str);
void	calculate_dimensions(char *str, int * input_width, int *input_height);
void	jk_putchar(char c);
void	assign_funs(t_rush *f_ptr);
void	ft_write(int i, int width, int height, int count);
int		str_match(char *input_str, void (*f_ptr)(int, int, char*, int*),
									int input_width, int input_height);
void	print(char *input_str, int input_width, int input_height);

#endif
