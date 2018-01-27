#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Entry
{
    public:
    int index;
    int index2;
    int data;
    
    Entry():index(0),data(0){};
    bool operator < (const Entry& right)
    {
        return data < right.data;
    }
};

int compare(const void *a, const void *b)
{
    return ((Entry *)a)->data - ((Entry *)b)->data; 
}

int main() {
    int num, count, count2, tmp;
    cin >> num;
    Entry *array = new Entry[num];
    count = count2 = 0;
    
    for (int i = 0; i < num; i++)
    {
        array[i].index=i;
        array[i].index2=num-1-i;
        cin >> array[i].data;
    }
    
    qsort(array, num, sizeof(Entry), compare);
    
    for (int i = 0; i < num; i++)
    {
        while (array[i].index != i)
        {
          count++;
          tmp = array[i].index;
          array[i].index = array[tmp].index;
          array[tmp].index = tmp;
        }
        
        while (array[i].index2 != i)
        {
          count2++;
          tmp = array[i].index2;
          array[i].index2 = array[tmp].index2;
          array[tmp].index2 = tmp;
        }
    }
    
    cout << (count < count2? count : count2) << endl;
    delete array;
    return 0;
}

