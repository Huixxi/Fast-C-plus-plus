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



