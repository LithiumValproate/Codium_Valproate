#include <climits>
#include <iostream>
#include <regex>
#include <queue>
#include <sstream>
using namespace std;
 
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {};
};

bool search(TreeNode* root, int value) {
    if (root == nullptr) return false;
    if (root->value == value) return true;
    if (value < root->value)
        return search(root->left, value);
    else
        return search(root->right, value);
}

TreeNode* insert(TreeNode* root, int value) {
    if (search(root, value))
        return root;
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

TreeNode* del(TreeNode* root, int value) {
    if (root == nullptr) return nullptr;
    if (value < root->value) {
        root->left = del(root->left, value);
    } else if (value > root->value) {
        root->right = del(root->right, value);
    } else {
        if (root->left == nullptr) {
            TreeNode* tmp = root->right;
            delete root;
            return tmp;
        } else if (root->right == nullptr) {
            TreeNode* tmp = root->left;
            delete root;
            return tmp;
        }
        TreeNode* tmp = root->right;
        while (tmp && tmp->left != nullptr) {
            tmp = tmp->left;
        }
        root->value = tmp->value;
        root->right = del(root->right, tmp->value);
    }
    return root;
}

bool is_full(TreeNode* root) {
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right == nullptr) return true;
    if (root->left != nullptr && root->right != nullptr)
        return is_full(root->left) && is_full(root->right);
    return false;
}

bool is_complete(TreeNode* root) {
    if (root == nullptr) return true;
    queue<TreeNode*> q;
    q.push(root);
    bool end = false;
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        if (node == nullptr) {
            end = true;
        } else {
            if (end) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}

void destroy(TreeNode* root) {
    if (root == nullptr) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

bool input(TreeNode*& root) {
    string line;
    getline(cin, line);
    if (line.empty()) return false;
    istringstream iss(line);
    string token;
    while (iss >> token) {
        if (!regex_match(token, regex("-?[0-9]+"))) {
            cout << "Please input integers only!" << endl;
            return false;
        }
        int value = stoi(token);
        if (value == -1) break;
        root = insert(root, value);
    }
    return true;
}

void show(TreeNode* root) {
    cout << "Preorder: \n";
    preorder(root);
    cout << endl;
    cout << "Inorder: \n";
    inorder(root);
    cout << endl;
    cout << "Postorder: \n";
    postorder(root);
    cout << endl;
    cout << "Level order: \n";
    levelorder(root);
    cout << endl;
    cout << "Count: " << count(root) << endl;
    cout << "Height: " << height(root) << endl;
    cout << "Sum: " << sum(root) << endl;
    cout << "Max: " << max(root) << endl;
    cout << "Min: " << min(root) << endl;
    cout << "Is full: " << (is_full(root) ? "Yes" : "No") << endl;
    cout << "Is complete: " << (is_complete(root) ? "Yes" : "No") << endl;
}

int main() {
    TreeNode* root = nullptr;
    cout << "Enter numbers to insert into the tree (end with -1): ";
    while (true) {
        if (!input(root))
            continue;
        else break;
    }
    cout << endl;
    show(root);
    int value, selectFunc;
    cout << "Select function:\n1. Delete\n2. Search\n";
    cin >> selectFunc;
    if (selectFunc == 1) {
        cout << "Enter value to delete: ";
        cin >> value;
        root = del(root, value);
        cout << "Deleted " << value << endl;
        show(root);
    } else if (selectFunc == 2) {
        cout << "Enter value to search: ";
        cin >> value;
        search(root, value) ? cout << "Found" : cout << "Not found";
    }
    else cout << "Invalid selection" << endl;
    destroy(root);
    cout << "Tree destroyed" << endl;
    system("pause");
    return 0;
}