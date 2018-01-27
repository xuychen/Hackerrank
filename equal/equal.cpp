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
int main() {
    int n, num;
    int min, total, res;
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
       cin >> num;
       vector<int> arr(num);
       min = INT_MAX;
        
       for (int j = 0; j < num; j++)
       {
         cin >> arr[j];
         if (min > arr[j])
             min = arr[j];
       }
       
       
       res = INT_MAX;
        
       for (int a = 0; a < 3; a++)
       {
         total = 0;
           
         for (int j = 0; j < num; j++)
         {
            int tmp = arr[j] - min + a;
            int five = tmp/5;
            int two = (tmp%5)/2;
            int one = tmp%5%2;
            total += five + two + one;
         }
                       
         if (res > total)
            res = total;
       }
               
       cout << res << endl;
    }
    return 0;
}

