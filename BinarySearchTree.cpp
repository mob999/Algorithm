#include<stdexcept>
#include<string>
#include<iostream>
template<typename K, typename V>
class BinarySearchTree{
private:
    struct TreeNode{
        K key;
        V val;
        int n;
        TreeNode* left;
        TreeNode* right;
        TreeNode(K k, V v, int N, TreeNode* l = nullptr,  TreeNode* r = nullptr): key(k), val(v), n(N), left(l), right(r) {}
    };
    TreeNode* root;
    V& get(TreeNode* x,const K& keyName);
    void insert(TreeNode*& x, const K& keyName, const V& valData);
    bool count(TreeNode* x,const K& keyName);
    TreeNode* floor(TreeNode* x, const K& keyName){
        if(x == nullptr)
            return nullptr;
        if(x->key == keyName)
            return x;
        if(x->key > keyName)
            return floor(x->left, keyName);
        auto t = floor(x->right, keyName);
        return t!=nullptr?t:x;
    }
    TreeNode* ceiling(TreeNode*x, const K& keyName){
        if(x == nullptr)
            return nullptr;
        if(x->key == keyName)
            return x;
        if(x->key < keyName)
            return ceiling(x->right, keyName);
        auto t = ceiling (x->left, keyName);
        return t!=nullptr?t:x;        
    }
    int rank(TreeNode* x, const K& keyName);
    void delMin(TreeNode*& x);
public:
    BinarySearchTree(): root(nullptr) {}
    int size(){ return size(root); }
    int size(TreeNode* x) { return ( x==nullptr?0:(x->n)); }
    V& operator [](const K& keyName){ return get(root, keyName); }
    void insert(const K& keyName, const V& valData){ insert(root, keyName, valData); }
    bool count(const K& keyName) { return count(root, keyName); }
    K min() { return min(root); }
    K max() { return max(root); }
    K floor(const K& keyName) { auto x = floor(root, keyName); return x==nullptr?nullptr:x->key; }
    K ceiling(const K& keyName) { auto x = ceiling(root, keyName); return x==nullptr?nullptr:x->key; }
    int rank(const K& keyName) { return rank(root, keyName); }
    void delMin() { delMin(root); }
};

template<typename K, typename V>
V& BinarySearchTree<K, V>::get(TreeNode* x, const K& keyName){
    if(x != nullptr){
        if(x->key == keyName)
            return x->val;
        return x->key>keyName?get(x->left, keyName):get(x->right, keyName);
    }
    throw std::out_of_range("key not exist in BST");
}

template<typename K, typename V>
void BinarySearchTree<K, V>::insert(TreeNode* &x,const K& keyName,const V& valData){
    if(x == nullptr)
        x = new TreeNode(keyName, valData, 1);
    if(x->key < keyName)
        insert(x->right, keyName, valData);
    else if(x->key > keyName)
        insert(x->left, keyName, valData);
    else x->val = valData;
    x->n = size(x->left) + size(x->right) + 1;
}

template<typename K, typename V>
bool BinarySearchTree<K, V>::count(TreeNode* x,const K& keyName){
    if(x->key == keyName)
        return true;
    if(x->left == nullptr && x->right == nullptr)
        return false;
    return keyName>x->key?count(x->right, keyName):count(x->left, keyName);
}

template<typename K, typename V>
int BinarySearchTree<K, V>::rank(TreeNode* x, const K& keyName){
    if(x == nullptr)
        return 0;
    if(keyName == x->key)
        return size(x->left);
    else if(keyName > x->key)
        return 1 + size(x->left) + rank(x->right, keyName);
    else return rank(x->left, keyName);
}

template<typename K, typename V>
void BinarySearchTree<K, V>::delMin(TreeNode*& x){
    if(x->left == nullptr){
        if(x == root){
            auto temp = root;
            root = root->right;
            delete temp;
            temp = nullptr;       
            return;
        }         
        delete(x);
        x = nullptr;
        return;
    }
    delMin(x->left);
    x->n = size(x->left) + size(x->right) + 1;
}

int main(){
    BinarySearchTree<std::string, int> bst;
    bst.insert("a", 4);
    bst.insert("b",9);
    bst.insert("dd",100);
    bst.delMin();
    std::cout <<bst.size();
}
    
// PT8SG36HK4X6
// SS9SYKNHKLHS
// QAQTHJNY35HW