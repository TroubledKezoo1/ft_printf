#include <stdarg.h>
#include "Libft/libft.h"

int deciding_chars(const char *input, va_list args)
{
    int printed_chars = 0;

    if (*input == 'c')
    {
        ft_putchar_fd(va_arg(args, int), 1);
        printed_chars++;
    }
    else if (*input == 's')
    {
        char *str = va_arg(args, char *);
        printed_chars += (int)ft_strlen(str);
        ft_putstr_fd(str, 1);
    }
    else if (*input == 'p')
    {

    }

    return printed_chars;
}

int ft_printf(const char *input, ...)
{
    va_list args;
    va_start(args, input);
    int printed_chars = 0;

    while (*input)
    {
        if (*input == '%')
        {
            input++;
            if (ft_strchr("cspdiuxX", *input))
            {
                printed_chars += deciding_chars(input, args);
            }
            else if (*input == '%')
            {
                ft_putchar_fd('%', 1);
                printed_chars++;
            }
        }
        else
        {
            ft_putchar_fd(*input, 1);
            printed_chars++;
        }
        input++;
    }

    va_end(args);
    return printed_chars;
}

int main(void)
{
    printf("%ld", ft_strlen("Hello, World!\n"));
    ft_printf("deneme123 %c devam eden string ::%s\n %c", 'P', "yaa işte öyle",'\n');
    return 0;
}
