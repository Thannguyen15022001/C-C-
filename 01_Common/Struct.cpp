#include <iostream>



//Struct in c++ and class

struct ColectionVariable{
	int age;
	char name [100];
	short int ID;
	std::string address;

	void updateInfo(int age, char * name, short int ID, const char * address){
		this->age = age;
		//(this->name[0])	= name;  nghiên cứu lại
		this->ID = ID;
		this -> address = address;
	}
};






int main(){
 	ColectionVariable a;

	return 0;
}