#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*arr;
	int	size;
	int	i;

	if (min >= max)
		return (NULL);
	i = 0;
	size = max - min;
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	while (i < size)
	{
		arr[i] = min;
		min++;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int main()
// {
//     int i = 0;
//     int min = -1;
//     int max = 3;
//     int size = max - min;
//     int *arr = ft_range(min, max);
//     while (i < size)
//     {
//         printf("%d\n", arr[i]);
//         i++;
//     }
// }