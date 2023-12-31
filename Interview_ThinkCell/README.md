## Time 
5-6 Hours 

## Resources
link: https://www.think-cell.com/en/career/jobs/development

## Problem
Correctness: Your program should produce a working interval_map with the behavior
described above. In particular, pay attention to the validity of iterators. It is illegal to
dereference end iterators. Consider using a checking STL implementation such as the
one shipped with Visual C++ or GCC.


## Description 

Interval_map<K,V> is a data structure that associates keys of type K with values of type V. It is designed to be used efficiently in situations where intervals of consecutive keys are associated with the same value. Your task is to implement the assign member function of this data structure, which is outlined below.

interval_map<K, V> is implemented on top of std::map. For more information on std::map, you may refer to 

Each key-value-pair (k,v) in interval_map<K,V>::m_map means that the value v is associated with all keys from k (including) to the next key (excluding) in m_map. The member interval_map<K,V>::m_valBegin holds the value that is associated with all keys less than the first key in m_map.

Example: Let M be an instance of interval_map<int,char> where

M.m_valBegin=='A',
M.m_map=={ (1,'B'), (3,'A') },
Then M represents the mapping

...
-2 -> 'A'
-1 -> 'A'
0 -> 'A'
1 -> 'B'
2 -> 'B'
3 -> 'A'
4 -> 'A'
5 -> 'A'
...
The representation in the std::map must be canonical, that is, consecutive map entries must not contain the same value: ..., (3,'A'), (5,'A'), ... is not allowed. Likewise, the first entry in m_map must not contain the same value as m_valBegin. Initially, the whole range of K is associated with a given initial value, passed to the constructor of the interval_map<K,V> data structure.
Key type

K - Key

besides being copyable and assignable, is less-than comparable via operator<
is bounded below, with the lowest value being std::numeric_limits::lowest()
does not implement any other operations, in particular no equality comparison or arithmetic operators
Value type

V - Value

besides being copyable and assignable, is equality-comparable via operator==
does not implement any other operations. 

## Requeriments

    23.2.1 General container requirements 
    
    §1 Containers are objects that store other objects. They control allocation and deallocation of 
    these objects through constructors, destructors, insert and erase operations.
    
    §6 begin() returns an iterator referring to the first element in the container. end() returns 
    an iterator which is the past-the-end value for the container. If the container is empty, 
    then begin() == end();
    
    24.2.1 General Iterator Requirements
    
    §1 Iterators are a generalization of pointers that allow a C++ program to work with different 
    data structures.
    
    §2 Since iterators are an abstraction of pointers, their semantics is a generalization of most 
    of the semantics of pointers in C++. This ensures that every function template that takes 
    iterators works as well with regular pointers.
    
    §5 Just as a regular pointer to an array guarantees that there is a pointer value pointing past 
    the last element of the array, so for any iterator type there is an iterator value that points 
    past the last element of a corresponding sequence. These values are called past-the-end values. 
    Values of an iterator i for which the expression *i is defined are called dereferenceable. 
    The library never assumes that past-the-end values are dereferenceable. Iterators can also have 
    singular values that are not associated with any sequence. [ Example: After the declaration of 
    an uninitialized pointer x (as with int* x;), x  must always be assumed to have a singular 
    value of a pointer. -end example ] Results of most expressions are undefined for singular 
    values; the only exceptions are destroying an iterator that holds a singular value, the 
    assignment of a non-singular value to an iterator that holds a singular value, and, for 
    iterators that satisfy the DefaultConstructible requirements, using a value-initialized 
    iterator as the source of a copy or move operation.
    
    §10 An invalid iterator is an iterator that may be singular. (This definition applies to 
    pointers, since pointers are iterators. The effect of dereferencing an iterator that has been 
    invalidated is undefined.)
    
    23.2.4 Associative containers
    
    §1 Associative containers provide fast retrieval of data based on keys. The library provides 
    four basic kinds of associative containers: set, multiset, map and multimap.
    
    §4 An associative container supports unique keys if it may contain at most one element for each 
    key. Otherwise, it supports equivalent keys. The set and map classes support unique keys; the 
    multiset and multimap classes support equivalent keys.
    
    §5 For map and multimap the value type is equal to std::pair<const Key, T>. Keys in an 
    associative container are immutable.
    
    §6 iterator of an associative container is of the bidirectional iterator category.
    (i.e., an iterator i can be incremented and decremented: ++i; --i;)
    
    §9 The insert member functions (see below) shall not affect the validity of iterators and 
    references to the container, and the erase members shall invalidate only iterators and 
    references to the erased elements.
    
    §10 The fundamental property of iterators of associative containers is that they iterate 
    through the containers in the non-descending order of keys where non-descending is defined by 
    the comparison that was used to construct them.
    
    Associative container requirements (in addition to general container requirements):
    
    std::pair<iterator, bool> insert(std::pair<const key_type, T> const" t)
    Effects: Inserts t if and only if there is no element in the container with key equivalent to 
    the key of t. The bool component of the returned pair is true if and only if the insertion 
    takes place, and the iterator component of the pair points to the element with key equivalent 
    to the key of t.
    Complexity: logarithmic
    
    iterator insert(const_iterator p, std::pair<const key_type, T> const" t)
    Effects: Inserts t if and only if there is no element with key equivalent to the key of t in 
    containers with unique keys. Always returns the iterator pointing to the element with key 
    equivalent to the key of t. 
    Complexity: logarithmic in general, but amortized constant if t is inserted right before p.
    
    size_type erase(key_type const" k)  
    Effects: Erases all elements in the container with key equivalent to k. Returns the number of 
    erased elements.
    Complexity: log(size of container) + number of elements with key k
    
    iterator erase(const_iterator q) 
    Effects: Erases the element pointed to by q. Returns an iterator pointing to the element 
    immediately following q prior to the element being erased. If no such element exists, returns 
    end().
    Complexity: Amortized constant
    
    iterator erase(const_iterator q1, const_iterator q2)
    Effects: Erases all the elements in the left-inclusive and right-exclusive range [q1,q2). 
    Returns q2.
    Complexity: Amortized O(N) where N has the value distance(q1, q2).
    
    void clear() 
    Effects: erase(begin(), end())
    Post-Condition: empty() returns true
    Complexity: linear in size().
    
    iterator find(key_type const" k);
    Effects: Returns an iterator pointing to an element with the key equivalent to k, or end() if 
    such an element is not found.
    Complexity: logarithmic
    
    size_type count(key_type constquot;& k) 
    Effects: Returns the number of elements with key equivalent to k
    Complexity: log(size of map) + number of elements with key equivalent to k
    
    iterator lower_bound(key_type const" k)
    Effects: Returns an iterator pointing to the first element with key not less than k, or end() 
    if such an element is not found.
    Complexity: logarithmic
    
    iterator upper_bound(key_type const" k)
    Effects: Returns an iterator pointing to the first element with key greater than k, or end() 
    if such an element is not found.
    Complexity: logarithmic
    
    23.4.1 Class template map
    
    §1 A map is an associative container that supports unique keys (contains at most one of each 
    key value) and provides for fast retrieval of values of another type T based on the keys. The 
    map class supports bidirectional iterators.
    
    23.4.1.2 map element access
    
    T" operator[](const key_type" x);
    Effects: If there is no key equivalent to x in the map, inserts value_type(x, T()) into the map. 
    Returns: A reference to the mapped_type corresponding to x in *this.
    Complexity: logarithmic.
    
    T" at(const key_type" x);
    const T" at(const key_type" x) const;
    Returns: A reference to the element whose key is equivalent to x.
    Throws: An exception object of type out_of_range if no such element is present.
    Complexity: logarithmic.
