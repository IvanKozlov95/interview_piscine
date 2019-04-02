#include <string.h>

 char *getSum(char *a, char *b) {
   char sum[7] = {0};
   int  carry = 0;

   for (int i = 5; i >= 0; i--) {
     carry += a[i] - '0' + b[i] - '0';
     sum[i] = (carry % 2) + '0';
     carry /= 2;
   }
   return (strdup(sum));
 }

int			toInt(char *bits)
{
	int		ret;

	ret = 0;
	while (*bits)
	{
		ret = ret * 2 + *bits - '0';
		bits += 1;
	}
	return (ret);
}