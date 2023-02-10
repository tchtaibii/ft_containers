#pragma once

namespace ft
{
	template <class T1, class T2>
	class pair
	{
		typedef	T1	first_type;
		typedef	T2	second_type;

		private:
		const first_type	first;
		second_type	second;

		public:
		first_type first_() const {return this->first;}
		second_type second_() const {return this->second;}
		pair () : first(), second() {}
		template<class U, class V>
		pair (const pair<U,V>& pr) : first(pr.first_()), second(pr.second_()) {}
		pair (const first_type& a, const second_type& b) : first(a), second(b) {}
		pair& operator= (const pair& pr)
		{
			this->first = pr.first_();
			this->second = pr.second_();
			return (*this);
		}
	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		if ((lhs.first < rhs.first) || (lhs.first == rhs.first && lhs.second < rhs.second))
			return (true);
		return (false);	
	}
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs < rhs || lhs == rhs);
	}
	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (rhs < lhs);
	}
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs > rhs || lhs == rhs);
	}
	template <class T1, class T2>
	pair<T1, T2> make_pair (T1 x, T2 y)
	{
		return (pair<T1, T2> (x, y));
	}
}