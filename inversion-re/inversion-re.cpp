#include <bits/stdc++.h>

using namespace std;

long swapping (vector<int> &arr){
    if (arr[0] <= arr[1])
        return 0;
    else
    {
        int tmp = arr[0];
        arr[0] = arr[1];
        arr[1] = tmp;
        return 1;
    }
}

long countInversions(vector<int> &arr) {
    int i, j;
    long count;
    vector<int> a (arr.begin(), arr.begin()+(arr.size()+1)/2);
    vector<int> b (arr.begin()+(arr.size()+1)/2, arr.end());
    
    if (a.size() > 2)
        count = countInversions(a);
    else if (a.size() == 2)
        count = swapping(a);
        
    if (b.size() > 2)
        count += countInversions(b);
    else if (b.size() == 2)
        count += swapping(b);
    
    for (i=j=0; i < a.size() || j < b.size();)
    {     
      if (a[i] <= b[j])
      {
          arr[i+j] = a[i];
          i++;
      }
      else 
      {
          arr[i+j] = b[j];
          j++;
          count += a.size() - i;
      }
      
      if (i == a.size())
         for (; j < b.size(); j++)
           arr[i+j] = b[j];
      else if (j == b.size())
         for (; i < a.size(); i++)
           arr[i+j] = a[i];
    }
    
    return count;
}

int main() {
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int arr_i = 0; arr_i < n; arr_i++){
           cin >> arr[arr_i];
        }
        long result = countInversions(arr);
        cout << result << endl;
    }
    return 0;
}

