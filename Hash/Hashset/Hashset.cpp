#include <unordered_set>                // 0. include the library
#include<iostream>
using namespace std;

int main() {
    // --------------- 1. initialize a hash set --------------- 
    unordered_set<int> hashset;  

    // ---------------  2. insert a new key --------------- 
    hashset.insert(3);
    hashset.insert(2);
    hashset.insert(1);

    // ---------------  3. delete a key --------------- 
    hashset.erase(2);

    // ---------------  4. check if the key is in the hash set --------------- 
    // ==== set.count( element ), return n or 0 (true or false)
    if (hashset.count(2) <= 0) {
        cout << "Key 2 is not in the hash set." << endl;
    }
    if (hashset.find(2) != hashset.end()){  // a lot faster than "count()" !!!
        cout << "Key 2 is not in the hash set." << endl;
    }

    // ---------------  5. get the size of the hash set --------------- 
    cout << "The size of hash set is: " << hashset.size() << endl; 
    
    // ---------------  6. iterate the hash set --------------- 
    for (auto it = hashset.begin(); it != hashset.end(); ++it) {
        cout << (*it) << " ";
    }
    cout << "are in the hash set." << endl;

    // ---------------  7. clear the hash set --------------- 
    hashset.clear();

    // ---------------  8. check if the hash set is empty --------------- 
    if (hashset.empty()) {
        cout << "hash set is empty now!" << endl;
    }
}