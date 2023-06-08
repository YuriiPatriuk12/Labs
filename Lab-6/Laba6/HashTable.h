#include <iostream>
using namespace std;

template <typename T>
struct Node {
    string key;
    T value;
    Node* next;
    Node(const string& k, const T& v) : key(k), value(v), next(nullptr) {}
};

template <typename T>
class HashTable {
private:
    Node<T>** table;
    int tableSize;
    int amountOfElements = 0;

public:
    class Iterator {
    private:
        const HashTable& hashTable;
        int currentBucket;
        Node<T>* currentNode;

    public:
        Iterator(const HashTable& ht, int bucket, Node<T>* node) : hashTable(ht), currentBucket(bucket), currentNode(node) {}
        bool operator!=(const Iterator& other) const {
            return currentNode != other.currentNode;
        }
        Iterator& operator++() {
            if (currentNode->next != nullptr) {
                currentNode = currentNode->next;
            }
            else {
                ++currentBucket;
                while (currentBucket < hashTable.tableSize && hashTable.table[currentBucket] == nullptr) {
                    ++currentBucket;
                }
                if (currentBucket < hashTable.tableSize)
                    currentNode = hashTable.table[currentBucket];
                else
                    currentNode = nullptr;
            }
            return *this;
        }
        Node<T>* operator->() const {
            return currentNode;
        }
        bool isEnd() const
        {
            return currentNode == nullptr;
        }
    };

    HashTable(int size);
    ~HashTable();
    void add(const string& key, const T& value);
    void del(const string& key);

    Iterator begin() const {
        int bucket = 0;
        while (bucket < tableSize && table[bucket] == nullptr) {
            ++bucket;
        }
        if (bucket < tableSize) {
            return Iterator(*this, bucket, table[bucket]);
        } else {
            return end();
        }
    }
    Iterator end() const {
        return Iterator(*this, tableSize, nullptr);
    }

    void printChain(Node<T>* head) const;
    void print() const;
    int getSize() const;
    float getFullnessCoefficient() const;

private:
    int hashFunction(const string& key) const;
};
