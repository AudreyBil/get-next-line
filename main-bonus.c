/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abillote <abillote@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 12:39:51 by abillote          #+#    #+#             */
/*   Updated: 2023/12/04 15:12:45 by abillote         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int fd;
	int fd1;
	int fd2;
	//int fd3;
	//int fd4;
	char	*line;

	fd = open("texte.txt", O_RDONLY);
	if (fd == -1)
	{
		printf("Error opening file");
		return 1;
    }

	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Print the line first
		if (ft_strchr(line, 't') != NULL) {
			free(line);
			break; // Break out of the loop if 't' is found
		}
		free(line);
	}

	fd1 = open("texte1.txt", O_RDONLY);
	if (fd1 == -1)
	{
		printf("Error opening file");
		return 1;
    }

	while((line = get_next_line(fd1)) != NULL )
	{
		printf("%s", line);
		if (ft_strchr(line, 't') != NULL) {
			free(line);
			break; // Break out of the loop if 't' is found
		}
		free(line);
	}

	fd2 = open("texte2.txt", O_RDONLY);
	if (fd2 == -1)
	{
		printf("Error opening file");
		return 1;
    }

	while((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line); // Print the line first
		if (ft_strchr(line, 't') != NULL) {
			free(line);
			break; // Break out of the loop if 't' is found
		}
		free(line);
	}

	while((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line); // Print the line first
		free(line);
	}

	while((line = get_next_line(fd1)) != NULL)
	{
		printf("%s", line); // Print the line first
		free(line);
	}

	while((line = get_next_line(fd2)) != NULL)
	{
		printf("%s", line); // Print the line first
		free(line);
	}

	close(fd);
	close(fd1);
	close(fd2);

	return 0;
}
