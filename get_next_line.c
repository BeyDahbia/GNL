/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dabey <dabey@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:01:32 by dabey             #+#    #+#             */
/*   Updated: 2019/12/12 20:59:37 by dabey            ###   ########.fr       */
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
	if (fd < 0 || (!(buffer = (char *)ft_calloc(sizeof(char) , (BUFFER_SIZE + 1)))))
		return (-1);
	stock = ((!stock) ? ft_calloc(sizeof(char) , 0) : stock);
	printf("/**strjoint stock et buf**/\n");
	while (!(ft_strchr(buffer, '\n')) && (len_read = read(fd, buffer, BUFFER_SIZE)))
	{
		if(len_read == -1 || (buffer[len_read] = '\0'))
			return (-1);
		stock = ft_strjoin(stock, buffer);
		printf("%s\n", stock);
	}
	while (stock && stock[i] != '\n')
		i++;

	*line = ft_substr(stock, 0, i);
	printf("line apres =%s\n", *line);
		/*
	stock = ft_substr(stock + i, 0, ft_strlen(stock + i));
	printf("line apres =%s\n", stock);
	*/
//             freee tout         //
	free(buffer);
	return (1);
}
