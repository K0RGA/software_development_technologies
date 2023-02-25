#ifndef SOFTWARE_DEVELOPMENT_TECHNOLOGIES_HASHNODE_H
#define SOFTWARE_DEVELOPMENT_TECHNOLOGIES_HASHNODE_H

#include <cstddef>
#include "memory"

template<typename K, typename V>
class HashNode {

private:
    K key;
    V value;
    HashNode *next;
public:
    HashNode(const K &key, const V &value) :
            key(key), value(value), next(NULL) {
    }

    K getKey() const {
        return key;
    }

    V getValue() const {
        return value;
    }

    void setValue(V value) {
        HashNode::value = value;
    }

    HashNode *getNext() const {
        return next;
    }

    void setNext(HashNode *next) {
        HashNode::next = next;
    }
};

#endif //SOFTWARE_DEVELOPMENT_TECHNOLOGIES_HASHNODE_H
