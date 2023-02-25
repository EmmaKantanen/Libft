/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekantane <ekantane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 16:24:39 by ekantane          #+#    #+#             */
/*   Updated: 2022/03/30 16:47:24 by ekantane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	word_len(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	return (i);
}

static int	word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static int	ft_fill_array(char **arr, char const *s, char c)
{
	int	i;
	int	width;
	int	newrow;

	i = 0;
	newrow = 0;
	while (s[i] != '\0')
	{
		width = 0;
		if (s[i] != c)
		{
			arr[newrow] = (char *)malloc(sizeof(char) * \
			(unsigned long)(word_len(&(s[i]), c) + 1));
			if (!arr[newrow])
				return (-1);
			while (s[i] != c && s[i] != '\0')
				arr[newrow][width++] = s[i++];
			arr[newrow++][width] = '\0';
			continue ;
		}
		i++;
	}
	return (0);
}

char	**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		height;

	height = word_count(s, c);
	arr = (char **)malloc(sizeof(char *) * (unsigned long)height + 1);
	if (arr == NULL)
		return (NULL);
	ft_fill_array(arr, s, c);
	arr[height] = NULL;
	if (ft_fill_array(arr, s, c) == -1)
		return (NULL);
	return (arr);
}
