#include<stack>
#include<string>
#include<iostream>

using std::stack;
using std::string;
using std::cout;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* l, TreeNode* r) : val(x), left(l), right(r) {}
};

struct Command{
    string action;
    TreeNode* node;
    Command(string a, TreeNode* n): action(a), node(n) {}
};


void traverse(TreeNode* root){
    stack<Command> sta;
    sta.push(Command("go", root));
    while(!sta.empty()){
        auto cmd = sta.top();
        sta.pop();
        if(cmd.action == "print" && cmd.node != nullptr)
            std::cout << cmd.node->val << ' ';
        else if(cmd.node == nullptr)
            std::cout << "null" << ' ';
        else if(cmd.action == "go"){
            sta.push(Command("go", cmd.node->right));
            sta.push(Command("go", cmd.node->left));
            sta.push(Command("print", cmd.node));
        }          
    }
}

TreeNode* creatBinaryTree(std::istream& is){
    int data;
    is >> data;
    if(data == 0)
        return nullptr;
    TreeNode* root = new TreeNode(data);
    root->left = creatBinaryTree(is);
    root->right = creatBinaryTree(is);
    return root;
}

int main(){
    TreeNode* tree = creatBinaryTree(std::cin);
    traverse(tree);
}