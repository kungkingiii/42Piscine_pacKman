#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void ft_checknbr(int nb, int fd)
{
    char b;
    char i;

    i = nb % 10 + '0';
    b = nb + '0';
    if (nb >= 10)
    {
        ft_checknbr(nb / 10, fd);
        write(fd, &i, 1);
    }
    else
    {
        write(fd, &b, 1);
    }
}

void ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        write(fd, "-", 1);
        write(fd, "2", 1);
        n = 147483648;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n *= -1;
    }
    ft_checknbr(n, fd);
}

int main()
{

    int file_descriptor = open("output.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (file_descriptor == -1)
    {
        perror("Error opening file");
        return 1;
    }

    ft_putnbr_fd(12345, file_descriptor);
    ft_putnbr_fd(-255, file_descriptor);

    close(file_descriptor);

    return 0;
}