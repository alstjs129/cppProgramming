#include <iostream>
#include <map>
#include "database.h"

using namespace std;

Entry *create(Type type, std::string key, void *value) {
    Entry *newEntry = new Entry;
    newEntry -> type = type;
    newEntry -> key = key;
    newEntry -> value = value;

    return newEntry;
}

void init(Database &database) {
    database.entries = nullptr;
    database.size = 0;
    database.capacity = 0;
}

void add(Database &database, Entry *entry) {
    if (database.size >= database.capacity) {
        int newCapacity = (database.capacity == 0) ? 1 : database.capacity * 2;
        Entry **temp = new Entry*[newCapacity];
        
        for (int i = 0; i < database.size; ++i) {
            temp[i] = database.entries[i];
        }
        
        delete[] database.entries;
    
        database.entries = temp;
        database.capacity = newCapacity;
    }
    
    database.entries[database.size++] = entry;
}

Entry *get(Database &database, std::string &key) {
    for (int i = 0; i < database.size; ++i) {
        if (database.entries[i]->key == key) {
            return database.entries[i];
        }
    }
    return nullptr;
}

void destroy(Database &database) {
    for (int i = 0; i < database.size; ++i) {
        delete database.entries[i];
    }
    
    delete[] database.entries;
}