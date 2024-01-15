#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printc(char c)
{
	return (write(1, &c, 1));
}

int	ft_prints(char *s)
{
	int	i;

	i = 0;
	while (*(s + i))
	{
		write(1, (s + i), 1);
		i++;
	}
	return (i);
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

int	ft_printu(unsigned int num)
{
	int	i;

	i = 0;
	if (num < 10)
		i += ft_printc(num + 48);
	else
	{
		ft_printu(num / 10);
		ft_printu(num % 10);
	}
	return (i);
}

int	ft_printhex(unsigned int num, char xX)
{
	char *base;
	int	i;

	i = 0;
	if (xX == 'x')
		base = "0123456789abcedf";
	if (xX == 'X')
		base = "0123456789ABCDEF";
	if (num >= 16)
	{
		i += ft_printhex(num / 16, xX);
		i += ft_printhex(num % 16, xX);
	}
	else
		i += ft_printc(base[num]);
	return (i);
}

int	ft_printadd(unsigned long int num)
{
	char *base;
	int	i;

	base = "0123456789abcedf";
	i = 0;
	if (!num)
		return (ft_printc('0'));
	if (num >= 16)
	{
		i += ft_printadd(num / 16);
		i += ft_printadd(num % 16);
	}
	else
		i += ft_printc(base[num]);
	return (i);
}
int ft_printf(char *str, ...)
{
	int	i;

	i = 0;
    va_list	ptr;
    va_start(ptr, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'c')
			{
				i += ft_printc(va_arg(ptr, int));
			}
			else if (*str == 's')
			{
				i += ft_prints(va_arg(ptr, char *));
			}
			else if (*str == 'd' || *str == 'i')
			{
				i += ft_printd(va_arg(ptr, int));
			}
			else if(*str == 'u')
			{
				i += ft_printu(va_arg(ptr, unsigned int));
			}
			else if (*str == 'x' || *str == 'X')
			{
				i += ft_printhex(va_arg(ptr, unsigned int), *str);
			}
			else if (*str == 'p')
			{
				i += ft_prints("0x");
				i += ft_printadd(va_arg(ptr, unsigned long int));
			}
			else if (*str == '%')
			{
				i += ft_printc(va_arg(ptr, int));
			}
			else
			{
				i += ft_printc(*str);
			}
		}
		else
			i += ft_printc(*str);
		str++;
	}
	printf("\n");
    va_end(ptr);
    return (i);
}

int main()
{
	int x = 42;
	int *ptr = &x;
	unsigned int value = 42;

    printf("The unsigned integer value is: %u\n", value);
    ft_printf("The unsigned integer value is: %u\n", value);

    // printf("Address of x: %p\n", x);
    // ft_printf("Address of x: %p\n", x);
	// // printf("gh%mou\n", 49);
	// ft_printf("gh%mou\n", 49);
    // int result = ft_printf("gh%xou\n", 452);
    // printf("Total characters: %d\n", ft_printf("gh%sou\n", "str"));
    return 0;
}
