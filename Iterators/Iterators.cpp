#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;

/*
You manipulate iterators using the following overloaded operators:

• Prefix and postfix increment (++) - for advancing
• Frefix and postfix decremenent (--) - for going back one
• Equal and unequal operators (== & !=) - To test if two points are at the same location
• Dereferencing operator (*) - which gives access to the data in the current location. This can be read/write/both only depending on the container class

Not all iterators have these overloads. 
Many containers will also have the following members:

• c.begin() - returns an iterator for the container c that points to the "first" data item in the container
• c.end() - returns something that can be used to test when an iterator has passed beyond the last data item (NULL)

These allow you to write loops that cycly through all the elements:
*/

void vectorIteratorLoop() {
    std::vector<int> c = {1,2,3,4,5};   //Vector<int>
    std::vector<int>::iterator itr;     //Vector<int> iterator
    for(itr = c.begin(); itr != c.end(); ++itr) { /*code*/ }
}

void listIteratorLoop() {
    std::list<int> l = {1,2,3,4,5};     //List<int>
    std::list<int>::iterator itr;       //List<int> iterator
    for(itr = l.begin(); itr != l.end(); ++itr) { /*code*/ }
}

void vectorIteratorDemo() {
    std::vector<int> container;
    for(int i = 1; i <=4; ++i)
        container.push_back(i);
    cout << "Here is what is in the container:\n";
    std::vector<int>::iterator itr;
    for(itr = container.begin(); itr != container.end(); ++itr) //container.end() is one past the last element -> returns NULL
        cout << *itr;
    cout << endl;
    cout << "Setting entries to 0:\n";
    for(itr = container.begin(); itr != container.end(); ++itr)
        *itr = 0;
    cout << "Container now contains:\n";
    for(itr = container.begin(); itr != container.end(); ++itr) 
        cout << *itr << " ";
    cout << endl;
}

/*
To see if two elements are in the same location you can use the "==" operator.
p1 == p2, where p1 and p2 are iterators. If they are pointing to the same location
it will return true, else false.

.begin() - 
This member function is used to position an iterator at the first element in a container. 
For vectors, and many other containers, the member function begin() returns an iterator 
located at the first element.
*/
    std::vector<int> c;
    std::vector<int>::iterator p = c.begin();
/*
This is used in for loops to initialize the iterator at the first element.

.end() - 
This does the same thing but returns a sentinel value. There for when itr passes the last
element it reaches c.end() which returns NULL. The loop runs while itr != c.end(),
or a null pointer.
*/
    std::vector<int>::iterator p = c.end();
/*
*itr - 
The dereferencing operator, *, is overloaded for STL container iterators so that *p produces
the element at location p. In particular, for a vector container, *p produces the element
located at the iterator p. The dereferencing operator always produces the element located
at the iterator p. In some situations *p produces read-only access, which does not allow you
to change the element. In other situation it gives you access to the element and will let 
you change it. For vectors you are allowed to change the element.

You can also use the following to declare an iterator if you will be doing it multiple times:
*/
     //using std::vector;
     //vector<char>::iterator p;
/*
Vector iterator have random access to the elements of a vector, such as container:
*/
void printElement() {
    std::vector<int> container{1,2,3,4};
    std::vector<int>::iterator itr = container.begin();
    cout << "The third entry is " << container[2] << endl;
    cout << "The third entry is " << itr[2] << endl;
    cout << "The third entry is " << *(itr + 2) << endl;
}
/*
Random access mean that you can go directly to any particualr element in one step. We have
already used container[2] as a form of random access to a vector. This is simply the square
bracket operator that is standard with arrays and vectors. What is new is that you can use
this same square bracket notation with an iterator. The expression itr[2] is a way to obtain
access to the element indexed by 2. 
The expression (itr + 2) returns an iterator and *(itr + 2) dereferences it to give you a value.
Neither itr[2] nor (itr + 2) changes the value of the iterator. The expression (itr + 2) returns
another iterator at another location, but it leaves itr where it was. Also, note that the 
meaning of itr[2] and (itr + 2) depends on the location of the iterator in itr. For example, 
(itr + 2) means two locations beyond the current location of itr, wherever that may be.
For example, suppose:
*/
void printElement2() {
    std::vector<int> container{1,2,3,4};
    std::vector<int>::iterator itr = container.begin();
    ++itr;
    cout << "The third entry is " << container[2] << endl;
    cout << "The third entry is " << itr[2] << endl;
    cout << "The third entry is " << *(itr + 2) << endl;
}
/*
This would now output:
    The third entry is C
    The third entry is D
    The third entry is D
The ++itr moves the location of itr from index 0 to index 1 and any references from its 
location will now reflect that. 


The main kinds of iterators are as follows:

    Forward iterator: ++ works on the iterator
    Bidirectional iterator: Both ++ and -- work on the iterator
    Random-access iterators: ++, --, and random access work with the iterator

Note that every random-access iterator is also a bidirectional iterator, and every 
bidirectional iterator is also a forward iterator.


CONSTANT AND MUTABLE ITERATORS -
The categories of forward iterators, bidirectional iterator, and random-access iterators
each subdivide into two categories - constanat and mutable - depending on how the dereferencing
operator behaves with the iterator. 

With a CONSTANT ITERATOR the dereferencing operator 
produces a read-only version of the element. With a constant iterator p, you can use *p
to assign it to a variable or output it to the screen, for example, but you cannot change
the element in the container by, for example, assigning to *p.

With a MUTABLE ITERATOR, *p can be assigned a value, which will change the corresponding
element in the container. 

If a container has only constant iterators, you cannot obtain a mutable iterator for the 
container. However, if a container has mutable iterators and you want a constant iterator
for the container, you can have it. For example:
*/
    std::vector<int> c = {1,2,3,4};
    std::vector<int>::const_iterator p = c.begin();

/*
REVERSE ITERATORS -
When you have a bidirectional iterator you cannot use container.end() as the first element
because it is not the first element. To loop through in reverse you want to use a reverse
iterator and the functions rbegin() and rend().
*/
void reverseIterator() {
    std::vector<int> c = {1,2,3,4};
    std::vector<int>::reverse_iterator ritr;
    for(ritr = c.rbegin(); ritr != c.rend(); ++ritr) {
        std::cout << *ritr << " ";
    }
}
/*
The memeber functions rbegin() returns an iterator located at the last element. The member
function rend() returns a sentinel that marks the "end" of the elements in the reverse
order. Note that for an iterator of type reverse_iterator, the increment operator, ++, moves
backward through the elements. In other words, the meaning of ++ and -- are interchanged. 
reverse_iterator also has a const version const_reverse_iterator.


OTHER KINDS OF ITERATORS - 
There are other kinds of iterators, which we will not cover in this book. We will briefly
mention two kinds of iterators whose names you may encounter. 
An INPUT ITERATOR is essentially a forward iterator that can be used with input streams.
An OUTPUT ITERATOR is essentially a forward iterator that can be used with output streams.
*/


