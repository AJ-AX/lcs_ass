#include <stdio.h>
#include <stdlib.h>

void print_array(int *arr, int size){
	for (int i=0; i<size; i++){
		printf("%d ",arr[i]);	
	}
	printf("\n");
}

int max(int a, int b){
	if(a>b){
		return a;
	}
	else{
		return b;
	}
}

int lcs3(int *a, int n,  int *b, int m, int *c, int l) {
	//write your code here
	int data[n+1][m+1][l+1];

	/*for(int i = 0; i < n+1; i++){
		data[i][0][0] = 0;
	}
	for(int i = 0; i < m+1; i++){
		data[0][i][0] = 0;
	}
	for(int i = 0; i < l+1; i++){
		data[0][0][i] = 0;
	}*/

	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= m; j++){
			for(int y = 0; y <= l; y++){
				// Since we have to initialize 0s in 3 dimensions rather than 2
				// We just do it inside the function
				if(i == 0){
					data[i][j][y] = 0;
				}
				else if(j == 0){
					data[i][j][y] = 0;
				}
				else if(y == 0){
					data[i][j][y] = 0;
				}
				else if(a[i-1] == b[j-1] && a[i-1] == c[y-1]){
					data[i][j][y] = data[i-1][j-1][y-1] + 1;
				}
				else{
					data[i][j][y] = max(max(data[i-1][j][y],data[i][j-1][y]),data[i][j][y-1]);
				}
			}
		}
	}
	return data[n][m][l];
}

int main() {
	int n, m, l;  
  
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
	
	printf("Enter value of l: ");
	fflush(stdout);
	scanf("%d", &l);

	int * c = malloc(l*sizeof(int));
	printf("Enter %d values for array b:\n", l);
	fflush(stdout);
	for (int i=0; i < l; i++){
		scanf("%d", &c[i]);
	}
	
	printf("Input sequences are:\n");	
	print_array(a, n);
	print_array(b, m);
	print_array(c, l);
	fflush(stdout);
	
	int lcs = lcs3(a, n, b, m, c, l);
	printf("LCS = %d\n",lcs);
	
	return 0;
}