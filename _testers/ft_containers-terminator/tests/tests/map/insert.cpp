/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:41:58 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/11 23:36:49 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

#define PRINT_INS_PAIR(p)                                                                          \
    {                                                                                              \
        PRINT_PAIR_REF(*p.first);                                                                  \
        PRINT_LINE("Inserted:", p.second ? "true" : "false");                                      \
    }

void map_test_insert()
{
    SETUP_ARRAYS();

    {
        typedef NAMESPACE::pair<intmap::iterator, bool> ins_pair;

        intmap m;

        ins_pair p = m.insert(NAMESPACE::make_pair(64, "64str"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair(64, "Double"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair(0, "0str"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair(-23, "-23str"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair(64, "dfgs"));

        PRINT_INS_PAIR(p);
    }
    {
        typedef NAMESPACE::pair<strmap::iterator, bool> ins_pair;

        strmap m;

        ins_pair p = m.insert(NAMESPACE::make_pair("64", "64str"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair("64n", "Double"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair("0n", "0str"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair("-23n", "-23str"));

        PRINT_INS_PAIR(p);

        p = m.insert(NAMESPACE::make_pair("64n", "dfgs"));

        PRINT_INS_PAIR(p);
    }
}
MAIN(map_test_insert)
