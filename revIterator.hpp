#ifndef REVITERATOR_HPP
# define REVITERATOR_HPP

template <class iterator>
	class rev_iterator
	{
		iterator _iter;

	public:
		typedef typename iterator::value_type value_type;

		rev_iterator() : _iter(){};

		explicit rev_iterator(iterator it) : _iter(it){};

		template <typename otherIterator>
		rev_iterator(const rev_iterator<otherIterator> &it) : _iter(it.base()){};

		rev_iterator(rev_iterator<iterator> const &it) : _iter(it._iter){};
		rev_iterator &operator=(const rev_iterator &operand)
		{
			_iter = operand._iter;
			return (*this);
		}
		iterator base() const { return _iter; }
		virtual ~rev_iterator(void){};
		rev_iterator &operator++()
		{
			_iter = _iter.operator--();
			return *this;
		}
		rev_iterator &operator--()
		{
			_iter = _iter.operator++();
			return *this;
		}
		value_type &operator*()
		{
			// iterator i = _iter;
			// i--;
			return (--iterator(_iter)).operator*();
		}
		rev_iterator operator++(int)
		{
			rev_iterator retval = *this;
			++(*this);
			return retval;
		}
		rev_iterator operator--(int)
		{
			rev_iterator retval = *this;
			--(*this);
			return retval;
		}
		value_type *operator->(void) { return &this->operator*(); };

        // Only for randomAccess

        rev_iterator operator+(int i) const
        {
            return rev_iterator(_iter.operator-(i));
        }
        rev_iterator operator-(int i) const
        {
            return rev_iterator(_iter.operator+(i));
        }

        rev_iterator& operator +=(int i)
        {
            _iter.operator-=(i);
            return (*this);
        }

        rev_iterator& operator -=(int i)
        {
            _iter.operator+=(i);
            return (*this);
        }

        //

		template <typename OtherIterator>
		bool operator==(const rev_iterator<OtherIterator> &other) const
		{
			return _iter.operator==(other.base());
		}
		template <typename OtherIterator>
		bool operator!=(const rev_iterator<OtherIterator> &other) const { return !(*this == other); }
		// reverse_iterator &operator*() const {return _iter.operator*(); return *this;}
	};

#endif