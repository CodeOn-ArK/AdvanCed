#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
	printf("Hello World\n");
//	char *user = getenv("G");
//	printf("G: %s\n", user ? user : "null");
	setenv("G", "123412r2wecr3454", 1);
	//user = getenv("G");
	//printf("G: %s\n", user ? user : "null");
	system("python3 lol.py");
	return 0;
}
