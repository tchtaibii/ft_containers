/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_range.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 17:56:15 by mleblanc          #+#    #+#             */
/*   Updated: 2023/01/24 23:35:52 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_assign_range()
{
    SETUP_ARRAYS();

    {
        strvector v;

        CHECK_AND_PRINT_ALL(v);

        v.assign(b_string, b_string + b_size);

        CHECK_AND_PRINT_ALL(v);

        v.assign(s_string, s_string + s_size);

        CHECK_AND_PRINT_ALL(v);

        v.assign(s_string, s_string);

        CHECK_AND_PRINT_ALL(v);
    }

    {
        longvector v;

        CHECK_AND_PRINT_ALL(v);

        v.assign(b_long, b_long + b_size);

        CHECK_AND_PRINT_ALL(v);

        v.assign(s_long, s_long + s_size);

        CHECK_AND_PRINT_ALL(v);
    }

    {
        intvector v(s_int, s_int + s_size);

        CHECK_AND_PRINT_ALL(v);

        v.push_back(64);
        v.assign(b_int, b_int + b_size);

        CHECK_AND_PRINT_ALL(v);
    }

    {
        intvector v(s_int, s_int + s_size);

        CHECK_AND_PRINT_ALL(v);

        v.push_back(64);
        v.assign(v.begin(), v.begin() + 21);

        CHECK_AND_PRINT_ALL(v);

        v.push_back(64);
        v.assign(v.begin(), v.end());

        CHECK_AND_PRINT_ALL(v);
    }

    {
        // This test checks if vector works with iterators tagged as std::input_iterator_tag
        charvector v;

        std::istringstream str("1 2 3 4 5 6 7");
        std::istreambuf_iterator<char> it(str), end;

        CHECK_AND_PRINT_ALL(v);

        v.assign(it, end);

        CHECK_AND_PRINT_ALL(v);
    }
}

MAIN(vec_test_assign_range)