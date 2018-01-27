#include <cmath>
#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Graph {
    vector < vector<int> > *graph;
    int nodes;
    public:
        Graph(int n):nodes(n) {
          graph = new vector < vector<int> > (n);
        }
    
        void add_edge(int u, int v) {
           (*graph)[u].push_back(v);
           (*graph)[v].push_back(u);
        }
    
        vector<int> shortest_reach(int start) {
            vector<int> res(nodes, -1);
            queue<int> qe;
            int num, time;
            qe.push(start);
           
            for (time = 1; qe.size(); time++)
            {
              queue<int> qe2;
              while (qe.size())
              {
                num = qe.front();
                qe.pop();
             
                for(auto &it:(*graph)[num])
                  if (res[it] == -1)
                  {
                    qe2.push(it);
                    res[it] = 6 * time;
                  }
              }
             
              qe = qe2;
            }
            
           return res;
       }
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);
        
        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
