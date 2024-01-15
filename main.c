#include "ft_funcs.h"
#include <stdio.h>

int main()
{
	int x = 42;
	int *ptr = &x;
	unsigned int value = 42;

    printf("The unsigned integer value is: %u\n", value);
    // ft_printf("The unsigned integer value is: %c\n", 'f');
    printf("Total characters: %d\n", ft_printf("%c", 'f'));

    // printf("Address of x: %p\n", x);
    // ft_printf("Address of x: %p\n", x);
	// // printf("gh%mou\n", 49);
	// ft_printf("gh%mou\n", 49);
    // int result = ft_printf("gh%xou\n", 452);
    // printf("Total characters: %d\n", ft_printf("gh%sou\n", "str"));
    return 0;
}