#include "main.hpp"
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

int main(int argc, char** argv) {
	Integer samples;
	Decimal sigma;

	if (!parse_args(argc, argv, samples, sigma)) {
		print_usage();
		return EXIT_FAILURE;
	}

	for (Integer i = 0ll; i < samples; ++i) {
		Decimal g = gaussian1D(static_cast<Decimal>(i), sigma);
		printf("%Lf ", g);
	}
	fputc('\n', stdout);

	return EXIT_SUCCESS;
}

bool parse_args(int argc, char** argv, Integer& samples, Decimal& sigma) {
	if (argc != 3)
		return false;
	
	samples = strtoll(argv[1], nullptr, 10);
	if (errno)
		return false;

	sigma = strtold(argv[2], nullptr);
	if (errno)
		return false;

	return true;
}

void print_usage() {
	fputs(
R"(Usage: gaussian_gen <samples> <sigma>
	samples  -- How many samples/taps to generate, expects an integer.
	sigma    -- The sigma value used in the gaussian function, expects a decimal/real.
)"
	, stdout);
}

Decimal gaussian1D(Decimal x, Decimal sigma) {
	Decimal ss = sigma * sigma;
	Decimal a = 1.0l / sqrt(2.0l * pi * ss);
	Decimal b = (x * x) / (2.0l * ss);
	return a * exp(-b);
}

Decimal gaussian2D(Decimal x, Decimal y, Decimal sigma) {
	Decimal ss = sigma * sigma;
	Decimal a = 1.0l / (2.0l * pi * ss);
	Decimal b = ((x * x) + (y * y)) / (2.0l * ss);
	return a * exp(-b);
}
