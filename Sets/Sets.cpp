#include <iostream>
#include <set>

int main() {

    //Simplest container possible
    //Stores elements without repetition
    //Capabilities: add, delete, check if element is in set
    //Stores values in sorted order
    std::set<int> set1;
    set1.insert(1);
    for(int i = 1; i < 11; ++i) {
        set1.insert(i);
    }

    //Print set
    //std::set<int>::const_iterator itr;
    auto itr = set1.begin();
    for(; itr != set1.end(); ++itr) {
        std::cout << *itr << " ";
    }
    std::cout << "\n";

    //Find 5, print element, remove
    std::cout << "Count 5: " << set1.count(5) << "\n";
    if(set1.contains(5)) {
        set1.erase(5);
        std::cout << "Removed 5\n";
    }

    auto found = set1.find(4);
    if(found != set1.end()) {
        std::cout << "Found 4 & erased\n";
        set1.erase(found);
    }

    //Print set another way
    for(auto value : set1) {
        std::cout << value << " ";
    }
    std::cout << "\n";

    auto higher = set1.upper_bound(6);
    auto lower = set1.lower_bound(2);
    for(auto itr = lower; itr != higher; ++itr) {
        std::cout << *itr << " ";
    }

    set1.erase(lower, higher);

    for(auto value: set1) 
        std::cout << value << " ";
    std::cout << std::endl;

}