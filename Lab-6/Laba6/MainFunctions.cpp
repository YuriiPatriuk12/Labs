#include "MainFunctions.h"
#include <iomanip>

void intMenuCode(int size)
{
    HashTable<int> hashTable(size);
    int menuChoose = 0;
    do {
        menuChoose = showUserMenu();
        switch(menuChoose)
        {
            case 1:
            {
                char choice = 'y';
                do {
                    if (choice == 'y') {
                        string key;
                        int elem;
                        cout << "Enter key(string):";
                        cin >> key;
                        cout << "Enter value:";
                        cin >> elem;
                        hashTable.add(key, elem);
                    } else if (choice != 'n')
                        cout << "Incorrect choice!" << endl;
                    cout << "Do you want to add element (y/n):";
                    cin >> choice;
                } while (choice != 'n');
                cout<<endl;
            }
                break;
            case 2:
            {
                string key;
                cout<<"Enter key:";
                cin>>key;
                hashTable.del(key);
                cout<<"Done"<<endl<<endl;
            }
                break;
            case 3:
                hashTable.print();
            break;
            case 4:
            {
                for (auto item = hashTable.begin(); item != hashTable.end(); ++item) {
                    cout << "Key: " << item->key << " Value: " << item->value << endl;
                }
                cout<<endl;
            }
                break;
            case 5:
                cout << "Fullness coefficient: " << setprecision(3)<< hashTable.getFullnessCoefficient() << endl<<endl;
                break;
            case 6:
                cout<<"Size of HashTable: "<<hashTable.getSize()<<endl<<endl;
                break;
            default:
                break;
        }
    }while(menuChoose!=0);
}

void stringMenuCode(int size)
{
    HashTable<string> hashTable(size);
    int menuChoose = 0;
    do {
        menuChoose = showUserMenu();
        switch(menuChoose)
        {
            case 1:
            {
                char choice = 'y';
                do {
                    if (choice == 'y') {
                        string key;
                        string elem;
                        cout << "Enter key(string):";
                        cin >> key;
                        cout << "Enter value:";
                        cin >> elem;
                        hashTable.add(key, elem);
                    } else if (choice != 'n')
                        cout << "Incorrect choice!" << endl;
                    cout << "Do you want to add element (y/n):";
                    cin >> choice;
                } while (choice != 'n');
                cout<<endl;
            }
                break;
            case 2:
            {
                string key;
                cout<<"Enter key:";
                cin>>key;
                hashTable.del(key);
                cout<<"Done"<<endl<<endl;
            }
                break;
            case 3:
                hashTable.print();
                break;
            case 4:
            {
                for (auto item = hashTable.begin(); item != hashTable.end(); ++item) {
                    cout << "Key: " << item->key << " Value: " << item->value << endl;
                }
                cout<<endl;
            }
                break;
            case 5:
                cout << "Fullness coefficient: " <<setprecision(3)<<hashTable.getFullnessCoefficient() << endl<<endl;
                break;
            case 6:
                cout<<"Size of HashTable: "<<hashTable.getSize()<<endl<<endl;
                break;
            default:
                break;
        }
    }while(menuChoose!=0);
}

void floatMenuCode(int size)
{
    HashTable<float> hashTable(size);
    int menuChoose = 0;
    do {
        menuChoose = showUserMenu();
        switch(menuChoose)
        {
            case 1:
            {
                char choice = 'y';
                do {
                    if (choice == 'y') {
                        string key;
                        float elem;
                        cout << "Enter key(string):";
                        cin >> key;
                        cout << "Enter value:";
                        cin >> elem;
                        hashTable.add(key, elem);
                    } else if (choice != 'n')
                        cout << "Incorrect choice!" << endl;
                    cout << "Do you want to add element (y/n):";
                    cin >> choice;
                } while (choice != 'n');
                cout<<endl;
            }
                break;
            case 2:
            {
                string key;
                cout<<"Enter key:";
                cin>>key;
                hashTable.del(key);
                cout<<"Done"<<endl<<endl;
            }
                break;
            case 3:
                hashTable.print();
                break;
            case 4:
            {
                for (auto item = hashTable.begin(); item != hashTable.end(); ++item) {
                    cout << "Key: " << item->key << " Value: " << item->value << endl;
                }
                cout<<endl;
            }
                break;
            case 5:
                cout << "Fullness coefficient: " << setprecision(3)<<hashTable.getFullnessCoefficient() << endl<<endl;
                break;
            case 6:
                cout<<"Size of HashTable: "<<hashTable.getSize()<<endl<<endl;
                break;
            default:
                break;
        }
    }while(menuChoose!=0);
}

int showUserMenu()
{
    int choose = 0;
    cout<<"\tMenu"<<endl;
    cout<<"1 - Add Element"<<endl;
    cout<<"2 - Delete Element"<<endl;
    cout<<"3 - Show HashTable"<<endl;
    cout<<"4 - Show HashTable using iterator"<<endl;
    cout<<"5 - Show Fullness Coefficient"<<endl;
    cout<<"6 - Show Size Of Table"<<endl;
    cout<<"0 - Exit"<<endl;
    cout<<"Choose:";
    cin>>choose;
    return choose;
}
