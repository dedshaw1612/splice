#include <iostream>
#include "LinkedList.h"
#include "ArrayList.h"

using namespace std;

double* arr;
int arr_len;

/**
 * If h is an element of the array arr, then
 * return its index. If not, return -1. So
 * indexOf(arr+2) should return 2...
 **/

/*int indexOf(double* h){
	for(int i = 0;i<arr_len;i++) {
		if(arr + i == h)
			return i;
	}
	return -1;

}*/
 
int indexOf(double* h) {
	//int offset = h-arr;
	int offset = (char*)h-(char*)arr;
	int index = offset/sizeof(double);

	if(index < 0 || index >= arr_len || (offset%sizeof(double))!= 0) {
		return -1;
	}else {
		return index;
	}
	
	return offset;
}

int main(){
	arr_len = 500;
	arr = new double[arr_len];
	double test;

	cout << indexOf(&arr[15]) << endl;
	cout << indexOf(&arr[1500]) << endl;
	cout << indexOf(&test) << endl;
	cout << indexOf(  (double*)(((char*)arr)+1)  ) << endl;

	//char is a byte, we point to the first index, 2nd byte
	cout << indexOf((double*)(((char*)arr)+1)) << endl;

	/*
	List* l = new LinkedList();

	l->pushFront(1.0);
	l->pushFront(2.0);
	l->pushFront(3.0);

	cout << "[";
	for(int i=0; l->at(i) != NULL; i++){
		if(i != 0) {
			cout << ", ";
		}
		cout << l->getData(l->at(i));
	}
	cout << "]" << endl;
	*/
	return 0;
}