#include <iostream>

int main(int arc, char *argv[]) {
	int i, n, *data;
	std::cout << "How many integers do you want to generate? ";
	std::cin >> n;

	data = new int[n];
	
	for(i=0; i<n; i++) {
		data[i] = rand();
		std::cout << data[i] << std::endl;
	}
	delete[] data;
	return 0;
}
