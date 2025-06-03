#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

void radix_sort_hex(unsigned int A[], unsigned int n) {
    for (int pass = 0; pass < 8; pass++) {
        unsigned int buckets[16][SIZE];
        unsigned int bucketCount[16] = {0};
	unsigned int mask = 0xF << (pass * 4);

        for (int i = 0; i < n; i++) {
            unsigned int value = A[i];
            unsigned int bucket_index = (value & mask)>>(pass * 4);
            buckets[bucket_index][ bucketCount[bucket_index]++] = value;
        }

        int index = 0;
        for (int b = 0; b < 16; b++) {
            for (int j = 0; j < bucketCount[b]; j++) {
                A[index++] = buckets[b][j];
            }
        }
    }
}

void radix_sort(int A[], int n) {
	unsigned int positive[SIZE], negative[SIZE]; 
	int pos_count=0, neg_count=0;
	for (int i=0; i<n; i++) {
		if (A[i] >= 0) {
			positive[pos_count++] = A[i];
		} else {
			negative[neg_count++] = ~A[i]; 
		}
	}
	radix_sort_hex(positive, pos_count);
	radix_sort_hex(negative, neg_count);

    int ind = 0;
    for (int i = neg_count - 1; i >= 0; i--) {
        A[ind++] = ~negative[i];  
    }
    for (int i = 0; i < pos_count; i++) {
        A[ind++] = positive[i];
    }
}

int main() {	
	int real[SIZE];
	int count = 0;
	printf("Please enter the total count of your numbers:\n");
	scanf("%d", &count);

	if (count <= 0 || count > 100) {
	printf("Invalid count was given, please provide a positive non-zero number:\n");
	exit(1);
	}

	printf("Please enter your numbers one by one (floats/real numbers)\n");
	for (int i=0; i<count; i++) {
		int num = 0;
		scanf("%d", &num);
		real[i] = num;
	}
	
	radix_sort(real,count);
	printf("\nSorted array numbers using radix sort:\n");
	for (int i=0; i<count; i++) {
		printf("%d\n", real[i]);
	}
	return 0;
}
