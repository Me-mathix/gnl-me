/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:05:53 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/23 15:08:59 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*merge_nl(char *nl_buff)
{
	int		i;
	int		j;
	char	*merged;
	size_t	nl_size;

	i = 0;
	j = -1;
	nl_size = ft_strlen(nl_buff);
	if (!nl_buff[i])
	{
		free (nl_buff);
		return (NULL);
	}
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	merged = malloc((sizeof (char)) * (nl_size - i + 1));
	if (!merged)
		return (NULL);
	i++;
	while (++j + i < (int)nl_size)
		merged[j] = nl_buff[j + i];
	merged[j] = '\0';
	free (nl_buff);
	return (merged);
}

char	*safe_nl(char *nl_buff)
{
	int		i;
	int		j;
	char	*buffer;

	i = 0;
	j = 0;
	if (!nl_buff[i])
		return (NULL);
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	buffer = malloc((sizeof (char)) * (i + 2));
	if (!buffer)
		return (NULL);
	while (nl_buff[j] != '\n' && nl_buff[j])
	{
		buffer[j] = nl_buff[j];
		j++;
	}
	buffer[j] = '\0';
	if (nl_buff[j])
		buffer[j] = '\n';
	buffer[j + 1] = '\0';
	return (buffer);
}

char	*free_n_join(char *base, char *add)
{
	char	*tmp;

	tmp = ft_strjoin (base, add);
	free(base);
	return (tmp);
}

char	*save_nl(int fd, char *nl_buff)
{
	int		readed;
	char	*buffer;

	if (!nl_buff)
		nl_buff = ft_calloc(1, 1);
	buffer = malloc((sizeof (char)) * (BUFFER_SIZE + 1));
	readed = 1;
	while (readed && !ft_strchr(nl_buff, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		nl_buff = free_n_join(nl_buff, buffer);
		if (!nl_buff)
			return (NULL);
		if (ft_strchr(nl_buff, '\n'))
			break ;
	}
	free (buffer);
	return (nl_buff);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*nl;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	nl = save_nl(fd, nl);
	if (!nl)
		return (NULL);
	buffer = safe_nl(nl);
	nl = merge_nl(nl);
	return (buffer);
}

// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	int fd = 0;
// 	char *bitte = NULL;
// 	int i = 0;

// 	fd = open(argv[1], O_RDONLY);
// 	i = 0;
// 	while (1)
// 	{
// 		bitte = get_next_line(fd);
// 		printf("%s", bitte);
// 		free (bitte);
// 	}
// 	return (0);
// }
