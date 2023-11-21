/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:02 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/21 14:21:19 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *merge_nl(char *nl_buff)
{
	int i;
	int j;
	char *merged;
	size_t nl_size;
	
	i = 0;
	j = -1;
	nl_size = ft_strlen(nl_buff);
	if (!nl_buff[i])
	{
		free (nl_buff);
		return(NULL);	
	}
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	merged = malloc((sizeof (char)) * (nl_size - i + 1));
	if (!merged)
		return (NULL);
	i++;
	while(++j + i < (int)nl_size)
		merged[j] = nl_buff[j + i];
	merged[j] = '\0';
	free (nl_buff);
	return (merged);
}

char *safe_nl(char *nl_buff)
{
	int i;
	int j;
	char *buffer;

	i = 0;
	j = 0;
	if (!nl_buff[i])
		return(NULL);		
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	buffer = malloc((sizeof (char)) * (i + 2));
	if (!buffer)
		return (NULL);
	while(nl_buff[j] != '\n' && nl_buff[j])
	{
		buffer[j] = nl_buff[j];
		j++;
	}
	buffer[j] = '\0';
	if (nl_buff[j])
		buffer[j] = '\n';
	buffer[j  + 1] = '\0';
	return(buffer);
}

char *free_n_join(char *base, char *add)
{
	char *tmp;

	tmp = ft_strjoin (base, add);
	free(base);
	return (tmp);
}

char *save_nl(int fd, char *nl_buff)
{
	int readed;
	char *buffer;
	
	if (!nl_buff)
		nl_buff = calloc(1, 1);
	buffer = malloc((sizeof (char)) *  (BUFFER_SIZE + 1));
	readed = 1;
 	while (readed && !ft_strchr(nl_buff, '\n'))
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (free(buffer), NULL);
		buffer[readed] = '\0';
		nl_buff = free_n_join(nl_buff, buffer);
		if (!nl_buff)
			return(NULL);
		if (ft_strchr(nl_buff, '\n'))
			break;
	}
	free (buffer);
	return (nl_buff);
}

char *get_next_line(int fd)
{
	char *buffer;
	static char *nl[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	nl[fd] = save_nl(fd, nl[fd]);
	if (!nl[fd])
		return (NULL);
	buffer = safe_nl(nl[fd]);
	nl[fd] = merge_nl(nl[fd]);
	return(buffer);
}

// int main(int argc, char **argv)
// {
// 	(void) argc;
// 	char *bleble;
// 	int fd;
// 	char *bitte;
// 	int i;

// 	fd = open(argv[1], O_RDONLY);
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
// 	// printf("%s",get_next_line(fd));
	
// 	while (i++ < 100183)
// 	{
// 		bitte = get_next_line(fd);
// 		printf("%s", bitte);
// 		free (bitte);
// 	}
// 	return (0);
// }
 