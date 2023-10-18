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

void ft_putendl_fd(char *s, int fd)
{
    const char nl = '\n';

    if (!s)
        return;
    write(fd, s, ft_strlen(s));
    write(fd, &nl, 1);
}
