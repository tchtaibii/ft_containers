/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctor_range.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 10:23:42 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/12 15:43:02 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_ctor_range()
{
    SETUP_ARRAYS();

    {
        track_allocator<NAMESPACE::pair<const int, std::string> > alloc;
        intmap m(intstr_arr, intstr_arr + intstr_size, std::less<int>(), alloc);

        PRINT_ALL(m);

        intmap m2(m.begin(), m.end());

        PRINT_ALL(m);
        PRINT_ALL(m2);
    }

    {
        strmap m1(strstr_arr, strstr_arr + strstr_size);

        PRINT_ALL(m1);

        strmap m2(strstr_arr, strstr_arr + strstr_size);

        PRINT_ALL(m1);
        PRINT_ALL(m2);
    }
}

MAIN(map_test_ctor_range)
