/// @file ArrayList.h

#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include <initializer_list>

namespace cs202 {

/// An ArrayList is a container that encapsulates dynamic arrays.
/// The storage of an ArrayList is handled automatically, being
/// expanded as needed.
class ArrayList {
public:
    // type aliases
    using value_type      = int;
    using size_type       = std::size_t;
    using reference       = value_type&;
    using const_reference = const value_type&;
    using pointer         = value_type*;
    using const_pointer   = const value_type*;

    /// Default ctor. Constructs an ArrayList with count copies of the
    /// default value of value_type, e.g., the default value for an
    /// int is 0.
    ArrayList(size_type count = 0);

    /// Copy constructor. Makes a deep copy of another ArrayList.
    ArrayList(const ArrayList& other);

    /// Constructs the container with a copy of the contents of source.
    ArrayList(const std::initializer_list<value_type>& source);

    /// Destructor.
    virtual ~ArrayList();

    /// Accesses the specified element with bounds checking.
    reference at(size_type pos);
    const_reference at(size_type pos) const;

    /// Accesses the first element.
    /// Calling front on an empty container is undefined.
    reference front();
    const_reference front() const;

    /// Accesses the last element.
    /// Calling back on an empty container is undefined.
    reference back();
    const_reference back() const;

    /// Returns a pointer to the beginning of the container
    pointer begin() { return m_data; };                      // do not modify
    const_pointer begin() const { return m_data; };          // do not modify

    /// Returns a pointer to the end of the container
    pointer end() { return begin() + size(); };              // do not modify
    const_pointer end() const { return begin() + size(); };  // do not modify

    /// Checks whether the container is empty, e.g. size() == 0
    bool empty() const;

    /// Returns the number of elements in use
    size_type size() const;

    /// Returns the number of elements that can be held in currently allocated
    /// storage.
    size_type capacity() const;

    /// Clears the contents. After this call, size() returns zero.
    /// Leaves the capacity() of the container unchanged.
    void clear();

    /// Appends the given element value to the end of the container. If the
    /// new size() is greater than capacity(), reallocation occurs.
    void push_back(const value_type& value);

    /// Resizes the container to contain count elements. If the current size
    /// is greater than count, the container is reduced to its first count
    /// elements. If the current size is less than count, additional default-
    /// constructed elements are appended.
    void resize(size_type count);

    /// Exchanges the contents of the container with those of another. Does
    /// not invoke any move, copy, or swap operations on individual elements.
    void swap(ArrayList& other);

    ArrayList& operator=(const ArrayList&) = delete;         // do not modify

protected:
    size_type m_capacity;  ///< The number of elements that can be stored.
    size_type m_size;      ///< The number of elements in use.
    pointer   m_data;      ///< Dynamically-allocated array custodian.
};  // Array

/// Compares the contents of two ArrayLists. Checks that each element in lhs
/// compares equal to each element in rhs at the same position.
bool equal(const ArrayList& lhs, const ArrayList& rhs);

/// Copies the elements in the range, defined by [first, last), to another
/// range beginning at d_first.
void copy(ArrayList::const_pointer first,
          ArrayList::const_pointer last,
          ArrayList::pointer d_first);

} // namespace cs202

/* EOF */

#endif
