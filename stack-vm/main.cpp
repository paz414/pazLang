#include "vm.h"
#include <map>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]){
    if(argc<2){
        cout << "Please provide a filename" << endl;
        exit(1);
    }
    ifstream r(argv[1],ios::binary);
    i32 i;
    vector<i32> prog;
    while(r.read((char*)&i,sizeof(i32))){
        prog.push_back(i);
    }

    StackVM vm;
    vm.load_program(prog);
    vm.run();
    return 0;
}