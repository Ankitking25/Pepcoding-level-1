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
  s += to_string(node->data) + " Child: ";
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

vector<int> nodeToRootPath(Node *node, int data)
{

    // Write your code here
    if(node->data==data)
    {
      vector<int> vec;
      vec.push_back(node->data);
      return vec;
    }

    //now take a empty vector if element is node find in the tree then print an empty vector:
    vector<int> empty;
    for(Node *child:node->children)
    {
      vector<int> result=nodeToRootPath(child,data);
      if(result.size()>0)
      {
        result.push_back(node->data);
        return result;
      }
    }
    return empty;  //here come when data tree me hai hi nahi then print empty node:
    
}

}

vector<int> nodeToRootPath(Node *node,int data)
{
    //let i know the root of the 
}


void solve()
{
    int n;
    cin>>n;
    vector<int>arr(n,0);
    for(int i = 0; i < arr.size(); i++)
    {
        cin>>arr[i];
    }
    
    int data;
    cin>>data;
   
    Node *root = constructor01(arr);
    vector<int> ans = nodeToRootPath(root,data);
    
    cout<<"[";
    for(int i =0 ; i < ans.size(); i++)
    {
        cout<<ans[i];
        if(i!=ans.size()-1)
            cout<<", ";
    }
    cout<<"]";
    
}

int main()
{
    solve();
    return 0;
}