#include <stdio.h>
#define MAX 8

int count_sort = 0;

void display(int *arr) {
	int i;
	
	for (i=0; i<MAX; i++) printf("%d ", arr[i]);
	printf("\n");
}

void display_k(int *arr, int k) {
	int i;
	
	for (i=0; i<MAX; i++) {
		if (i==k) printf("[ ");
		printf("%d ", arr[i]);
	}
	printf("]\n");
}

int arrange(int a, int b, int *arr) {
	int left, right, bd, temp;
	
	left=a; right=b; bd=arr[(a+b)/2];
	
	while(1) {
		while (arr[left] < bd) {
			left++; if (left > b) break;
		}
		while (arr[right] >= bd) {
			right--; if (right < a) break;
		}
		
		if (right < a) {
			arr[(a+b)/2] = arr[a]; arr[a] = bd;
			printf("line 25\n");
			return a+1;
		} else if (left <= right) {
			temp = arr[left];
			arr[left] = arr[right]; arr[right] = temp;
			
			left++; right--;
		} else {
			break;
		}
	}

	return(left);
}

void sort(int a, int b, int *arr) {
	int k;
	printf("count_sort=%d\n",++count_sort);
	
	if (b <= a) return;
	k = arrange(a, b, arr);
	display_k(arr,k);
printf("%d = %d?\n-\n", k, b);	//add for (3)
	sort(a, k-1, arr);
	sort(k, b, arr);
}

int main(void) {
//	int dat[] = {30, 50, 70, 40, 20, 80, 60, 10};
	int dat[] = {20, 40, 60, 80, 10, 50, 30, 70};
		display(dat);
		count_sort=0;
	sort(0, MAX-1, dat);
	display(dat);
	return 0;
}

/*
a b c d e f g h  d=80
«
a b c 80 e f g h
«
a b c 70 e f g [80] h=70
«
a b 60 g e f [70 80]  c = 60
«
a b 50 g e [60 70 80]  f=50
«
a 40 e g [50 60 70 80]  b=40
«
a 30 e [40 50 60 70 80] g=30
«
20 e [30 40 50 60 70 80] a=20
«
10 [20 30 40 50 60 70 80] e=10

‚æ‚Á‚Ä
20 40 60 80 10 50 30 70
*/