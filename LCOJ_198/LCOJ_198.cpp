
#include <stdio.h>
#include <stdlib.h>

int rob(int num[], int n){
	
	int max[3] = {0};
	if(n <= 2) return num[0] > num[1] ? num[0] : num[1];
	max[0] = num[0];
	max[1] = num[1] > num[0] ? num[1] : num[0];

	for(int i = 2; i < n; i++){

		max[2] = max[1] > max[0] + num[i] ? max[1] : max[0] + num[i];
		max[0] = max[1];
		max[1] = max[2];
	}

	return max[2];
}

int main(){

	int num[5] = {1, 2, 5, 4, 3};

	int res = rob(num, 5);

	printf("%d\n", res);
}