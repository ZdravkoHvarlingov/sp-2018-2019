#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUFFER_SIZE 1000
#define MAX_STD_FILENO 2
#define NEWLINE_CHARACTER '\n'

#define REQUIRED_ARG_COUNT 1

void head(int fileno, size_t total_count)
{
    size_t current_count = 0;
    char buffer;
    while (current_count < total_count && read(fileno, &buffer, 1) > 0)
    {
        if (NEWLINE_CHARACTER == buffer)
            current_count++;
        write(STDOUT_FILENO, &buffer, 1);
    }
}

int main(int argc, char const* const* argv)
{
    if (argc < REQUIRED_ARG_COUNT + 1)
        return 1;

    size_t total_count = atoi(argv[1]);

    if (argc > REQUIRED_ARG_COUNT + 1)
    {
        for (int i = REQUIRED_ARG_COUNT + 1; i < argc; i++)
            open(argv[i], O_RDONLY);

        for (int i = 1; i < argc - REQUIRED_ARG_COUNT; i++)
            head(MAX_STD_FILENO + i, total_count);
    }
    else
        head(STDIN_FILENO, total_count);

    return 0;
}
