#include "HashTable.h"

template <typename T>
HashTable<T>::HashTable(int size): tableSize(size) {
    table = new Node<T>*[tableSize];
    for (int i = 0; i < tableSize; ++i) {
        table[i] = nullptr;
    }
}

template<typename T>
HashTable<T>::~HashTable() {
    for (int i = 0; i < tableSize; ++i) {
        Node<T>* currentNode = table[i];
        while (currentNode != nullptr) {
            Node<T>* nextNode = currentNode->next;
            delete currentNode;
            currentNode = nextNode;
        }
    }
    delete[] table;
}

template<typename T>
void HashTable<T>::add(const string &key, const T &value)
{
    int bucket = hashFunction(key);
    Node<T>* newNode = new Node<T>(key, value);
    if (table[bucket] == nullptr) {
        table[bucket] = newNode;
    } else {
        Node<T>* currentNode = table[bucket];
        while (currentNode->next != nullptr) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
    amountOfElements++;
}

template<typename T>
void HashTable<T>::del(const string &key)  {
    int bucket = hashFunction(key);
    Node<T>* currentNode = table[bucket];
    Node<T>* prevNode = nullptr;

    while (currentNode != nullptr && currentNode->key != key) {
        prevNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == nullptr) {
        return;
    }

    if (prevNode == nullptr) {
        table[bucket] = currentNode->next;
    } else {
        prevNode->next = currentNode->next;
    }

    delete currentNode;
    amountOfElements--;
}

template <typename T>
void HashTable<T>::printChain(Node<T> *head) const  {
    if(head == NULL) {
        cout << endl;
        return;
    }
    cout<<'['<<head->key<<':'<<head->value<<']';
    if(head->next != NULL)
        cout<<"->";
    printChain(head->next);
}

template <typename T>
void HashTable<T>::print() const {
    for (int i = 0; i < tableSize; ++i) {
        cout<<i<<':';
        printChain(table[i]);
    }
    cout<<endl;
}

template<typename T>
int HashTable<T>::hashFunction(const string&key) const  {
    return hash<string>{}(key) % tableSize;
}

template<typename T>
float HashTable<T>::getFullnessCoefficient() const {
    return (float)amountOfElements/tableSize;
}

template<typename T>
int HashTable<T>::getSize() const {
    return this->tableSize;
}

