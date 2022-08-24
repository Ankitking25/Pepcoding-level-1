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
/*
Node *getTail(Node *r)
{
    while (r->children.size()==1)
    {
        for (int i = 0; i < r->children.size(); i++)
        {
            r = r->children[i];
        }
    }
    return r;
}

void linearize(Node *node)
{
    for (int i = 0; i < node->children.size(); i++)
    {
        linearize(node->children[i]);
    }
    for (int i = node->children.size() - 1; i >= 1; i--)
    {
        Node *last_node = node->children[i];
        Node *second_last_node=node->children[i - 1];
        Node *slt = getTail(second_last_node);
        slt->children.push_back(last_node);
        node->children.pop_back();
    }
}
*/

Node *linearize2(Node *node)
{
  if(node->children.size()==0)
  {
    return node;
  }
 Node *lkt=linearize2(node->children[node->children.size()-1]);  //last ki tail;
 while(node->children.size()>1)
 {
   Node *last_tail=node->children.back();  //remove last Ka Head;
   node->children.pop_back(); //remove karna hai to pop_back use karo any everywhere;
   Node *sl=node->children[node->children.size()-1];  //Now after remove the last tail it is second last;
   Node *slt=linearize2(sl);    //find the second last ki tail by calling itself;
   slt->children.push_back(last_tail);
 }
 return lkt;
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
    
  linearize2(root);
   display(root);
    
}

int main()
{
    solve();
    return 0;
}