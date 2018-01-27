#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Player {
    string name;
    int score;
}; 

bool operator > (Player p1, Player p2)
{
    if (p1.score != p2.score)
      return p1.score > p2.score;
    else
      return p1.name.compare(p2.name) < 0;
}

vector<Player> comparator(vector<Player> players) {
  vector<Player> a, b, c;
    
  for (auto &it: players)
  {
    if (it > players[0])
        a.push_back(it);
    else if (players[0] > it)
        c.push_back(it);
    else
        b.push_back(it);
  }
  
  if (a.size() > 1)
    a = comparator(a);
  if (c.size() > 1)
    c = comparator(c);
    
  a.insert(a.end(), b.begin(), b.end());
  a.insert(a.end(), c.begin(), c.end());
  return a;
}

int main() {
    
    int n;
    cin >> n;
    vector< Player > players;
    string name;
    int score;
    for(int i = 0; i < n; i++){
        cin >> name >> score;
        Player p1;
        p1.name = name, p1.score = score;
        players.push_back(p1);
    }
    
    vector<Player > answer = comparator(players);
    for(int i = 0; i < answer.size(); i++) {
        cout << answer[i].name << " " << answer[i].score << endl;
    }
    return 0;
}

