#include <bits/stdc++.h>

using namespace std;

int activityNotifications(vector <int> ex, int d) {
    int count[201], j, h, a, b, total=0;
    memset(count, 0, sizeof(int) * 201);
    for (int i=0; i < ex.size(); i++)
    {
        if (i < d)
        {
           count[ex[i]]++;
           continue;
        }
        
        h=0;
        for (j=0; h < (d+1)/2; j++)
           h += count[j];
        a=j-1;
        
        h=0;
        if (d % 2 == 0)
          for (j=0; h < d/2+1; j++)
            h += count[j];
        b=j-1;
        
        if (a+b <= ex[i])
            total++;
        
        count[ex[i-d]]--;
        count[ex[i]]++;
    }
    return total;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<int> expenditure(n);
    for(int expenditure_i = 0; expenditure_i < n; expenditure_i++){
       cin >> expenditure[expenditure_i];
    }
    int result = activityNotifications(expenditure, d);
    cout << result << endl;
    return 0;
}

