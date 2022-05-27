#include "libft.h"

char	*ft_decToHexa(size_t n)
{
	char		hexaDeciNum[40];
	static char	str[40];
	int			i;
	int			j;
	int			temp;

	i = 0;
	if (n == 0)
		return ("0");
	while (n != 0)
	{
		temp = 0;
		temp = n % 16;
		if (temp < 10)
			 hexaDeciNum[i++] = temp + 48;
		 else
			 hexaDeciNum[i++] = temp + 87;
		 n /= 16;
	}
	j = i - 1;
	i = 0;
	ft_bzero(str, 40);
	while (j >= 0)
		str[i++] = hexaDeciNum[j--];
	return (str);
}
