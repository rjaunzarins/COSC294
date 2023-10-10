#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(10);
    int i;
    for (i = 0; i < v.size(); ++i)
        v[i] = i;
    std::vector<int> copy;
    copy = v;
    v[0] = 42;
    copy.push_back(55);

    for (i = 0; i < copy.size(); ++i)
        std::cout << copy[i] << " ";
    std::cout << std::endl; 

    for (i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;    
}