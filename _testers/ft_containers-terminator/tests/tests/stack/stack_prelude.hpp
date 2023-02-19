/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_prelude.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:48:53 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/19 23:01:29 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../../../../../stack/stack.hpp"
#include <stack>
#include <vector>

#include "prelude.hpp"

template <typename C>
void add_values(C& s, typename C::value_type value, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i, ++value) {
        s.push(value);
    }
}

template <typename C>
void add_value(C& s, typename C::value_type value, std::size_t count)
{
    for (std::size_t i = 0; i < count; ++i) {
        s.push(value);
    }
}
