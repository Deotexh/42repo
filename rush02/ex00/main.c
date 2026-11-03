/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 19:16:58 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/02 19:17:00 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include "query.h"
#include "convert_input.h"

void	query_dict(int fd, char *search);

void	open_file(char *path)
{
		return (open(path, O_RDONLY));
}
void	error_printer()
{
	write(2, "Error\n", 6);
}

int main(int argc, char **argv)
{
	int fd;

	if (argc < 2 || argc > 3)
	{
		error_printer();
		return (1);
	}
	if (argc == 3)
	{
		fd = open_file(argv[1]);
		query_dict(fd, argv[2]);
		close(fd);
	}
	else 
	{
		fd = open_file(argv[1]);
		query_dict(int fd, char *search);
		close(fd);
	}
	return (0);
}
