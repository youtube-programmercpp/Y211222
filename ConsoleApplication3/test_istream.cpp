#include <sstream>
#include <iostream>
int main()
{
	static const char sample_string[] = "    ABC   DEF";

	std::cout << "yistm >> chz\n";
	for (std::istringstream istm(sample_string); ;) {
		char ch;
		if (istm >> ch)
			std::cout << '\'' << ch << '\'' << '\n';
		else
			break;
	}

	std::cout << "ych = istm.get()z\n";
	for (std::istringstream istm(sample_string); ;) {
		const char ch = istm.get();
		if (ch == EOF)
			break;
		else
			std::cout << '\'' << static_cast<char>(ch) << '\'' << '\n';
	}

	std::cout << "yistm.read(&ch, 1)z\n";
	for (std::istringstream istm(sample_string); ;) {
		char ch;
		if (istm.read(&ch, 1))
			std::cout << '\'' << static_cast<char>(ch) << '\'' << '\n';
		else
			break;
	}
}
