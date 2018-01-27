#include <bits/stdc++.h>

using namespace std;

__int64_t calculate(vector<string> genes, vector<int> health, int first, int last, string d) {
    int i, index;
    __int64_t count;

    count = 0;
    for (i = first; i <= last; i++) {
        index = 0;
        while (index != -1) {
            index = d.find(genes[i], index);
            
    //        printf("%d %s\n",index, genes[i]);
            if (index != -1) {
                count += health[i];
                index++;
            }
        }
    }

    return count;
}

int main(){
    int n;
    __int64_t max, min, res;
    max = -LONG_MAX;
    min = -max;

    cin >> n;
    vector<string> genes(n);
    for(int genes_i = 0; genes_i < n; genes_i++){
       cin >> genes[genes_i];
    }
    vector<int> health(n);
    for(int health_i = 0; health_i < n; health_i++){
       cin >> health[health_i];
    }
    int s;
    cin >> s;
    for(int a0 = 0; a0 < s; a0++){
        int first;
        int last;
        string d;
        cin >> first >> last >> d;
        res = calculate(genes, health, first, last, d);
       // printf("%d %s\n", res, d);
        if (max < res)
            max = res;
        if (min > res)
            min = res;
    }
    
    cout << min << " " << max << endl;
    return 0;
}

