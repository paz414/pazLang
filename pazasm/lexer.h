 #ifndef LEXER_H
 #define LEXER_H

 #include<iostream>
 #include<vector>

//defining aliases
typedef uint8_t byte; // Unsigned 8-bit integer
typedef std::vector<std::string> strings;

enum State{
    START,
    READCHAR,
    READBLOCK,
    SKIP,
    DUMP,
    COMMENT,
    END
};

class Lexer{
    bool isspace(char c);
    bool isspecial(char c);
    bool isgroup(char c);
    char end_char, beg_char;

    public:
    strings lex(std::string lex);
};
#endif 