

#include <iostream>

// exemplo passagem por referencia usando ponteiros
int function01(int *p){
    *p = *p + 3;
    return *p;
}


// exmplo passagem por referencia sem o uso de ponteiros
void function02(int& x){
    x += 3;
}

int main(){

    int x = 7;
    int y;

    y = function01(&x);
    x++;
    y++;

    std::cout << "x: " << x << std::endl << "y: " << y << std::endl;

    function02(x);
    std::cout << "new x: " << x << std::endl;

    return 0;
}
