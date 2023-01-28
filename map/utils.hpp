#pragma once

namespace ft
{
    template <typename T1, typename T2>
    class pair
    {
    private:
        T1 m_first;
        T2 m_second;

    public:
        // Constructor with initial values
        pair(const T1 &first, const T2 &second) : m_first(first), m_second(second){}

        // Get first element
        T1 &first()
        {
            return m_first;
        }

        // Get second element
        T2 &second()
        {
            return m_second;
        }
    };
}