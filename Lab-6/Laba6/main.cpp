#include <iostream>
#include "HashTable.cpp"

int main() {
    HashTable<string> hashTable(6);

    hashTable.add("key1", "first");
    hashTable.add("key10","second");
    hashTable.add("key3","third");
    hashTable.add("key4","fourth");
    hashTable.add("key5","fifth");
    hashTable.add("test","inserted");
    hashTable.add("key1231","seventh");
    hashTable.print();

    cout<<"-------------For loop-------------"<<endl;
    for(auto item = hashTable.begin(); item!=hashTable.end(); ++item)
    {
        cout<<"Key: "<<item->key<<" Value: "<<item->value<<endl;
    }

    HashTable<string>::Iterator item = hashTable.begin();
    cout<<endl<<"-------------While loop-------------"<<endl;
    while(!item.isEnd())
    {
        cout<<"Key: "<<item->key<<" Value: "<<item->value<<endl;
        ++item;
    }

    cout<<endl<<"Fullness coefficient: "<<hashTable.getFullnessCoefficient()<<endl;
    return 0;
}
