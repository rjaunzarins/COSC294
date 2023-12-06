#include <map>
#include <set>
#include <stack>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <iostream>
// CONTAINERS

/*
The CONTAINER CLASSES of the STL are diferent kinds of structures for holding data, such
as lists, queues, and stacks. Each is a template class with a parameter for the particular
type of data to be stored. You can specify the type of data that will be used in the
container. Each container template class may have its own specialized accessor and mutator 
functions for adding data and removing data from the container. Different container classes
may have different kinds of iterators. Some containers may have bidirectional iterators,
while another may have only forward iterators. However, whener they are defined, the 
iterator operators and the member function begin() and end() have the same meaning for all
STL container classes.
*/

/*
SEQUENTIAL CONTAINERS -
A sequential container arranges its data items into a list such that there is a first element,
a next element, and so forth, up to a last element. The linked list is an example of a kind
of sequential container; these kinds of lists are also sometimes called SINGLY LINKED LISTS 
because there is only one link from one location to another. The STL has no container corresponding
to such a singly linked list, although some implementations do offer an implementation of a 
singly linked list, typically under the name <slist>. 
The simplest form that is part of the STL is the DOUBLY LINKED LIST, which is the template 
class named <list>.
*/
void lists() {
    std::list<int> list = {1,2,3};
    list.push_back(4);
    std::list<int>::iterator itr;
    for(itr = list.begin(); itr != list.end(); ++itr) {
        std::cout << *itr << " ";
    }
}
/*
A singly linked list can only traverse in the forward direction, while a double linked list,
or <list> can traverse bidirectionally.
Where as a <vector> has random access to its elements, <list> only has sequential access. 
This is because each element in a <vector> has a correctsponding element number, whereas in
a <list> there is no index for each element. The only way an element can be found is by
traversing the list.
*/

/*
QUEUE AND DEQUE - 
With a queue you add data at one end and
*/
void queueAndDeque() {
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    std::deque<int> d;
    d.push_back(2);
    d.push_front(1);
    d.push_back(3);
    std::deque<int>::iterator ditr;
    for(ditr = d.begin(); ditr != d.end(); ++ditr)
        std::cout << *ditr << " ";
}
/*
STL BASIC SEQUENTIAL CONTAINERS - 

TEMPLATE        ITERATOR TYPE NAMES         KIND OF ITERATORS           HEADER FILE
CLASS NAME
-------------------------------------------------------------------------------------
list            list<T>::iterator           Mutable Bidirectional       <list>
                list<T>::const_iterator     Constant Bidirectional  
                list<T>::reverse_iterator   Mutable Bidirectional   
                list<T>::const_reverse_     Constand Bidirectional
                         iterator

vector          vector<T>::iterator         Mutable Random Access       <vector>
                vector<T>::const_iterator   Constant Random Access
                vector<T>::reverse_iterator Mutable Random Access
                vector<T>::const_reverse_   Constant Random Access
                           iterator

deque           deque<T>::iterator          Mutable Random Access       <deque>
                deque<T>::const_iterator    Constant Random Access
                deque<T>::reverse_iterator  Mutable Random Access
                deque<T>::const_reverse_    Constand Random Access
                          iterator
*/

/*
SOME SEQUENTIAL CONTAINER MEMBER FUNCTIONS - 

MEMBER FUNCTION     MEANING
-------------------------------------------------------------------------------------
c.size()            Returns the number of elements in the container
c.begin()           Returns an iterator located at the first element in the container
c.end()             Returns an NULL iterator to show you are one past the end of the container
c.rbegin()          Returns an iterator located at the last element in the container
c.rend()            Returns a NULL iterator "one before" the first element.
c.push_back(elem)   Inserts (elem) at the end of the sequence.
c.push_front(elem)  Inserts (elem) at the front of the sequence
c.insert(itr, elem) Inserts a copy of (elem) before the location of (itr) 
c.erase(itr)        Removes the element at location (itr). Returns an iterator at location 
                    immediately following. Returns c.end() if last element removed.
c.clear()           A void function that removes all the elements in the container.
c.front()           Returns a reference to the element in the front of the sequence. 
                    Equivalent to *(c.begin()).
c1 == c2            True if ci.size() == c2.size() and each element of c1 is equal to the
                    corresponding element of c2
c1 != c2            !(c1 == c2)

Adding or removing an element to or from a container can affect other iterators. In general,
There is no guarentee that the iterators will be located at the same element after an 
addition or deletion. Some containers do, however, guarentee that the iterators will not
be moved by additions or deletions, except of course if the iterator is located at an
elements that is removed.

Of the template classes we have seen so far, <list> and <slist> guarentee that their 
iterators will not be moved by additions or deletions, except of course if the iterator
is located at the element that is removed. The template classes <vector> and <deque>
make no such guarentee
*/

/*
THE CONTAINER ADAPTERS <STACK> AND <QUEUE> - 
Container adapters are template classes that are implemented on top of other classes. 
For example, the <stack> template class is by default implemented on top of the <deque>
template class, which means that buried in the implementation of the stack is a deque
where all the data resides. However, you are shielded from this implementation detail 
and see a stack as a simple last-in / first-out data structure.

Other container adapters classes are the <queue> and <priority_queue> template classes. 
Stacks and queues were discussed in Chapter 17. A priority queue is a queue with the 
additional property that each entry is given a priority when it is added to the queue.
If all entries have the same priority, then entries are removed from a priority queue
in the same manner as they are removed from a queue. If items have different priorities,
the higher-priority items are removed before the lower-priority items. 

Although an adapter template class has a default container class on top of which it is 
built, you may choose to specify a different underlying container, for efficiency or 
other reasons, depending on your application. For example, any sequence container may
serve as the underlying container for the <stack> template class, and any sequence 
container other than <vector> may serve as the underlying container for the <queue> 
template class. The default underlying data structure is the <deque> for both the <stack>
and the <queue>. For a <priority_queue>, the default underlying container is a <vector>.

For example, the normal way to create a stack would be:
*/
    std::stack<int> stack;
/*
To create a stack with the underlying container as a vector, you would do:
*/
    std::stack<int, std::vector<int>> vectorStack;

/*
STACK MEMBER FUNTIONS - (s is a stack)

MEMBER FUNCTION     MEANING

s.size()            Returns the number of elements in the stack
s.empty()           Returns true if the stack is empty, otherwise false
s.top()             Returns a mutable reference to the top member of the stack
s.push(elem)        Inserts a copy of (elem) at the top of the stack
s.pop()             Removes the top element of the stack. Note that pop is a void
                    function. It does not return the element removed.
s1 == s2            True if s1.size() == s2.size() and each element of s1 is equal to
                    the corresponding element of s2; otherwise return false.
The <stack> template class also has a default constructor, a copy constructor, and a 
constructor that takes an object of any sequence class and initializes the stack to the
elements in the sequence. It also has a destructor that returns all storage for 
recycling, and a well-behaved assignment operator.
*/

/*
QUEUE MEMBER FUNCTIONS - (q is a queue)

MEMBER FUNCTION     MEANING
q.size()            Returns the number of elements in the queue
q.empty()           Returns true if the queue is empty; otherwise false
q.front()           Returns a mutable reference to the front member of the queue
q.back()            Returns a mutable reference to the last member of the queue
q.push(elem)        Adds (elem) to the back of the queue
q.pop()             Removes the front element of the queue. Note that pop is a void 
                    function. It does not return the element removed.
q1 == q2            True if q1.size() == q2.size() and each corresponding element
                    is equal; otherwise false.
The queue template class also has a default constructor, a copy constructor, and a 
constructor that takes an object of any sequence class and initializes the stack to 
the elements in the sequence. It also has a destructor that returns all storage for 
recycling, and a well-behaved assignment operator.
*/


/*
THE ASSOCIATIVE CONTAINERS <SET> AND <MAP> -

Associative containers are basically very simple databases. They store data, such as 
structs or any other type of data. Each data item has an associated value known as its 
KEY. For example, if the database was a struct of employee records the employees SIN
might be used as the key. With a <set>, each element is its own key.

The <set> template class is, in some sense, the simplest container you can imagine. It 
stores elements without repetition. The first iteration places an element in the set. 
Additional insertions after the first have no effect, so that no element appears more
than once. Each element is its own key. Basically, you just add or delete elements and 
ask if an element is in the set or not. Like all STL classes, the <set> template class
was written with efficiency as a goal. To work efficiently, a <set> object stores its 
values in sorted order. You can specify the order used for storing elements as follows:
*/
void setDemo() {
    std::set<int, std::greater<int>> s;     // std::greater<int> is the ordering you want
    std::set<int, std::less<int>> s2;       // std::less<int> is the default
    std::set<int> s3;                       // Less ordering
    s3.insert(1);
}
/*
<SET> MEMBER FUNTIONS - 

MEMBER FUNCTION     MEANING
s.insert(elem)      Inserts a copy of (elem) in the set. If (elem) is alread in set, no effect
s.erase(elem)       Removes (elem) from set. If (elem) is not in set, no effect
s.find(elem)        Returns an iterator located at the copy of (elem) in the set. If (elem)
                    is not in the set, s.end() is returned. Whether the iterator is 
                    mutable or not is implementation dependent.
s.erase(itr)        Erases the element at the location of the iterator
s.size()            Returns the number of elements in the set
s.empty()           Returns true if the set is empty; otherwise false
s1 == s2            Returns true if sets contain the same elements; otherwise false
The <set> template class also has a default constructor, a copy constructor, and other
specialized constructors not mentioned here. It has a destructor as well that returns all
storage for recycling, and a well-behaved assignment operator.
*/
void set() {
    std::set<char> s;
    s.insert('A');
    s.insert('D');
    s.insert('D');
    s.insert('C');
    s.insert('C');
    s.insert('B');

    std::cout << "The set containes:\n";
    std::set<char>::const_iterator citr;
    for(citr = s.begin(); citr != s.end(); ++citr)
        std::cout << *citr << " ";
    std::cout << std::endl;

    std::cout << "Set contains 'C': ";
    if(s.find('C') == s.end())
        std::cout << " no \n";
    else   
        std::cout << " yes\n";
    
    std::cout << "Removing 'C'.\n";
    s.erase('C');
    for(citr = s.begin(); citr != s.end(); ++citr)
        std::cout << *citr << " ";
    std::cout << std::endl;

    std::cout << "Set contains 'C': ";
    if(s.find('C') == s.end())
        std::cout << " no\n";
    else
        std::cout << " yes\n";
}

/*
<MAP> TEMPLATE CLASS - 

A <map> is essentially a function given as a set of ordered pairs. For each value (first)
that appears in a pair, there is at most one value (second) such that the pair (first, second)
is in the map. The template class <map> implements map objects in the STL. To declard a
map:
*/
    std::map<std::string, int> numberMap;
    std::map<std::string, int, std::greater<std::string>> map2;

/*
For string values known as /keys/, the numberMap object can associate a unique /int/ 
value. An alternate way to think a map is as an associative array. A traditional array
maps from a numerical index to a value. For example, a[10] = 5 would store the number 5 
at index 10. An associate array allows you to define your own indices using the data type
of your choice. For example, numberMap["c++"] = 5 would associate the integer 5 with the
string "c++". For convenience, the [] square bracket operator is defined to allow you 
to use an array-like notation to access a map, although you can also use the /insert/ 
or /find/ functions if you want.

Like a <set> object, a <map> object stores its elements sorted by its key values. You
can specify the ordering on keys as a third entry in the angular brackets <>. If you do 
not specify an ordering, a default ordering is used. The restrictions on orderings you 
can use are the same as those on the orderings allowed for the <set> template class. Note
that the ordering is on key values only. The second type can be any type and need not 
have anything to do with any ordering. As with the <set> object, the sorting of the stored
entries in a <map> object is done for reasons of efficiency.

The easiest way to add and retrieve data from a map is to use the [] operator. Given a
map object m, the expression m[key] will return a reference to the data element associated
with the key. If no entry exists in the map for the key then a new entry will be created
with the default value for the data element. This can be used to add a new item to the
map or to replace an existing entry. For example, the statement m[key] = newData; will 
create a new association between key and newData. Note that care must be taken to ensure
that map entries are not created by mistake. For example, if you execute the statement 
val = m[key]; with the intention of retrieving the value associated with key but mistakenly
enter a value for key that is not already in the map, then a new entry will be made for
key with the default value and assigned to val.


<MAP> MEMBER FUNCTIONS - (m is a map object)

MEMBER FUNCTION     MEANING 
m.insert(elem)      Inserts (elem) in the map. (elem) is of type pair<KeyType,T>. Returns
                    a value of type par<iterator,bool>. If the insertion is successful, 
                    the second part of the returned pair is true and the iterator is located
                    at the inserted element.
m.erase(Target_Key) Removes the element with the key Target_Key.
m.find(Target_Key)  Returns an iterator located at the element with key value Target_Key.
                    If the map does not already contain such an object, then a default
                    object of type T is inserted.
m.size()            Returns the number of pairs in the map.
m.empty()           Returns true if the map is empty; otherwise returns false.
m1 == m2            Returns true of the maps contain the same pairs; otherwise false.
The <map> template class also has a default constructor, a copy constructor, and other 
specialized constructors not mentioned here. It has a destructor as well that returns all
storage for recycling, and a well-behaved assignment operator.

In order to understand the <map> template class, you need to understand how the <pair>
template class works.
The STL template class pair<T1,T2> has objects that are pairs of values such that the first
element is of type T1 and the second is of type T2. If aPair is an object of type pair<T1,T2>, 
then aPair.first is the first element, which is of type T1, and aPair.second is the second
element, which is of type T2. The member variables /first/ and /second/ are public member
variable, so no accessor or mutator fuctions are needed.

The header file for the pair template is <utility>. So, to use the pair template class,
you need to include <utility>.
*/
void map() {

    std::map<std::string, int> numberMap;
    numberMap["c++"] = 10;
    
    typedef std::map<std::string, int>::iterator MapItr;
    //Print with iterator
    MapItr itr;
    for(itr = numberMap.begin(); itr != numberMap.end(); ++itr) {
        std::cout << "Key: " << itr->first << ", Value: " << itr->second << "\n";
    }
    //Print with for each loop
    for(const auto& pair : numberMap) {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << "\n";
    }
}
/*
<MULTISET> AND <MULTIMAP> - 
The template clases multiset and multimap are essentially the same as set and map, 
respectively, except that multiset allows repitition of elements and multimap allows
multiple values to be associated with each key value. Some implementations of STL also
include the <hash_set> and <hash_map> classes. These template classes are essentially
the same as set and map, except they are implemented using a hash table. Instead of
has tables, most implementations of the set and map class use balanced binary trees.
In a balanced binary trr, the number of nodes to the left of the root is approximately
equal to the number of nodes to the right of the root. Binary search trees are also 
described in Chapter 17, although we do not discuss the details of balancing them.
*/