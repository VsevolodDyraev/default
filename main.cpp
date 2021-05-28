#include <iostream>
#include "island.hpp"

int main() {
	int m, n;
	std::cin >> m >> n;

	int** arr = new int* [m];
	for (int i = 0; i < m; i++) {
		arr[i] = new int[n];
		for (int j = 0; j < n; j++) {
			arr[i][j] = rand() % 2 + 0; //cin >> arr[i][j];
		}
	}
    std::cout<<std::endl;
	display(arr, m, n);
    std::cout<<std::endl;
	std::cout << std::endl << found(arr, m, n) << std::endl;
    std::cout<<std::endl;
    display(arr, m, n);
    return_correct(arr,m,n);
    std::cout<<std::endl;
    display(arr, m, n);
    
	

	return 0;
}