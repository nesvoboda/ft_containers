#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <stdexcept>
# include <iostream>
# include <limits>
# include "revIterator.hpp"

// how many elements allocate for empty list
# define START_ALLOC 10

// How many times more elements reserve
# define RESERVE_FACTOR 2

namespace ft
{

    template <bool B, class T = void>
	struct enable_if
	{
	};

	template <class T>
	struct enable_if<true, T>
	{
		typedef T type;
	};

    // Stay tuned for the iterator
    template <typename T, typename Val>
    class vectorIterator;    

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
        typedef vectorIterator<T, T> iterator;
        typedef vectorIterator<T, const T> const_iterator;
        typedef rev_iterator<vectorIterator<T, T> > reverse_iterator;
        typedef rev_iterator<vectorIterator<T, const T> > const_reverse_iterator;
    
    private:
        /* data */
        pointer _base;
        size_type _size;
        size_type _capacity;

    public:
        
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

                // range (3)	
        // template <class InputIterator>
        // vector (InputIterator first, InputIterator last,
        //          const allocator_type& alloc = allocator_type());
        // copy (4)	
        // vector (const vector& x);

        // Element access
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

        reference front() { return *_base; };
        const_reference front() const { return *_base; };

        reference back() { return *(_base + _size - 1); };
        const_reference back() const { return *(_base + _size - 1); };

        // Capacity

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

        // Modifiers

        // range (1)	
        template <class InputIterator>
        void assign (typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
            delete[] _base;
            _capacity = START_ALLOC;
            _base = new T[_capacity];
            _size = 0;
            for (InputIterator it = first; it != last; it++)
            {
                push_back(*it);
            }
        }

        // fill (2)	
        void assign (size_type n, const value_type& val)
        {
            if (n > _capacity)
            {
                delete[] _base;
                _capacity = n * RESERVE_FACTOR;
                _base = new T[_capacity];
                for (size_type i = 0; i < n; i++)
                    _base[i] = val;
                _size = n;
            }
            else
            {
                for (size_type i = 0; i < n; i++)
                    _base[i] = val;
                _size = n;
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

        // Iterators
        iterator begin() { return iterator(_base); }
        const_iterator begin() const { return const_iterator(_base); }

        iterator end() { return iterator(_base + _size); }
        const_iterator end() const { return const_iterator(_base + _size); }

        reverse_iterator rbegin() { return reverse_iterator(_base + _size); } ;
        const_reverse_iterator rbegin() const { return const_reverse_iterator(_base + _size); };

        reverse_iterator rend() { return reverse_iterator(_base); };
        const_reverse_iterator rend() const { return const_reverse_iterator(_base); };

        ~vector() {};

    };

    template <typename Tt, typename Val>
        class vectorIterator
        {
        public:
            typedef typename vector<Tt>::size_type size_type;
            typedef Val value_type;
        
        private:
            Tt *_ptr;
        public:
            vectorIterator(void) : _ptr(NULL) {};
            vectorIterator(const vectorIterator &copy) : _ptr(copy._ptr) {};
            vectorIterator(Tt *ptr) : _ptr(ptr) {};
            // vectorIterator(vector<Tt> *vec, size_type index) : _vec(vec), _index(index) {};
            // vectorIterator(const vectorIterator &copy) : _vec(copy._vec), _index(copy._index) {};
            vectorIterator &operator=(const vectorIterator &op)
            {
                _ptr = op._ptr;
                return (*this);
            }

            Tt *base() const { return _ptr; };

            // vectorIterator(/* args */);
            // ~vectorIterator();

        
            Val &operator*(void) {
                return *_ptr;
            }

            Val *operator->(void) {
                return _ptr;
            }

            vectorIterator &operator++()
            {
                _ptr++;
                return *this;
            }
            vectorIterator &operator--()
            {
                _ptr--;
                return *this;
            }

            vectorIterator operator++(int)
            {
                vectorIterator retval = *this;
                ++(*this);
                return retval;
            }
            vectorIterator operator--(int)
            {
                vectorIterator retval = *this;
                --(*this);
                return retval;
            }

            vectorIterator operator+(int i) const
            {
                vectorIterator<Tt, Val> retval(_ptr+i);
                return retval;
            }
            vectorIterator operator-(int i) const
            {
                vectorIterator<Tt, Val> retval(_ptr-i);
                return retval;
            }

            vectorIterator& operator +=(int i)
            {
                _ptr += i;
                return (*this);
            }

            vectorIterator& operator -=(int i)
            {
                _ptr -= i;
                return (*this);
            }

            template <typename T1, typename Val1>
            friend class vectorIterator; // we have to befriend other iterators to be able to compare with them

        };

    template <typename T, typename Val>
    bool operator==(const vectorIterator<T, Val>& lhs, const vectorIterator<T, Val>& rhs)
    { 
        return (lhs.base() == rhs.base());
    }

    template <typename T, typename Val>
    bool operator!=(const vectorIterator<T, Val>& lhs, const vectorIterator<T, Val>& rhs)
    { 
        return (!(lhs == rhs));
    }

    
} // namespace ft


#endif