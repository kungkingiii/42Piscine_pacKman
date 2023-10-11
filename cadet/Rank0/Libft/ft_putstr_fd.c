#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

size_t ft_strlen(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void ft_putstr_fd(char *s, int fd)
{
    if (!s)
        return;
    write(fd, s, ft_strlen(s));
}

int main()
{

    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }

    ft_putstr_fd("good evening!", file_descriptor);
    ft_putstr_fd("good morning!", file_descriptor);

    close(file_descriptor);

    return 0;
}