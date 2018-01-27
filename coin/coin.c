#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

void change(long *arr, int m, int money, long *count)
{
  long coins[money+1];
  memset(coins, 0, sizeof(long) * (money+1));
  coins[0]=1;
    
  for (int i = 0; i < m; i++)
    for (long j = arr[i]; j <= money; j++)
      coins[j] += coins[j-arr[i]];
    
  *count = coins[money];
}

int main(){
    int n; 
    int m; 
    long count;
    scanf("%d %d",&n,&m);
    long *coins = malloc(sizeof(long) * m);
    for(int coins_i = 0; coins_i < m; coins_i++){
       scanf("%ld",&coins[coins_i]);
    }
    
    change(coins, m, n, &count);
    printf("%ld\n", count);
    return 0;
}
