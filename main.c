/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 10:18:39 by jkaplin           #+#    #+#             */
/*   Updated: 2019/02/28 12:33:11 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *
 * orientation - 'H' / 'V'
 * n_tags
 * char *tags[MAX_TAGS]
 *
 * o
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * t_slide:
 * n_tags
 * char *tags[2 * MAX_TAGS]
 * 
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 * int common
 * int only_s1
 * int only_s2
 *
 *
 *
*/



t_slide		*gen_all_slides(long *n_v_p, h_word n_photos, t_photo *collection, *n_slides)
{
	int common = 0;
	int only_p1 = 0;
	int	only_p2 = 0;
	for (int i = 0; i < n_photos; i++)
	{
		if (collection[i].orientation == 'V')
			*(n_v_p)++;
	}
	*n_slides = (n_photos - *n_v_p) + *n_v_p / 2;
	long all_slides_pos = (*n_v_p * (*n_v_p - 1)) / 2;
	t_slide		*all_slides[all_slides_pos];
	long k = 0;
	for (int i = 0; i < n_photos; i++)
	{
		if (collection[i].orientaion == 'V')
			for (int j = 0; j < n_photos; j++)
			{
				if (i != j && collection[j].orientation == 'V')
				{
					common = 0;
					only_s1 = 0;
					only_s2 = 0;
					t = 0;
					for (int a = 0; a < collection[i].n_tags; a++)
					{
						for(int b = 0; b < collection[j].n_tags; b++)
						{
							if (strequ(collection[i].tags[a], collection[j].tags[b]))
							{
								strcp(all_slides[k].tags[t], collection[i].tags[a]);
								common++;
								t++;
								break ;
							}
							else
							{
								strcp(all_slides[k].tags[t], collection.tags[a]);
								t++;
								strcp(all_slides[k].tags[t], collection.tags[a]);
								t++;
							}
						}
					}
					only_p1 = collection[i].n_tags - common;
					only_p2 = collection[j].n_tags - common;
					all_slides[k].n_tags = only_p1 + only_p2 + common;
					k++;
				}
			}
	}
	return all_slides;
}

t_slide		*gen_present(long n_v_p, int n_slides, t_slide *all_slides, t_photo *collection)
{
	t_slide tmp;
	for (int i = 0; i < n_v_p - 1; i++)
	{
		if (all_slides[i].n_tags <= all_slides[i + 1].n_tags)
		{
			tmp = all_slides[i];
			all_slides[i] = all_slides[i + 1];
			all_slides[i + 1] = tmp;
		}
	}
	for (int i = 0; i < n_slides;
}

int		main()
{
	t_photo		*collection;
	t_slide		*all_slides;
	h_word		n_photos;
	int			n_slides;
	long n_v_p;

	n_v_p = 0;

	collection = gen_photos("file_name", &n_photos);
	all_slides = gen_all_slides(&n_v_p, n_photos, collection, &n_slides);
	presentation = gen_present(n_v_p, n_slides, all_slides collection);


























