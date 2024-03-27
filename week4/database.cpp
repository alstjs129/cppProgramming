#include <iostream>
#include <map>
#include "database.h"

using namespace std;

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value) {
    Entry *newEntry = new Entry;

    newEntry -> type = type;
    newEntry -> key = key;
    newEntry -> value = value;

    return newEntry;
}

void add(Database &database, Entry *entry) {
    string key = entry -> key;

}