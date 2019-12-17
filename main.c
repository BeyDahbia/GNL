#include "get_next_line.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int        main()
{
    int        fd;
    int        res_gnl;
    char       **line;
    int        i;

    i = 0;
	line = NULL;
	res_gnl = 0;
    fd = open("text.txt", O_RDONLY);
	if (fd == -1)
		printf("probleme a lire : %d\n",fd);
	res_gnl = get_next_line(fd, line);
	printf("res_gnl =%d\n",res_gnl);
	printf("line Main =%s\n",*line);
	close(fd);
	free(line);
    return (0);
}