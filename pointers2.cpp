#include <iostream>
using namespace std;


void print(int array[] , size_t array_size ) {  // Don't write array[] {} and array_size {}, doesn't work
	cout << "[";
    for (int i; i < array_size; ++i)			// Range based for loop not working.
        cout << array[i] << " ";
    cout << "]" <<endl;
}

// Notice the * before apply_all, it is because we will return a pointer from the function
int *apply_all(int array1[],size_t array1_size, int array2[],size_t array2_size) {  
	int *new_storage {nullptr};							            // Setting pointer to nowhere
	int size {0};   
	new_storage = new int[array1_size * array2_size];               // Allocating dynamic storage of 15 integers
	// Applying logic 				
	for (int i {0} ; i < array2_size ; i++){
		for (int j {0}, k {0}; j < array1_size ; j++,k++) {
			new_storage[size] = array2[i] * array1[j]; 			    // new_storage[size++] can also be used.
			size++;
		}
	}
	return new_storage; 											// Returning the pointer
}

int main() {

	// Now value can't be modified as const is used
    const size_t array1_size {5};
    const size_t array2_size {3};

    int array1[] {1,2,3,4,5};
    int array2[] {10,20,30};

	// Pointer pointing to array
    int *array1_ptr {array1};
    int *array2_ptr {array2};

    cout << "Array1: ";
    print(array1, array1_size);                    

    cout << "Array2: ";
    print(array2, array2_size);

	// The new_storage pointer returned and stored in results pointer
    int *results = apply_all(array1,array1_size, array2,array2_size);
    size_t results_size {array1_size * array2_size};

    cout << "Results: ";
    print(results, results_size);

    delete [] results;                   // Deleting the allocating storage

    return 0;

}

