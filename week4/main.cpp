#include <iostream>
#include "database.h"

using namespace std;

string cmd, key, type, value;

void query() {
    cout << "command (list, add, get, del, exit): ";
    cin >> cmd;

    cout << "key: ";
    cin >> key;

    cout << "type (int, double, string, array): ";
    cin >> type;

    cout << "value: ";
    cin >> value;
}

int main() {

    query();
    
    Entry *entry;
    Type type=INT;
    entry = create(type, key, &value);

    cout << entry->key << "\n" << entry->type << "\n" << entry->value << "\n";
    return 0;
}