#include <iostream>
#include "database.h"

using namespace std;

string cmd, key, inputType, value;
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

void cmdAdd(Database &db) {
    cmdAddInput();
    // add(db, create(INT, "key1", new int(42)));
    add(db, create(type, key, new int(stoi(value))));
}

void cmdGet(Database &db) {
    cout << "key: ";
    cin >> key;

    Entry *getEntry = get(db, key);
    if (getEntry != nullptr) {
        cout << getEntry -> key << ": " << *(static_cast<int*>(getEntry->value));
    }
    cout << "\n";
}

int main() {

    Database db;
    init(db);

    while(1) {
        
        cout << "command (list, add, get, del, exit): ";
        cin >> cmd;

        if (cmd == "list") {

        } else if (cmd == "add") {
            cmdAdd(db);
        } else if (cmd == "get") {
            cmdGet(db);
        } else if (cmd == "del") {
            
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "[ERROR] undefined command ";
            break;
        }
    }

    destroy(db);
    cout << "destroy (db)" << endl;
    return 0;
}