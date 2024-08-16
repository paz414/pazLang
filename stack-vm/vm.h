#ifndef STACK_VM_H
#define STACK_VM_H
//Prevents multiple definitions of the same classes, functions, 
//or variables, which would cause compilation errors.
#include <iostream>
#include <vector>

typedef int32_t i32;

class StackVM{
    i32 pc=100; //program counter
    i32 sp=0; //stack pointer
    std::vector<i32> memory; //memory of the virtual cpu
    i32 typ=0; //type of the current operation
    i32 dat=0; //data of the current operation
    i32 running=1; //is the vm running?

    i32 get_type(i32 instruct);
    i32 get_data(i32 instruct);

    void fetch();
    void decode();
    void execute();
    void do_primitive();
    public:
        StackVM();
        void run();
        void load_program(std::vector<i32> prog);
};
#endif