#include "ft_printf.h"

int	ft_put_char(va_list *ap)
{
	char	c;

	c = va_arg(*ap, unsigned int);
	write (1, &c, 1);
	return (1);
}

int	ft_put_str(va_list *ap)
{
	char	*s;

	s = va_arg(*ap, char *);
	if (!s)
		return ((int)write(1, "(null)", 6));
	write (1, s, ft_strlen(s));
	return (ft_strlen(s));
}

int	ft_put_digit(va_list *ap)
{
	int		i;
	char	*s;

	i = va_arg(*ap, int);
	s = ft_itoa(i);
	i = (ft_strlen(s));
	write(1, s, i);
	free (s);
	return (i);
}
