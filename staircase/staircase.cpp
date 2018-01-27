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

/*
public static int calcNum(int n) {
        int[] array = new int[n];
        if (n == 1) {
            return 1;
        }
        else if(n == 2) {
            return 2;
        }
        else if(n == 3) {
            return 4;
        }
        array[0] = 1;
        array[1] = 2;
        array[2] = 4;
        for (int i = 3; i < n; i++) {
            array[i] = array[i-1] + array[i-2] + array[i-3];
        }
        return array[array.length-1];
    }
*/

using namespace std;

int staircase (int stairs, int *arr)
{
  if (stairs > 3)
  {
    if(!arr[stairs-3])
       arr[stairs-3] = staircase(stairs-3, arr);
    if(!arr[stairs-2])
       arr[stairs-2] = staircase(stairs-2, arr);
    if(!arr[stairs-1])
       arr[stairs-1] = staircase(stairs-1, arr);
      
    return arr[stairs-1] + arr[stairs-2] + arr[stairs-3];
  }

  return arr[stairs];
}

int main(){
    int s, res;    
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        int arr[n+1];
    
        for (int i = 0; i <= n; i++)
          arr[i] = 0;
    
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        res = staircase (n, arr);
        cout << res << endl;
    }
    return 0;
}

