#include<bits/stdc++.h>
#include<climits>
using namespace std;

class Node
{
public:
  int data = 0;
  vector<Node *> children;
  Node(int data)
  {
    this->data = data;
  }
};

void display(Node *node)
{
  string s = "";
  s += to_string(node->data) + " -> ";
  for (Node *child : node->children)
  {
    s += to_string(child->data) + ", ";
  }

  cout << s << "." << endl;

  for (Node *child : node->children)
  {
    display(child);
  }
}

Node *constructor01(vector<int> &arr)

{

  if (arr.size() == 0)

    return NULL;



  vector<Node *> stack;

  stack.push_back(new Node(arr[0]));



  Node *root = stack[0];



  for (int i = 1; i < arr.size(); i++)

  {

    if (arr[i] != -1)

    {

      Node *node = stack.back();

      Node *nnode = new Node(arr[i]);



      node->children.push_back(nnode);

      stack.push_back(nnode);

    }

    else

      stack.pop_back();

  }

  return root;

}


void remove_leave(Node *node)
{
  for(int i=node->children.size()-1;i>=0;i--)
  {
    Node *temp=node->children[i];
    if(temp->children.size()==0)
    {
      // root->children.erase(root->children.begin() + i);
      node->children.erase(node->children.begin()+i);  //erase function erase(iterator)
    }                   //erase.(v.begin()+i);->this erase the i index wala element
  }
  
   for (auto x : node->children)
    {
        remove_leave(x);
    }
}

void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    Node * root=constructor01(arr);
    
  remove_leave(root);
   display(root);
    
}

int main()
{
    solve();
    return 0;
}