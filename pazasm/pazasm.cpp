#include<iostream>
#include<fstream>
#include "lexer.h"

typedef uint32_t i32;
using namespace std;

//functions

vector<i32> compile(strings s);
bool isInt(string s);
bool isPrimitive(string s);
i32 map(string s);


int main(int argc, char* argv[]){
    if(argc != 2){
        cout << "Usage:"<<argv[0]<<" pazasm <filename>" << endl;
        return 1;
    }
    ifstream file(argv[1]);
    if(!file.is_open()){
        cout << "Error: Could not open file" << endl;
        return 1;
    }
    string line;
    string lexemes;
    while(getline(file, line)){
        lexemes+= line+"\n";
    }
    file.close();

    //lexer
    Lexer lexer;
    strings lexed= lexer.lex(lexemes);

    //compiler
    vector<i32> instructions= compile(lexed);

    //write to file
    ofstream ofile;
    ofile.open("a.out", ios::binary);
    for(i32 i: instructions){
        ofile.write((char*)&i, sizeof(i));
    }
    ofile.close();
    return 0;
};

vector<i32> compile(strings s){
    vector<i32> instructions;
    for(string lexeme: s){
        if(isInt(lexeme)){
            instructions.push_back(stoi(lexeme));
        }
        else{
                i32 opcode= map(lexeme);
                if(opcode!=-1)
                    instructions.push_back(opcode);
                else{
                    cout << "Error: Invalid lexeme: " << lexeme << endl;
                    exit(1);
                }
        }
    }
    instructions.push_back(0x40000000);
    return instructions;
};


bool isInt(string s){
    for(char c: s){
        if(!isdigit(c))
            return false;
    }
    return true;
};

i32 map(string s){
    if(s=="+")
        return 0x40000001;
    if(s=="-")
        return 0x40000002;
    if(s=="*")
        return 0x40000003;
    if(s=="/")
        return 0x40000004;
    return -1;
}