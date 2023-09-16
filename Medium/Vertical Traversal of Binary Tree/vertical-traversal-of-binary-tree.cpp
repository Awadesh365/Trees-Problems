//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
       // Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root) {
        map<int, map<int, vector<int>>> nodes; // Use vectors to store values at each position

        // Initialize the queue with the root node and its position (vertical and horizontal)
        queue<pair<Node *, pair<int, int>>> todoList;
        todoList.push({root, {0, 0}});

        while (!todoList.empty()) {
            auto curNode = todoList.front();
            todoList.pop();
            Node *node = curNode.first;
            int vertical = curNode.second.first;
            int horizontal = curNode.second.second;

            nodes[vertical][horizontal].push_back(node->data); // Push the node's value into the vector

            if (node->left != nullptr)
                todoList.push({node->left, {vertical - 1, horizontal + 1}});

            if (node->right != nullptr)
                todoList.push({node->right, {vertical + 1, horizontal + 1}});
        }

        vector<int> ans;

        // Traverse the nodes map and add values to the result
        for (auto &verticalLevel : nodes) {
            for (auto &horizontalLevel : verticalLevel.second) {
                for (int val : horizontalLevel.second) {
                    ans.push_back(val);
                }
            }
        }

        return ans;
    }
   
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    }
	return 0;
}



// } Driver Code Ends