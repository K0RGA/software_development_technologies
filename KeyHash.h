#ifndef LAB1_KEYHASH_H
#define LAB1_KEYHASH_H

template <typename K>
struct KeyHash {
    int const TABLE_SIZE = 30;
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<int>(key) % TABLE_SIZE;
    }
};

#endif //LAB1_KEYHASH_H
