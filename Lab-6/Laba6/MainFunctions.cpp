#include "MainFunctions.h"

void intMenuCode(int size)
{
    HashTable<int> hashTable(size);
    char choice;
    do{
        cout<<"Do you want to add element (y/n):";
        cin>>choice;
        if(choice=='y')
        {
            string key; int elem;
            cout<<"Enter key(string):";
            cin>>key;
            cout<<"Enter value:";
            cin>>elem;
            hashTable.add(key,elem);
        }
        else if(choice!='n')
            cout<<"Incorrect choice!"<<endl;
    }while(choice!='n');
    hashTable.print();
    cout<<"-------------For loop-------------"<<endl;
    for(auto item = hashTable.begin(); item!=hashTable.end(); ++item)
    {
        cout<<"Key: "<<item->key<<" Value: "<<item->value<<endl;
    }
    HashTable<int>::Iterator item = hashTable.begin();
    cout<<endl<<"-------------While loop-------------"<<endl;
    while(!item.isEnd())
    {
        cout<<"Key: "<<item->key<<" Value: "<<item->value<<endl;
        ++item;
    }
    cout<<endl<<"Fullness coefficient: "<<hashTable.getFullnessCoefficient()<<endl;

}

void stringMenuCode(int size)
{
    HashTable<string> hashTable(size);
    char choice;
    do{
        cout<<"Do you want to add element (y/n):";
        cin>>choice;
        if(choice=='y')
        {
            string key; string elem;
            cout<<"Enter key(string):";
            cin>>key;
            cout<<"Enter value:";
            cin>>elem;
            hashTable.add(key,elem);
        }
        else if(choice!='n')
            cout<<"Incorrect choice!"<<endl;
    }while(choice!='n');
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
}

void floatMenuCode(int size)
{
    HashTable<float> hashTable(size);
    char choice;
    do{
        cout<<"Do you want to add element (y/n):";
        cin>>choice;
        if(choice=='y')
        {
            string key; float elem;
            cout<<"Enter key(string):";
            cin>>key;
            cout<<"Enter value:";
            cin>>elem;
            hashTable.add(key,elem);
        }
        else if(choice!='n')
            cout<<"Incorrect choice!"<<endl;
    }while(choice!='n');
    hashTable.print();
    cout<<"-------------For loop-------------"<<endl;
    for(auto item = hashTable.begin(); item!=hashTable.end(); ++item)
    {
        cout<<"Key: "<<item->key<<" Value: "<<item->value<<endl;
    }
    HashTable<float>::Iterator item = hashTable.begin();
    cout<<endl<<"-------------While loop-------------"<<endl;
    while(!item.isEnd())
    {
        cout<<"Key: "<<item->key<<" Value: "<<item->value<<endl;
        ++item;
    }
    cout<<endl<<"Fullness coefficient: "<<hashTable.getFullnessCoefficient()<<endl;
}