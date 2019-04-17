/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 19:40:44 by jkaplin           #+#    #+#             */
/*   Updated: 2018/11/11 19:40:53 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH00_H
# define RUSH00_H
# include <unistd.h>
# include <stdlib.h>

void	rush00(int x, int y, char *str, int *i);
void	rush01(int x, int y, char *str, int *i);
void	rush02(int x, int y, char *str, int *i);
void	rush03(int x, int y, char *str, int *i);
void	rush04(int x, int y, char *str, int *i);
int		ft_atoi(char *str);
void	ft_putchar(char c, char *str, int *i);
char	*rush_to_str(int x, int y, void (*f_ptr)(int, int, char*, int*));

#endif
