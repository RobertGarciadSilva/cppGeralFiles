#define SIZE 5

int main(){

    long value1 = 200000;
    long value2;

    long *long_ptr;
    long_ptr = &value1;
    std::cout << *long_ptr << " ";
    value2 = *long_ptr;
    std::cout << value2 << " ";
    std::cout << &value1 << " ";
    std::cout << long_ptr << " ";
    std::cout << 1 << " ";

    unsigned int values[SIZE];

    for(int i = 0, j = 2; i < SIZE; i++, j+=2){
        values[i] = j;
    }

    unsigned int *v_ptr;
    
    for(int i = 0; i < SIZE; i++){
        std::cout << values[i] << " ";
    }

    v_ptr = values;
    
    for(int i = 0; i < SIZE; i++){
        std::cout << *(v_ptr + i) << " ";
    }

    for(int i = 0; i < SIZE; i++){
        std::cout << *(values + i) << " ";
    }

    for(int i = 0; i < SIZE; i++){
        std::cout << v_ptr[i] << " ";
    }

    std::cout << values[4] << " ";
    std::cout << *(values + 4) << " ";
    std::cout << v_ptr[4] << " ";
    std::cout << *(v_ptr + 4) << " ";

    std::cout << (v_ptr + 3) << " " << *(v_ptr + 3) << " ";
    std::cout << v_ptr << " ";
    std::cout << 2;

    return 0;
}