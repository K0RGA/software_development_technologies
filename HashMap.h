#ifndef LAB1_HASHMAP_H
#define LAB1_HASHMAP_H

#include <cstddef>
#include "KeyHash.h"
#include "HashNode.h"
#include <memory>

template<typename K, typename V, typename F = KeyHash<K>>
class HashMap {

private:
    HashNode<K, V> **table;
    F hashFunc;
    int const TABLE_SIZE = 30;
public:
    HashMap() {
        table = new HashNode<K, V> *[TABLE_SIZE]();
    }

    V operator[](const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *entry = table[hashValue];

        return entry->getValue();
    }

    void put(const K &key, const V &value) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            entry = new HashNode<K, V>(key, value);
            if (prev == NULL) {
                table[hashValue] = entry;
            } else {
                prev->setNext(entry);
            }
        } else {
            entry->setValue(value);
        }
    }

    void remove(const K &key) {
        unsigned long hashValue = hashFunc(key);
        HashNode<K, V> *prev = NULL;
        HashNode<K, V> *entry = table[hashValue];

        while (entry != NULL && entry->getKey() != key) {
            prev = entry;
            entry = entry->getNext();
        }

        if (entry == NULL) {
            return;
        } else {
            if (prev == NULL) {
                table[hashValue] = entry->getNext();
            } else {
                prev->setNext(entry->getNext());
            }
            delete entry;
        }
    }
};

#endif //LAB1_HASHMAP_H
