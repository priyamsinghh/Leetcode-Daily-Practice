//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverseList(Node *head)
    {
        if(head == NULL || head->next == NULL)
            return head;
            
       
       Node* prev = NULL;
       Node* curr = head;
       
       while(curr != NULL){
           Node* forward = curr->next;
           curr->next = prev;
           prev = curr;
           curr = forward;
       }
       
       return prev;
    }
    
    Node* addOne(Node *head) 
    {
        Node* head1 = reverseList(head);
        Node* temp = head1;
        Node* prev = NULL;
        
        if(temp->data == 9){
            while(temp != NULL && temp->data == 9){
                temp->data = 0;
                prev = temp;
                temp = temp->next;
            }
            
            if(temp == NULL){
                Node* newnode = new Node(1);
                prev->next = newnode;
            }else{
                temp->data += 1;
            }
        }
        else{
            temp->data += 1;
        }
        
        return reverseList(head1);
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends