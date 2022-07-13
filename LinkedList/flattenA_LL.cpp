#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

Node* merge(Node* left, Node* right) {
    
    if(right == NULL) {
        return left;
    }
    
    if(left == NULL) {
        return right;
    }
    
    Node* ans = new Node(-1);
    Node* temp = ans;
    
    while(left != NULL && right != NULL) {
        
        if(left -> data < right -> data) {
            
            temp -> bottom = left;
            temp = left;
            left = left -> bottom;
            
        } else {
            
            temp -> bottom = right;
            temp = right;
            right = right -> bottom;
            
        }
    }
    
    while(left != NULL) {
        temp -> bottom = left;
        temp = left;
        left = left -> bottom;
    }
    
    while(right != NULL) {
        temp -> bottom = right;
        temp = right;
        right = right -> bottom;
    }
    
    ans = ans -> bottom;
    
    return ans;
}

Node *flatten(Node *root)
{   
   
   if(root == NULL || root -> next == NULL) {
       return root;
   }   
   
   Node* down = root; 
   Node* right = root -> next;
   down -> next = NULL;

   Node* restOfList = flatten(right);
   
   Node* flattenedList = merge(down, restOfList);
   
   return flattenedList;
}

