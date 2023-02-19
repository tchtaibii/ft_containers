/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compare.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 02:53:39 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/15 21:34:27 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"
#include <functional>

void map_test_compare()
{
    SETUP_ARRAYS();

    {
        NAMESPACE::map<int, std::string, std::greater<int>,
                       track_allocator<NAMESPACE::pair<const int, std::string> > >
            m(intstr_arr, intstr_arr + intstr_size);
        PRINT_ALL(m);
    }
}

MAIN(map_test_compare)
