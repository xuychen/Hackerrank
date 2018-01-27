#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <limits.h>
#include <stdbool.h>

int mystrstr(char *str, int pos, char *sub) {
    int index = 0;
    str += pos;
    for (int i = 0; str[i] != '\0'; i++) {
        if (sub[index] == str[i])
            index++;
        else if (sub[0] == str[i])
            index = 1;
        else
            index = 0;
        
     //   if (strcmp(sub, "gqlwpknbre") == 0)
     //       printf("test %d\n", index);
        
        if (sub[index] == '\0')
            return i - index + 1 + pos;     
    }
    
    return -1;
}

__int64_t calculate(char **genes, int *health, int first, int last, char *d) {
    int i, index;
    long count;
    
    count = 0;
    for (i = first; i <= last; i++) {
        index = 0;
        while (index != -1) {
            char* tmp = strstr(d + index, genes[i]);
            if(tmp)
                index = (int) (tmp - d);
            else
                index = -1;
    //        printf("%d %s\n",index, genes[i]);
            if (index != -1) {
                count += health[i];
                index++;
            }
        }
    }
    
    return count;
}

int main(){
    int n;
    __int64_t max, min, res; 
    max = -LONG_MAX;
    min = -max;
    scanf("%d",&n);
    char** genes = malloc(sizeof(char*) * n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       genes[genes_i] = (char *)malloc(10240 * sizeof(char));
       scanf("%s",genes[genes_i]);
    }
    printf("dsg\n");
    int *health = malloc(sizeof(int) * n);
    for(int health_i = 0; health_i < n; health_i++){
       scanf("%d",&health[health_i]);
       printf("%d\n", health[health_i]);
    }
    int s; 
    scanf("%d",&s);
    for(int a0 = 0; a0 < s; a0++){
        int first; 
        int last; 
        char* d = (char *)malloc(512000 * sizeof(char));
        scanf("%d %d %s",&first,&last,d);
        res = calculate(genes, health, first, last, d);
       // printf("%d %s\n", res, d);
        if (max < res)
            max = res;
        if (min > res)
            min = res;
    }
    
    printf("%ld %ld result\n", min, max);
    return 0;
}

