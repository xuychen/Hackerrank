#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

// MaxHeap greater than
// MinHeap smaller than

bool lt (int left, int right)
{
    return left < right;
}

bool gt (int left, int right)
{
    return left > right;
}

class Heap
{
  public:
    int count;
    vector<int> *hp;
    bool (*cmp) (int a, int b);
    
    Heap(int num, bool (*func)(int a, int b)):count(0)
    {
      cmp = func;
      hp = new vector<int> (num);
    }
    
    void insert(int num)
    {
      int i;
      count++;
      for (i = count; i != 1 && cmp(num, hp->at(i/2)); i /= 2)
        hp->at(i) = hp->at(i/2);
      
      hp->at(i) = num;
    }
    
    int deleteTop()
    {
       int index = 1, tmp;
       tmp = hp->at(1);
       while (index*2 <= count)
       {        
           if (index*2+1 > count || cmp(hp->at(index*2), hp->at(index*2+1)))
               index = index*2;
           else
               index = index*2+1;

           hp->at(index/2) = hp->at(index);
       }
       
       hp->at(index)= hp->at(count--);
       return tmp;
    }
    
    int getTop()
    {
     return hp->at(1);
    }
    
};

int main()
{
    int n, num;
    cin >> n;
    Heap min(n+1, lt), max(n+1, gt);
    for(int a_i = 0; a_i < n; a_i++){
       cin >> num; 
       if (max.count > min.count)
       {
          if (max.getTop() > num)
          {
              max.insert(num);
              num = max.deleteTop();
          }
          
          min.insert(num);
       }
       else
       {
           if (min.count && min.getTop() < num)
           {
               min.insert(num);
               num = min.deleteTop();
           }
           
           max.insert(num);
       }
       
       if (max.count > min.count)
           printf("%.1f\n",(double) max.getTop());
       else
           printf("%.1f\n", (double)(max.getTop()+min.getTop())/2);
    }
    
    return 0;
}
