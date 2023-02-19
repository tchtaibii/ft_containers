/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchtaibi <tchtaibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:07:57 by mleblanc          #+#    #+#             */
/*   Updated: 2023/02/19 20:48:02 by tchtaibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack_prelude.hpp"

void stack_test_misc()
{
    {
        NAMESPACE::stack<int, NAMESPACE::vector<int, track_allocator<int> > > st;

        PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));

        st.push(34);

        PRINT_LINE("Size:", st.size());
        PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));
        PRINT_LINE("Top:", st.top());

        // st.push(64);

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));
        // PRINT_LINE("Top:", st.top());

        // st.top() = 1;

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));
        // PRINT_LINE("Top:", st.top());

        // st.push(128);

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Top:", st.top());

        // const NAMESPACE::stack<int, NAMESPACE::vector<int, track_allocator<int> > > st1(st);

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));
        // PRINT_LINE("Top:", st.top());

        // st.pop();
        // st.pop();

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));
        // PRINT_LINE("Top:", st.top());

        // st.pop();

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));

        // st = st1;

        // PRINT_LINE("Size:", st.size());
        // PRINT_LINE("Empty:", (st.empty() ? "true" : "false"));
        // PRINT_LINE("Top:", st.top());
    }
}

MAIN(stack_test_misc)
