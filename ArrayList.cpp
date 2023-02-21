/// @file ArrayList.cpp

#include "ArrayList.h"  // Using
#include <iostream>

#include <cctype>
#include <cassert>

using namespace std;

// Maintains new variables and fills pointer array
cs202::ArrayList::ArrayList(cs202::ArrayList::ArrayList::size_type count) {
    m_size = count; // New size set to count
    m_capacity = count;     // Max capacity set to count

    m_data = new value_type[count];


    for (size_type i = 0; i < size(); i++) {
        *(ArrayList::m_data + i) = ArrayList::value_type();
    }
}

// Copy constructor for deep copy
cs202::ArrayList::ArrayList(const ArrayList& other) {
    m_size = other.m_size;
    m_data = new value_type[m_size];    // Making a deep copy means
    // making a new set of memory to allocate to

    for (size_type i = 0; i < size(); i++) {
        *(ArrayList::m_data + i) = *(other.m_data + i);
    }
}

cs202::ArrayList::ArrayList::~ArrayList() {
    delete [] ArrayList::m_data;
}

//
cs202::ArrayList::ArrayList(const std::initializer_list<value_type>& source) {

    m_size = source.size();
    m_capacity = m_size;
    m_data = new value_type[m_size];


    for (size_type i = 0; i < size(); i++) {
        *(ArrayList::m_data + i) = *(source.begin() + i);
    }
}

// Return value at position
cs202::ArrayList::reference cs202::ArrayList::ArrayList::at(ArrayList::size_type pos) {
    assert(pos < ArrayList::m_capacity);
    return *(ArrayList::m_data + pos);
}

// Return const at position
cs202::ArrayList::const_reference cs202::ArrayList::ArrayList::at(ArrayList::size_type pos) const {
    assert(pos < ArrayList::m_capacity);
    return *(ArrayList::m_data + pos);
}

// Return value at beginning
cs202::ArrayList::reference cs202::ArrayList::ArrayList::front() {
    if (ArrayList::m_size == 0) {
        throw std::out_of_range("outta range bro");
    }

    return *(ArrayList::m_data);
}

// Return const at beginning
cs202::ArrayList::const_reference cs202::ArrayList::ArrayList::front() const {
    if (ArrayList::m_size == 0) {
        throw std::out_of_range("outta range bro");
    }

    return *(ArrayList::m_data);
}

// Return value at end
cs202::ArrayList::reference cs202::ArrayList::ArrayList::back() {
    if (ArrayList::m_size == 0) {
        throw std::out_of_range("outta range bro");
    }

    return *(ArrayList::m_data + (ArrayList::m_size - 1));
}

// Return const at end
cs202::ArrayList::const_reference cs202::ArrayList::ArrayList::back() const {
    if (ArrayList::m_size == 0) {
        throw std::out_of_range("outta range bro");
    }

    return *(ArrayList::m_data + (ArrayList::m_size - 1));
}

// Check if container is empty
bool cs202::ArrayList::empty() const {
    return ArrayList::m_size == 0;
    // make sure this works instead of an if statement
}

// Return current num of elements
cs202::ArrayList::size_type cs202::ArrayList::size() const {
    return ArrayList::m_size;
}

// Return num of elements that can be held
cs202::ArrayList::size_type cs202::ArrayList::capacity() const {
    return ArrayList::m_capacity;
}

// Clear container without changing capacity
void cs202::ArrayList::ArrayList::clear() {
    m_size = 0;
}

void cs202::ArrayList::push_back(const cs202::ArrayList::value_type& value) {
        if (size() == capacity()) {

            value_type* final1 = nullptr;

            if (capacity() != 0) {
                m_capacity *= 2;
                final1 = new value_type[m_capacity];
            } else {
                m_capacity = 1;
                final1 = new value_type[m_capacity];
            }

            copy(m_data, m_data + m_size, final1);

            delete [] m_data;
            m_data = final1;

            *(m_data + m_size) = value;
        } else {
            *(m_data + m_size) = value;
        }

        m_size++;

}

// Resizes array based on comparison by count and size
void cs202::ArrayList::resize(ArrayList::size_type count) {


    value_type* final1 = new value_type[count];

    if (size() > count) {

       m_size = count;
       m_capacity = count;
    } else {
        for (size_type i = 0; i < count; ++i) {
            if(i < size()) {
                *(final1 + i) = *(m_data + i);
            } else {
               *(final1 + i) = 0;
            }
        } // reduce to one line

       m_size = count;
       m_capacity = count;

       delete [] m_data;
       m_data = final1;

    }
}


void cs202::ArrayList::swap(ArrayList& other) {
    size_type temp = m_size;
    size_type temp2 = m_capacity;
    pointer temp3 = m_data;

    if (capacity() == 0) {
        temp2 = m_size;
    }

    m_size = other.m_size;
    m_capacity = other.m_capacity;
    m_data = other.m_data;

    other.m_size = temp;

    other.m_capacity = temp2;

    other.m_data = temp3;
    // do how you did with pointers
}

// Check if ranges and elements at positions are equal
 bool cs202::equal(const ArrayList& lhs, const ArrayList& rhs) {
     cs202::ArrayList::value_type inequality = 0;

    if (lhs.size() != rhs.size()) {
        return false;
  }

     for (cs202::ArrayList::size_type i = 0; i < lhs.size(); ++i) {
         if (lhs.cs202::ArrayList::at(i) != rhs.cs202::ArrayList::at(i)) {
             inequality = 1;
         }
     }

     if (inequality != 0) {
         return false;
     } else {
         return true;
     }
 }

// Copy elements in range to another range
void cs202::copy(cs202::ArrayList::const_pointer first, cs202::ArrayList::const_pointer last, cs202::ArrayList::pointer d_first) {
    for (; first != last; ++first, ++d_first) {
        *d_first = *first;
    }
}
