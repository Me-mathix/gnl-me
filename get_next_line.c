/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:02 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/15 20:26:48 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *merge_nl(char *nl_buff)
{
	int i;
	int j;
	char *merged;
	static int c;
	if(!c)
	c=0;	
	i = 0;
	j = 0; 
	printf("Before merge N*%d :\n%s", c++, nl_buff);
	if (!nl_buff[i])
	{
		free (nl_buff);
		return(NULL);	
	}
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	merged = malloc((sizeof (char)) * (11000000 - i + 1));
	if (!merged)
		return (NULL);
	i++;
	while(nl_buff[j + i])
	{
		merged[j] = nl_buff[j + i];
		j++;
	}
	printf("after merge :\n%s\n-----------------------------------------------", merged);
	return (merged);
}

char *safe_nl(char *nl_buff)
{
	int i;
	int j;
	char *buffer;

	i = 0;
	j = 0;
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	if (!nl_buff[i])
		return(NULL);		
	buffer = malloc((sizeof (char)) * (i + 1));
	if (!buffer)
		return (NULL);
	while(nl_buff[j - 1] != '\n' && nl_buff[j])
	{
		buffer[j] = nl_buff[j];
		j++;
	}
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
	
	nl_buff = calloc(1, 1);
	buffer = malloc((sizeof (char)) *  (BUFFER_SIZE + 1));
	readed = 1;
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
	static int i;

	if (!i)
		i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	if (i++ <= 0)
	{
		nl = save_nl(fd, nl);
		if (!nl)
			return (NULL);
	printf("starting NL : %s", nl);
	}
	buffer = safe_nl(nl);
	nl = merge_nl(nl);
	return(buffer);
}

int main(int argc, char **argv)
{
	(void) argc;
	int fd;

	fd = open(argv[1], O_RDONLY);
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
/* 	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd);
	get_next_line(fd); */
	return (0);
}
 