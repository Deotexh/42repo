#include <unistd.h>

char *get_next_line(int fd)
{
	static t_fd_read_infos leftover;
	char *buffer;
	char *result;
	size_t result_size;
	size_t temp_read_bytes;

	result_size = 32;
	buffer = malloc(BUFFER_SIZE);
	result = vi_realloc(leftover.str, leftover.size, vi_get_enough_size(leftover.size));
	if (!buffer || !result)
		return (NULL);
	free(leftover.str);
	while (temp_read_bytes == BUFFER_SIZE && !vi_is_wholeline())
	{
		temp_read_bytes = read(fd, buffer, BUFFER_SIZE - 1);
		leftover.bytes_read = temp_read_bytes;
		if (leftover.size + BUFFER_SIZE > result_size)
			vi_realloc(result, result_size, vi_get_size(result_size));
		vi_strappend(result, buffer);
	}
	rest = vi_trim_after_newline(result);
	return (result);
}
