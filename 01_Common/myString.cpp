#include <iostream>
#include <String>

std::string myAppend(std::string firstString, std::string secondString){
    return firstString.append(secondString);
}

int getLength(std::string myString){
    return myString.length();
}

std::string getInputString(){
    std::string inputString;
    //std::cin >> inputString;
    std::cout << "Please enter your input\n";
    std::getline(std::cin,inputString);
    return inputString;
}
 
int main(){
    std::cout << myAppend("Nguyen ","Than") << " " << getLength(myAppend("Nguyen ","Than"));
    std::cout << getInputString();
    return 0;
}