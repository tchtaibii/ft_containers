/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 19:58:21 by mleblanc          #+#    #+#             */
/*   Updated: 2023/01/18 17:00:07 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"
#include <algorithm>

void vec_test_swap()
{
    SETUP_ARRAYS();

    {
        strvector v1(s_string, s_string + s_size);
        strvector v2(b_string, b_string + b_size);

        v1.swap(v2);

        CHECK_AND_PRINT_ALL(v1);
        CHECK_AND_PRINT_ALL(v2);

        NAMESPACE::swap(v1, v2);

        CHECK_AND_PRINT_ALL(v1);
        CHECK_AND_PRINT_ALL(v2);

        v1.resize(0);

        v1.swap(v2);

        CHECK_AND_PRINT_ALL(v1);
        CHECK_AND_PRINT_ALL(v2);

        v1.resize(0);

        NAMESPACE::swap(v1, v2);

        CHECK_AND_PRINT_ALL(v1);
        CHECK_AND_PRINT_ALL(v2);
    }
}

MAIN(vec_test_swap)
