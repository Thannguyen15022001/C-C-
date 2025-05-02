#include <iostream>
#include "static_lib/static_lib.h"
#include "static_lib_c/static_lib_c.h"

extern "C"

int main() {
	printHelloFromC();

	return 0;
}