#include "database.h"

// 엔트리를 생성한다.
Entry *create(Type type, std::string key, void *value) {
    Entry *newEntry = new Entry;
    newEntry->type = type;
    newEntry->key = key;
    newEntry->value = value;
    return newEntry;
}