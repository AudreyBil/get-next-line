/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:39:51 by abillote          #+#    #+#             */
/*   Updated: 2023/11/30 15:01:33 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char	*line;

	if (argc > 1)
	{
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return 1;
    }
	}
	else
		fd = STDIN_FILENO;

	while((line = get_next_line(fd)) != NULL )
	{
		printf("%s", line);
		free(line);
	}

	if (argc > 1)
		close(fd);

	return 0;
}
