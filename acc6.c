//Bad approach.
#include <stdio.h>
#include <limits.h>

int largeSmallSum(int *array, int n)
{
    if (n <= 3)
        return 0;
    int maxm = INT_MIN;
    int minm = INT_MAX;
    int min_index = -1;
    int max_index = -1;
    int i;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (array[i] > maxm)
            {
                maxm = array[i];
                max_index = i;
            }
        }
        else
        {
            if (array[i] < minm)
            {
                minm = array[i];
                min_index = i;
            }
        }
    }
    array[max_index] = INT_MIN;
    array[min_index] = INT_MAX;
    maxm = INT_MIN;
    minm = INT_MAX;
    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            if (array[i] > maxm)
            {
                maxm = array[i];
                max_index = i;
            }
        }
        else
        {
            if (array[i] < minm)
            {
                minm = array[i];
                min_index = i;
            }
        }
    }

    return maxm + minm;
}

int main()
{
    int n, result, i;
    scanf("%d", &n);
    int array[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }
    result = largeSmallSum(array, n);
    printf("%d", result);
    return 0;
}