#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void merge(int arr[], int m, int n, int p) {
	int n1 = n - m + 1;
	int n2 = p - n;
	int L[n1], R[n2];
	for(int i = 0; i < n1; i++) {
		L[i] = arr[m+i];
	}
	for(int j = 0; j < n2; j++) {
		R[j] = arr[n+1+j]; 
	}
	int i = 0;
	int j = 0;
	int k = m;
	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			arr[k] = L[i];
			i++;
		} else {
			arr[k] = R[j];
			j++;
		}
		k++;
	}
	while(i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}
	while(j < n2) {
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSort(int arr[], int m, int n) {
	if(m < n) {
		int k = m + (n-m)/2;
		mergeSort(arr, m, k);
		mergeSort(arr, k+1, n);
		merge(arr, m, k, n);
	}
}

int main() {
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mergeSort(arr, 0, n-1);
	for(int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	return 0;
}
