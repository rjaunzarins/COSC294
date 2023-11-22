#include <iostream>
#include <vector>

template<class T>
std::ostream& operator <<(std::ostream& outStream, const std::vector<T>& vec) {
    outStream << "{";
    for(size_t i = 0; i < vec.size(); ++i) {
        if(i < vec.size()-1) {
            outStream << vec[i] << ", ";
        }
        else {
            outStream << vec[i];
        }
    }
    outStream << "}\n";
    return outStream;
};

int main() {

    std::vector<int> v1{1,2,3,4,5};
    std::vector<double> v2{1.1,2.2,3.3,4.4,5.5};
    std::cout << v1 << "\n";
    std::cout << v2 << "\n";
}

