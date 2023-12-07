#include <iostream>

using namespace std;


double average(double* a, int size);
	
double* maximum(double* a, int size);
	
double* minimum(double* a, int size);


	
int main() {
	int size;
	cout << "Enter size of array: ";
	cin >> size;

	if (size <= 0) {
		cout << "Invalid array size." << endl;
		return 1;
	}

	double* array = new double[size];

	cout << "Enter " << size << " floating-point values: ";
	for (int i = 0; i < size; ++i) {
		cin >> array[i];
	}

	double avg = average(array, size);
	cout << "Average is " << avg << endl;

	double* maxPtr = maximum(array, size);
	if (maxPtr != nullptr) {
		cout << "Maximum value is element #" << (maxPtr - array) << ": " << *maxPtr << endl;
	}
	else {
		cout << "Array is empty." << endl;
	}

	double* minPtr = minimum(array, size);
	if (minPtr != nullptr) {
		cout << "Minimum value is element #" << (minPtr - array) << ": " << *minPtr << endl;
	}
	else {
		cout << "Array is empty." << endl;
	}

	delete[] array; // Don't forget to free dynamically allocated memory

	return 0;
}



double average(double* a, int size) {
	if (size == 0) {
		return 0;
	}

	double sum = 0;
	double* ptr = a;
	for (int i = 0; i < size; ++i) {
		sum += *ptr;
		ptr++;
	}
	return sum / size;
}


double* maximum(double* a, int size) {
	if (size == 0) {
		return nullptr;
	}

	double* maxPtr = a;
	for (int i = 1; i < size; ++i) {
		if (*(a + i) > *maxPtr) {
			maxPtr = a + i;
		}
	}
	return maxPtr;
}

double* minimum(double* a, int size) {
	if (size == 0) {
		return nullptr;
	}

	double* minPtr = a;
	for (int i = 1; i < size; ++i) {
		if (*a > *(a + i)) {
			minPtr = a + i;
		}
	}
	return minPtr;
}