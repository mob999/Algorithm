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
    void delMax(TreeNode*& x);
    TreeNode* select(TreeNode* x ,int index){
        if(x == nullptr) return nullptr;
        auto t = size(x->left);
        if(t > index) return select(x->left, index);
        else if(t < index) return select(x->right, index-t-1);
        else return x;
    }
    TreeNode* min(TreeNode* x){
        if(x->left == nullptr) return x;
        return min(x->left);
    }
    TreeNode* max(TreeNode* x){
        if(x->right == nullptr) return x;
        return max(x->right);
    }
public:
    BinarySearchTree(): root(nullptr) {}
    int size(){ return size(root); }
    int size(TreeNode* x) { return ( x==nullptr?0:(x->n)); }
    V& operator [](const K& keyName){ return get(root, keyName); }
    void insert(const K& keyName, const V& valData){ insert(root, keyName, valData); }
    bool count(const K& keyName) { return count(root, keyName); }
    K min() { auto m = min(root); return m->key; }
    K max() { auto m = max(root); return m->key; }
    K floor(const K& keyName) { auto x = floor(root, keyName); return x==nullptr?nullptr:x->key; }
    K ceiling(const K& keyName) { auto x = ceiling(root, keyName); return x==nullptr?nullptr:x->key; }
    int rank(const K& keyName) { return rank(root, keyName); }
    void delMin() { delMin(root); } 
    void delMax() { delMax(root); }
    void del(const K& keyName);
    K select(int index){ auto x = select(root, index); if(x == nullptr) throw std::out_of_range("select index not exist in BST"); return x->key; }
};

template<typename K, typename V>
using bstMap = BinarySearchTree<K, V>;

template<typename K, typename V>
V& BinarySearchTree<K, V>::get(TreeNode* x, const K& keyName){
    try{
        if(x != nullptr){
            if(x->key == keyName)
                return x->val;
            return x->key>keyName?get(x->left, keyName):get(x->right, keyName);
        }
        else throw std::out_of_range("key not exist in BST");
    }
    catch(std::out_of_range err){
        std::cerr << err.what();
    }
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

template<typename K, typename V>
void BinarySearchTree<K, V>::delMax(TreeNode*& x){
    if(x->right == nullptr){
        if(x == root){
            auto temp = root;
            root = root->left;
            delete temp;
            temp = nullptr;
            return;
        }
        delete(x);
        x = nullptr;   
        return; 
    }
    delMax(x->right);
    x->n = size(x->left) + size(x->right) + 1;
}

template<typename K, typename V>
void BinarySearchTree<K, V>::del(const K& keyName){
    TreeNode* delNode = root;    // ???????????????
    TreeNode* preNode = nullptr; // ??????????????????????????????
    /* while:???????????????keyName??????????????????????????? */
    while(delNode != nullptr){
        if(delNode->key == keyName) break;
        preNode = delNode;
        if(delNode->key > keyName) delNode = delNode->left;
        else delNode = delNode->right;
    }
    if(delNode == nullptr) return;
    /* ???????????????????????????????????? */
    auto temp = delNode;
    /* 1.???????????????????????? */
    if(delNode->left != nullptr && delNode->right != nullptr){
        auto s = delNode->left; // ???????????????????????????????????????????????????
        while(s->right){        // ????????????????????????????????????
            temp = s;
            s = s->right;
        }
        delNode->key = s->key; delNode->val = s->val; // ?????????????????????????????????????????????????????????
        if(temp != delNode)
            temp->right = s->left; // ?????????????????????????????????
        else temp->left = s->left;// ?????????????????????????????????
        delete s;
        s = nullptr;
        return;
    }
    else if(delNode->right == nullptr)
        delNode = delNode->left;
    else if(delNode->left == nullptr)
        delNode = delNode->right;
    if(preNode == nullptr)
        root = delNode;
    else if(temp == preNode->left)
        preNode->left = delNode;
    else preNode->right = delNode;
    delete temp;
    temp = nullptr;
}



int main(){
    bstMap<std::string, int> bst;
    bst.insert("e",5);
    bst.insert("c",3);
    bst.insert("g",7);
    bst.insert("d",4);
    bst.insert("b",2);
    bst.del("e");
    
}
    
// PT8SG36HK4X6
// SS9SYKNHKLHS
// QAQTHJNY35HW