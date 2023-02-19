/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_range.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:33:54 by mleblanc          #+#    #+#             */
/*   Updated: 2023/01/21 16:12:47 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_prelude.hpp"

int main()
{
    SETUP;

    NAMESPACE::vector<int> data;

    for (std::size_t i = 0; i < MAXSIZE; ++i) {
        data.push_back(rand());
    }

    timer t;

    for (int i = 0; i < 10; ++i) {
        NAMESPACE::vector<int> v;
        v.assign(data.begin(), data.end());
        BLOCK_OPTIMIZATION(v);
    }

    {
        NAMESPACE::vector<int> v;
        for (int i = 0; i < 10; ++i) {
            v.assign(data.begin(), data.end());
            BLOCK_OPTIMIZATION(v);
        }
    }

    PRINT_TIME(t);
}
