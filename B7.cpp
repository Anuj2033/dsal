#include <iostream>
#include <stack>
#include <string>
using namespace std;

// TreeNode class represents a node in the binary tree
class TreeNode {
public:
    char value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char val) : value(val), left(nullptr), right(nullptr) {}
};

// Function to check if a character is an operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to construct a binary tree from a prefix expression
TreeNode* constructTree(string prefix) {
    stack<TreeNode*> st;
    TreeNode* root = nullptr;

    // Process the expression from right to left
    for (int i = prefix.length() - 1; i >= 0; --i) {
        char c = prefix[i];
        TreeNode* newNode = new TreeNode(c);

        // If the character is an operator, pop two nodes from stack and set them as children
        if (isOperator(c)) {
            newNode->left = st.top();
            st.pop();
            newNode->right = st.top();
            st.pop();
        }

        st.push(newNode);
    }

    // The top of the stack will be the root of the tree
    root = st.top();
    st.pop();

    return root;
}

// Function to display the binary tree in postorder
void postorder(TreeNode* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";

}

int main() {
    string prefix = "*+AB-CD";

    TreeNode* root = constructTree(prefix);

    // Display the tree in postorder
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;

    // Remember to deallocate memory
    delete root;

    return 0;
}
