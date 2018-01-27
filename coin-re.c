#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int cmp(const void *a, const void *b)
{
  return *(int *)a-*(int *)b;
}

void change(int *arr, int m, int money, int *count)
{
  if (m == 0)
     return;
   
  if (arr[0] < money)
  {
    change(arr, m, money-arr[0], count);
    change(arr+1, m-1, money, count);
  }
  else if (arr[0] == money)
    (*count)++;
}

int main(){
    int n; 
    int m; 
    int count;
    scanf("%d %d",&n,&m);
    int *coins = malloc(sizeof(int) * m);
    for(int coins_i = 0; coins_i < m; coins_i++){
       scanf("%d",&coins[coins_i]);
    }
    
    qsort(coins, m, 4, cmp);
    change(coins, m, n, &count);
    printf("%d\n", count);
    return 0;
}
