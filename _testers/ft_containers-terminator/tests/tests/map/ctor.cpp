/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctor.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 19:03:47 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/11 17:03:28 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_prelude.hpp"

void map_test_ctor()
{
    // Default
    {
        intmap m;

        PRINT_ALL(m);
    }

    // Compare/Allocator
    {
        track_allocator<NAMESPACE::pair<const std::string, std::string> > alloc;
        strmap m(std::less<std::string>(), alloc);

        PRINT_ALL(m);
    }
}

MAIN(map_test_ctor)
