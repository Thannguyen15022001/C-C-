#include <iostream>

int a = 50;
int& func(){
    static int x = 10;
    return x;    // or biến toàn cục đều được tương tự pointer
}


int func2(int &x){
	x = x + 1;
	return x;
}


void swap(char*& str1, char*& str2){        // char*& str1 tham chiếu kiểu con trỏ
	char * temp = str1;
	str1 = str2;
	str2 = temp;
}




class Ref{
	int id;
public:
	int value ;
	Ref(int arg){
		std::cout << "Contructor " << arg << std::endl;
		value = arg;
	}
	~Ref(){
		std::cout <<"Detructor " << value << std::endl;
	}
// Truyền tham chiếu
	void changeData(Ref &arg){
		std::cout <<"Change data " << std::endl;             // Detructor của class A (class arg) không được gọi cho dù hàm đã termination
		arg.value = arg.value + 5;
	}

// Truyền tham trị
	void changeDataVal(Ref arg){
		std::cout <<"Change data by pass value" <<std::endl;  // Detructor của class arg được gọi và đay chỉ là 1 bản sao
		arg.value = arg.value + 30;

	}
};



char s[30] = "Hello wourld";
char &Relace(int index){
	return s[index];
}



void FunctionLvalue(int& arg){
	std::cout << "Function pass lvalue: " << arg << std::endl;
}

void FunctionRvalue(int&& arg){
	std::cout << "Function pass rvalue: " << arg << std::endl;
}

int main(){
	int val = 10;
	func() = 30;

	int & ref = val ;
	int *ptr = &ref;
	*ptr = 30;

	std::cout << "Value of pointer " << *ptr << std::endl;
	std::cout << "Value of val " << val << std::endl;

	//============================================================

	int val_1 = 200;
	int *ptr_1 = &val_1;
	int* &ref_1 = ptr_1;             // tham chiếu với kiểu dữ liệu con trỏ , ngược lại (int&* a => con trỏ kiểu dữ liệu tham chiếu -> vô lý)thì không được vì không có kiểu dữ liệu tham chiếu

	ref_1 = &val;
	std::cout << "Value of ref_1 " << *ref_1 << std::endl;

	//===========================================================
	std::cout << func2(val) << std::endl;

	//std::cout << func2(50) << std::endl;           error

	std::string str1 = "Hello";
	std::string str2 = "Hello wourld";

	swap(str1,str2);
	std::cout << str1 << std::endl; 
    
    //==========================================================
    int *null_ptr = NULL;
    int &ref_null = *null_ptr;
    //std::cout << ref_null << std::endl;         core dump

    //=========================================================

    Ref A(100);
    A.changeData(A);
    A.changeDataVal(A);
    std::cout << "Value of class A" << A.value << std::endl;

    char tex = 'N';
    std::cout << "Old message: " << s << std::endl;
    Relace(5) = tex;
    std::cout << "New message: " << s << std::endl;
    //================================================
    //rvalue and lvalue
    int variable = 10;

    //lvalue
    int &ref_lval = variable;

    //rvalue 
    int &&ref_rval = 50;

    ref_rval =variable;         // chỉ gán giá trị của variable vào biến ref_rval và biến ref_rval không thể thay đổi giá trị của biến variable
     
    ref_rval = 5000;
    std::cout <<"variable: " << variable << "- ref_rval: " << ref_rval << std::endl;
    ref_lval = 1000;

    ref_rval = ref_lval;

    std::cout <<"lvalue: " << ref_lval <<std::endl;
    std::cout <<"rvalue: " << ref_rval <<std::endl;

    FunctionLvalue(variable);
    FunctionRvalue(2310);
    //FunctionRvalue(variable);            lỗi
    /*Tóm lại, không thể truyền một biến (lvalue) vào một tham số yêu cầu tham chiếu rvalue (int&&), 
    nhưng bạn có thể gắn kết một tham chiếu rvalue với một biến khác.
    */
	return 0;


}