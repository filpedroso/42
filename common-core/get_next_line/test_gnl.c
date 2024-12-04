#include "get_next_line.h"
#include <fcntl.h>  // For open()
#include <stdio.h>  // For printf()
#include <unistd.h> // For close()

void	test_file(const char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}
	printf("Testing file: %s\n", filename);
	while ((line = get_next_line(fd)))
	{
		printf("%s", line); // Print the line (should include '\n' if present)
		free(line);         // Free the returned line
	}
	printf("\nEOF reached or error occurred\n");
	close(fd);
}

/* void test_standard_input()
{
	char	*line;

	printf("Testing standard input (type lines and press Enter,
		Ctrl+D to finish):\n");
	while ((line = get_next_line(STDIN_FILENO)))
	{
		printf("You entered: %s", line);
		free(line);
	}
	printf("\nEOF reached or error occurred\n");
} */
int	main(void)
{
	printf("%s", "working");
	test_file("1char.txt"); // A file with a single character
	/* test_file("empty.txt");          // An empty file
	test_file("normal.txt");         // A regular text file
	test_file("long_lines.txt");     // A file with very long lines
	test_file("no_newline.txt");     // A file with no newline at the end
	// Test standard input
	test_standard_input(); */
	return (0);
}
