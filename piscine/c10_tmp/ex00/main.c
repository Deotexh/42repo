/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/06 14:39:06 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/06 15:02:06 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int fd;
	int read_res;
	char buf[20];

	if (argc == 1)
	{
		write(1, "File name missing.\n", 19);
		return (1);
	}
	if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (2);
	}
	fd = open(argv[1], O_RDONLY);

	read_res = 42;
	while (read_res != 0)
	{
		read_res = read(fd, buf, 20);
		if (read_res == -1)
		{
			write(1, "Cannot read file.\n", 18);
			return (3);
		}
		write(1, buf, 20);
	}
	close(fd);
	return (0);
}
