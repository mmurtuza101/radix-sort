#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void radix_sort_float(unsigned int A[], unsigned int n){
	unsigned int bucket0[SIZE],bucket1[SIZE];
	unsigned int mask, count0, count1;

	for (int d=0; d<32; d++){
		mask = 1<<d;
		count0 = count1 = 0;
		for (int i=0; i<n; i++) {
			if ((A[i]&mask) == 0) {
				bucket0[count0++] = A[i];
			} else {
				bucket1[count1++] = A[i];
			}
		}
		for (int i =0; i<count0; i++) {
			A[i] = bucket0[i];
		}
		
		for (int i=0; i<count1; i++) {
			A[count0 + i] = bucket1[i];
		}
	}
}
void radix_sort(float A[], int n) {
	unsigned int positive[SIZE], negative[SIZE]; 
	int pos_count=0, neg_count=0;
	for (int i=0; i<n; i++) {
		unsigned int *bit = (unsigned int *)&A[i];
		if (A[i] >= 0) {
			positive[pos_count++] = *bit;
		} else {
			negative[neg_count++] = ~(*bit); 
		}
	}
	radix_sort_float(positive, pos_count);
	radix_sort_float(negative, neg_count);

	for (int i =0; i<neg_count;i++){
		unsigned int neg = ~negative[i];
		A[i] = *(float*)&neg;
	}

	for (int i=0; i<pos_count; i++) {
		A[i+neg_count] = *(float *)&positive[i];
	}
}

int main() {	
	float real[SIZE];
	int count = 0;
	printf("Please enter the total count of your numbers:\n");
	scanf("%d", &count);

	if (count <= 0 || count > 100) {
	printf("Invalid count was given, please provide a positive non-zero number:\n");
	exit(1);
	}

	printf("Please enter your numbers one by one (floats/real numbers)\n");
	for (int i=0; i<count; i++) {
		float num = 0;
		scanf("%f", &num);
		real[i] = num;
	}
	
	radix_sort(real,count);
	printf("\nSorted array numbers using radix sort:\n");
	for (int i=0; i<count; i++) {
		printf("%.6f\n", real[i]);
	}
	return 0;
}
