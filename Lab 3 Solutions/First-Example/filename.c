#include <stdio.h>

int factorial1(int);
int factorial2(int);

int main()
{
	int num, ans1, ans2;
	printf ("Enter the number: ");
	scanf ("%d", &num );
	ans1 = factorial1(num);
	ans2 = factorial2(num);	
	printf("The factorial of %d is %d by first method.\n",num,ans1);
	printf("The factorial of %d is %d by second method.\n",num,ans2);
	return 0;
}

int factorial1(int n){
	if(n == 1){
		return 1;
	}else{
		return n * factorial1(n-1);
	}
}

int factorial2(int m){
	int i=1, j=1;
	for(i=1;i<=m;i++){
		j = j*i;
	}
	return j;
}
