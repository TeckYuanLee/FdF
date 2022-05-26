#include "libft.h"

char	*ft_decToHexaBig(size_t n)
{
	char		hexaDeciNum[40];
	static char	s[40];
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
			 hexaDeciNum[i++] = temp + 55;
		 n /= 16;
	}
	j = i - 1;
	i = 0;
	ft_bzero(s, 40);
	while (j >= 0)
		s[i++] = hexaDeciNum[j--];
	return (s);
}
