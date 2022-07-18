/*
Youtube: Apna College
Link : https://www.youtube.com/watch?v=JW-9nhktGGA&ab_channel=ApnaCollege
*/

#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left,*right;

    Node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }
};

bool getPath(Node* root,int key,vector<int>&path)
{
    if(root == NULL){
        return false;
    }

    path.push_back(root->data);

    if(root -> data == key){
        return true;
    }

    if(getPath(root->left,key,path) || getPath(root->right,key,path)){
        return true;
    }

    path.pop_back();
    return false;
}

int LCA(Node* root,int n1,int n2){
    vector<int>path1,path2;

    if(!getPath(root,n1,path1) || !getPath(root,n2,path2))
        return -1;
    
    int pc;
    for(pc = 0;pc<path1.size() && pc < path2.size();pc++)
    {
        if(path1[pc] != path2[pc])
            break;
    }

    return path1[pc-1];
}

int main()
{
    /*
                    1
                   / \
                  2  3
                 /  / \
                4  5  6
                  /
                 7

    */
   Node *root = new Node(1);
   root-> left = new Node(2);
   root-> right = new Node(3);
   root -> left->left = new Node(4);
   root -> right -> left = new Node(5);
   root -> right -> right = new Node(6);
   root -> right -> left -> left = new Node(7);

   int n1 = 7;
   int n2 = 6;
   int lca = LCA(root,n1,n2);
   if(lca == -1){
    cout << "LCA doesn't exist" << endl;
   }
   else{
    cout << "LCA: " << lca << endl;
   }

   return 0;
}