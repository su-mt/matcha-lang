
#include "ast.h"


#include <stdio.h>
#include <string.h>
#include <stdlib.h>


ASTNode* makeIntNode(int value) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = NODE_INT_LITERAL;
    node->left = NULL;
    node->right = NULL;

    node->int_val = value;

    return node;
}



ASTNode* makeDoubleNode(double value) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = NODE_DOUBLE_LITERAL;
    node->left = NULL;
    node->right = NULL;

    node->double_val = value;

    return node;
}



ASTNode* makeBoolNode(uint8_t value) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = NODE_BOOL_LITERAL;
    node->left = NULL;
    node->right = NULL;

    node->bool_val = value;

    return node;
}


ASTNode* makeStringNode(const char* value) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = NODE_STRING_LITERAL;
    node->left = NULL;
    node->right = NULL;

    char* str = strdup(value);

    node->string_val = str;

    return node;
}


ASTNode* makeVoidNode(NodeType type) {
    ASTNode* node = malloc(sizeof(ASTNode));

    node->type = type;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

ASTNode* makeBinOpNode(NodeType type, ASTNode* left, ASTNode* right) {
    ASTNode* node = malloc(sizeof(ASTNode));
    node->type = type;
    node->left = left;
    node->right = right;
    return node;
}


ASTNode* makeIdentifierNode(char* name) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_IDENTIFIER;
    node->string_val = strdup(name);  // Копируем строку
    node->left = NULL;
    node->right = NULL;
    return node;
}

ASTNode* makeTypeNode(int type_id) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->type = NODE_TYPE_NODE;
    node->int_val = type_id;  // Сохраняем тип
    node->left = NULL;
    node->right = NULL;
    return node;
}




size_t sizeofnode(NodeType type) {

    switch (type) {
    case NODE_INT_LITERAL:
        return sizeof(int);
        break;
        
    case NODE_DOUBLE_LITERAL:
        return sizeof(double);
        break;

    case NODE_STRING_LITERAL:
        return sizeof(char*);
        break;

    case NODE_BOOL_LITERAL:
        return sizeof(char);
        break;
    
    default:
        return -1;
        break;
    }
}




static void print_indent(const char* indent, int is_left) {
    printf("%s", indent);
    if (is_left) {
        printf("|__ ");
    } else {
        printf("`__ ");
    }
}

static char* make_indent(const char* indent, int is_left) {
    size_t len = strlen(indent) + 5;
    char* newindent = malloc(len);
    strcpy(newindent, indent);
    strcat(newindent, is_left ? "|   " : "    ");
    return newindent;
}

// Обновленный массив названий типов узлов
const char* node_type_names[] = {
    [NODE_INT_LITERAL] = "INT_LITERAL",
    [NODE_DOUBLE_LITERAL] = "DOUBLE_LITERAL", 
    [NODE_STRING_LITERAL] = "STRING_LITERAL",
    [NODE_BOOL_LITERAL] = "BOOL_LITERAL",
    [NODE_IDENTIFIER] = "IDENTIFIER",
    [NODE_ADD] = "ADD",
    [NODE_SUB] = "SUB", 
    [NODE_MUL] = "MUL",
    [NODE_DIV] = "DIV",
    [NODE_ASSIGN] = "ASSIGN",
    [NODE_FIELD_DECL] = "FIELD_DECL",
    [NODE_OBJECT_DECL] = "OBJECT_DECL",
    [NODE_SYSTEM_DECL] = "SYSTEM_DECL", 
    [NODE_VAR_DECL] = "VAR_DECL",
    [NODE_DECLARATION_LIST] = "DECLARATION_LIST",
    [NODE_STATEMENT_LIST] = "STATEMENT_LIST",
    [NODE_TYPE_NODE] = "TYPE_NODE",
    // Добавьте остальные типы узлов согласно вашему enum NodeType
    // Например:
    // [NODE_ARRAY_LITERAL] = "ARRAY_LITERAL",
    // [NODE_OBJECT_LITERAL] = "OBJECT_LITERAL",
    // [NODE_INCLUDE] = "INCLUDE",
    // [NODE_QUERY] = "QUERY", 
    // [NODE_RUN] = "RUN",
    // [NODE_FOR_LOOP] = "FOR_LOOP",
    // [NODE_IF_STMT] = "IF_STMT",
    // [NODE_BLOCK] = "BLOCK",
    // ... и так далее
};

// Обновленная функция print_ast_tree с лучшей обработкой неизвестных типов
void print_ast_tree(const ASTNode* node, const char* indent, int is_left) {
    if (!node) return;
    
    print_indent(indent, is_left);
    
    // Улучшенный вывод значения узла
    switch (node->type) {
        case NODE_INT_LITERAL:
            printf("INT(%d)\n", node->int_val);
            break;
        case NODE_DOUBLE_LITERAL:
            printf("DOUBLE(%g)\n", node->double_val);
            break;
        case NODE_STRING_LITERAL:
            printf("STRING(\"%s\")\n", node->string_val);
            break;
        case NODE_BOOL_LITERAL:
            printf("BOOL(%s)\n", node->bool_val ? "true" : "false");
            break;
        case NODE_IDENTIFIER:
            printf("IDENTIFIER(\"%s\")\n", node->string_val ? node->string_val : "NULL");
            break;
        case NODE_TYPE_NODE:
            printf("TYPE(%d)\n", node->int_val);
            break;
        case NODE_FIELD_DECL:
            printf("FIELD_DECL\n");
            break;
        case NODE_OBJECT_DECL:
            printf("OBJECT_DECL\n");
            break;
        case NODE_SYSTEM_DECL:
            printf("SYSTEM_DECL\n");
            break;
        case NODE_VAR_DECL:
            printf("VAR_DECL\n");
            break;
        case NODE_DECLARATION_LIST:
            printf("DECLARATION_LIST\n");
            break;
        case NODE_STATEMENT_LIST:
            printf("STATEMENT_LIST\n");
            break;
        default:
            // Безопасная проверка границ массива
            if (node->type >= 0 && node->type < sizeof(node_type_names)/sizeof(node_type_names[0]) 
                && node_type_names[node->type] != NULL) {
                printf("%s\n", node_type_names[node->type]);
            } else {
                printf("UNKNOWN_NODE (type=%d)\n", node->type);
            }
    }
    
    // Рекурсивно выводим дочерние узлы
    if (node->left || node->right) {
        char* newindent = make_indent(indent, is_left);
        if (node->left) {
            print_ast_tree(node->left, newindent, 1);
        }
        if (node->right) {
            print_ast_tree(node->right, newindent, 0);
        }
        free(newindent);
    }
}
// Вызов из клиента
void printAST(const ASTNode* root) {
    if (!root) {
        printf("(empty AST)\n");
    } else {
        // корневой узел не левый
        print_ast_tree(root, "", 0);
    }
}