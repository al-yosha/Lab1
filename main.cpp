#include <iostream>
#include "lab1.h"

using namespace lab1;

int main() {
	int m = 1;
	int n = 1;
	std::cout << "Enter m and n:" << std::endl;
	while (getInt(m) < 0 || getInt(n) < 0) {
		std::cout << "Incorrect input, try again" << std::endl;
	}
	Col* matrix = matrix_create(m, n);
	if (matrix == nullptr) {
		std::cout << "Incorrect data" << std::endl;
		return 1;
	}
	Col* matrix_new = modify(matrix, n);
	output("Original matrix:", matrix, m, n);
	output("Modified matrix:", matrix_new, m, n);
	erase(matrix);
	return 0;
}