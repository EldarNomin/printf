#include "ft_printf.h"

int	ft_define_spec(char s, va_list *ap)
{
	int	i;

	i = 0;
	if (s == 'c')
		i += ft_put_char(ap);
	if (s == 's')
		i += ft_put_str(ap);
	if (s == 'p')
		i += ft_put_ptr(ap);
	if (s == 'd' || s == 'i')
		i += ft_put_digit(ap);
	if (s == 'x' || s == 'X')
		i += ft_put_hex(ap, s);
	if (s == 'u')
		i += ft_put_u(ap);
	if (s == '%')
		i += (int)write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	while (*format)
	{
		if (*format != '%')
			i += (int)write(1, format, 1);
		else
		{
			format++;
			i += ft_define_spec(*format, &ap);
		}
		format++;
	}
	va_end(ap);
	return (i);
}
