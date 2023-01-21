#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "reverse_iterator.hpp"
#include "utils.hpp"
namespace ft
{
	template <typename T, typename Alloc = std::allocator<T> >
	class vector
	{
	public:
		typedef T value_type;
		typedef const T const_value_type;
		typedef T *pointer;
		typedef const T *const_pointer;
		typedef T &reference;
		typedef const T &const_reference;
		typedef size_t size_type;
		typedef Alloc allocator_type;
		typedef typename ft::iterator<value_type> iterator;
		typedef typename ft::iterator<value_type> const_iterator;
		typedef typename ft::reverse_iterator<iterator> reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
		typedef typename std::ptrdiff_t difference_type;
		// Default constructor
		explicit vector(const allocator_type &alloc = allocator_type()) : data_(NULL), size_(0), capacity_(0), alloc(alloc) {}
		// Constructor that takes an initial size and a value
		explicit vector(size_type size, value_type value = T(), const allocator_type &alloc = allocator_type()) : alloc(alloc)
		{
			size_ = size;
			capacity_ = size;
			data_ = this->alloc.allocate(size);
			for (size_type i = 0; i < size; i++)
				this->alloc.construct(data_ + i, value);
		}
		// Copy constructor
		vector(const vector &other) : data_(NULL), size_(other.size_), capacity_(other.capacity_), alloc(other.alloc)
		{
			data_ = this->alloc.allocate(size_);
			for (size_type i = 0; i < size_; i++)
				this->alloc.construct(data_ + i, other.data_[i]);
		}
		template <class InputIterator>
		vector(InputIterator first, InputIterator last, const allocator_type &alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			this->alloc = alloc;
			vector v;
			while (first != last)
			{
				v.push_back(*first);
				first++;
			}
			this->data_ = this->alloc.allocate(v.size_);
			for (size_type i = 0; i < v.size_; i++)
				this->alloc.construct(data_ + i, v.data_[i]);
			size_ = v.size_;
			capacity_ = v.size_;
		}

		// Assigment copy
		vector &operator=(const vector &other)
		{
			if (this != &other)
			{
				// Deallocate the current data array
				this->clear();
				if (data_)
					this->alloc.deallocate(data_, capacity_);
				// Allocate a new data array and copy the elements from the other vector
				size_ = other.size_;
				capacity_ = other.capacity_;
				data_ = this->alloc.allocate(capacity_);
				for (size_type i = 0; i < size_; i++)
					this->alloc.construct(data_ + i, other.data_[i]);
			}
			return *this;
		}
		// Destructor
		~vector()
		{
			this->clear();
			if (data_)
				alloc.deallocate(data_, capacity_);
		}
		// Return true if the vector is empty
		bool empty() const { return size_ == 0; }
		// Return the number of elements in the vector
		size_type size() const { return size_; }
		// Return size of allocated storage capacity
		size_type capacity() const { return capacity_; }
		// Return max size of the vector
		size_type max_size() const
		{
			// if (typeid(value_type) == typeid(char) || typeid(value_type) == typeid(unsigned char))
			// 	return alloc.max_size() / 2;
			// return alloc.max_size();
			return alloc.max_size() > PTRDIFF_MAX ? PTRDIFF_MAX : alloc.max_size();
		}
		// Add an element to the end of the vector
		void push_back(value_type value)
		{
			this->resize(size_ + 1, value);
		}
		// Removes the last element in the vector, effectively reducing the container size by one.
		void pop_back()
		{
			this->alloc.destroy(data_ + size_ - 1);
			--size_;
		}
		// Resizes the container so that it contains n elements.
		void resize(size_type n, value_type val = value_type())
		{
			if (n > capacity_)
			{
				size_type tmp_size = size_;
				size_type tmp_capacity = capacity_;
				if ((capacity_ * 2) >= n)
					tmp_capacity *= 2;
				else
					tmp_capacity = n;
				pointer data_new = this->alloc.allocate(tmp_capacity);
				size_type i = 0;
				while (i < tmp_size)
				{
					this->alloc.construct(&data_new[i], data_[i]);
					i++;
				}
				while (i < n)
				{
					this->alloc.construct(&data_new[i], val);
					i++;
				}
				size_ = n;
				for (size_type i = 0; i < tmp_size; i++)
					alloc.destroy(&data_[i]);
				if (data_ != NULL)
					this->alloc.deallocate(data_, capacity_);
				capacity_ = tmp_capacity;
				data_ = this->alloc.allocate(capacity_);
				for (size_type i = 0; i < n; i++)
					alloc.construct(&data_[i], data_new[i]);
				for (size_type i = 0; i < n; i++)
					alloc.destroy(&data_new[i]);
				if (data_ != NULL)
					this->alloc.deallocate(data_new, tmp_capacity);
				// data_ = data_new;
			}
			else
			{
				if (n < size_)
				{
					while (n < size_)
					{
						this->alloc.destroy(data_ + size_ - 1);
						size_--;
					}
				}
				else if (n > size_)
					while (size_ < n)
						alloc.construct(&data_[size_++], val);
			}
		}
		// Returns a reference to the element at position n in the vector.
		reference at(size_type index)
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return data_[index];
		}
		const_reference at(size_type index) const
		{
			if (index >= size_)
				throw std::out_of_range("Index out of range");
			return data_[index];
		}
		// Return a reference to the element at the given index, without bounds checking
		reference operator[](size_type index) { return data_[index]; }
		const_reference operator[](const size_type index) const { return data_[index]; }
		// Returns a reference to the first element in the vector.
		reference front() { return data_[0]; }
		const_reference front() const { return data_[0]; }
		// Returns a reference to the last element in the vector.
		reference back() { return data_[size_ - 1]; }
		const_reference back() const { return data_[size_ - 1]; }
		// Requests that the vector capacity be at least enough to contain n elements.
		void reserve(size_type n)
		{
			if (capacity_ < n)
			{
				pointer new_data_ = this->alloc.allocate(n);
				for (size_type i = 0; i < size_; i++)
					this->alloc.construct(new_data_ + i, this->data_[i]);
				for (size_type i = 0; i < size_; i++)
					alloc.destroy(data_ + i);
				if (data_)
					this->alloc.deallocate(data_, capacity_);
				data_ = new_data_;
				capacity_ = n;
			}
		}
		// Removes all elements from the vector (which are destroyed), leaving the container with a size of 0.
		void clear()
		{
			if (size_ != 0)
			{
				for (size_type i = 0; i < size_; i++)
					alloc.destroy(data_ + i);
				size_ = 0;
			}
		}
		// Exchanges the content of the container by the content of x, which is another vector object of the same type. Sizes may differ.
		void swap(vector &x)
		{
			std::swap(data_, x.data_);
			std::swap(size_, x.size_);
			std::swap(capacity_, x.capacity_);
		}
		// begin iterator
		const_iterator begin() { return iterator(data_); }
		iterator begin() const { return const_iterator(data_); }
		// end iterator
		iterator end() { return iterator(data_ + size_); }
		const_iterator end() const { return const_iterator(data_ + size_); }
		// begin iterator
		reverse_iterator rbegin() { return reverse_iterator(this->end()); }

		const_reverse_iterator rbegin() const { return const_reverse_iterator(this->end()); }
		// reverse end
		reverse_iterator rend() { return reverse_iterator(this->begin()); }
		const_reverse_iterator rend() const { return const_reverse_iterator(this->begin()); }
		// The vector is extended by inserting new elements before the element at the specified position
		iterator insert(iterator position, const value_type &val)
		{
			size_type index = (position - this->begin());
			push_back(val);
			size_type tmp_size = size_;
			value_type tmp;
			// shift element to the left
			while (index < tmp_size - 1)
			{
				if (tmp_size - 2 >= 0 && tmp_size - 1 >= 0)
				{
					tmp = data_[tmp_size - 1];
					data_[tmp_size - 1] = data_[tmp_size - 2];
					data_[tmp_size - 2] = tmp;
					tmp_size--;
				}
				else
					break;
			}
			iterator it = std::find(this->begin() + index, this->end(), val);
			return (it);
		}
		void insert(iterator position, size_type n, const value_type &val)
		{
			if ((size_type)std::numeric_limits<difference_type>::max() == n)
				throw std::length_error("Length exception");
			if (n)
			{
				size_type tmp_capacity = 0;
				if (n + size_ > capacity_)
				{
					if ((capacity_ * 2) >= n + size_)
						tmp_capacity = 2 * capacity_;
					else
						tmp_capacity = n + size_;
				}
				else
					tmp_capacity = capacity_;
				size_type i = 0;
				while (i < n)
				{
					position = this->insert(position, val);
					i++;
				}
				capacity_ = tmp_capacity;
			}
		}
		// void insert(iterator position, size_type n, const value_type &val)
		// {
		// 	if ((std::size_t)std::numeric_limits<std::ptrdiff_t>::max() == n)
		// 		throw std::length_error("Length exception");
		// 	if (n)
		// 	{
		// 		vector tmp;
		// 		tmp.resize(size_ + n);
		// 		tmp.clear();
		// 		size_type i = 0;
		// 		iterator it;
		// 		while (i < n)
		// 		{
		// 			position = this->insert(position, val);
		// 			i++;
		// 		}
		// 		for (size_type j = 0; j < size_; j++)
		// 		{
		// 			tmp.data_[j] = data_[j];
		// 			// std::cout << tmp.data_[j] << std::endl;
		// 		}
		// 		this->clear();
		// 		if (data_)
		// 			this->alloc.deallocate(data_, capacity_);
		// 		capacity_ = tmp.capacity_;
		// 		size_ = tmp.size_;
		// 		data_ = tmp.data_;
		// 		// for (size_type j = 0; j < size_; j++)
		// 		// {
		// 		// 	std::cout << data_[j] << std::endl;
		// 		// }
		// 	}
		// }

		template <class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			if (last != first)
			{
				vector tmp;
				while (last != first)
				{
					tmp.push_back(*first);
					first++;
				}
				iterator it = tmp.end();
				while (--it != tmp.begin())
					position = this->insert(position, *it);
				position = this->insert(position, *tmp.begin());
			}
		}
		void assign(size_type n, const value_type &val)
		{
			this->clear();
			this->resize(n, val);
		}
		template <class InputIterator>
		void assign(InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type * = 0)
		{
			this->clear();
			vector tmp(first, last);
			this->resize(tmp.size_, tmp.data_[0]);
			for (size_t i = 0; i < tmp.size_; i++)
				data_[i] = tmp.data_[i];
		}
		iterator erase(iterator position)
		{
			if (size_)
			{
				iterator it = this->begin();
				while (position != it)
					it++;
				size_type i = it - this->begin();
				value_type tmp = data_[i];
				// shift all elements to the right
				for (size_type j = i; j < size_ - 1; j++)
					data_[j] = data_[j + 1];
				data_[size_ - 1] = tmp;
				this->pop_back();
			}
			return (position);
		}
		iterator erase(iterator first, iterator last)
		{
			difference_type it = first - last;
			if (it < 0)
				it *= -1;
			for (size_t i = 0; i < (size_type)it; i++)
			{
				first = this->erase(first);
			}
			return first;
		}
		allocator_type get_allocator() const { return this->alloc; }

	private:
		pointer data_;
		size_type size_;
		size_type capacity_;
		allocator_type alloc;
	};
	template <class T, class Alloc>
	bool operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return 1;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return 1;
		}
		return 0;
	}

	template <class _T, class alloc_>
	void swap(vector<_T, alloc_> &v1, vector<_T, alloc_> &v2)
	{
		v1.swap(v2);
	}

	template <class T, class Alloc>
	bool operator<=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return 0;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return 0;
		}
		return 1;
	}
	template <class T, class Alloc>
	bool operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() > rhs.size())
			return 1;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] > rhs[i])
				return 1;
		}
		return 0;
	}
	template <class T, class Alloc>
	bool operator>=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() < rhs.size())
			return 0;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] < rhs[i])
				return 0;
		}
		return 1;
	}
	template <class T, class Alloc>
	bool operator==(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return 0;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return 0;
		}
		return 1;
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return 1;
		for (size_t i = 0; i < lhs.size() && i < rhs.size(); i++)
		{
			if (lhs[i] != rhs[i])
				return 1;
		}
		return 0;
	}
}
#endif