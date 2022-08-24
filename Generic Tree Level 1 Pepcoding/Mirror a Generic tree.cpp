#include <bits/stdc++.h>
using namespace std;

struct Node{
	int data;
	vector<Node*> children;
};

Node *constructor(int *arr,int n)
{
	Node *root= new Node();
	root->data=arr[0];
	stack<Node*> st;
	st.push(root);
	
	for(int i=1;i<n;i++)
	{
		if(arr[i]==-1)
		{
			st.pop();
		}
		else
		{
			Node *t = new Node();
			t->data=arr[i];
			st.top()->children.push_back(t);
			st.push(t);
		}
	}
	return root;
}


void display(Node *node)
{
	string str=to_string(node->data)+" -> ";
	for(Node *child:node->children)
	{
		str+=to_string(child->data)+", ";
	}
	str+=".";
	cout<<str<<endl;
	
	//Take recursive apprach;
	for(Node *child:node->children)
	{
		display(child);
	}
}



void mirrorTree(Node *root)
{
    cout << root->data << " -> ";
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        cout << root->children[i]->data << ", ";
    }
    cout << "." << endl;
    for (int i = root->children.size() - 1; i >= 0; i--)
    {
        mirrorTree(root->children[i]);
    }
}


int main()
{
  int n;
  cin>>n;
	int arr[]={10, 20 ,50, -1, 60, -1, -1, 30, 70, -1 ,80 ,110, -1 ,120, -1, -1, 90, -1 ,-1,40 ,100 ,-1, -1, -1};
	
	Node *tt = constructor(arr,n);
	display(tt);
	mirrorTree(tt);
	return 0;
}
