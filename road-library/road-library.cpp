#include <bits/stdc++.h>

using namespace std;

long BFS (vector <int> *graph, int root, vector <int> *visit)
{    
    int node , time = 0;
    queue<int> qe;
    qe.push(root);

    while (qe.size())
    {
        node = qe.front();
        qe.pop();
        
        if ((*visit)[node])
           continue;
        
        (*visit)[node] = 1;
        time++;
        
        for (auto &it:graph[node])
           qe.push(it);
    }
    
    return time;
}

int main() {
    int q;
    long count, total;
    cin >> q;   
    
    for(int a0 = 0; a0 < q; a0++){
        int m,n;
        long x,y;
        cin >> n >> m >> x >> y;
        vector<int> *graph = new vector<int> [n];
        vector<int> visit (n, 0);
        
        for(int a1 = 0; a1 < m; a1++){
            int city_1, city_2;
            cin >> city_1 >> city_2;
            graph[city_1-1].push_back(city_2-1);
            graph[city_2-1].push_back(city_1-1);
        }
        
        total = 0;
        for(int i = 0; i < n; i++)
        {
           if (visit[i])
             continue;
           
           count = BFS(graph, i, &visit);
           total += count*x < y*count+x-y ? count*x : y*count+x-y;
        }
       
       cout << total << endl;
    }
    
    return 0;
}

