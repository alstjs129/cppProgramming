#include <iostream>
#include <string>
#include "database.h"

using namespace std;

string cmd, key, inputType;
int intValue;
double doubleValue;
string stringValue;
Type type;

void cmdAddInput() {
    cout << "key: ";
    cin >> key;

    cout << "type (int, double, string, array): ";
    cin >> inputType;

    cout << "value: ";
    if (inputType == "int") {
        type=INT;
        cin >> intValue;
    }
    else if(inputType == "double") {
        type=DOUBLE;
        cin >> doubleValue;
    }
    else if(inputType == "string") {
        type=STRING;
        getline(cin >> ws, stringValue);
    }
    else {
        type=ARRAY;
    }
}

void cmdAdd(Database &db) {
    cmdAddInput();

    switch (type) {
        case INT:
            add(db, create(type, key, new int(intValue)));
            break;
        case DOUBLE:
            add(db, create(type, key, new double(doubleValue)));
            break;
        case STRING:
            add(db, create(type, key, new string(stringValue)));
            break;
        case ARRAY:
            break;
    }
}

void cmdGet(Database &db) {
    cout << "key: ";
    cin >> key;

    Entry *getEntry = get(db, key);
    if (getEntry != nullptr) {
        switch (type) {
        case INT:
            cout << getEntry -> key << ": " << *(static_cast<int*>(getEntry->value));
            break;
        case DOUBLE:
            cout << getEntry -> key << ": " << *(static_cast<double*>(getEntry->value));
            break;
        case STRING:
            cout << getEntry -> key << ": \"" << *(static_cast<string*>(getEntry->value)) << "\"";
            break;
        case ARRAY:
            break;
        }
    }
    cout << endl;
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
        cout << endl;
    }

    destroy(db);
    cout << "[END] destroy (db)" << endl;
    return 0;
}