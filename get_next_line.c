/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@42paris.fr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:02 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/13 21:47:27 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *merge_nl(char *nl_buffer)
{
	int i;
	int j;
	char *merged;
	
	i = 0;
	j = 0;
	while (nl_buffer[i] && nl_buffer[i] != '\n')
		i++;
	merged = malloc((sizeof (char)) * ft_strlen(nl_buffer) - i + 1);
	i++;
	while (j < i)
	{
		merged[j] = nl_buffer[j + i];
		j++;
	}
	return (merged);
}

char *safe_nl(char *nl_buffer)
{
	int i;
	int j;
	char *tmp;

	i = 0;
	j = 0;
	while (nl_buffer[i] && nl_buffer[i] != '\n')
		i++;
	tmp = malloc((sizeof (char)) * (i + 1));
	tmp[i] = '\0';
	while (nl_buffer[j] != '\n')
	{
		tmp[j] = nl_buffer[j];
		j++;
	}
	return(tmp);	
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
	
	nl_buff = calloc(1, 1);
	readed = 1;
	buffer = malloc((sizeof (char)) *  (BUFFER_SIZE + 1));
 	while (readed)
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
	static char *nl;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	// printf("%d", fd);
	nl = save_nl(fd, nl);
	// if (!nl[0])
	// {
	// 	free(nl);
	// 	return (NULL);
	// }
	buffer = safe_nl(nl);
	nl = merge_nl(nl);
	return(buffer);
}

int main(int argc, char **argv)
{
	(void) argc;
	// char *bleble;
	int fd;

	fd = open(argv[1], O_RDONLY);
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
		printf("%s", get_next_line(fd));
							
	return (0);
}
 