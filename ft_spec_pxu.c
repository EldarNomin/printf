#include "ft_printf.h"

int	ft_put_ptr(va_list *ap)
{
	int				i;
	unsigned long	j;
	char			reform[21];
	unsigned long	tmp;
	int				count;

	i = 0;
	j = (unsigned long)va_arg(*ap, void *);
	i += (int)write(1, "0x", 2);
	count = 2;
	if (j == 0)
		count += (int)(write(1, "0", 1));
	while (j)
	{
		tmp = j % 16;
		if (tmp < 10)
			reform[i++] = (char)(tmp + 48);
		else
			reform[i++] = (char)(tmp + 87);
		j = j / 16;
	}
	while (i-- > 2)
		count += (int)write(1, &reform[i], 1);
	return (count);
}

int	ft_put_hex(va_list *ap, char c)
{
	unsigned int	j;
	char			reform[21];
	int				i;
	unsigned int	tmp;
	int				count;

	count = 0;
	j = va_arg(*ap, unsigned int);
	i = 0;
	if (j == 0)
		count += (int)write(1, "0", 1);
	while (j)
	{
		tmp = j % 16;
		if (tmp < 10)
			reform[i++] = (char)(tmp + 48);
		else if (c == 'X')
			reform[i++] = (char)(tmp + 55);
		else
			reform[i++] = (char)(tmp + 87);
		j = j / 16;
	}
	while (i-- > 0)
		count += (int)write(1, &reform[i], 1);
	return (count);
}

int	ft_put_u(va_list *ap)
{
	unsigned int	j;
	unsigned long	tmp;
	char			reform[21];
	int				i;
	int				count;

	count = 0;
	j = va_arg(*ap, unsigned int);
	i = 0;
	if (j == 0)
		count += (int)write(1, "0", 1);
	while (j != 0)
	{
		tmp = j % 10;
		if (tmp < 10)
			reform[i++] = (char)(tmp + 48);
		j = j / 10;
	}
	while (i-- > 0)
		count += (int)write(1, &reform[i], 1);
	return (count);
}
