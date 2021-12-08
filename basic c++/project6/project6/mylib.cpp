#include <iostream>

namespace mystd{

	float* initArr(int n) {

		float* arr = new float[n];

		for (int i = 0; i < n; i++) {

			arr[i] = static_cast<float> (rand() % 100 - 50) / 10;
		}
		return arr;
	}

	 void coutArr(float* arr, int n) {

		 for (int i = 0; i < n; i++) {

			 std::cout << arr[i] << " ";
		 }
		 
		 std::cout << std::endl;
	}

	 void negativeAndPositive(float* arr, int n) {

		 size_t neg = 0, pos = 0;

		 for (int i = 0; i < n; i++) {

			 if (arr[i] >= 0) {
				 pos++;
			 }
			 else {
				 neg++;
			 }
		 }

		 std::cout << "negative: " << neg << std::endl;
		 std::cout << "positive: " << pos << std::endl;
	 }


}