#include <climits>
#include <iostream>
#include <queue>
using namespace std;
 
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {};
};

TreeNode* insert(TreeNode* root, int value) {
    if (root == nullptr) return new TreeNode(value);
    if (value < root->value)
        root->left = insert(root->left, value);
    else if (value > root->value)
        root->right = insert(root->right, value);
    return root;
}

void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

void postorder(TreeNode* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

void levelorder(TreeNode* root) {
    if (root == nullptr) return;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        cout << node->value << " ";
        if (node->left != nullptr) q.push(node->left);
        if (node->right != nullptr) q.push(node->right);
    }
}

int count(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + count(root->left) + count(root->right);
}

int height(TreeNode* root) {
    if (root == nullptr) return 0;
    return 1 + max(height(root->left), height(root->right));
}

int sum(TreeNode* root) {
    if (root == nullptr) return 0;
    return root->value + sum(root->left) + sum(root->right);
}

int max(TreeNode* root) {
    if (root == nullptr) return INT_MIN;
    return std::max(root->value, std::max(max(root->left), max(root->right)));
}

int min(TreeNode* root) {
    if (root == nullptr) return INT_MAX;
    return std::min(root->value, std::min(min(root->left), min(root->right)));
}

bool search(TreeNode* root, int value) {
    if (root == nullptr) return false;
    if (root->value == value) return true;
    if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

void destroy(TreeNode* root) {
    if (root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    TreeNode* root = nullptr;
    cout << "Enter numbers to insert into the tree (end with -1): ";
    int value;
    while (cin >> value && value != -1) {
        root = insert(root, value);
    }
    cout << endl;
    cout << "Preorder: ";
    preorder(root);
    cout << endl;
    cout << "Inorder: ";
    inorder(root);
    cout << endl;
    cout << "Postorder: ";
    postorder(root);
    cout << endl;
    cout << "Level order: ";
    levelorder(root);
    cout << endl;
    cout << "Count: " << count(root) << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Sum: " << sum(root) << endl;
    cout << "Max: " << max(root) << endl;
    cout << "Min: " << min(root) << endl;
    cout << "Search for: ";
    cin >> value;
    search(root, value) ? cout << "Found" : cout << "Not found";
    cout << endl;
    destroy(root);
    cout << "Tree destroyed." << endl;
    system("pause");
    return 0;
}