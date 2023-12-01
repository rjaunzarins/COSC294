#include <iostream>
#include <map>

int main() {

    using ScoreMap = std::map<std::string, int>;
    ScoreMap map;
    map["Name1"] = 10;
    map["Name2"] = 5;
    map["Name3"] = 7;

    //1st way
    for(ScoreMap::const_iterator itr = map.begin(); itr != map.end(); ++itr) {
        auto& key = itr->first;
        auto& value = itr->second;
        std::cout << key << " = " << value << std::endl;
    }
    std::cout << std::endl;

    //2nd way
    for(auto kv : map) {
        auto& key = kv.first;
        auto& value = kv.second;
        std::cout << key << " = " << value << "\n";
    }
    std::cout << std::endl;

    //3rd way
    for(auto[key, value] : map) {
        std::cout << key << " = " << value << "\n";
    }
 }