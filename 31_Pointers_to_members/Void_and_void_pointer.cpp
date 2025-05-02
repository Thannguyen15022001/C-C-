// TOPIC what is void and void pointer (void*) in C/C++

// VOID:
// 1. Void is used to denote nothing (biểu thị/dùng để chỉ không có gì)
// 2. If some function is not returning anything then we use void type to denote that
// 3. If some function doesn't take any parameter then we use void type(argument) to denote that
// 4. We can not create void variable.
// 5. Sizeof void is 1 in gcc complier but in other it is not valid to check sizeof void.

// VOID POINTER
// 1. Void* is universal(phổ quát/ có mặt ở bất kì đâu hay liên quan với everyone) pointer
// 2. We can convert any data type pointer to void* (except function pointer volatile)
// 3. void* can not be dereferenced ("Dereference" là một thuật ngữ trong lập trình để chỉ việc truy cập đến giá trị mà một con trỏ đang trỏ tới)


// NOTE:
// Function() và Function(void) khác nhau trong C
// Function() có nghĩa là số lượng arg là không giới hạn(có thể truyền bất kì arg nào) còn Function(void) là không có arg
// Function() và Function(void) đều giống nhau trong C++ là không có arg

/*
#include <stdio.h>
void func() {
        printf("Argument \n");
}
void func1(void) {
    printf("No arguments\n");
}
int main() {
    func(3, 10, 'c', 30);
    func1();
    return 0;
}
*/

#include <iostream>


int function(int a, int b){
	std::cout << "Hello wourld" << std::endl;
	return 0;
}

void *Sum(char * val1);
void *Sum(int val1);
void *Sum(float val1);

int main(){

	//We can convert any data type pointer to void*
	int * val = new(int);
	char * c = new(char);
	void *pVoid = val;     // void *pVoid = static_cast<void*>(val);
	pVoid = c;

	int *ptr = (int*) malloc(2*sizeof(int));  // malloc(2*sizeof(int)); trả về con trỏ void
	/* 
	Trong C chúng ta có thể dùng int *ptr = malloc(2*sizeof(int)); (chuyển đổi ngầm định)
	/or int *ptr = (int*) malloc(2*sizeof(int)); nhưng trong C++ chỉ được sử dụng int *ptr = (int*) malloc(2*sizeof(int));
	*/

	// const Pointer
	const int cons_val = 10;
	const int cons_val2 = 10;
	const int *pCons = &cons_val;          // con trỏ hằng trỏ vào một dữ liệu hằng và không thể thay đổi giá trị của biến đó (và con trỏ hằng có thể trỏ đến 1 biến khác)
	// *pCons = 1000;    -> ERRO
	pCons = &cons_val2;


	// Pointer const
	int a = 100;
	int b = 53;
	int *const consPtr =  &a;
	*consPtr = 5;
	// consPtr = &b;  -> ERRO


	// Conver const pointer & pointer const to const void
	const int cons_vl = 10;
	const int *ptrCon = &cons_vl;  
	const void *pVoidCons = ptrCon;

	int cons_v2 = 10;
	int *const ptrCon2 = &cons_v2; 
	void *const pVoidCons1 = ptrCon2; 


	// Cannot convert function pointer and volatile

	int (*fun)(int, int) = function;

	// void * pFun = fun; or void * pFun = static_cast<void*>(fun)  => ERROR invalid conversion from ‘int (*)(int, int)’ to ‘void*’ [-fpermissive]
	
	/*
	NOTE:
		HOWEVER, it is possible to cast even function pointers into void pointers using reinterpret_cast but, quoting:
		"It should always work for every compiler, but it's not always safe"
		Meaning depending on your compiler it could be undefined behavior. So don't do it.
		But in case if anyone wants to know, this is how.

		void * pFun = reinterpret_cast<void*>(fun);

	*/

	volatile int * valx = new(int);
	//void * pVol = valx;                 => ERROR


	// 3. void* can not be dereferenced
    int num = 10;
    void* voidPtr = &num;  // void pointer to an int

    // Incorrect: Attempting to dereference a void pointer directly
    // printf("%d\n", *voidPtr);  // Error: void* cannot be dereferenced

    // Correct: Casting the void pointer to int* before dereferencing
    int* intPtr = (int*)voidPtr;
    printf("%d\n", *intPtr);  // Output: 10

    std::cout << "======================" <<std::endl;
    char *ptrC = (char *)Sum('H');
    std::cout << *ptrC << std::endl;

    int *ptrInt = (int *)Sum(100);
    std::cout << *ptrInt << std::endl;

    float *ptrF = (float *)Sum(100.46f);
    std::cout << *ptrF << std::endl;
}


void *Sum(char * val1){
	char *ptr = new(char);
	*ptr = *val1;
	return (void *)ptr;
}

void *Sum(int val1){
	int *ptr = new(int);
	*ptr = val1;
	return (void *)ptr;
}

void *Sum(float val1){
	float *ptr = new(float);
	*ptr = val1;
	return (void *)ptr;
}