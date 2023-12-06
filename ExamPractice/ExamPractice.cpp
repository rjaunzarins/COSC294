#include <iostream>
#include <list>
#include <vector>



// template<class T>       
// class Set {         //Container adapter because Set wraps around list
//     public:
//         typedef std::list<T>::iterator Iterator;          //can also use using Iterator = std::list<T>::iterator;         
//         Set(std::initializer_list<T> values) {
//             for(auto& val : values)
//                 list.push_back(val);
//         }
//         Set() = default;
//         ~Set() {}
//         void add(const T& value) {  //Keep elems in order
//             //Lower_bound performs binary search from begin() to end() and
//             //returns the first element greater than value. Then insert
//             //inserts value one position before
//             if(!contains(value))
//                 list.insert(std::lower_bound(begin(),end(),value),value);
//         }
//         void remove(const T& value) { 
//             list.remove(value); 
//         }
//         Iterator find(const T& value) const {
//             return std::find(begin(), end(), value);
//         }
//         bool contains(const T& value) const {
//             return (find(value)) != end();
//         }
//         void clear() { 
//             list.clear();
//         }
//         friend std::ostream& operator <<(std::ostream& os, const Set& s) {
//             for(auto& value : s.list)
//                 os << value << " ";
//             return os;
//         }
//         Iterator begin() const { return list.begin(); }
//         Iterator end() const { return list.end(); }
//     private:
//         std::list<T> list;
// };

template<class T>
class DynamicArray {                            //! Make this generic
    public:
        DynamicArray();
        explicit DynamicArray(int size);
        ~DynamicArray();
        void resize(int size);
        void add(const T& value);
        void pop(int index);
        T& operator [](int index);
        int size() { return num_items; }
        int capacity() { return total_capacity; }
        friend std::ostream& operator <<(std::ostream& os, const DynamicArray& data);
    private:
        int num_items;
        int total_capacity;
        T *data;
};

int main() {
    // Set<int> s;
    // Set<int> s2{1, 2, 3, 4, 5};
    // Set<int>::Iterator itr;
    // s.add(3);
    // s.add(1);
    // s.add(4);
    // s.add(2);
    // std::cout << s << "\n";

    // s.remove(3);
    // std::cout << "Remove 3:\n" << s << "\n";

    // std::list<int>::iterator it = s.find(2);
    // std::cout << "Find 2: " << *it << "\n";

    // std::cout << "Contains 1: " << s.contains(1) << "\n";
    // std::cout << "Contains 5: " << s.contains(5) << "\n";
    // s.clear();
    // std::cout << "Clear list: \n" << s << "\n"; 

    // std::cout << "Set 2:\n";

    // DynamicArray da(3);
    // da.add(1.1);
    // da.add(2.2);
    // if(da[2] == 3.3)
    //     std::cout << "Yes\n";
    // else
    //     std::cout << "No\n";
    int num1 = 1;
    int num2 = 2;
    std::swap(num1, num2);
    std::cout << num1 << ", " << num2 << "\n";
    std::vector<int> v = {1,2,3,4,5};
    std::swap(v[1], v[2]);
    std::sort(v.begin(), v.end(), std::greater());
    for (auto& itr : v)
        std::cout << itr << " ";
    
}

template<class T>
DynamicArray<T>::DynamicArray() : num_items(0), total_capacity(1), data(new T[1]) {}

template<class T>
DynamicArray<T>::DynamicArray(int size) : num_items(0) {
    if(size < 0) {
        DynamicArray();
    }
    else {
        total_capacity = size;
        data = new T[size];
    }
}

template<class T>
DynamicArray<T>::~DynamicArray() { delete[] data; }

template<class T>
void DynamicArray<T>::resize(int size) {
    if(size < 0) {
        if(num_items > 0)    
            num_items = 1;
        else    
            num_items = 0;
        total_capacity = 1;
    }
    else if(size < total_capacity) {
        num_items = size;
        total_capacity = size;  //leave this out if you want to preserve the data
    }
    else if(size > total_capacity) {
        T *data2 = new T[size];
        for(size_t i = 0; i < num_items; ++i) {
            data2[i] = data[i];
        }
        delete[] data;
        data = data2;
        total_capacity = size; 
    }
}

template<class T>
void DynamicArray<T>::add(const T& value) {
    if(num_items == total_capacity) {
        resize(total_capacity * 2);
    }
    data[num_items++] = value;
}

template<class T>
void DynamicArray<T>::pop(int index) {
    if(index >= 0 && index < size()) {
        for(int i = index; i < size(); ++i) {
            data[i] = data[i + 1];
        }
        --num_items;
    }
    return;
}

template<class T>
T& DynamicArray<T>::operator [](int index) {
    if(index >= 0 && index <= num_items)     
        return data[index];
    else
        throw std::out_of_range("Index out of bounds");
}

template<class T>
std::ostream& operator <<(std::ostream& os, const DynamicArray<T> &da) {
    for(size_t i = 0; i < da.num_items; ++i) {
        if(i != 0)
            os << ", ";
        os << da.data[i];
    }
    return os;
}


// using namespace std;
// #define SIZE 512

// int main() {

//     srand(time(0));                         // missing srand()?
//     int *values = new int[SIZE];
//     for(int i = 0; i < SIZE; ++i) {         // i < SIZE, not i <= SIZE
//         values[i] = rand() % 84 - 42;
//         cout << values[i] << " ";
//     }
//     cout << "\nMax value is: ";
//     int max = values[0];                    // max = values[0], not max = 0;
//     for(int i = 0; i < SIZE; ++i){
//         if(values[i] > max)
//             max = values[i];
//     }
//     cout << max << endl;
//     delete[] values;                        //delete[] values, not delete values;
// }


using namespace std;

class A {
    public:
        void func1() { cout << "func1 of classA" << endl; }
        virtual void func2() { cout << "func2 of classA" << endl; }
};
class B : public A {
    public:
        virtual void func1() { cout << "func1 of classB" << endl; }
        void func2() { cout << "func2 of classB" << endl; }
};

// int main() {          //!!!!!!!!!! Know this.
//     A *a1, a2;
//     B *b1;
//     a1 = new B;
//     b1 = new B;
//     a1->func1();    //func1 of classA
//     a1->func2();    //func2 of classB
//     a2.func1();     //func1 of classA
//     a2.func2();     //func2 of classA
//     b1->func1();    //func1 of classB
//     b1->func2();    //func2 of classB
// }

class Stack {
    struct Node {                           // The Node class is an inner private class to the 'Stack' class
        double value = 0.;                  // The value to hold
        Node *next = nullptr;               // A pointer to the next node in the list.
    };
    Node *head = nullptr;                   // A pointer to the head of our Stack's data
public:
    Stack(std::initializer_list<double> values) {
        for (auto value : values) {
            push_back(value);
        }
    }
    void push_front(double value) {
        Node* newNode = new Node{value, head};
        head = newNode;
    }
    void push_back(double value) {
        Node* newNode = new Node{value, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    Stack &operator=( const Stack &other ) { // Copy the ‘other’ stack into this stack, overwriting any existing contents.
                                            //other.clear(); remove
        if(this == &other)                  //add this
            return *this;
        clear();
        Node *otherTemp = other.head;
        Node *thisTemp = nullptr;
        while ( otherTemp ) {               // otherTemp, not !otherTemp
            Node *n = new Node();           // Node *n, not Node n
            n->value = otherTemp->value;
            if ( thisTemp )
                thisTemp->next = n;
            else
                head = n;                   // head = n, not n = head
            thisTemp = n;
            otherTemp = otherTemp->next;
        }
        return *this;                       // return *this at the end
    }
    void clear() {                          // Function to remove all items from the stack
        while(head) {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
   friend std::ostream& operator <<(std::ostream& os, const Stack& s) {
        Node *tmp = s.head;
        while(tmp) {
            os << tmp->value << " ";
            tmp = tmp->next;
        }
        delete tmp;
        return os;
    }
    ~Stack() { clear(); } 
};

// int main() {
//     Stack s = {1.2,2.2,3.3,4.4,5.5};
//     std::cout << s << "\n";
// }
    
//     DynamicArray da(5);
//     da.add(1.01);
//     da.add(2.01);
//     da.add(3.01);
//     da.add(4.01);
//     da.add(5.01);
//     std::cout << da[0] << " " << da[1] << " " << da[2] << " " << da[3] << " " << da[4] << "\n";
//     std::cout << "DA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << "\n\nResize 10, add 2 elems: \n";
//     da.resize(10);
//     da.add(6.01);
//     da.add(7.01);
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     std::cout << "\nResize 4: ";
//     da.resize(4);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << std::endl;    
//     da.pop(2);
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << std::endl;
//     da.pop(1);
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << std::endl;    
//     da.pop(0);
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << std::endl;
//     da.pop(0);
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << std::endl;
//     da.pop(5);
//     for(int i = 0; i < da.size(); ++i) 
//         std::cout << da[i] << " ";
//     std::cout << std::endl;

//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(6.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
//     da.add(7.01);
//     std::cout << "\nDA Size: " << da.size() << "\n";
//     std::cout << "DA Capacity: " << da.capacity() << "\n";
// }

// #include <iostream>
// #include <fstream>
// #include <cctype>
// #include <string>

// int main(int argc, char* argv[]) {
//     std::ifstream inputFile(argv[1]);
//     std::ofstream outputFile(argv[2]);
//     std::string line;
//     size_t totalCharacters = 0;

//     while(std::getline(inputFile, line)) {
//         //Convert line to uppercase
//         for(char &c : line) {
//             c = std::toupper(c);
//         }
//         //std::transform( line.begin(), line.end(), line.begin(), std::toupper );   This also does what the for loop does
//         if(inputFile.eof()){
//             std::cout << "End of file\n";
//         }
//         //Write the uppercase line to out file
//         outputFile << line << '\n';
//         //Update the total number of characters
//         totalCharacters += line.size();
//     }
//     //Print number of characters
//     std::cout << "Total number of characters: " << totalCharacters << '\n';
// }





struct Oranges {
	int* p = new int[5];
	int size = 5;

	Oranges(const Oranges& o) { //copy constructor
		p = new int[o.size];
		size = o.size;
	}

	Oranges(Oranges&& o) { 	//move constructor
		p = o.p;
		size = o.size;
		o.p = nullptr;	//set to nullptr to prevent double deletion in case of destruction
		o.size = 5;
	}

	~Oranges() {
		delete[] p;
	}
};
