#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printc(char c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_prints(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

int	ft_printd(int n)
{
	int	i;
	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		i++;
		n = -n;
		ft_printd(n);
	}
	else if (n > 9)
	{
		ft_printd(n / 10);
		ft_printd(n % 10);
	}
	else
	{
		i += ft_printc(n + 48);
	}
	return (i);
}

int	ft_printhex(unsigned int num, char xX)
{
	char *base = "0123456789ABCDEF";
	int	i;

	i = 0;
	if (num >= 16)
	{
		i += ft_printhex(num / 16);
		i += ft_printhex(num % 16);
	}
	else
		i += ft_printc(base[num]);
	return (i);
}

int ft_printf(char *str, ...)
{
    int i = 0;
    va_list ptr;
    va_start(ptr, str);
	// printf("%c\n", *str);
	// printf("%c\n", *str++);
	while (*str)
	{
		int	i;

		i = 0;
		if (*str != '%')
		{
			ft_printc(*str);
		}
		else
		{
			str++;
			if (*str == 'c')
			{
				ft_printc(va_arg(ptr, int));
			}
			else if(*str == 's')
			{
				ft_prints(va_arg(ptr, char *));
				// printf("%ld", ft_strlen(va_arg(ptr, char *)));
			}
			else if(*str == 'p')
			{

			}
			else if(*str == 'd')
			{
				i += ft_printd(va_arg(ptr, int));
			}
			else if(*str == 'i')
			{

			}
			else if(*str == 'u')
			{

			}
			else if(*str == 'x' || *str == 'X')
			{

			}
			else if(*str == '%')
			{
				i += ft_printc(va_arg(ptr, int));
			}
			else
			{
				ft_printc('%');
			}
		}
		str++;
	}
	printf("\n");
	printf("cspdiuxX%%\n");
	printf("\n");
	printf("%c\n", va_arg(ptr, int));
	printf("%c\n", va_arg(ptr, int));
    va_end(ptr);
    return i;
}

int main()
{
	char c = 123;
	char *cc = "KLM";
    int result = ft_printf("gh%d%sou", c, cc);
    printf("Total characters: %d\n", result);
    return 0;
}
