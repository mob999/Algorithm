// 基于二叉堆的优先队列
// @github.com/mob999
#ifndef MAXPQBR
#define MAXPQBR
#include"sqList.cpp"
template<typename T>
class MaxPQBR{
private:
    SqList<T> val;// 顺序表作为完全二叉堆的存储方式 @sqList.cpp
                  // val[0]不存储数据
                  // 无需维护其它变量如size，因为在sqlist.cpp中均已实现
    /*---------------------------------------------*/
    /* 
     * 由下至上的堆有序化（上浮）
     * 插入新结点时若某个结点变得比其父节点大，堆的有序态就会被打破
     * 通过上浮使堆恢复有序态
    */
    /*---------------------------------------------*/
    void swim(unsigned index);
    /*---------------------------------------------*/
    /*
     * 由上至下的堆有序化（下沉）
     * 删除最大结点时若某个结点变得比其子结点小，堆的有序态就会被打破
     * 通过下沉使堆恢复有序态
     */
    void sink(unsigned index);
public:
    /*---------------------------------------------*/
    /* 创建一个最大容量为maxsize的默认优先队列*/
    MaxPQBR(unsigned maxSize=DEFAULT_SIZE);
    /*---------------------------------------------*/
    /* 通过标准输入流创建一个最大容量为maxsize的优先队列*/
    MaxPQBR(std::istream&, unsigned maxSize=DEFAULT_SIZE);
    /*---------------------------------------------*/
    /* 通过std::vector创建一个最大容量为maxsize的优先队列*/
    MaxPQBR(const std::vector<T>& arr, unsigned maxSize=DEFAULT_SIZE);
    /*---------------------------------------------*/
    /* 当优先队列为空时返回值为真 */
    bool empty();
    /*---------------------------------------------*/
    /* 返回优先队列当前长度 */
    unsigned size();
    /*---------------------------------------------*/
    /* 向优先队列中添加一个元素 */
    void insert(const T&);
    /*---------------------------------------------*/
    /* 返回优先队列最大值 */
    T max();
    /*---------------------------------------------*/
    /* 返回并删除优先队列最大值 */
    T delMax();
    /*---------------------------------------------*/
    /* 遍历优先队列 */
    friend void traverse(MaxPQBR<T>& pq, std::ostream& os=std::cout){for(auto i = pq.val.begin(); i < pq.val.end(); i++){os << *i << ' ';}}
    ~MaxPQBR()=default;
};

template<typename T>
void swap(T& a, T& b);

template<typename T>
void MaxPQBR<T>::swim(unsigned index){
    while(index > 1 && val[index/2] < val[index]){
        swap(val[index/2], val[index]);
        index /= 2;
    }
}

template<typename T>
void MaxPQBR<T>::sink(unsigned index){
    while(2*index <= size() -1){
        int son = 2*index;
        if(son < size() && val[son] < val[son+1])
            son++;
        if(val[index] >= val[son])
            break;
        swap(val[index], val[son]);
        index = son;
    }
}

template<typename T>
MaxPQBR<T>::MaxPQBR(unsigned maxSize):val(maxSize){}    

template<typename T>
MaxPQBR<T>::MaxPQBR(std::istream& is, unsigned maxSize):val(maxSize){
    T data;
    while(is >> data){
        insert(data);
    }
}

template<typename T>
MaxPQBR<T>::MaxPQBR(const std::vector<T>& arr, unsigned maxSize):val(maxSize){
    for(auto i : arr){
        insert(i);
    }
}

template<typename T>
bool MaxPQBR<T>::empty(){
    return val.empty();
}

template<typename T>
unsigned MaxPQBR<T>::size(){
    return val.size();
}

template<typename T>
void MaxPQBR<T>::insert(const T& data){
    val.pushBack(data);
    swim(size() - 1);
}

template<typename T>
T MaxPQBR<T>::max(){
    return val[1];
}

template<typename T>
T MaxPQBR<T>::delMax(){
    T del = val[1];
    swap(val[1], val[size() - 1]);
    val.erase(size() - 1);
    sink(1);
    return del;
}

template<typename T>
void swap(T& a, T& b){
    T temp = a;
    a = b;
    b = temp;
}

#endif