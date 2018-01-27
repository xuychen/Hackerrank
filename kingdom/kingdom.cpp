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

using namespace std;
#define MOD 10000000007

class Change
{
    public:
      long rr;
      long rb;
      long br;
      long bb;
      
      Change():rr(1), rb(1), br(1), bb(1){};
};

vector<int> *graph; 
int *visited;
Change *ch;

void DFS (int node)
{
    int flag = 1;
    visited[node] = 1;
    for (vector<int>::iterator it = graph[node].begin(); it != graph[node].end(); it++) 
      if (!visited[*it])
      {      
        DFS(*it);
        flag = 0;
        ch[node].rr = ch[node].rr * (ch[*it].rr + ch[*it].br + ch[*it].bb) % MOD;
        ch[node].br = ch[node].br * ch[*it].bb % MOD;
        ch[node].rb = ch[node].rb * ch[*it].rr % MOD;
        ch[node].bb = ch[node].bb *(ch[*it].rr + ch[*it].rb + ch[*it].bb) % MOD;
      }
    
    if (flag)
        ch[node].bb = ch[node].rr = 0;
    else{
      ch[node].rr = (ch[node].rr - ch[node].br + MOD) % MOD;
      ch[node].bb = (ch[node].bb - ch[node].rb + MOD) % MOD;   
    }
}


int main() {
    int n, u, v;    
    cin >> n;
    graph = new vector <int> [n];
    ch = new Change[n];
    visited = new int[n];
    
    while (cin >> u >> v)
    {
       graph[u-1].push_back(v-1);
       graph[v-1].push_back(u-1);
    }
    
    DFS(0);
    cout << (ch[0].rr + ch[0].bb) % MOD << endl;
    
    delete ch, visited, graph;
    return 0;
}

