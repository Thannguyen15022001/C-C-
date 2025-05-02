#pragma once
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif
	void printHelloFromC();
	//void printHelloFromC(char *c);  // compile error because C not support overloadind
#ifdef __cplusplus
}
#endif

void printTextFromC(char* c);
