#include <bits/stdc++.h>
using namespace std;

struct Node{
  int data;
  vector<Node*> children;
};

Node *constructor(int *arr,int n)
{
  Node *root = new Node();
  root->data=arr[0];
  stack<Node*> st;
  st.push(root);
  
  //from 1 to n;
  for(int i=1;i<n;i++)
  {
    if(arr[i]==-1)
    {
      st.pop();
    }
    else
    {
      Node *t =new Node();
      t->data=arr[i];
      st.top()->children.push_back(t);
      st.push(t);
    }
  }
  return root;
}

void display(Node *node)
{
  string str=to_string(node->data)+"->";
  for(Node *child:node->children)
  {
    str+=to_string(child->data)+",";
  }
  str+=".";
  cout<<str<<endl;
  //recursive;
  for(Node *child:node->children)
  {
    display(child);
  }
}

//size of the generic tree;
int size(Node *node)
{
	int len=0;
	for(Node *child:node->children)
	{
		int cs=size(child);
		len+=cs;
	}
	len+=1;
	return len;
}

int Height(Node *node)
{
	int ht=-1;
	for(Node *child:node->children)
    {
    	int nht=Height(child);
    	ht=max(ht,nht);
	}
	//now add +1 for root node;
	ht+=1;
	return ht;
}

//Max element of a generic tree;
int Max(Node *node)
{
	int maxx=INT_MIN;
	for(Node *child:node->children)
	{
		int nmax=Max(child);
		maxx=max(maxx,nmax);
	}
	//now find the max according to root node;
	maxx=max(maxx,node->data);
	return maxx;
}

//traversal of pre ,post and edge:
void traversal(Node *node)
{
	cout<<"The pre node "<<node->data<<endl;
	for(Node *child:node->children)
	{
		cout<<"The Pre Edge is "<<node->data<<" "<<child->data<<endl;
		traversal(child);
		cout<<"The Post Edge is "<<node->data<<" "<<child->data<<endl;
	}
	cout<<"The post node"<<node->data<<endl;
}

void levelorder(Node *node)
{
   queue<Node*> parent;
   parent.push(node);
   
   while(!parent.empty())
   {
   	 Node *temp=parent.front();
   	 parent.pop();
   	 cout<<temp->data<<endl;
   	 for(Node *child:temp->children)
   	 {
   	 	parent.push(child);
   	}
   }	
}

//levelorderlinewise
void levelorderlinewise1(Node *node)
{
	//by two queue method;
	queue<Node*> parent;
	queue<Node*> baby;
	parent.push(node);
	
	while(!parent.empty())
	{
		//rpa;
		Node *temp=parent.front();
		parent.pop();
		cout<<temp->data<<" ";
		//add temp child node in baby queue;
		for(Node *child:temp->children)
		{
			baby.push(child);
		}
		//now when parent is empty the go to new and change both queue;
		if(parent.size()==0)
		{
			swap(parent,baby);
			cout<<endl;
		}
	}
}

void levelorderlinewise2(Node *node)
{
	//by using NULL method;
	queue<Node*> parent;
	parent.push(node);
	parent.push(NULL); 
	//rpa;
	while(!parent.empty())
	{
	Node *temp=parent.front();
	parent.pop();
	if(temp!=NULL)
	{
		cout<<temp->data<<" ";
		//now add all child of temp in children;
		for(Node *child:temp->children)
		{
			parent.push(child);
		}
	}
	else
	{
		if(parent.size()>0)
		{
			parent.push(NULL);
			cout<<endl;
		}
 	}
    }
}

void levelorderlinewise3(Node *node)
{
	//by size method;
	queue<Node*> parent;
	parent.push(node);
	
	while(!parent.empty())
	{
		int len=parent.size();
		for(int i=0;i<len;i++)
		{
			Node *temp=parent.front();
			parent.pop();
			cout<<temp->data<<" ";
			
			for(Node *child:temp->children)
	      	{
			parent.push(child);
		     }
	      	
		}
		cout<<endl;
		
		//now add all it's children:
		
	}
}

class Pair{
	public:
		Node *node;
		int level;
	Pair(Node *node,int level)
	{
		this->node=node;
		this->level=level;
	}
};
void levelorderlinewise4(Node *node)
{
	queue<Pair> parent;
	parent.push(Pair(node,1));
	int level=1;
	while(!parent.empty())
	{
		Pair temp=parent.front();  //take the pair Front of the node;
		parent.pop();             //Now pop frist pair:
		if(temp.level>level)
		{
		  level=temp.level;
		  cout<<endl;
		}
		cout<<temp.node->data<<" ";   //write pair data;
		for(Node *child:temp.node->children)
		{
			parent.push(Pair(child,temp.level+1));    //add all pair it 
		}
	}
}

void levelorderzigzag(Node *node)
{
	stack<Node*> parent;
	stack<Node*> baby;
	parent.push(node);
	int level=1;
	while(!parent.empty())
	{
		Node *temp=parent.top();
		parent.pop();
		cout<<temp->data<<" ";
		if(level%2==1)
		{
			//means level odd hai to;->left to right child ko add karo;
			for(Node *child:temp->children)
			{
				baby.push(child);
			}
		}
		else
		{
			//means level even hai when first level 1 hai to child to add karo right to left;
			for(int i=temp->children.size()-1;i>=0;i--)
			{
				baby.push(temp->children[i]);
			}
		}
		if(parent.size()==0)
		{
			swap(parent,baby);
			level++;
			cout<<endl;
		}
	}
	
}

void Mirror_Image(Node *node)
{
	cout<<node->data<<"->";
	for(int i=node->children.size()-1;i>=0;i--)
	{
		cout<<node->children[i]->data<<",";
	}
	cout<<"."<<endl;
	//recursive law;
	for(int i=node->children.size()-1;i>=0;i--)
	{
		Mirror_Image(node->children[i]);
	}
}

//Now remove the last node of a generic tree:
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
  
   for (Node *child:node->children)
    {
        remove_leave(child);
    }
}



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

Node *linearize2(Node *node)
{
  if(node->children.size()==0)  //base case;
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
 //last ki tail give head;
 return lkt;  
}

bool find_element(Node *node,int data)
{
  if(node->data==data)
  {
    return true;
  }
  for(Node *child:node->children)
  {
    bool check=find_element(child,data);
    if(check)
    {
      return true;
    }
  }
  return false;
}

vector<int> Node_to_root(Node *node,int data)
{
  if(node->data==data)
  {
    vector<int> vec;
    vec.push_back(node->data);
    return vec;
  }
  
  vector<int> empty;
  for(Node *child:node->children)
  {
    vector<int> result=Node_to_root(child,data);
    if(result.size()>0)
    {
      result.push_back(node->data);
      return result;
    }
  }
  return empty;
}

void preorder(Node *node)
{

	string str=to_string(node->data);
	cout<<str<<" ";
	for(Node *child:node->children)
	{
		preorder(child);
	}
	
}

void postorder(Node *node)
{
	string str=to_string(node->data);
	for(Node *child:node->children)
	{
		postorder(child);
	}
	cout<<str<<" ";
}

int main()
{
  int arr[]={10, 20, 50, -1 ,60 ,-1, -1, 30, 70, -1, 80, 110 ,-1, 120, -1 ,-1, 90 ,-1 ,-1 ,40, 100, -1 ,-1, -1};
  int n=sizeof(arr)/sizeof(arr[0]);
  Node *t = constructor(arr,n);
  display(t);
  /*
  cout<<endl;
   cout<<"Only Preorder"<<endl;
   preorder(t);
   cout<<endl;
   cout<<"Only Postorder"<<endl;
   postorder(t);
   */
  cout<<"The size of the generic tree was "<<size(t)<<endl;
  cout<<"The height of the generic tree was "<<Height(t)<<endl;
  cout<<"The Max element of a generic tree is "<<Max(t)<<endl;
  cout<<"The Pre Node,pre edge,post edge,post node"<<endl;
  traversal(t);
  cout<<"The levelorder traversal is "<<endl;
  levelorder(t);
  cout<<"The levelorderlinewise 1 by using two stack is "<<endl;
  levelorderlinewise1(t);
  cout<<"The levelorderlinewise 2 by using null method  is "<<endl;
  levelorderlinewise2(t);
  cout<<"The levelorderlinewise 3 by using size method is "<<endl;
  levelorderlinewise3(t);
  cout<<"The levelorderlinewise 4 by using pair method is "<<endl;
  levelorderlinewise4(t);
  cout<<"The zigzag levelorder traversal"<<endl;
  levelorderzigzag(t);
  cout<<"Mirror Image of Generic Tree is "<<endl;
  Mirror_Image(t);
  cout<<"Remove the last node of the Generic Tree is "<<endl;
  remove_leave(t);
  cout<<"Display after remove the last leave "<<endl;
  display(t);
  cout<<"The Linearise way to represent a tree "<<endl;
  linearize(t);
  display(t);
  cout<<"The Linearise2 way to represent a tree "<<endl;
  linearize2(t);
  display(t);
  
  bool flag =find_element(t,80); 
    if(flag == true){   
      cout<<"true"<<endl;
    }
    else{
        cout <<"false"<<endl;
    }
    
    //node to root;
    cout<<"Node to root "<<endl;
    vector<int> ans=Node_to_root(t,80);
    cout<<"[";
    for(int i =0 ; i < ans.size(); i++)
    {
        cout<<ans[i];
        if(i!=ans.size()-1)
            cout<<", ";
    }
    cout<<"]";
    
   
   
    
    
   
   
  return 0;
}