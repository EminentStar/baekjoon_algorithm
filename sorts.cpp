#include <cstdio>
#include <iostream>

using namespace std;

void bubbleSort(int* data, int len){
	for(int i = 0 ; i < len -1 ; i++){
		for(int j = 0; j < len - 1 -i ; j++){
			if(data[j] > data[j+1]){
				int tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
			}
		}
	}
}

void qsort(int *data, int left, int right){
	int pVal = data[(left+right)/2];
	int i = left;
	int j = right;
	int tmp = 0;

	while(i <= j){
		while(data[i] < pVal) i++;
		while(data[j] > pVal) j--;

		if(i <= j){
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
			i++;
			j--;
		}
	}

	if(left < j) qsort(data, left, j);
	if(i < right) qsort(data, i, right);

}

int* merge(int *dest, int *left, int *right, int dlen, int llen, int rlen){
	int didx = 0;
	int lidx = 0;
	int ridx = 0;

	while(lidx < llen && ridx < rlen){
		if(left[lidx] < right[ridx])
			dest[didx++] = left[lidx++];
		else
			dest[didx++] = right[ridx++];
	}

	while(lidx < llen)
		dest[didx++] = left[lidx++];

	while(ridx < rlen)
		dest[didx++] = right[ridx++];

	return dest;
}

int* merge_sort(int *data, int len){
	if(len < 2)
		return data;
	int mid = (len)/2;
	int *left = new int[mid];
	int *right = new int[len-mid];
	int curIdx = 0;
	for(int i = 0; i < mid ; i++){
		left[i]  = data[curIdx++];
	}
	for(int i = 0; i < len-mid; i++){
		right[i] = data[curIdx++];
	}
	
	left = merge_sort(left, mid);
	right = merge_sort(right, len - mid);
	return merge(data, left, right, len, mid, len-mid);
}


int main(void){
	int a[10] = {4,5,3,6,2,7,1,8,9,10};
	int len = 10;

	for(int i = 0; i < len ; i++)
		printf("%d ", a[i]);
	printf("\n");

	//bubbleSort(a, len);
	//qsort(a, 0, len-1);
	merge_sort(a, len);

	for(int i = 0; i < len ; i++)
		printf("%d ", a[i]);
	printf("\n");

	return 0;
}