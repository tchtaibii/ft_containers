#ifndef FT_vector_HPP
#define FT_vector_HPP

#include <iostream>

namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
		typedef T value_type;
		typedef T* pointer;
		typedef const T* const_pointer;
		typedef T& reference;
		typedef const T& const_reference;
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef typename ft::iterator<value_type> iterator;
		typedef typename ft::iterator<value_type>::difference_type difference_type;

	public:
		// Default constructor
		vector(const allocator_type &alloc = allocator_type()) : data_(nullptr), size_(0), capacity_(0), alloc(alloc) {}
		// Constructor that takes an initial size and a value
		vector(size_t size, value_type value = T(), const allocator_type &alloc = allocator_type()) : alloc(alloc)
		{
			size_ = size;
			capacity_ = size;
			data_ = this->alloc.allocate(size);
			for (size_type i = 0; i < size; i++)
				this->alloc.construct(data_ + i, value);
		}
		// Copy constructor
		vector(const vector &other) : data_(nullptr), size_(other.size_), capacity_(other.capacity_), alloc(other.alloc)
		{
			data_ = this->alloc.allocate(size_);
			for (size_type i = 0; i < size_; i++)
				this->alloc.construct(data_ + i, other.data_[i]);
		}
		// Assigment copy
		vector &operator=(const vector &other)
		{
			if (this != &other)
			{
				// Deallocate the current data array
				for (size_type i = 0; i < size_; i++)
					this->alloc.destroy(data_ + i);
				this->alloc.deallocate(data_, size_);
				// Allocate a new data array and copy the elements from the other vector
				size_ = other.size_;
				capacity_ = other.capacity_;
				data_ = this->alloc.allocate(size_);
				for (size_type i = 0; i < size_; i++)
					this->alloc.construct(data_ + i, other.data_[i]);
			}
			return *this;
		}
		// Destructor
		~vector()
		{
			for (size_t i = 0; i < size_; i++)
				alloc.destroy(data_ + i);
			alloc.deallocate(data_, size_);
		}

		// Return true if the vector is empty
		bool empty() const { return size_ == 0; }

		// Return the number of elements in the vector
		size_type size() const { return size_; }

		// Return size of allocated storage capacity r
		size_type capacity() const { return capacity_; }

		// Return max size of the vector
		size_type max_size() const { return alloc.max_size(); }

		// Add an element to the end of the vector
		void push_back(value_type value)
		{
			if (size_ == capacity_)
				this->resize(size_ + 1);
			this->alloc.construct(data_ + size_ + 1, value);
		}

		// Removes the last element in the vector, effectively reducing the container size by one.
		void pop_back()
		{
			if (size_ != 0)
			{
				this->alloc.destroy(data_[size_ - 1]);
				--size_;
			}
		}

		// Resizes the container so that it contains n elements.
		void resize(size_type n, value_type val = value_type())
		{
			if (n < size_)
			{
				while (n < size_)
				{
					this->alloc.destroy(data_ + n);
					--size_;
				}
			}
			else
			{
				int tmp_capacity = this->capacity();
				int tmp_size = this->size();
				if (n > capacity_)
				{
					if (capacity_ * 2 >= n)
						capacity_ *= 2;
					else
						capacity_ = n;
				}
				ft::vector<value_type> new_(capacity_, val);
				new_.size_ = n;
				size_type i = -1;
				while (++i < new_.size_)
					new_.alloc.construct(new_.data_ + i, this->data_[i]);
				*this = new_;
			}
		}

		// Returns a reference to the element at position n in the vector.
		value_type &at(size_t index)
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return data_[index];
		}

		// Return a reference to the element at the given index, without bounds checking
		value_type &operator[](size_t index) { return data_[index]; }

		// Returns a reference to the first element in the vector.
		reference front() { return data_[0]; }

		// Returns a reference to the last element in the vector.
		reference back() { return data_[size_ - 1]; }

		// Requests that the vector capacity be at least enough to contain n elements.
		void reserve(size_type n)
		{
			if (capacity_ < n)
			{
				pointer new_data_ = this->alloc.allocate(n);
				for (size_type i = 0; i < size_; i++)
					this->alloc.construct(new_data_ + i, this->data_[i]);
				data_ = new_data_;
				capacity_ = n;
			}
		}

		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		void clear()
		{
			if (size_ != 0)
			{
				for (size_t i = 0; i < size_; i++)
					alloc.destroy(data_ + i);
				size_ = 0;
			}
		}

		// Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		void swap(vector &x)
		{
			pointer tmp1, tmp2;
			size_type tmp_size1, tmp_size2;
			size_type tmp_capacity1, tmp_capacity2;

			tmp1 = this->alloc.allocate(size_);
			tmp_size1 = size_;
			tmp_capacity1 = capacity_;
			for (size_type i = 0; i < size_; i++)
				this->alloc.construct(tmp1 + i, data_[i]);

			tmp2 = x.alloc.allocate(x.size_);
			tmp_size2 = x.size_;
			tmp_capacity2 = x.capacity_;
			for (size_type i = 0; i < x.size_; i++)
				x.alloc.construct(tmp2 + i, x.data_[i]);
			size_ = tmp_size2;
			capacity_ = tmp_capacity2;
			data_ = tmp2;
			x.size_ = tmp_size1;
			x.capacity_ = tmp_capacity1;
			x.data_ = tmp1;
		}

		iterator begin()
		{
			
		}

	private:
		pointer data_;
		size_type size_;
		size_type capacity_;
		allocator_type alloc;
	};
}
#endif