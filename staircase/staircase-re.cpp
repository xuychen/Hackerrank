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

int staircase (int stairs)
{
  if (stairs > 0)
    return staircase(stairs-3)+staircase(stairs-2)+staircase(stairs-1);
  else if (stairs == 0)
    return 1;
  else
    return 0;
}

int main(){
    int s, res;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int n;
        cin >> n;
        res = staircase (n);
        cout << res << endl;
    }
    return 0;
}

