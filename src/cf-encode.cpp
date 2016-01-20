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

#include <rational/gmp_rational.h>

using namespace Commons::Math;

int main ( int, const char ** ) {

    mpf_set_default_prec ( 65536 );

    unsigned long lnr = 1u;

    try {

        std::vector<gmp_rational::integer_type> cfv;

        for ( std::string line; std::getline ( std::cin, line ); ++lnr ) {

            std::for_each ( begin ( line ), end ( line ), [&] ( const std::string::value_type &n ) {
                cfv.push_back ( n );
            } );

            cfv.push_back ( '\n' );

            std::cout << cf ( begin ( cfv ), end ( cfv ) ) << std::endl;

            cfv.clear();
        }

    } catch ( const std::exception &e ) {
        std::cerr << "Error in line " << lnr << ": " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
