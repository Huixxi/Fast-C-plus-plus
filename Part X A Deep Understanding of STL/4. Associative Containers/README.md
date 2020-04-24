## Associative Containers
Each element has a **key** and a **value**. In general, in order to get a good search efficient, its inner structure is a **balanced binary tree**, such as **AVL-Tree, RB-Tree, AA-Tree**.   

**Associatice Containers**  
* RB-tree (non-public)
  * set (contains an RB-tree)
  * map (contains an RB-tree)
  * multiset (contains an RB-tree)
  * multimap (contains an RB-tree)
* hashtable (non-std)
  * hash_set (contains a hashtable)(non-std)
  * hash_map (contains a hashtable)(non-std)
  * hash_multiset (contains a hashtable)(non-std)
  * hash_multimap (contains a hashtable)(non-std)
  
___
  
## Tree
* Binary Search Tree
* Balanced Binary Search Tree
  * AVL Tree (Adelson-Velskii-Lands Tree)
    * Single Rotation (outside insert)
    * Double Rotation (inside insert)
  * RB Tree

## RB Tree
* Each node is either red or black.
* Root node is black.
* If a node is red, its sub-node must be black.
* Any path that from any node to NULL, must include the same number black node.

According to rule 4, the newly insert node must be red; according to rule 3, the newly insert node's parent node must be black.  

### Set
```c++
template <class Key, class Compare = less<Key>, class Alloc = alloc>  // 缺省采用递增排序
class set {
    // ...
    insert_unique() { // ... }
};
```

### map
```c++
template <class Key, class Compare = less<Key>, class Alloc = alloc>  // 缺省采用递增排序
class map {
    // ...
    insert_unique() { // ... }
};
```

### multiset
```c++
template <class Key, class Compare = less<Key>, class Alloc = alloc>  // 缺省采用递增排序
class multiset {
    // ...
    insert_equal() { // ... }
};
```

### multimap
```c++
template <class Key, class Compare = less<Key>, class Alloc = alloc>  // 缺省采用递增排序
class multimap {
    // ...
    insert_equal() { // ... }
};
```

## hashtable(散列表)
二叉搜索树具有对数平均时间，依赖“输入数据有足够的随机性”的前提，而hashtable散列表在插入，删除，搜寻等操作上具有“常数平均时间”，牺牲内存空间和初始化时间，换取时间上的效率，而不需要依赖这一前提。   
**索引相同造成的碰撞问题**   
**负载系数（loading factor）**：指元素个数除以表格大小，负载系数永远在0～1之间。  
* 线性探测（linear probing），假设表格足够大；每个元素都足够独立。会造成平均插入成本的成长幅度远高于负载系数的成长幅度。  
* 二次探测（quadratic probing），用于解决主集团问题（primary clustering）。若hash function计算出新元素的位置为H，且这一位置实际上已被占用，我们则依序尝试`H+1^2, H+2^2, H+3^2, .. H+i^2`. 而不是像线性探测那样`H+1, H+2, H+3, .. H+i`。当表格大小设置为质数，且永远保持负载系数低于0.5，则每插入一个新元素所需要探测的次数不多于2。此方法可以消除主集团，但可能造成次集团，可使用复式散列解决。 
* 开链算法（separate chaining），在每个表格元素中维护一个list，hash function为我们分配一个list，我们在这个list上执行元素插入，删除等操作。

```c++
template <class Value, class Key, class HashFcn, class ExtractKey, class EqualKey, class Alloc = alloc>
class hashtable {
    // ...
    insert_unique() { // ... } or insert_equal() { // ... }
}
```

### hash_set
```c++
template <class Value, class HashFcn = hash<Value>, class ExtractKey = equal_to<Value>, class Alloc = alloc>
class hash_set {
    // ...
    insert_unique() { // ... } 
}
```

### hash_map
```c++
template <class Key, class T, class HashFcn = hash<Value>, class ExtractKey = equal_to<Value>, class Alloc = alloc>
class hash_map {
    // ...
    insert_unique() { // ... } 
}
```

### hash_multiset
```c++
template <class Value, class HashFcn = hash<Value>, class ExtractKey = equal_to<Value>, class Alloc = alloc>
class hash_multiset {
    // ...
    insert_equal() { // ... } 
}
```

### hash_multimap
```c++
template <class Key, class T, class HashFcn = hash<Value>, class ExtractKey = equal_to<Value>, class Alloc = alloc>
class hash_map {
    // ...
    insert_equal() { // ... } 
}
```

___

## String
String 类的实现。


## Skiplist(跳表)
跳表的实现。



