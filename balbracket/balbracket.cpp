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

bool is_balanced(string expression) {
    stack<char> st;
    
    for (auto &it:expression)
    {
      if (it == '{' || it == '[' || it == '(')
        st.push(it);
      else if (it == ')')
      {
        if (!st.empty() && st.top() == '(')
          st.pop();
        else
          return false;
      }
      else if (it == ']')
      {
        if (!st.empty() && st.top() == '[')
          st.pop();
        else
          return false;
      }
      else if (it == '}')
      {
        if (!st.empty() && st.top() == '{')
          st.pop();
        else
          return false;
      }
      else
          continue;
    }
    
    return st.empty();
}

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        string expression;
        cin >> expression;
        bool answer = is_balanced(expression);
        if(answer)
            cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

