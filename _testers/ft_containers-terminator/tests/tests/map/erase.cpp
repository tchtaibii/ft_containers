/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   erase.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 00:04:03 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/14 23:38:29 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_erase()
{
    SETUP_ARRAYS();

    {
        intmap m(intstr_arr, intstr_arr + 25);

        intmap::iterator it = m.begin();

        m.erase(it);

        PRINT_ALL(m);

        it = m.begin();

        std::advance(it, 21);

        m.erase(it);

        PRINT_ALL(m);

        it = m.end();

        it = m.end();

        std::advance(it, -3);

        m.erase(it);
        

        PRINT_ALL(m);

        it = m.end();

        std::advance(it, -1);
        
        m.erase(it);

        PRINT_ALL(m);

        it = m.begin();

        std::advance(it, 1);

        m.erase(it);

        PRINT_ALL(m);

        for (it = m.begin(); it != m.end(); it = m.begin()) {
            m.erase(it);
            PRINT_ALL(m);
        }
    }
}

MAIN(map_test_erase)
