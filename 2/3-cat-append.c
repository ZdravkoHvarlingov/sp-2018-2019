#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 1000
#define DEFAULT_FILE_MODE 0644
#define APPEND_FILE_FLAGS O_WRONLY | O_CREAT | O_APPEND

#define REQUIRED_ARG_COUNT 1

int main(int argc, const char* const* argv)
{
    if (argc < REQUIRED_ARG_COUNT + 1)
        return 1;

    int output_fileno = open(argv[1], APPEND_FILE_FLAGS, DEFAULT_FILE_MODE);
    if (-1 == output_fileno)
    {
        perror(argv[0]);
        return 2;
    }

    char buffer[BUFFER_SIZE];
    ssize_t count;
    while ((count = read(STDIN_FILENO, buffer, BUFFER_SIZE)) != 0)
    {
        if (-1 == count)
        {
            perror(argv[0]);
            return 3;
        }

        write(output_fileno, buffer, count);
    }

    return 0;
}
