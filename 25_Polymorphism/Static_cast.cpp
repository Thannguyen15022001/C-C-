// TOPIC: static_cast
// static_cast là một compile-time cast (cast trong thời gian biên dịch chứ không phải thời gian chạy)

#include<iostream>



// // 1. It performs implicit conversion between types

// float val_f = 3.6f;

// int a = val_f;       // implicit type cast
// int b = static_cast<int> (val_f);



// char val_str = 'h';
// int c = val_str;


// /*
// Giai thich:
//  char = 'h'  => int = 0x68  = 0b01101000

//  int | 1 byte | 1 byte | 1 byte | 1 byte      => |0000 0000|0000 0000|0000 0001|0110 1000|   => 0x168
//  											STATIC_CAST
//  char |1 byte|																   |0110 1000|   => 0x68

// */
// int m  = 0x168;
// char val_str1 = static_cast<char> (m);


// float k = 2.5f;    
// bool i = static_cast<bool> (k);   // nếu ép về kiểu bool những số >= 1 đều thành 1 (true)



// // 2. Use static_cast when conversion between types is provided through conversion operator or conversion constructor

// class Integer{
// private:
// 	int val ;

// public:

// 	Integer(int X):val(X){
// 		std::cout << "Contructor was called" << std::endl;
// 	}

// 	operator std::string(){
// 		std::cout << "operator string was called" << std::endl;
// 		return std::to_string(val);
// 	}

// 	operator char (){
// 		std::cout << "operator char was called" << std::endl;
// 		return static_cast<char>(val);
// 	}

// };


// // 3. static_cast is more restrictive(hạn chế) than C-Stype
// // Ex: char* to int* is allowed in C-Style but not with static_cast

// // 4. static_cast for Inheritance in C++
// // static_cast can provide both upcasting and downcasting in case of inheritance

// class Base{

// };

// class Derived: public Base {

// };

// int main(){

// 	Integer obj(50);

// 	std::string str = static_cast<std::string>(obj);
// 	std::cout << str << std::endl;
// 	obj = 0x68;				// conversion constructor: Chỉ áp dụng cho constructor chỉ có 1 arg và constructor sẽ được gọi.
// 	obj = static_cast<int>(0x68);
// 	char m = static_cast<char> (obj);

// /*=============================================*/
// 	// 3.char* to int* is allowed in C-Style but not with static_cast

// 	char val_c = 'M';
// 	int *ptr_int = (int*)&val_c;  // PASS at compile time but maybe FAIL at run time

// 	*ptr_int = 5005;    // Nguy hiểm
// 	/*
// 	Giai thích:
// 	biến char chỉ chiếm 1 byte trong vùng mem và những byte xung quanh
// 	biến char này có thể được cấp phát cho những biến khác or Không
// 	Khi một con trỏ kiểu int (4 byte) trỏ đén địa chỉ của biến char (1 byte) => điều gì xảy ra
// 	Con trỏ kiểu int nó sẽ sử dụng 3 byte lân cận vùng địa chỉ của biến char để sử dụng điều này
// 	là nguy hiểm và không được phép

// 	*/


// 	//int *p = static_cast<int*>(&val_c); // FAIL at compile time
// 	std::cout << *ptr_int <<std::endl;
// /*=================================================*/

// 	Derived Dr;
// 	// upcasting using static_cast
// 	Base *Ba =static_cast<Base*> (&Dr);

// 	// downcasting using static_cast
// 	Base Bas;
// 	Derived *D = static_cast<Derived*>(&Bas);  

// 	/*
// 	static_cast FAIL khi Drived kế thừ private/protected BASE

// 	class Base {};
 
// 	class Derived: private Base 
// 	{ 
//   		// Inherited private/protected 
//   		// not public
// 	};

// 		Base *Ba =static_cast<Base*> (&Dr); // FAIL
// 	*/

// 	return 0;
// }



//5. Use for all upcasts, but never use for confuse down cast

class Base{

};

class Derived1: public Base{

};

class Derived2: public Base{

};

int main(){
	Derived1 d1;
	// Derived2 *d2 = static_cast<Derived2*> (&d1);   FAIL at compile time
	Derived2 d2;

	Base *B1 = static_cast<Base*>(&d1);
	Base *B2 = static_cast<Base*>(&d2);

	Derived1 *dB1 = static_cast<Derived1*>(B2);
	Derived2 *dB2 = static_cast<Derived2*>(B1);

	//6. static_cast should be prefered when converting to void* OR from void*

	int i = 5;
	void *ptr_v = static_cast<void*> (&i);
	int *pr = static_cast<int*>(ptr_v);

}