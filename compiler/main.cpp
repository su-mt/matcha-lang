#include "parser/ast.h"          // ASTNode и функции
#include "parser/parser.h"   // yyparse
#include <cstdio>
#include <iostream>

extern ASTNode* root;      // Определена в matcha.y
extern FILE* yyin;         // Используется Flex'ом
extern int yyparse();;


int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <source.mch>\n";
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("fopen");
        return 1;
    }

    if (yyparse() == 0) {
        std::cout << "Parse success.\n";
        printAST(root);  // Функция для вывода дерева
    } else {
        std::cerr << "Parse failed.\n";
    }

    fclose(yyin);
    return 0;
}