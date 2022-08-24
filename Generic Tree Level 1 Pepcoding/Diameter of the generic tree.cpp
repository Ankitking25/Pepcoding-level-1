#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    vector<Node*>children;
};



Node* construct(vector<int>&arr) {
    Node* root = nullptr;

    stack <Node*> st;
    for (int i = 0; i < arr.size(); i++) {
      if (arr[i] == -1) {
        st.pop();
      } else {
        Node* t = new Node();
        t->data = arr[i];

        if (st.size() > 0) {
          st.top()->children.push_back(t);
        } else {
          root = t;
        }
        st.push(t);
      }
    }
    return root;
  }
int dia = 0;
 int diameter(Node* root){ 
//write your code here
//let we have two ht;
int maxheight=-1;   //maxht denoted the deepth of the max height;
int secondheight=-1;    //secht denoted the deepth of the second max height of the tree;
for(int i=0;i<root->children.size();i++)
{
  int newheight=diameter(root->children[i]);   //give the height of the tree
  if(newheight>maxheight)
  {
    //matlab new height agar maxht se bhi greater ho jaay:
    secondheight=maxheight; 
    maxheight=newheight;
     
  } 
  else if(newheight>secondheight)
  {
    secondheight = maxheight;
  }
}
//Now the diameter is:
dia=max(dia,maxheight+secondheight+2);
//Now we return the deepest node but as dia is outside of fuction so we use;
//use this form outside of the fucntion call:
maxheight+=1; //
return maxheight;  //return not give diameter it just give the height but as in function;
  //dia is outside the fucntion and give the diameter so we use this value in return fucntion:
}
int main(){
    int n,x;
    cin>>n;
    vector<int>arr;
    for(int i=0;i<n;i++){
        cin>>x;
        arr.push_back(x);
    }
    Node *root = construct(arr);
    dia=0;
    diameter(root);
    cout<<dia<<endl;
    
}