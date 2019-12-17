/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:01:32 by dabey             #+#    #+#             */
/*   Updated: 2019/12/17 21:31:55 by dabey            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 5
#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int			i;
	int			len_read;
	char		*buffer;
	static char	*stock;

	i = 0;
	len_read = 0;
	buffer = NULL;
	if (fd < 0 || (!(buffer = ft_calloc(sizeof(char) , (BUFFER_SIZE + 1)))))
	stock = (!(stock) ? ft_calloc(sizeof(char),0) : stock);
	if (!stock)
	{
		len_read = read(fd, buffer, BUFFER_SIZE);
		stock = ft_strdup(buffer);
	}
	if (!(ft_strchr(stock, '\n')))
		while ((len_read = read(fd, buffer, BUFFER_SIZE)) && ft_strchr(buffer, '\n'))
		{
			if (len_read == -1)
				return (-1);
			buffer[len_read] = '\0';
			len_read = read(fd, buffer, BUFFER_SIZE);
			stock = ft_strjoin(stock, buffer);
		}
	printf("stockGNLAV =%s\n",stock);
	while (stock[i] != '\0' && stock[i] != '\n')
		i++;
	*line = ft_substr(stock, 0, i - 1);
	stock = ft_substr(stock + i, i, ft_strlen(stock + i));
	printf("lineGNLAP =%s\n",*line);
	printf("stockGNLAP =%s\n",stock);
	return (1);
}
