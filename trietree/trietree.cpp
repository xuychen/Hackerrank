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

class TrieNode
{
   public:
    TrieNode *next[26];
    int count;
    
    TrieNode():count(0)
    {
     memset(next,0, 26);
    }
};

class TrieTree
{
  TrieNode *head;
  
  public:
    TrieTree()
    {
       head = new TrieNode;
    }
    
    void insert(string str)
    {
        TrieNode *ptr = head;
        for(string::iterator itr=str.begin(); itr != str.end(); itr++)
        {
            if (ptr->next[*itr - 'a'])
              ptr = ptr->next[*itr - 'a'];
            else
              ptr = ptr->next[*itr-'a'] = new TrieNode();
            
            ptr->count++;  
        }
    }
    
    int findPart(string part)
    {
        TrieNode *ptr = head;
        TrieNode *prev;
        for(string::iterator itr=part.begin(); itr != part.end(); itr++)
        {
            if (ptr->next[*itr - 'a'])
              ptr = ptr->next[*itr - 'a'];
            else
              return 0;
            
            prev = ptr;
        }
        
        return prev->count;
    }
};


int main(){
    int n;
    cin >> n;
    TrieTree tt;
    for(int a0 = 0; a0 < n; a0++){
        string op;
        string contact; 
        cin >> op >> contact;
        
        if (op[0] == 'a') // add
          tt.insert(contact);
        else
          cout << tt.findPart(contact) << endl;
    }
    return 0;
}
