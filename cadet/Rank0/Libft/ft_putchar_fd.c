#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int main()
{

    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }

    ft_putchar_fd('B', file_descriptor);

    close(file_descriptor);

    return 0;
}