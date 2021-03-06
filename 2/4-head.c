#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

#define REQUIRED_ARG_COUNT 2

int main(int argc, const char* const* argv)
{
    if (argc < REQUIRED_ARG_COUNT + 1)
        return 1;

    int total_count = atoi(argv[1]);
    if (total_count < 0)
    {
        perror(argv[0]);
        return 2;
    }

    int input_fileno = open(argv[2], O_RDONLY);
    if (-1 == input_fileno)
    {
        perror(argv[0]);
        return 3;
    }

    char buffer;
    ssize_t read_result;
    int current_count = 0;
    while (current_count < total_count && (read_result = read(input_fileno, &buffer, 1)) != 0)
    {
        if (-1 == read_result)
        {
            perror(argv[0]);
            return 4;
        }

        write(STDOUT_FILENO, &buffer, 1);
        current_count++;
    }

    return 0;
}
