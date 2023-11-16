/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mda-cunh <mda-cunh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 18:23:02 by mda-cunh          #+#    #+#             */
/*   Updated: 2023/11/16 13:38:18 by mda-cunh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "get_next_line.h"

char *merge_nl(char *nl_buff)
{
	int i;
	int j;
	char *merged;
	
	i = 0;
	j = 0; 
	if (!nl_buff[i])
	{
		free (nl_buff);
		return(NULL);	
	}
	while (nl_buff[i] && nl_buff[i] != '\n')
		i++;
	merged = malloc((sizeof (char)) * (ft_strlen(nl_buff) - i + 1));
	if (!merged)
		return (NULL);
	i++;
	while(nl_buff[j + i] != '\0')
	{
		merged[j] = nl_buff[j + i];
		j++;
	}
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
	nl = save_nl(fd, nl);
	if (!nl)
		return (NULL);
	buffer = safe_nl(nl);
	nl = merge_nl(nl);
	return(buffer);
}

int main(int argc, char **argv)
{
	(void) argc;
	// char *bleble;
	int fd;
	// char *bitte;
	// int i;

	fd = open(argv[1], O_RDONLY);
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	// printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	
	// while (i++ < 100183)
	// {
	// 	bitte = get_next_line(fd);
	// 	printf("%s", bitte);
	// 	free (bitte);
	// }
	return (0);
}
 