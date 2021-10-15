#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);
int		ft_put_ptr(va_list *ap);
int		ft_put_u(va_list *ap);
int		ft_put_char(va_list *ap);
int		ft_put_str(va_list *ap);
int		ft_put_digit(va_list *ap);
int		ft_strlen(const char *s);
void	ft_itoa_fill(long int j, char *n, int index);
char	*ft_itoa(int n);
int		ft_put_ptr(va_list *ap);
int		ft_put_hex(va_list *ap, char c);
int		ft_put_u(va_list *ap);

#endif
