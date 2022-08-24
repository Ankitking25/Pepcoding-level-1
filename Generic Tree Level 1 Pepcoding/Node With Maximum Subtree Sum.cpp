#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int c= INT_MAX;
int flloor= INT_MIN;

struct Node{
    int data;
    vector<Node*>children;
};

Node *newNode(int key){
	Node *temp=new Node;
	temp->data=key;
	return temp;

}

Node *construct(int arr[],int n ){
    Node *root=NULL;
    stack<Node*>st;
    for(int i=0;i<n;i++){
        if(arr[i]==-1){
            st.pop();
        }else{
            Node *t=newNode(arr[i]);
                        
            if(st.size()>0){
                st.top()->children.push_back(t);
            }else{
                root=t;
            }
            st.push(t);
        }
    }
    return root;
}


//Main case of the Node with Maximum substree sum:
int msn =0;   //msn give the that node 
int ms = INT_MIN;   //ms give the maximum sun:
int subsumtree(Node *node)
{
    int sum=0;
    //Write your code here
    for(Node *child:node->children)
    {
        int ans=subsumtree(child);
        sum+=ans;
    }
    sum+=node->data;
    if(sum>ms)
    {
        msn=node->data;
        ms=sum;
    }
    return sum;
}



int main(){
    
    int n;
    cin>>n;
    
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    Node *root=construct(arr,n);
    subsumtree(root);
    cout<<msn<<"@"<<ms<<endl;    
}

/*
Sample Input

20
10 20 -50 -1 60 -1 -1 30 -70 -1 80 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
30@130
*/

