#include "ft_printf.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_itoa_fill(long int j, char *n, int index)
{
	long int	x;

	if (j < 0)
	{
		x = -j;
		n[0] = '-';
	}
	else
		x = j;
	if (x >= 10)
	{
		ft_itoa_fill(x / 10, n, index -1);
		ft_itoa_fill(x % 10, n, index);
	}
	if (x < 10)
	{
		x += 48;
		n[index] = x;
	}
}

char	*ft_itoa(int n)
{
	char		*r;
	long int	x;
	int			size;

	x = n;
	size = 0;
	while (x != 0)
	{
		x /= 10;
		size++;
	}
	if (n < 9)
	{
		size++;
		x *= -n;
	}
	if (n == 0)
		size = 1;
	r = malloc((size +1) * sizeof(char));
	if (r == NULL)
		return (NULL);
	r[size] = '\0';
	ft_itoa_fill(n, r, size - 1);
	return (r);
}
