#include <iostream>
#include<queue>
using namespace std;

class node{
public:
    int data;
    node* left;
    node* right;
    node(int d){
        data = d;
        left = NULL;
        right = NULL;}};




node* buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void print(node *root){
    if(root==NULL){
        return;
    }
    print(root->left);
    print(root->right);
    cout<<root->data<<" ";
}

int height(node* root){
    if(root==NULL){
        return 0;
    }
    int ls = height(root->left);
    int rs = height(root->right);
    return max(ls,rs)+1;
}

void bfs(node *root){
    queue<node *> q;
    q.push(root);
    while(!q.empty()){
        node *f =q.front();
        cout<< f->data<<",";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
    return;
}

void bfs_formatted(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node *f =q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
        cout<< f->data<<",";
        q.pop();
        if(f->left){
            q.push(f->left);
        }
        if(f->right){
            q.push(f->right);
        }
    }
}
}

int count(node *root)
{
    if(root == NULL){
        return 0;
    }
    return 1+ count(root->left)+count(root->right);
}

void printkthlevel(node* root, int k)
    {
    if(root == NULL){
        return;
    }
    if(k==1){
        cout<<root->data<<" ";
        return;
    }
    printkthlevel(root->left,k-1);
    printkthlevel(root->right,k-1);
    return;
}

void printAllLevel(node* root)
    {
    int H = height(root);
    
    for(int i=1;i<=H;i++){
        printkthlevel(root,i);
        cout<<endl;
    }
}


int diameter1(node*root){
    if(root==NULL){
        return 0;
    }
    int h1=height(root->left);
    int h2=height(root->right);
    int op1=h1+h2;
    int op2=diameter1(root->left);
    int op3=diameter1(root->right);
    return max(op1,max(op2,op3));
}

class Pair{
public:
    int height;
    int diameter;
};

Pair diameter2(node*root){
    Pair p;
    if(root==NULL){
        p.diameter=p.height=0;
        return p;
    }
    //otherwise
    Pair left = diameter2(root->left);
    Pair right= diameter2(root->right);
    
    p.height = max(left.height,right.height)+1;
    p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));
    return p;
    
}

int main() {
    node* root =buildTree();
   // print(root);
   // cout<<height(root)<<endl;;
   // bfs(root);
    //printkthlevel(root,3);
//    printAllLevel(root);
//    bfs_formatted(root);
//    cout<<count(root);
//    cout<<diameter1(root);
    Pair p =diameter2(root);
    cout<<p.height<<endl;
    cout<<p.diameter<<endl;

    
    return 0;
}
