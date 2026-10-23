
#include <unistd.h>
#include <fcntl.h>

void	display_file(int fd)
{
	char	buffer[1024];
	int		bytes_read;

	bytes_read = read(fd, buffer, 1024);
	while (bytes_read > 0)
	{
		write(1, buffer, bytes_read);
		bytes_read = read(fd, buffer, 1024);
	}
	if (bytes_read == -1)
		write(2, "Cannot read file.\n", 18);
	close(fd);
}

int	main(int argc, char **argv)
{
	int	fd;

	if (argc == 1)
		return (write(2, "File name missing.\n", 19), 1);
	if (argc > 2)
		return (write(2, "Too many arguments.\n", 20), 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (write(2, "Cannot read file.\n", 18), 1);
	display_file(fd);
	return (0);
}
