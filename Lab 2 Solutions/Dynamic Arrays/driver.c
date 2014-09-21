#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include "ListOps.h"

int main(int argc, char *argv[]){
	FILE *fp1;
	List head1 = NULL, head2 = NULL, head3 = NULL, head4 = NULL, head5 = NULL;
	long long int i = 0, size = 0, history1 = 0, history2 = 0, history3 = 0, temp = 0;
	int j = 0;
	double t0 = 0, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0;
	struct timeval tv;
	srand(time(NULL));
	fp1 = fopen(argv[2], "w");
	if(fp1 != NULL)
		fclose(fp1);
	for(i = 0; i < 150; i++){
		do{
			temp = rand();
			size = (1000 + ((temp)%15000));
		}while(size == history1 || size == history2 || size == history3);
		if(j == 0){
			j = rand()%3;
			history1 = size;
		}else if(j == 1){
			j = rand()%3;
			history2 = size;
		}else{
			j = rand()%3;
			history3 = size;
		}
		fp1 = fopen(argv[1], "w");
        	fp1 = input(fp1, size);
        	fclose(fp1);
        	fp1 = fopen(argv[1], "r");
        	head1 = makeArray(fp1, size);
		head2 = makeArray(fp1, size);
		head3 = makeArray(fp1, size);
		head4 = makeArray(fp1, size);
		head5 = makeArray(fp1, size);
        	fclose(fp1);
		gettimeofday(&tv,NULL);
		t0 = (tv.tv_sec *1e+6) + tv.tv_usec;
		head1 = method1(head1, size);
		gettimeofday(&tv,NULL);
                t1 = (tv.tv_sec *1e+6) + tv.tv_usec;
                head2 = method2(head2, size);
                gettimeofday(&tv,NULL);
                t2 = (tv.tv_sec *1e+6) + tv.tv_usec;
		head3 = method3(head3, size);
                gettimeofday(&tv,NULL);
                t3 = (tv.tv_sec *1e+6) + tv.tv_usec;
		head4 = method4(head4, size);
                gettimeofday(&tv,NULL);
                t4 = (tv.tv_sec *1e+6) + tv.tv_usec;
		head5 = method5(head5, size);
                gettimeofday(&tv,NULL);
                t5 = (tv.tv_sec *1e+6) + tv.tv_usec;
		fp1 = fopen(argv[2], "a");
		print_time(fp1, t0, t1, t2, t3, t4, t5, size);
		free(head1);
		free(head2);
		free(head3);
		free(head4);
		free(head5);
		if(fp1 != NULL)
			fclose(fp1);
	}
        return 0;
}
