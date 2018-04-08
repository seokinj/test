#include <stdio.h>
#include <string.h>

// 0xffb7d0b8(&input) - 0xffb7d0ec(&main_ret) = 0x34 
// main = /lib32/libc-2.23.so + 0x18637(offset)
// libc_base = main - 0x18637
// system = 0xf7e44940.. libc_base + 0x3A940

struct test{
	char buf[10]; 
	int (*vuln)(char *);
};

void print_val(char * s, int r){
	int i;
	for(i=0;i<r;i+=4){
		printf("%p: %x%x%x%x\n", &s[i],(unsigned int)(unsigned char)s[i+3],(unsigned int)(unsigned char)s[i+2],(unsigned int)(unsigned char)s[i+1],(unsigned int)(unsigned char)s[i]);
	}
}

void main(){
	char input[20] = {0, };
	char input2[20] = {0, };
	int range;

	puts("Range : \n"); 
	scanf("%d", &range);
	print_val(input, range); //60

	puts("Name : \n"); // to overwrite "a"*12 + libc + system_offset
        scanf("%s", &input);
	puts("Organization : \n"); // '/bin/ls'
	scanf("%s", &input2);	

	struct test t;
        strcpy(t.buf, input);

	t.vuln(input2);
}
