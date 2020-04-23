//
// Created by hugo on 20-4-23.
//

#ifndef WEEK1_STL_RB_TREE_H
#define WEEK1_STL_RB_TREE_H

#include <cstddef>

/* RB-Tree Node */
typedef bool __rb_tree_color_type;
const __rb_tree_color_type __rb_tree_red = false;
const __rb_tree_color_type __rb_tree_black = true;

struct __rb_tree_node_base {
    typedef __rb_tree_color_type color_type;
    typedef __rb_tree_node_base* base_ptr;

    color_type color;
    base_ptr parent;
    base_ptr left;
    base_ptr right;

    static base_ptr minimum(base_ptr x) {
        while(x->left != nullptr)
            x = x->left;
        return x;
    }

    static base_ptr maximum(base_ptr x) {
        while(x->right != nullptr)
            x = x->right;
        return x;
    }
};

template <class Value>
struct __rb_tree_node : public __rb_tree_node_base{
    typedef __rb_tree_node<Value>* link_type;
    Value value_field;  // 节点值
};

/* RB-Tree's Iterator */
struct __rb_tree_base_iterator {
    typedef __rb_tree_node_base::base_ptr base_ptr;
    typedef bidirectional_iterator_tag iterator_category;
    typedef ptrdiff_t difference_type;
    base_ptr node;

    void increment() {
        if(node->right != nullptr) {
            node = node->right;
            while(node->left != nullptr)
                node = node->left;
        }
        else {
            base_ptr y = node->parent;
            while(node == y->right) {
                node = y;
                y = y->parent;
            }
            if(node->right != y)
                node = y;
        }
    }

    void decrement() {
        if(node->color != __rb_tree_red && node->parent->parent == node)
            node = node->right;
        else if(node->left != nullptr) {
            base_ptr y = node->left;
            while(y->right != nullptr) {
                y = y->right;
                node = y;
            }
            if(node->right != y)
                node = y;
        }
        else {
            base_ptr y = node->parent;
            while(node == y->right) {
                node = y;
                y = y->parent;
            }
            node = y;
        }
    }
};

template <class Value, class Ref, class Ptr>
struct __rb_tree_iterator : public __rb_tree_base_iterator {
    typedef Value value_type;
    typedef Ref reference;
    typedef Ptr pointer;
    typedef __rb_tree_iterator<Value, Value&, Value*> iterator;
    typedef __rb_tree_iterator<Value, const Value&, const Value*> const_iterator;
    typedef __rb_tree_iterator<Value, Ref, Ptr> self;
    typedef __rb_tree_iterator<Value, Ref, Ptr>* link_type;

    __rb_tree_iterator() {}
    __rb_tree_iterator(link_type x) { node = x; }
    __rb_tree_iterator(const iterator& it) { node = it.node; }

    reference operator*() const { return link_type(node)->value_field; }

# ifndef __SGI_STL_NO_ARROW_OPERATOR
    pointer operator->() const { return &(operator*()); }
# endif

    self& operator++() {increment(); return *this; }
    self operator++(int) {
        self tmp = *this;
        increment();
        return tmp;
    }

    self& operator--() {decrement(); return *this; }
    self operator--(int) {
        self tmp = *this;
        decrement();
        return tmp;
    }
};


/*
 x          y
  \  -->   /
   y      x
 */
inline void __rb_tree_rotate_left(__rb_tree_node_base* x, __rb_tree_node_base*& root) {
    // x为旋转点
    __rb_tree_node_base* y = x->right;
    x->right = y->left;
    if(y->left)
        y->left->parent = x;
    y->parent = x->parent;

    if(x == root)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

/*
  x       y
 /   -->   \
y           x
 */
inline void __rb_tree_rotate_right(__rb_tree_node_base* x, __rb_tree_node_base*& root) {
    // x为旋转点
    __rb_tree_node_base* y = x->left;
    x->left = y->right;
    if(y->right)
        y->right->parent = x;
    y->parent = x->parent;

    if(x == root)
        root = y;
    else if(x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->right = x;
    x->parent = y;
}

// 每次插入操作， 插入节点完毕后都要进行一次调整操作使之满足RB-tree的要求
inline void __rb_tree_rebalance(__rb_tree_node_base* x, __rb_tree_node_base*& root) {
    x->color = __rb_tree_red;  // 新节点必须为红
    while(x != root && x->parent->color == __rb_tree_red) {  // P节点为红
        if(x->parent == x->parent->parent->left) { // P为G的左子节点
            __rb_tree_node_base* y = x->parent->parent->right;  // 令y为S节点
            if(y && y->color == __rb_tree_red) {
                x->parent->color = __rb_tree_black;
                y->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                x = x->parent->parent;
            }
            else {
                if(x == x->parent->right) {
                    x = x->parent;
                    __rb_tree_rotate_left(x, root);
                }
                x->parent->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                __rb_tree_rotate_right(x->parent->parent, root);
            }
        }
        else {
            __rb_tree_node_base* y = x->parent->parent->left;  // 令y为S节点
            if(y && y->color == __rb_tree_red) {
                x->parent->color = __rb_tree_black;
                y->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                x = x->parent->parent;
            }
            else {
                if(x == x->parent->left) {
                    x = x->parent;
                    __rb_tree_rotate_right(x, root);
                }
                x->parent->color = __rb_tree_black;
                x->parent->parent->color = __rb_tree_red;
                __rb_tree_rotate_left(x->parent->parent, root);
            }
        }
    }
    root->color = __rb_tree_black;
}

#endif //WEEK1_STL_RB_TREE_H
