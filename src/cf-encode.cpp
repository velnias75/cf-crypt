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

template<class IIter>
struct uchar_conv_iterator : std::iterator<std::input_iterator_tag, gmp_rational::integer_type> {

    uchar_conv_iterator& operator= ( const uchar_conv_iterator& ) = delete;

    uchar_conv_iterator ( IIter iter ) : iter_ ( iter ),
        it ( static_cast<unsigned char> ( *iter_ ) ) {}

    bool operator!= ( const uchar_conv_iterator &o ) const {
        return iter_ != o.iter_;
    }

    reference operator*() {
        return it;
    }

    uchar_conv_iterator operator++ ( int ) {

        uchar_conv_iterator tmp ( *this );

        it = static_cast<unsigned char> ( * ( ++iter_ ) );

        return tmp;
    }

private:
    IIter iter_;
    gmp_rational::integer_type it;
};

int main ( int, const char ** ) {

    mpf_set_default_prec ( 65536 );

    unsigned long lnr = 1u;

    try {

        for ( std::string line; std::getline ( std::cin, line ); ++lnr ) {

            if( !std::cin.eof() ) line.append ( 1, '\n' );

            std::cout << cf ( uchar_conv_iterator<std::string::iterator> ( std::begin ( line ) ),
                              uchar_conv_iterator<std::string::iterator> ( std::end ( line ) ) )
                      << std::endl;
        }

    } catch ( const std::exception &e ) {
        std::cerr << "Error in line " << lnr << ": " << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

// kate: indent-mode cstyle; indent-width 4; replace-tabs on; 
