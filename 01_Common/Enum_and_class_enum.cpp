#include <iostream>


// Enum 
enum Color { red, blue, yellow};
enum size { small, big};
// int red;  => lỗi không thể khai báo trùng tên với các thành phần của enum
// enum Color2 { red, blue, yellow, brow}; => lỗi tương tự trên



// Class enum
enum class C_Color {black, pink, white}; 
enum class Csize { small, big};
enum class C_Color2 {black, pink, white, blue};
int back = 10;

void enum_class_func(C_Color c){   // không thể thay thế bằng kiểu int
	switch(c){
		case C_Color::black:
			std::cout << "function black color" << std::endl;
			break;
		case C_Color::pink:
			std::cout << "function pink color" << std::endl;
			break;
		case C_Color::white:
			std::cout << "function white color" << std::endl;
			break;
	}
}


void enum_func(int c){
	switch(c){
	case red:
		std::cout << "function Red color" << std::endl;
		break;
	case blue:
		std::cout << "function blue color" << std::endl;
		break;
	case yellow:
		std::cout << "function yellow color" << std::endl;
		break;
	}
}

int main(){

// cách dùng
    /*enum*/

    Color c1 = red;
	switch(c1){
	case red:
		std::cout << "Red color" << std::endl;
		break;
	case blue:
		std::cout << "blue color" << std::endl;
		break;
	case yellow:
		std::cout << "yellow color" << std::endl;
		break;
	}

	/*enum class*/

    C_Color c2 = C_Color::black;
	switch(c2){
	case C_Color::black:
		std::cout << "black color" << std::endl;
		break;
	case C_Color::pink:
		std::cout << "pink color" << std::endl;
		break;
	case C_Color::white:
		std::cout << "white color" << std::endl;
		break;
	}


   enum_func(0);
   enum_func(1);
   enum_func(yellow);

	enum_class_func(C_Color::black);
	//enum_class_func(1);   lỗi

   // có thể so sánh 2 biến trong 2 enum với nhau
	if(red == small)
		std::cout << "Hello wourld" << std::endl;

	/*
	if(C_Color::black == Csize::small)
		std::cout << "Hello wourld" << std::endl;   => lỗi
	*/

}
