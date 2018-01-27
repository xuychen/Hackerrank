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

void swap (int *a, int *b)
{
   int tmp;
   tmp = *a;
   *a = *b;
   *b = tmp;
}

int main(){
    int n, count = 0;
    cin >> n;
    vector<int> a(n);
    for(int a_i = 0;a_i < n;a_i++){
       cin >> a[a_i];
    }
    
    for (int i = 0; i < n - 1; i++)
      for (int j = i; j < n; j++)
        if (a[i] > a[j])
        {
             swap(&a[i], &a[j]);
             count++;
        }
    
   cout << "Array is sorted in " << count << " swaps." << endl;
   cout << "First Element: " << a[0] << endl;
   cout << "Last Element: " << a[n-1] << endl;
   return 0;
}
