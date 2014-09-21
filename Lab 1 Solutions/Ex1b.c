#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc > 3){
		printf("%s %s %s %d\n\n", argv[0], argv[1], argv[2], atoi(argv[3]));
	}else{
		printf("%s %s %s\n\n", argv[0], argv[1], argv[2]);
	}
	return 0;
}
