#include <iostream>

static int hello(int num);

static int hello(int num){
    return num*2;
}

int main(){
    std::cout<<hello(3);
}

// C:\Users\teckn\AppData\Local\Temp\ccii6Drp.o:main.cpp:(.text+0x1e): undefined reference to `hello(int)'
// collect2.exe: error: ld returned 1 exit status
//Ошибка "undefined reference to hello(int)'" говорит о том, 
//что компилятор не может найти определение (реализацию) функции helloдля типаint` при линковке объектных файлов.

