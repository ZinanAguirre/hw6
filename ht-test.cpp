#include "ht.h"
#include "hash.h"
#include <unordered_map>
#include <iostream>
#include <utility>
#include <string>
#include <sstream>
#include <functional>
#include <set>
using namespace std;
int main()
{
  HashTable<string, int, DoubleHashProber<string, std::hash<string>>, hash<string>, equal_to<string> > ht;
    set<pair<string, int>> items;
    for(int i = 0; i < 5; i++) {
        pair<string, int> newItem(to_string(i), i);
        ht.insert(newItem);
        items.insert(newItem);
    }
    cout << ht.size() << endl;
    pair<string,int> newItem(to_string(5),5);
    ht.insert(newItem);
    items.insert(newItem);
    cout << ht.size() << endl;
}
