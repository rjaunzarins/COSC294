#include <iostream>

template<class t>
class Node {
    public:
        Node(T data, Node<T>* link) : data(data), link(link) {}
        Node<T> getLink() const { return link; }
        const T& getData() const { return data; }
        void setData(const T& data) { data = theData; }
        void setLink(Node<T>* ptr) { link = ptr; }
    private:
        T data;
        Node<T> *link;
};

template<class T>
class ListIterator {
    public:
        ListIterator() : current(NULL) {}
        ListIterator(Node<T>* initial) : current(initial) {}
        const T& operator *() const { return current->getData(); } //Precondition: Not equal to the default constructor object. That is, current != nullptr
        ListIterator& operator ++() { //Prefix form
            current = current->getLink();
            return *this;
        }
        ListIterator& operator ++(int) { //Postfix form
            ListIterator startVersion(current);
            current = current->getLink();
            return startVersion;
        }
        bool operator ==(const ListIterator& rightSide) const {
            return (current == rightSide.current; )
        }
        bool operator !=(const ListIterator& rightSide) const {
            return (current != rightSide.current); 
        }
    private:
        Node<T> *current;
};
    

template<class T>
class Queue {
    public:
        typedef ListIterator<T> Iterator;

        Queue();
        Queue(const Queue<T>& aQueue);
        Queue<T>& operator =(const Queue<T>& rightSide);
        virtual ~Queue();
        void add(T item);
        T remove();
        bool isEmpty() const;

        Iterator begin() const { return Iterator(front); }
        Iterator end() const { return Iterator(); } //The end iterator has end().current == nullptr (cannot be dereferenced)
    private:
        Node<T> *front; //Points to the head of a linked list
                        //Items are removed at the head
        Node<T> *back;  //Points to the node at the other end of the linked list
                        //Items are added at this end
};



int main() {
    char next, ans;
    do {
        Queue<char> q;
        std::cout << "Enter a line of text:\n";
        std::cin.get(next);
        while(next != '\n') {
            q.add(next);
            std::cin.get(next);
        }
        std::cout << "You entered:\n";
        Queue<char>::Iterator i;
        for( i = q.begin(); i != q.end(); ++i) {
            std::cout << *i;
        }
        std::cout << std::endl;
        std::cout << "Again> (y/n): ";
        std::cin >> ans;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } while(ans != 'n' && ans != 'N');
}