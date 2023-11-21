/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:53:58 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/17 12:52:31 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t s1_len;
	size_t s2_len;

	i = -1;
	j = -1;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	if ((!s1) || (!s2))
		return (NULL);
	join = malloc((sizeof (char)) * (s1_len + s2_len) + 1);
	if (!join)
		return (NULL);
	while (++i < s1_len)
		join[i] = s1[i];
	while (++j < s2_len)
		join[i + j] = s2[j];
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
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
