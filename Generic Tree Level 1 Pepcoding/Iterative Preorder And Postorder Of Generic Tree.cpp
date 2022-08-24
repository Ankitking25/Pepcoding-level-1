#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    vector<Node *> children;
};

Node *construct(int *arr, int n)
{
    Node *root = new Node();
    root->data = arr[0];
    stack<Node *> st;
    st.push(root);

    for (int i = 1; i < n; i++)
    {
        if (arr[i] == -1)
        {
            st.pop();
        }
        else
        {
            Node *nn = new Node();
            nn->data = arr[i];
            st.top()->children.push_back(nn);
            st.push(nn);
        }
    }
    return root;
}

void iterativePreAndPostOrder(Node *node)
{
    stack<pair<Node*,int>> st;
    st.push({node,-1});
    string preorder = "";
    string postorder ="";
    while(st.size()!=0)
    {
        pair<Node*,int> top = st.top();
        st.pop();
        
        if(top.second==-1)
        {
            preorder+=(to_string)(top.first->data)+" ";
            top.second++;
            st.push(top);
        }
        else if(top.second==top.first->children.size())
        {
            postorder+=(to_string)(top.first->data)+" ";
            
        }
        else
        {
            pair<Node*,int> newPair(top.first->children[top.second],-1);
            top.second+=1;
            st.push(top);
            st.push(newPair);
         
        }
    }
    cout<<preorder<<endl;
    cout<<postorder<<endl;
}


int main()
{
    int n, m;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Node *root = construct(arr, n);
   iterativePreAndPostOrder(root);
    return 0;
}

/*

Sample Input

24
10 20 -50 -1 60 -1 -1 30 70 -1 -80 110 -1 -120 -1 -1 90 -1 -1 40 -100 -1 -1 -1

Sample Output
10 20 -50 60 30 70 -80 110 -120 90 40 -100 
-50 60 20 70 110 -120 -80 90 30 -100 40 10





*/