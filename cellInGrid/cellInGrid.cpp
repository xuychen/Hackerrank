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

bool search (const vector< vector<int> > &grid, int &i, int &j, int num_row, int num_col)
{
    if (i > 0 && grid[i-1][j]) i--;
    else if (j > 0 && grid[i][j-1]) j--;
    else if (i < num_row - 1 && grid[i+1][j]) i++;
    else if (j < num_col - 1 && grid[i][j+1]) j++;
    else if (i > 0 && j > 0 && grid[i-1][j-1] && i-- && j--) {}
    else if (i > 0 && j < num_col - 1 && grid[i-1][j+1] && i-- && j++) {}
    else if (i < num_row - 1 && j > 0 && grid[i+1][j-1] && i++ && j--) {}
    else if (i < num_row - 1 && j < num_col - 1 && grid[i+1][j+1] && i++ && j++) {}
    else
       return false;
    
    return true;
}

int get_biggest_region(vector< vector<int> > grid) {
    int num_row = grid.size();
    int num_col = grid[0].size();
    int count, max;
    bool res;
    stack<int> st;
    max = 0;
    for (int i = 0; i < num_row; i++)
        for (int j = 0; j < num_col; j++)
        {
            if (!grid[i][j])
                continue;
            
            count = 0;
            while (true)
            {    
               grid[i][j] = 0;
               count++;
               int coordinate = 10*i+j;
               res = search(grid, i, j, num_row, num_col);
               
               if (res)
                 st.push(coordinate);
               else if (st.size())
               {
		 i = st.top()/10;
                 j = st.top()%10;
                 st.pop();
                 count--; // duplicate
               }
               else
                 break;               
            }
            
           if (max < count)
               max = count;
        }
    
    return max;
}

int main(){
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector< vector<int> > grid(n,vector<int>(m));
    for(int grid_i = 0;grid_i < n;grid_i++){
       for(int grid_j = 0;grid_j < m;grid_j++){
          cin >> grid[grid_i][grid_j];
       }
    }
    cout << get_biggest_region(grid) << endl;
    return 0;
}

