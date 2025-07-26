// ast.h

#include <stdio.h>
#include <stdlib.h>

#ifndef _AST_H
#define _AST_H



#ifdef __cplusplus
extern "C" {
#endif

typedef enum  NodeType {
    // Литералы
    NODE_INT_LITERAL,
    NODE_DOUBLE_LITERAL,
    NODE_STRING_LITERAL,
    NODE_BOOL_LITERAL,

    // Идентификатор
    NODE_IDENTIFIER,
    NODE_DECLARATION_LIST,
    NODE_STATEMENT_LIST,
    NODE_EXPRESSION_LIST,
    NODE_VAR_DECL,
    NODE_TYPE_NODE,

    // Арифметика
    NODE_ADD,
    NODE_SUB,
    NODE_MUL,
    NODE_DIV,

    // Сравнение
    NODE_EQ,
    NODE_NEQ,
    NODE_LT,
    NODE_GT,

    // Присваивание
    NODE_ASSIGN,
    NODE_ADD_ASSIGN,
    NODE_SUB_ASSIGN,
    NODE_MUL_ASSIGN,
    NODE_DIV_ASSIGN,

    // Конструкции языка
    NODE_FIELD_DECL,
    NODE_OBJECT_DECL,
    NODE_SYSTEM_DECL,
    NODE_INCLUDE,
    NODE_QUERY,
    NODE_RUN,

    // Управляющие конструкции
    NODE_IF,
    NODE_ELSE,
    NODE_FOR,
    NODE_WHILE,
    NODE_RETURN

}NodeType;


typedef struct ASTNode {

    NodeType type;
    struct ASTNode* left;
    struct ASTNode* right;

    union {
        int int_val;
        double double_val;
        char* string_val;
        u_int8_t bool_val;
    };

} ASTNode;


ASTNode* makeIntNode(int value);
ASTNode* makeBoolNode(uint8_t value);
ASTNode* makeDoubleNode(double value);
ASTNode* makeStringNode(const char* value);
ASTNode* makeVoidNode(NodeType type);

ASTNode* makeIdentifierNode(char* name);
ASTNode* makeTypeNode(int type_id);
ASTNode* makeBinOpNode(NodeType type, ASTNode* left, ASTNode* right);


void printAST(const ASTNode* root) ;

size_t sizeofnode(NodeType type);   


// void makeTree(AstNode* root, ...);

#ifdef __cplusplus
}
#endif


#endif // _AST_H