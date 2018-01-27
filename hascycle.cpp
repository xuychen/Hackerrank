boolean hasCycle(Node head) {
    Node tortoise = head;
    Node hare = head;
    do{
        if(hare == null || hare.next == null) return false;  
        hare = hare.next.next;
        tortoise = tortoise.next;
    } while(hare != tortoise);
    return true;
}
// two speed meet together
// java

#include <map>
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    Node *ptr = head;
    map<Node*,bool> mp;
    while (ptr)
    {
     if (mp[ptr]== false)
         mp[ptr]=true;
     else
         return true;

     ptr = ptr->next;
    }

    return false;
}
