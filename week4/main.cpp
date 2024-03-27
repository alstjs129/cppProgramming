#include <iostream>
#include <map>
#include "database.h"

using namespace std;

string cmd, key, inputType, value;
int inputTypeINT;
Type type;

void cmdAddInput() {
    cout << "key: ";
    cin >> key;

    cout << "type (int, double, string, array): ";
    cin >> inputType;

    if (inputType == "int") type=INT;
    else if(inputType == "double") type=DOUBLE;
    else if(inputType == "string") type=STRING;
    else type=ARRAY;

    cout << "value: ";
    cin >> value;
}

void cmdAdd() {
    Entry *entry;
    Database myDatabase;
    
    cmdAddInput();
    entry = create(type, key, &value);
    
    add(myDatabase, entry);
}

int main() {
    
    // Entry *entry;
    // entry = create(type, key, &value);
    // entry->type = static_cast<Type>(inputTypeINT);

    // Database myDatabase;
    // add(myDatabase, entry);

    // cout << entry->key << "\n" << entry->type << "\n" << entry->value << "\n";

    while(1) {
    
        cout << "command (list, add, get, del, exit): ";
        cin >> cmd;

        if (cmd == "list") {

        } else if (cmd == "add") {
            cmdAdd();
        } else if (cmd == "get") {

        } else if (cmd == "del") {
            
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "[ERROR] undefined command ";
            break;
        }
    }
    int a = 3;
    return 0;
}