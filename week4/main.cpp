#include <iostream>
#include <string>
#include "database.h"

using namespace std;

string cmd, key, inputType, getKey;
int intValue;
double doubleValue;
string stringValue;
Type type;

void cmdList(Database &db) {
    for (int i = 0; i < db.size; ++i) {
        cout << db.entries[i] -> key << ": ";
        switch (db.entries[i] -> type) {
        case INT:
            cout << *(static_cast<int*>(db.entries[i] -> value));
            break;
        case DOUBLE:
            cout << *(static_cast<double*>(db.entries[i] -> value));
            break;
        case STRING:
            cout << "\"" << *(static_cast<string*>(db.entries[i] -> value)) << "\"";
            break;
        case ARRAY:
            break;
        }
        cout << endl;
    }
}

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
    cin >> getKey;

    Entry *getEntry = get(db, getKey);
    if (getEntry != nullptr) {
        switch (getEntry -> type) {
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
            cmdList(db);
        } else if (cmd == "add") {
            cmdAdd(db);
        } else if (cmd == "get") {
            cmdGet(db);
        } else if (cmd == "del") {
            
        } else if (cmd == "exit") {
            break;
        } else {
            cout << "[ERROR] undefined command" << endl;
            break;
        }
        cout << endl;
    }

    destroy(db);
    cout << "[END] destroy (db)" << endl;
    return 0;
}