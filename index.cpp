#include <iostream>
#include <string>
#include <array>

int _size = 4;
int _capacity = 0;

void consoleResult(int* array){
    std::cout<<"Capacity: "<<_capacity<<" - Size: "<<_size<<std::endl;
    for(int i = 0; i < _capacity; i++){
        std::cout<<i<<" - value: "<<*(array + i)<<" - Location: "<<&*(array + i)<<std::endl;
    };
}

int * resizeArray(int* array){
    _size*=2;
    int newArray[_size];
    for(int i = 0; i < _capacity; i++){
        newArray[i] = *(array + i);
    };
    //int *pAr = newArray;
    //consoleResult(pAr);

    return newArray;
}

int pushback(int* array, int* arg){
    if(_capacity + 1 > _size) { 
        array = resizeArray(array);
        std::cout<<"New array size: "<<_size<<" -> "<<std::endl;
    }
    *(array + _capacity) = *arg;
    _capacity++;
    return 0;
}



int main(void){
    int array[_size];
    int *pArr = array;
    while(true){
        int entryValue;
        std::cout<<"Enter integer value to add to the array: ";
        std::cin>>entryValue;
        pushback(pArr, &entryValue);
        consoleResult(pArr);
    }
    return 0;
};