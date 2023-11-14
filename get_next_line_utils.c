/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@42paris.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:53:58 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/12 21:15:09 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if ((!s1) || (!s2))
		return (NULL);
	join = malloc((sizeof (char)) * (ft_strlen(s1) + ft_strlen(s2)) + 1);
	if (!join)
		return (NULL);
	while (i < ft_strlen(s1))
	{
		join[i] = s1[i];
		i++;
	}
	while (j < ft_strlen(s2))
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	car;

	i = 0;
	car = (char) c;
	while (s[i] != car)
	{
		if (s[i] == '\0')
			return (0);
		i++;
	}
	return ((char *)s + i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
