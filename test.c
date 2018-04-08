#include <stdio.h>
#include <string.h>

struct test{
	char buf[10]; 
	int (*vuln)();
};

void bad(){
	printf("Somethig bad path\n");
}

void main(){
	char input[20] = {0, };
	char input2[20] = {0, };
	puts("Name : \n");
	scanf("%s", &input);
	puts("Organization : \n");
	scanf("%s", &input2);
	
	struct test t;
	strcpy(t.buf, input);

	t.vuln();
}
