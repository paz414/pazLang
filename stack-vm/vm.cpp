#include "vm.h"
/*
*Instruction format:
* 2 bits for the type of operation
* 30 bits for the data
* Types of operation:
* 0: positive number
* 1: primitive instruction
* 2: negative number
* 3: undefined

*/
StackVM::StackVM(){
    memory.reserve(1000000);
}
i32 StackVM::get_type(i32 instruct){
    // takes out the type of the instruction from the passed instruction
    // PS: See instruct format
    i32 type=0xc0000000; //minimum value of a 32 bit signed int
    type = (type & instruct) >> 30;
    return type;
}
i32 StackVM::get_data(i32 instruct){
    i32 data=0x3fffffff; //maximum value of a 30 bit signed int
    data = data & instruct;
    return data;
}
void StackVM::fetch(){
    pc++;
}
void StackVM::decode(){
    typ=get_type(memory[pc]);
    dat=get_data(memory[pc]);
}
void StackVM::execute(){
    if(typ==0 || typ==2){
        sp++;
        memory[sp]=dat;
    }else{
        do_primitive();
    }
}
void StackVM::do_primitive(){
    switch(dat){
        case 0: //halt
            std::cout<<"halt\n";
            running=0;
            break;
        case 1: //add
            std::cout<<"add "<<memory[sp-1]<<" "<<memory[sp]<<"\n";
            memory[sp-1]=memory[sp-1]+memory[sp];
            sp--;
            break;
        case 2: //sub
            std::cout<<"sub "<<memory[sp-1]<<" "<<memory[sp]<<"\n";
            memory[sp-1]=memory[sp-1]-memory[sp];
            sp--;
            break;
        case 3: //mul
            std::cout<<"mul "<<memory[sp-1]<<" "<<memory[sp]<<"\n";
            memory[sp-1]=memory[sp-1]*memory[sp]; 
            sp--;
            break;
        case 4: //div
            std::cout<<"div "<<memory[sp-1]<<" "<<memory[sp]<<"\n";
            //this is integer division
            memory[sp-1]=memory[sp-1]/memory[sp];
            sp--;
            break;
    }
}
void StackVM::run(){
    pc-=1; //we do this because the first thing we do in the fetch is increment the pc 
    //so we need to decrement it to start from the first instruction
    while (running==1)
    {
        fetch();
        decode();
        execute();
        std::cout<<"TOS: "<<memory[sp]<<"\n";
    }
}
void StackVM::load_program(std::vector<i32> prog){
    for(i32 i=0;i<prog.size();i++){
        memory[pc+i]=prog[i];
    }
}

