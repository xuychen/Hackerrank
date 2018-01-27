#include <cmath>
#include <cstdio>
#include <climits>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, num, min = INT_MAX;
    cin >> n;
    vector <int> vec(n), thing;
    for (int i=0; i < n; i++)
      cin >> vec[i];
    
    sort(vec.begin(), vec.end());
    for (int i=1; i < n; i++)
    {
      num = vec[i]-vec[i-1];
      if (num < min)
      {
          min = num;
          thing.clear();
          thing.push_back(vec[i-1]);
          thing.push_back(vec[i]);
      }
      else if (num == min)
      {
          thing.push_back(vec[i-1]);
          thing.push_back(vec[i]);
      }
    }
    
    for (auto it: thing)
        cout << it << " ";
    
    return 0;
}

