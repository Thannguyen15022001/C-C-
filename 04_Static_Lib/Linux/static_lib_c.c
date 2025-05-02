#include "static_lib_c.h"


void printHelloFromC() {
	printf("Hello world from C");
}

void printHelloFromC(char* c) {
	printf("%c from C", *c);
}

void printTextFromC(char* c) {
	printf("%c from C", *c);
}