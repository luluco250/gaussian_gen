#ifndef MAIN_HPP
#define MAIN_HPP

using Decimal = long double;
using Integer = long long;

bool parse_args(int argc, char** argv, Integer& samples, Decimal& sigma);
void print_usage();

Decimal gaussian1D(Decimal x, Decimal sigma);
Decimal gaussian2D(Decimal x, Decimal y, Decimal sigma);

constexpr const Decimal pi = 3.1415926535897932384626433832795l;

#endif