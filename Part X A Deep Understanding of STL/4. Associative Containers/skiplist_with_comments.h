//
// Created by hugo on 20-4-24.
// Copy from https://gist.github.com/unsuthee/4116663
//

#ifndef SKIPLIST_WITH_COMMENTS_H
#define SKIPLIST_WITH_COMMENTS_H

#include <iostream>
#include <sstream>

template <class K, class V, int MAXLEVEL>
class skiplist_node {
    K key;
    V value;
    // forwards[], 存放该节点在各层级的下一节点
    skiplist_node<K, V, MAXLEVEL>* forwards[MAXLEVEL + 1];

public:
    skiplist_node() {
        for(int i = 1; i <= MAXLEVEL; ++i)
            forwards[i] = nullptr;
    }

    skiplist_node(K searchKey) : key(searchKey) {
        for(int i = 1; i <= MAXLEVEL; ++i)
            forwards[i] = nullptr;
    }

    skiplist_node(K searchKey, V val) : key(searchKey), value(val) {
        for(int i = 1; i <= MAXLEVEL; ++i)
            forwards[i] = nullptr;
    }
};

template <class K, class V, int MAXLEVEL = 16>
class skiplist {
protected:
    K m_minKey;
    K m_maxKey;
    int max_curr_level;
    skiplist_node<K, V, MAXLEVEL>* m_pHeader;
    skiplist_node<K, V, MAXLEVEL>* m_pTail;

    double uniformRandom() {
        return rand() / double(RAND_MAX);
    }

    int randomLevel() {
        int level = 1;
        double p = 0.5;
        while(uniformRandom() < p && level < MAXLEVEL)
            ++level;
        return level;
    }

public:
    const int max_level;

    typedef K KeyType;
    typedef V ValueType;
    typedef skiplist_node<K, V, MAXLEVEL> NodeType;

    skiplist(K minKey, K maxKey) : m_pHeader(nullptr), m_pTail(nullptr), max_curr_level(1), max_level(MAXLEVEL), m_maxKey(maxKey), m_minKey(minKey) {
        m_pHeader = new NodeType(m_minKey);
        m_pTail = new NodeType(m_maxKey);
        for(int i = 1; i <= MAXLEVEL; ++i)
            m_pHeader->forwards[i] = m_pTail;
    }

    virtual ~skiplist() {
        NodeType* currNode = m_pHeader->forwards[1];
        while(currNode != m_pTail) {
            NodeType* tempNode = currNode;
            currNode = currNode->forwards[1];
            delete tempNode;
        }
        delete m_pHeader;
        delete m_pTail;
    }


    void insert(K searchKey, V newValue) {
        skiplist_node<K, V, MAXLEVEL>* update[MAXLEVEL];
        NodeType* currNode = m_pHeader;
        for(int level = max_curr_level; level >= 1; --level) {
            while(currNode->forwards[level]->key < searchKey)
                currNode = currNode->forwards[level];
            update[level] = currNode;
        }
        currNode = currNode->forwards[1];
        if(currNode->key == searchKey)
            currNode->value = newValue;
        else {
            int newlevel = randomLevel();
            if(newlevel > max_curr_level) {
                for(int level = max_curr_level + 1; level <= newlevel; ++level)
                    update[level] = m_pHeader;
                max_curr_level = newlevel;
            }
            currNode = new NodeType(searchKey, newValue);
            for(int lv = 1; lv <= max_curr_level; ++lv) {
                currNode->forwards[lv] = update[lv]->forwards[lv];
                update[lv]->forwards[lv] = currNode;
            }
        }
    }

    void erase(K searchKey) {
        skiplist_node<K, V, MAXLEVEL>* update[MAXLEVEL];
        NodeType* currNode = m_pHeader;
        for(int level = max_curr_level; level >= 1; --level) {
            while(currNode->forwards[level]->key < searchKey)
                currNode = currNode->forwards[level];
            update[level] = currNode;
        }
        currNode = currNode->forwards[1];
        if(currNode->key == searchKey) {
            for(int lv = 1; lv < max_curr_level; ++lv) {
                if(update[lv]->forwards[lv] != currNode)
                    break;
                update[lv]->forwards[lv] = currNode->forwards[lv];
            }
            delete currNode;
            // update the max_level
            while(max_curr_level > 1 && m_pHeader->forwards[max_curr_level] == NULL)
                --max_curr_level;
        }
    }


    const NodeType* find(K searchKey) {
        NodeType* currNode = m_pHeader;
        for(int level = max_curr_level; level >= 1; --level) {
            while(currNode->forwards[level]->key < searchKey)
                currNode = currNode->forwards[level];
        }
        currNode = currNode->forwards[1];
        if(currNode->key == searchKey)
            return currNode;
        else
            return nullptr;
    }

    bool empty() const {
        return (m_pHeader->forwards[1] == m_pTail);
    }

    std::string printList() {
        std::stringstream sstr;
        NodeType* currNode = m_pHeader->forwards[1];
        while(currNode != m_pTail) {
            sstr << "(" << currNode->key << "," << currNode->value << ")" << endl;
            currNode = currNode->forwards[1];
        }
        return sstr.str();
    }
};

#endif //SKIPLIST_WITH_COMMENTS_H
