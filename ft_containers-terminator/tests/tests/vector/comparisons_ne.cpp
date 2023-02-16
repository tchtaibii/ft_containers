/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comparisons_ne.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 15:15:27 by mleblanc          #+#    #+#             */
/*   Updated: 2023/01/18 01:31:29 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

void vec_test_comparisons_ne()
{
    {
        NAMESPACE::vector<long> v1;
        NAMESPACE::vector<long> v2;

        if (v1 != v2) {
            PRINT_MSG("Not equal");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2;

        if (v1 != v2) {
            PRINT_MSG("Not equal.");
        }
    }

    {
        NAMESPACE::vector<long> v1;
        NAMESPACE::vector<long> v2(5, 32);

        if (v1 != v2) {
            PRINT_MSG("Not equal..");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(5, 48);

        if (v1 != v2) {
            PRINT_MSG("Not equal...");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(5, 64);

        if (v1 != v2) {
            PRINT_MSG("Not equal...");
        }
    }

    {
        NAMESPACE::vector<long> v1(5, 64);
        NAMESPACE::vector<long> v2(4, 64);

        if (v1 != v2) {
            PRINT_MSG("Not equal....");
        }
    }

    {
        NAMESPACE::vector<long> v1(4);
        NAMESPACE::vector<long> v2(5);

        if (v1 != v2) {
            PRINT_MSG("Not equal.....");
        }
    }
}

MAIN(vec_test_comparisons_ne)
