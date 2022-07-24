#include<stdio.h>

void csort(int *array, int n){

    //Bubble Sort
    int i,j;
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-i-1; j++)
        {
            if(array[j]>array[j+1]){

                int temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
        
    }
    
}

int productSmallestPair(int *array, int n, int sum)
{
   if(n<2) return -1;

    csort(array,n);

    int temp = array[0] + array[1];

    return temp<=sum ? (array[0]*array[1]) : 0; 
}
 
int main()
{
    int n, sum, result, i;
    scanf("%d",&sum);
    scanf("%d",&n);
    int array[n];
    for(i=0; i<n; i++)
    {
        scanf("%d",&array[i]);
    }
    result = productSmallestPair(array, n, sum);
    printf("%d",result);
    return 0;
}