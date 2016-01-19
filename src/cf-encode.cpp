#include <iostream>

#include <rational/gmp_rational.h>

using namespace Commons::Math;

int main(int, const char **) {

	mpf_set_default_prec ( 65536 );

	unsigned long lnr = 1u;

	try {

		std::vector<gmp_rational::integer_type> cfv;

		for(std::string line; std::getline(std::cin, line); ++lnr) {

			std::for_each(begin(line), end(line), [&](const std::string::value_type &n)
				{ cfv.push_back(n); });

			cfv.push_back('\n');

			std::cout << cf(begin(cfv), end(cfv)) << std::endl;

			cfv.clear();
		}

	} catch ( const std::exception &e ) {
		std::cerr << "Error in line " << lnr << ": " << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
