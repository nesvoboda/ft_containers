#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include <limits>

// how many elements allocate for empty list
# define START_ALLOC 10

// How many times more elements reserve
# define RESERVE_FACTOR 2

namespace ft
{
    template <typename T, typename Alloc = std::allocator<T> >
    class vector
    {
    public:
        // Member types
        typedef T value_type;
        typedef Alloc allocator_type;
        typedef value_type& reference;
        typedef const value_type& const_reference;
        typedef value_type* pointer;
        typedef size_t size_type;
    
    private:
        /* data */
        pointer _base;
        size_type _size;
        size_type _capacity;

    public:

        // iterator ... TODO
        
        // default (1)	
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            _base = new T[START_ALLOC];
            _size = 0;
            _capacity = START_ALLOC;
        }
        // fill (2)	
        explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
        {
            _capacity = n * RESERVE_FACTOR;
            _base = new T[_capacity];
            for (size_type i = 0; i < n; i++)
                _base[i] = val;
            _size = n;
        }

        reference operator[] (size_type n)
        {
            return _base[n];
        }
        const_reference operator[] (size_type n) const
        {
            return _base[n];
        }

        reference at (size_type n)
        {
            if (n >= _size)
            {
                throw std::out_of_range("oopsie");
            }
            return _base[n];
        }
        const_reference at (size_type n) const
        {
            if (n >= _size)
                throw std::out_of_range("oopsie");
            return _base[n];
        }

        size_type size() const
        {
            return _size;
        }

        size_type max_size() const
        {
            return std::numeric_limits<size_type>::max();
        }

        bool empty() const
        {
            return _size == 0;
        }

        size_type capacity() const { return _capacity; }

        void reserve (size_type n)
        {
            if (n > _capacity)
            {
                size_type newCapacity = n;
                pointer newBase = new value_type[newCapacity];
                for (size_type i = 0; i < _size; i++)
                {
                    newBase[i] = _base[i];
                }
                delete _base;
                _base = newBase;
                _capacity = newCapacity;
            }
        }

        void push_back (const value_type& val)
        {
            if (_capacity == _size)
            {
                reserve(_capacity * RESERVE_FACTOR);
            }
            _base[_size] = val;
            _size++;
        }

        void pop_back()
        {
            _size--;
        }

        void clear()
        {
            _size = 0;
        }

        // range (3)	
        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last,
        //          const allocator_type& alloc = allocator_type());
        // copy (4)	
        // vector (const vector& x);

        ~vector() {};

    };
    
} // namespace ft


#endif