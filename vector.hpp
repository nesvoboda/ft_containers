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

    template <typename T>
	void swap_val(T &a, T &b)
	{
		T buf = a;
		a = b;
		b = buf;
	}

    template<typename T>
    T min(T a, T b)
    {
        return a < b ? a : b;
    }

    template <typename InputIterator>
    size_t distance(InputIterator a, InputIterator b)
    {
        size_t s = 0;
        while (a != b)
        {
            a++;
            s++;
        }
        return s;
    }

    template<typename T, typename T1>
    T min(T a, T1 b)
    {
        return a < b ? a : b;
    }

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
        typedef const value_type* const_pointer;
        typedef vectorIterator<T, T> iterator;
        typedef vectorIterator<T, const T> const_iterator;
        typedef rev_iterator<vectorIterator<T, T> > reverse_iterator;
        typedef rev_iterator<vectorIterator<T, const T> > const_reverse_iterator;
        typedef ptrdiff_t difference_type;
        typedef size_t size_type;
    
    private:
        /* data */
        pointer _base;
        size_type _size;
        size_type _capacity;
        allocator_type _alloc;

    public:
        
        // TODO Use allocator properly

        // default (1)	
        explicit vector (const allocator_type& alloc = allocator_type())
        {
            _base = new T[1];
            _size = 0;
            _capacity = 0;
            _alloc = alloc;

        }
        // fill (2)	
        explicit vector (size_type n, const value_type& val = value_type(),
                 const allocator_type& alloc = allocator_type())
        {
            _capacity = n;
            _base = new T[_capacity];
            for (size_type i = 0; i < n; i++)
                _base[i] = val;
            _size = n;
            _alloc = alloc;
        }

        // range (3)	
        template <class InputIterator>
        vector (typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last,
                 const allocator_type& alloc = allocator_type())
        {
            _alloc = alloc;
            _capacity = 0;
            _base = new T[1];
            _size = 0;
            // for (InputIterator it = first; it != last; it++)
            // {
            //     push_back(*it);
            // } 
            assign(first, last);
        }

        // copy (4)	
        vector (const vector& x)
        {
            _alloc = x.get_allocator();
            _capacity = x.capacity();
            _base = new T[_capacity];
            _size = 0;
            
            for (vector::const_iterator it = x.begin(); it != x.end(); it++)
            {
                _base[_size++] = *it;
            }
        }

        ~vector() {

            delete[] _base;
            _size = 0;
            _capacity = 0;
        };

        vector& operator= (const vector& x)
        {
             _alloc = x.get_allocator();

            if (_capacity < x.capacity())
            {
                delete[] _base;
                _capacity = x.size();
                _base = new T[_capacity];
                _size = 0;
                for (vector::const_iterator it = x.begin(); it != x.end(); it++)
                {
                    _base[_size++] = *it;
                }
            }
            else
            {
                _size = 0;
                for (vector::const_iterator it = x.begin(); it != x.end(); it++)
                {
                    _base[_size++] = *it;
                }
            }
            return (*this);
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

        // Capacity

        size_type size() const
        {
            return _size;
        }

        size_type max_size() const
        {
            return min(_alloc.max_size(), (unsigned long)std::numeric_limits<difference_type>::max());
        }

        void resize (size_type n, value_type val = value_type()) {
            if (n < _size)
            {
                // TODO check if destruction here is ok
                _size = n;
            }
            if (n > _size)
            {
                if (n > _capacity)
                    reserve(n * RESERVE_FACTOR);
                while (_size != n)
                {
                    _base[_size++] = val;
                }
            }
        }

        size_type capacity() const { return _capacity; }

        bool empty() const { return _size == 0; }

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

        // Modifiers
          template <class Iterator>
            struct iterator_traits {
                typedef typename Iterator::iterator_category iterator_category;
                // typedef typename Iterator::value_type        value_type;
                // typedef typename Iterator::difference_type   difference_type;
                // typedef typename Iterator::pointer           pointer;
                // typedef typename Iterator::reference         reference;
        };

        // range (1)	
        template <class InputIterator>
        void assign (typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
            size_t their_len = ft::distance(first, last);
            // std::cout << "Their len: " << their_len << std::endl;
            if (their_len > _capacity)
            {
                delete[] _base;
                _capacity = their_len;
                _base = new T[their_len];
                _size = 0;
                
                for (InputIterator it = first; it != last; it++)
                {
                    _base[_size++] = *it;
                }
            }
            else {
                _size = 0;
                for (InputIterator it = first; it != last; it++)
                {
                    _base[_size++] = *it;
                }
            }

            
        }

        // fill (2)	
        void assign (size_type n, const value_type& val)
        {
            // if (n > _capacity)
            // {
            //     delete[] _base;
            //     _capacity = n * RESERVE_FACTOR;
            //     _base = new T[_capacity];
            //     for (size_type i = 0; i < n; i++)
            //         _base[i] = val;
            //     _size = n;
            // }
            // else
            // {
            //     for (size_type i = 0; i < n; i++)
            //         _base[i] = val;
            //     _size = n;
            // }


            if (n > _capacity)
            {
                delete[] _base;
                _capacity = n;
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
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity*2);
            }
            _base[_size] = val;
            _size++;
        }

        void pop_back()
        {
            _size--;
        }

        // single element (1)	
        iterator insert (iterator position, const value_type& val)
        {
            size_type target_index = position.base() - _base;

            if (_size == _capacity)
            {
                reserve((_size + 1) * RESERVE_FACTOR);
            }

            for (size_type z = _size; z != target_index; z--)
            {
                _base[z] = _base[z-1];
            }
            _base[target_index] = val;
            _size++;
            return iterator(&_base[target_index]);
        }

        // fill (2)	
        void insert (iterator position, size_type n, const value_type& val)
        {
            size_type target_index = position.base() - _base;

            if ((_size+n) >= _capacity)
            {
                reserve((_size + n) * RESERVE_FACTOR);
            }

            // size_type target_index = position.base() - _base;
            for (size_type z = _size+n-1; z != target_index+n-1; z--)
            {
                _base[z] = _base[z-n];
            }
            // _base[target_index] = val;
            for (size_type x = target_index; x != target_index+n; x++)
                _base[x] = val;
            _size += n;
        }

        // range (3)	
        template <class InputIterator>
            void insert (iterator position, typename ft::enable_if<!std::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last)
        {
            size_type target_index = position.base() - _base;

            size_type n = ft::distance(first, last);

            if ((_size+n) >= _capacity)
            {
                reserve((_size + n));
            }

            // size_type target_index = position.base() - _base;
            for (size_type z = _size+n-1; z != target_index+n-1; z--)
            {
                _base[z] = _base[z-n];
            }
            // _base[target_index] = val;
            // for (size_type x = target_index; x != target_index+n; x++)
            //     _base[x] = val;
            for (InputIterator iter = first; iter != last; iter++)
                _base[target_index++] = *iter;
            _size += n;
        }

        iterator erase(iterator position)
        {
            size_type target_index = position.base() - _base;
            for (size_type i = target_index; i != _size-1; i++)
            {
                _base[i] = _base[i+1];
            }
            _size--;
            return (iterator(&_base[target_index]));
        }

        iterator erase (iterator first, iterator last)
        {
            size_type target_index1 = first.base() - _base;
            size_type target_index2 = last.base() - _base;
            size_type n = target_index2-target_index1;

            for (size_type i = target_index1; i != _size - n; i++)
            {
                _base[i] = _base[i+n];
            }

            _size -= n;
            return (iterator(&_base[target_index1]));
        }

        void swap (vector& x)
        {
            swap_val(_base, x._base);
            swap_val(_capacity, x._capacity);
            swap_val(_size, x._size);
            swap_val(_alloc, x._alloc);
        }

        void clear()
        {
            _size = 0;
        }

        allocator_type get_allocator() const
        {
            return _alloc;
        }

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

            size_type operator-(vectorIterator vi) const
            {
                return _ptr - vi.base();
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

    // (1)	
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;

        typename vector<T, Alloc>::const_iterator lhs_it = lhs.begin();
        typename vector<T, Alloc>::const_iterator rhs_it = rhs.begin();

        for (size_t i = 0; i < lhs.size(); i++)
        {
            if (*lhs_it++ != *rhs_it++)
                return false;
        }
        return true;
    }

    // (2)	
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }

    // (3)	
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        typename ft::vector<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename ft::vector<T, Alloc>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it != *rhs_it)
			{
				if (*lhs_it < *rhs_it)
					return true;
				return false;
			}
			lhs_it++;
			rhs_it++;
		}
		return lhs.size() < rhs.size();
    }
    // (4)	
    template <class T, class Alloc>
    bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs > rhs);
    }
    // (5)	
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        typename ft::vector<T, Alloc>::const_iterator lhs_it = lhs.begin();
		typename ft::vector<T, Alloc>::const_iterator rhs_it = rhs.begin();
		for (size_t i = 0; i < lhs.size(); i++)
		{
			if (*lhs_it != *rhs_it)
			{
				if (*lhs_it > *rhs_it)
					return true;
				return false;
			}
			lhs_it++;
			rhs_it++;
		}
		return lhs.size() > rhs.size();
    }
    // (6)	
    template <class T, class Alloc>
    bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    }

    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);
    }

    
} // namespace ft


#endif