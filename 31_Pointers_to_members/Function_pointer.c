/*
Q1. What is Function Pointer and how to create them?
Q2. Calling a function using a function pointer.
Q3. How to pass a function pointer as an argument
Q4. How to return function Pointer
Q5. How to use arrays of function pointer?
Q6. Where to use function pointer?
*/


//======================================================================
//Q1. What is Function Pointer and how to create them?
//Q2. Calling a function using a function pointer.
//A1. Normal pointer variable store the address of another variables, function pointer
//	store address of another function


#include <stdio.h>

int a;         // variable => 1 biến được tạo thành nên từ 2 thành phần là: type name - int a
int *p = &a;   // pointer  tương tự nhưng có thêm *

int add(int a, int b){            // Nếu declare như này -> int *add(int a, int b) nghĩa là hàm đang trả về 1 kiểu dữ liệu con trỏ 
	return a + b;
}


int sub(int a, int b){
	return a - b;
}

// Define function pointer cũng gồm 2 thành phần là type và name
int (*pFun)(int,int);



int sum(int a, int b,int (*fun)(int, int)){
	return fun(a,b);
}




//typedef < return_type > ( * < alias_name >)(< tham số_type >,< tham số_type >, .... );

typedef int(*aliasFun)(int,int);


int (*Func (const char* operation))(int,int){   // => aliasFun (const char* operation)
	if( operation == "-" ){
		return sub;
	} else {
		return add;	
	}
}

int main(){
	// Declare function pointer
	pFun = &add;            // Có thể khai báo theo kiểu mới -> pFun = &add;

	int (*pFun1)(int,int) = &add;   // Có thể khai báo theo kiểu mới -> int (*pFun1)(int,int) = add;

	//How use

	int val = pFun(1,2);
	int val2 = (*pFun1)(3,4);

	printf("%d\n",val);
	printf("%d\n",val2);

	
	//int (*pFun1)(int,int,int) = &add;           
	//int val = pFun(1,2,3);
	//=> Dùng như này sẽ sảy ra warning và biến thứ 3 sẽ bị bỏ qua

//============================================================================
// Q3. How to pass a function pointer as an argument
//

	int val3 = sum(2,3,add);
	printf("%d\n",val3);

//Q4. How to return function Pointer
	int (*funValue)(int,int) = Func("-");

	printf("%d\n",funValue(2,3));

	funValue = Func("+");

	printf("%d\n",funValue(2,3));


//Q5. How to use arrays of function pointer?

	typedef int (*typeFunc)(int,int);

	typeFunc typeArr[2] = {add,sub};
	printf("%d\n",typeArr[0](1,3));
 
	int (*Arr[2])(int,int) = {add,sub};
	printf("%d\n",Arr[0](1,3));   // or printf("%d\n",(*Arr[0])(1,3)));
	printf("%d\n",Arr[1](2,9));

	return 0;
}



