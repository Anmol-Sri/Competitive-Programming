// CPP Program to find sum of all combination takne 
// (1 to N) at a time using dynamic programming 
#include <iostream> 
using namespace std; 

// find the postfix sum array 
void postfix(int a[], int n) { 
for (int i = n - 1; i > 0; i--) 
	a[i - 1] = a[i - 1] + a[i]; 
} 

// modify the array such that we don't have to 
// compute the products which are obtained before 
void modify(int a[], int n) { 
for (int i = 1; i < n; i++) 
	a[i - 1] = i * a[i]; 
} 

// finding sum of all combination taken 1 to N at a time 
void allCombination(int a[], int n) { 

int sum = 0; 

// sum taken 1 at time is simply sum of 1 - N 
for (int i = 1; i <= n; i++) 
	sum += i; 
cout << "f(1) --> " << sum << "\n"; 

// for sum of products for all combination 
for (int i = 1; i < n; i++) { 

	// finding postfix array 
	postfix(a, n - i + 1); 
	
	// sum of products taken i+1 at a time 
	sum = 0; 
	for (int j = 1; j <= n - i; j++) { 
	sum += (j * a[j]); 
	} 
	cout << "f(" << i + 1 << ") --> " << sum << "\n"; 

	// modify the array for overlapping problem 
	modify(a, n); 
} 
} 

// Driver's Code 
int main() { 
int n = 5; 
int *a = new int[n]; 

// storing numbers from 1 to N 
for (int i = 0; i < n; i++) 
	a[i] = i + 1; 

// calling allCombination 
allCombination(a, n); 

return 0; 
} 
