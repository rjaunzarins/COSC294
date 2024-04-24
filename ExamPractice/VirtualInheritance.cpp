#include <iostream>
#include <map>

// struct A {
// 	A() { std::cout << "A constructor\n"; }
// 	~A() { std::cout << "A destructor\n"; }
// };

// struct B : virtual A {					//virtual inheritance
// 	B() { std::cout << "B constructor\n"; }
// 	~B() { std::cout << "B destructor\n"; }
// };
// struct C : virtual A {					//virtual inheritance
// 	C() { std::cout << "C constructor\n"; }
// 	~C() { std::cout << "C destructor\n"; }
// };

// struct D : B, C {					//inherits but no own const or dest
	
// };

// int main() {
// 	D d;
// }


// struct A {
// 	A( int ) { std::cout << "A constructor"; }
// };

// struct B : A {
// 	using A::A;
// };

// int main() {
// 	B b(3);
// }

int main() {
    std::map<std::string, int, std::greater<std::string>> map;
    map["abc"] = 123;
    map["def"] = 456;
    map["ghi"] = 789;
    map["jkl"] = 101112;

    std::map<std::string, int>::iterator itr = map.begin();
    for(; itr != map.end(); ++itr) {
        std::cout << "Key: " << itr->first << " Value: " << itr->second << "\n";
    }
    std::cout << std::endl;

    std::map<std::string, int> map2;
    map2["abc"] = 101112;
    map2["def"] = 789;
    map2["ghi"] = 456;
    map2["jkl"] = 123;

    for(const auto& val : map2) {
        std::cout << "Key: " << val.first << " Value: " << val.second << "\n";
    }
    std::cout << std::endl;

    std::map<int, int, std::greater<char>> myMap2;
    myMap2[1] = 101112;
    myMap2[2] = 789;
    myMap2[3] = 456;
    myMap2[4] = 123;

    for(const auto& val : myMap2) {
        std::cout << "Key: " << val.first << " Value: " << val.second << "\n";
    }
    std::cout << std::endl;

    for(const auto& [key, value] : myMap2) {
        std::cout << "Key: " << key << " Value: " << value << "\n";
    }
    std::cout << std::endl;

    std::string str = "abc" "def";
    std::string str2 = str + "ghi";
    std::string str3 = str2 + std::to_string(42);
    std::string str4 = std::to_string('z') + str3;
    std::string str5 = str4 > str3 ? "Yes" : "No";
}



#include <iostream>
#include <vector>

template <typename K, typename V>
class Map {
private:
    std::vector<K> keys;
    std::vector<V> values;

public:
    void insert(const K& key, const V& value) {
        // Check if the key already exists
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                std::cout << "Key already exists. Update the value." << std::endl;
                values[i] = value;
                return;
            }
        }
        keys.push_back(key);
        values.push_back(value);
    }

    V get(const K& key) const {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        std::cout << "Key not found." << std::endl;
        return V(); // Return default value of type V if key not found
    }

    void remove(const K& key) {
        for (size_t i = 0; i < keys.size(); ++i) {
            if (keys[i] == key) {
                keys.erase(keys.begin() + i);
                values.erase(values.begin() + i);
                return;
            }
        }
        std::cout << "Key not found. Cannot remove." << std::endl;
    }
};
//Usage example of the Map class:

// cpp
// Copy code
int main() {
    Map<std::string, int> myMap;

    myMap.insert("One", 1);
    myMap.insert("Two", 2);
    myMap.insert("Three", 3);

    std::cout << "Value for key 'Two': " << myMap.get("Two") << std::endl;

    myMap.insert("Two", 20); // Update value for existing key 'Two'

    std::cout << "Value for key 'Two' after update: " << myMap.get("Two") << std::endl;

    myMap.remove("Three");
    std::cout << "Value for key 'Three' after removal: " << myMap.get("Three") << std::endl;

    
    int x = 2;
    int y = 3;
    int &r1 = x;
    int &r2 = y;
    r1 = r2;
    
    
    
    
    return 0;


}