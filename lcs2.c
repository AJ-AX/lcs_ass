#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("[%d] ",arr[i]);	
	}
	printf("\n");
}

int max(int a, int b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}

int lcs2(int *a, int n,  int *b, int m) {
	//write your code here
	int data[n+1][m+1];

	for(int i = 0; i < n+1; i++){
		data[i][0] = 0;
	}
	for(int j = 0; j < m+1; j++){
		data[0][j] = 0;
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(a[i-1] == b[j-1]){
				data[i][j] = data[i-1][j-1] + 1;
			}
			else{
				data[i][j] = max(data[i-1][j], data[i][j-1]);
			}
		}
	}
	return data[n][m];
}

int main() {
	int n, m;  
  
	printf("Enter value of n: ");
	fflush(stdout);
	scanf("%d", &n);
	
	int * a = malloc(n*sizeof(int));
	printf("Enter %d values for array a, separated by spaces:\n", n);
	fflush(stdout);
	for (int i=0; i < n; i++){
		scanf("%d", &a[i]);
	}	
	
	printf("Enter value of m: ");
	fflush(stdout);
	scanf("%d", &m);

	int * b = malloc(m*sizeof(int));
	printf("Enter %d values for array b:\n", m);
	fflush(stdout);
	for (int i=0; i < m; i++){
		scanf("%d", &b[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	fflush(stdout);
	
	int lcs = lcs2(a, n, b, m);
	printf("LCS = %d\n",lcs);
	
	return 0;
}