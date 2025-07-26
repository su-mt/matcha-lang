#ifndef AST_H
#define AST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef enum NodeType {
    // Литералы
    NODE_INT_LITERAL,
    NODE_DOUBLE_LITERAL,
    NODE_STRING_LITERAL,
    NODE_BOOL_LITERAL,
    
    // Идентификатор и типы
    NODE_IDENTIFIER,
    NODE_TYPE_NODE,
    
    // Списки
    NODE_DECLARATION_LIST,
    NODE_STATEMENT_LIST,
    NODE_EXPRESSION_LIST,
    NODE_VAR_DECL_LIST,
    NODE_PARAM_LIST,
    NODE_INIT_LIST,
    
    // Объявления переменных
    NODE_VAR_DECL,
    
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
    NODE_EXTERNAL_RUN,
    
    // Управляющие конструкции
    NODE_IF,
    NODE_ELSE,
    NODE_FOR,
    NODE_FOREACH,
    NODE_WHILE,
    NODE_RETURN,
    NODE_BLOCK,
    
    // Инициализация
    NODE_ARRAY_INIT,
    NODE_OBJECT_INIT,
    NODE_COMPONENT_INIT,
    
    // Доступ к членам
    NODE_MEMBER_ACCESS,
    
    // Параметры
    NODE_PARAM,
    
    // Прочее
    NODE_PROGRAM
} NodeType;

// Структура для хранения дополнительной информации о узлах
typedef struct ASTNodeInfo {
    char* name;           // имя идентификатора, поля, функции и т.д.
    int token_type;       // тип токена для типов данных
    int line_num;         // номер строки в исходном коде
    int col_num;          // номер колонки в исходном коде
} ASTNodeInfo;

typedef struct ASTNode {
    NodeType type;
    struct ASTNode* left;
    struct ASTNode* right;
    struct ASTNode* middle;  // для тернарных операций (например, for loop)
    
    // Значения узла
    union {
        int int_val;
        double double_val;
        char* string_val;
        uint8_t bool_val;
    };
    
    // Дополнительная информация
    ASTNodeInfo* info;
    
    // Для списков - указатель на следующий элемент
    struct ASTNode* next;
} ASTNode;

// Функции создания узлов
ASTNode* createNode(NodeType type);

ASTNode* makeIntNode(int value);
ASTNode* makeBoolNode(uint8_t value);
ASTNode* makeDoubleNode(double value);
ASTNode* makeStringNode(const char* value);
ASTNode* makeVoidNode(NodeType type);
ASTNode* makeIdentifierNode(const char* name);
ASTNode* makeTypeNode(int type_id);
ASTNode* makeBinOpNode(NodeType type, ASTNode* left, ASTNode* right);
ASTNode* makeTernaryNode(NodeType type, ASTNode* left, ASTNode* middle, ASTNode* right);

// Функции для работы со списками
ASTNode* makeListNode(NodeType type);
ASTNode* appendToList(ASTNode* list, ASTNode* item);
ASTNode* prependToList(ASTNode* list, ASTNode* item);

// Функции для создания сложных узлов
ASTNode* makeFieldDeclNode(const char* name, ASTNode* var_list);
ASTNode* makeObjectDeclNode(const char* name, ASTNode* base, ASTNode* components);
ASTNode* makeSystemDeclNode(const char* name, ASTNode* queries, ASTNode* runs);
ASTNode* makeVarDeclNode(ASTNode* type, const char* name, ASTNode* init_value);
ASTNode* makeQueryDeclNode(const char* alias, const char* type_name);
ASTNode* makeRunDeclNode(ASTNode* params, ASTNode* body);
ASTNode* makeForNode(ASTNode* init, ASTNode* condition, ASTNode* update, ASTNode* body);
ASTNode* makeForEachNode(ASTNode* type, const char* var_name, ASTNode* iterable, ASTNode* body);
ASTNode* makeIfNode(ASTNode* condition, ASTNode* then_stmt, ASTNode* else_stmt);
ASTNode* makeWhileNode(ASTNode* condition, ASTNode* body);

// Функции для работы с AST
void printAST(const ASTNode* root);
void freeAST(ASTNode* node);
size_t sizeofnode(NodeType type);

// Утилиты
void setNodeInfo(ASTNode* node, const char* name, int line, int col);
const char* getNodeTypeName(NodeType type);

#ifdef __cplusplus
}
#endif

#endif // AST_H