/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head;
        Node* cloneHead = NULL;
        if(head==NULL) {return cloneHead;}
        Node* newNode;
        while(curr!=NULL) {
            newNode = new Node(curr->val);
            newNode->next = curr->next;
            curr->next = newNode;
            curr = newNode->next;
        }
        curr = head;
        while(curr!=NULL) {
            if(curr->random==NULL) {
                curr->next->random = NULL;
            } else {
                curr->next->random = curr->random->next;   
            }
            curr = curr->next->next;
        }
        cloneHead = head->next; 
        Node* currClone = cloneHead;
        Node* upcoming = NULL;
        curr = head;
        while(curr!=NULL) {
            upcoming = curr->next->next;
            if(upcoming!=NULL) {
                currClone->next = currClone->next->next;
            } else {
                currClone->next = NULL;
            }
            currClone = currClone->next;
            curr->next = upcoming;
            curr = curr->next;
        }
        return cloneHead;
    }
};