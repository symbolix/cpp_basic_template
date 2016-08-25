// main.cpp - A simple default cpp application.
#include <iostream>
#include <hello.h>

int main(int argc, char *argv[])
{
    std::cout << ";\n" <<  "[myApp]: Basic Template Application  v.0.0.1.[1]\n" << ";\n";
    std::cout << "[MAIN_]: Calling function <HELLO::SayHello()> " <<  std::endl;
    
    // Call the external function
    HELLO::SayHello();
    
    std::cout << ";\n";
    return 0;
}
