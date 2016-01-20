/*
 * Copyright 2016 by Heiko Schäfer <heiko@rangun.de>
 *
 * This file is part of cf-crypt.
 *
 * cf-crypt is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as
 * published by the Free Software Foundation, either version 3 of
 * the License, or (at your option) any later version.
 *
 * cf-crypt is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with cf-crypt.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
#include <iterator>

#include <rational/gmp_rational.h>

using namespace Commons::Math;

typedef Rational<gmp_rational::integer_type, GCD_null, NO_OPERATOR_CHECK> gmp_nogcd_rational;

struct gmp_cout_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {

    gmp_cout_iterator& operator= ( const gmp_cout_iterator & ) = delete;

    gmp_cout_iterator &operator*() {
        return *this;
    }

    gmp_cout_iterator operator++ ( int ) {
        return *this;
    }

    gmp_cout_iterator& operator= ( const gmp_nogcd_rational::integer_type &value ) {
        std::cout << static_cast<std::ostream::char_type> ( value.get_si() );
        return *this;
    }
};

int main ( int, const char ** ) {

    mpf_set_default_prec ( 65536 );

    unsigned long lnr = 1u;

    try {

        gmp_cout_iterator citer;

        for ( std::string line; std::getline ( std::cin, line ); ++lnr ) {
            seq ( gmp_nogcd_rational ( line.c_str() ), citer );
        }

    } catch ( const std::exception &e ) {
        std::cerr << "Error in line " << lnr << ": " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
