# ft_printf

## Description

`libftprintf.a` is a library that contains a function `ft_printf()`, which mimics the behavior of the original `printf()` function from the C standard library. The purpose of this project is to recode the `printf()` function without implementing the buffer management of the original.

## Prototype
```c
int ft_printf(const char *, ...);
```

## Conversions Handled

- `%c`: Prints a single character.
- `%s`: Prints a string (as defined by the common C convention).
- `%p`: The `void *` pointer argument has to be printed in hexadecimal format.
- `%d`: Prints a decimal (base 10) number.
- `%i`: Prints an integer in base 10.
- `%u`: Prints an unsigned decimal (base 10) number.
- `%x`: Prints a number in hexadecimal (base 16) lowercase format.
- `%X`: Prints a number in hexadecimal (base 16) uppercase format.
- `%%`: Prints a percent sign.

## Requirements

- External Functions: `write`, `va_start`, `va_arg`, `va_copy`, `va_end`, (`malloc` && `free`) I didn't use it in my code.
- Libft Authorized: Yes (I don't inlude it in the code).


## Notes

- The library (`libftprintf.a`) will be created at the root of the repository.
- Buffer management of the original `printf()` is not implemented.
- The function will be compared against the original `printf()`.
- The library is created using the `ar` command. The use of `libtool` is forbidden.

## Turn in files

- The program name (`libftprintf.a`).
- Files : (`ft_printf.c` && `Makefile` && `file.c`).

## Author

Kheireddine-Anas

kheireddine.anas@gmail.com
