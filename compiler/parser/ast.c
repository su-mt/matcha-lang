#include "ast.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Массив названий типов узлов
const char* node_type_names[] = {
    [NODE_INT_LITERAL] = "INT_LITERAL",
    [NODE_DOUBLE_LITERAL] = "DOUBLE_LITERAL",
    [NODE_STRING_LITERAL] = "STRING_LITERAL",
    [NODE_BOOL_LITERAL] = "BOOL_LITERAL",
    [NODE_IDENTIFIER] = "IDENTIFIER",
    [NODE_TYPE_NODE] = "TYPE_NODE",
    [NODE_DECLARATION_LIST] = "DECLARATION_LIST",
    [NODE_STATEMENT_LIST] = "STATEMENT_LIST",
    [NODE_EXPRESSION_LIST] = "EXPRESSION_LIST",
    [NODE_VAR_DECL_LIST] = "VAR_DECL_LIST",
    [NODE_PARAM_LIST] = "PARAM_LIST",
    [NODE_INIT_LIST] = "INIT_LIST",
    [NODE_VAR_DECL] = "VAR_DECL",
    [NODE_ADD] = "ADD",
    [NODE_SUB] = "SUB",
    [NODE_MUL] = "MUL",
    [NODE_DIV] = "DIV",
    [NODE_EQ] = "EQ",
    [NODE_NEQ] = "NEQ",
    [NODE_LT] = "LT",
    [NODE_GT] = "GT",
    [NODE_ASSIGN] = "ASSIGN",
    [NODE_ADD_ASSIGN] = "ADD_ASSIGN",
    [NODE_SUB_ASSIGN] = "SUB_ASSIGN",
    [NODE_MUL_ASSIGN] = "MUL_ASSIGN",
    [NODE_DIV_ASSIGN] = "DIV_ASSIGN",
    [NODE_FIELD_DECL] = "FIELD_DECL",
    [NODE_OBJECT_DECL] = "OBJECT_DECL",
    [NODE_SYSTEM_DECL] = "SYSTEM_DECL",
    [NODE_INCLUDE] = "INCLUDE",
    [NODE_QUERY] = "QUERY",
    [NODE_RUN] = "RUN",
    [NODE_EXTERNAL_RUN] = "EXTERNAL_RUN",
    [NODE_IF] = "IF",
    [NODE_ELSE] = "ELSE",
    [NODE_FOR] = "FOR",
    [NODE_FOREACH] = "FOREACH",
    [NODE_WHILE] = "WHILE",
    [NODE_RETURN] = "RETURN",
    [NODE_BLOCK] = "BLOCK",
    [NODE_ARRAY_INIT] = "ARRAY_INIT",
    [NODE_OBJECT_INIT] = "OBJECT_INIT",
    [NODE_COMPONENT_INIT] = "COMPONENT_INIT",
    [NODE_MEMBER_ACCESS] = "MEMBER_ACCESS",
    [NODE_PARAM] = "PARAM",
    [NODE_PROGRAM] = "PROGRAM"
};

const char* getNodeTypeName(NodeType type) {
    if (type >= 0 && type < sizeof(node_type_names)/sizeof(node_type_names[0]) 
        && node_type_names[type] != NULL) {
        return node_type_names[type];
    }
    return "UNKNOWN_NODE";
}

// Создание базового узла
ASTNode* createNode(NodeType type) {
    ASTNode* node = malloc(sizeof(ASTNode));
    if (!node) return NULL;
    
    node->type = type;
    node->left = NULL;
    node->right = NULL;
    node->middle = NULL;
    node->next = NULL;
    node->info = NULL;
    
    // Обнуляем union
    node->int_val = 0;
    
    return node;
}

// Создание информационного узла
static ASTNodeInfo* createNodeInfo(const char* name, int line, int col) {
    ASTNodeInfo* info = malloc(sizeof(ASTNodeInfo));
    if (!info) return NULL;
    
    info->name = name ? strdup(name) : NULL;
    info->token_type = 0;
    info->line_num = line;
    info->col_num = col;
    
    return info;
}

void setNodeInfo(ASTNode* node, const char* name, int line, int col) {
    if (!node) return;
    node->info = createNodeInfo(name, line, col);
}

// Основные функции создания узлов
ASTNode* makeIntNode(int value) {
    ASTNode* node = createNode(NODE_INT_LITERAL);
    if (node) node->int_val = value;
    return node;
}

ASTNode* makeDoubleNode(double value) {
    ASTNode* node = createNode(NODE_DOUBLE_LITERAL);
    if (node) node->double_val = value;
    return node;
}

ASTNode* makeBoolNode(uint8_t value) {
    ASTNode* node = createNode(NODE_BOOL_LITERAL);
    if (node) node->bool_val = value;
    return node;
}

ASTNode* makeStringNode(const char* value) {
    ASTNode* node = createNode(NODE_STRING_LITERAL);
    if (node) node->string_val = value ? strdup(value) : NULL;
    return node;
}

ASTNode* makeVoidNode(NodeType type) {
    return createNode(type);
}

ASTNode* makeIdentifierNode(const char* name) {
    ASTNode* node = createNode(NODE_IDENTIFIER);
    if (node) {
        node->string_val = name ? strdup(name) : NULL;
    }
    return node;
}

ASTNode* makeTypeNode(int type_id) {
    ASTNode* node = createNode(NODE_TYPE_NODE);
    if (node) node->int_val = type_id;
    return node;
}

ASTNode* makeBinOpNode(NodeType type, ASTNode* left, ASTNode* right) {
    ASTNode* node = createNode(type);
    if (node) {
        node->left = left;
        node->right = right;
    }
    return node;
}

ASTNode* makeTernaryNode(NodeType type, ASTNode* left, ASTNode* middle, ASTNode* right) {
    ASTNode* node = createNode(type);
    if (node) {
        node->left = left;
        node->middle = middle;
        node->right = right;
    }
    return node;
}

// Функции для работы со списками
ASTNode* makeListNode(NodeType type) {
    return createNode(type);
}

ASTNode* appendToList(ASTNode* list, ASTNode* item) {
    if (!item) return list;
    if (!list) return item;
    
    // Находим последний элемент в списке
    ASTNode* current = list;
    while (current->next) {
        current = current->next;
    }
    current->next = item;
    
    return list;
}

ASTNode* prependToList(ASTNode* list, ASTNode* item) {
    if (!item) return list;
    item->next = list;
    return item;
}

// Функции для создания сложных узлов
ASTNode* makeFieldDeclNode(const char* name, ASTNode* var_list) {
    ASTNode* node = createNode(NODE_FIELD_DECL);
    if (node) {
        node->left = makeIdentifierNode(name);
        node->right = var_list;
    }
    return node;
}

ASTNode* makeObjectDeclNode(const char* name, ASTNode* base, ASTNode* components) {
    ASTNode* node = createNode(NODE_OBJECT_DECL);
    if (node) {
        node->left = makeIdentifierNode(name);
        node->middle = base;
        node->right = components;
    }
    return node;
}

ASTNode* makeSystemDeclNode(const char* name, ASTNode* queries, ASTNode* runs) {
    ASTNode* node = createNode(NODE_SYSTEM_DECL);
    if (node) {
        node->left = makeIdentifierNode(name);
        node->middle = queries;
        node->right = runs;
    }
    return node;
}

ASTNode* makeVarDeclNode(ASTNode* type, const char* name, ASTNode* init_value) {
    ASTNode* node = createNode(NODE_VAR_DECL);
    if (node) {
        node->left = type;
        node->middle = makeIdentifierNode(name);
        node->right = init_value;
    }
    return node;
}

ASTNode* makeQueryDeclNode(const char* alias, const char* type_name) {
    ASTNode* node = createNode(NODE_QUERY);
    if (node) {
        node->left = alias ? makeIdentifierNode(alias) : NULL;
        node->right = makeIdentifierNode(type_name);
    }
    return node;
}

ASTNode* makeRunDeclNode(ASTNode* params, ASTNode* body) {
    ASTNode* node = createNode(NODE_RUN);
    if (node) {
        node->left = params;
        node->right = body;
    }
    return node;
}

ASTNode* makeForNode(ASTNode* init, ASTNode* condition, ASTNode* update, ASTNode* body) {
    ASTNode* node = createNode(NODE_FOR);
    if (node) {
        // Создаем вспомогательный узел для хранения init, condition, update
        ASTNode* header = createNode(NODE_EXPRESSION_LIST);
        header->left = init;
        header->middle = condition;
        header->right = update;
        
        node->left = header;
        node->right = body;
    }
    return node;
}

ASTNode* makeForEachNode(ASTNode* type, const char* var_name, ASTNode* iterable, ASTNode* body) {
    ASTNode* node = createNode(NODE_FOREACH);
    if (node) {
        ASTNode* var_decl = makeVarDeclNode(type, var_name, NULL);
        node->left = var_decl;
        node->middle = iterable;
        node->right = body;
    }
    return node;
}

ASTNode* makeIfNode(ASTNode* condition, ASTNode* then_stmt, ASTNode* else_stmt) {
    ASTNode* node = createNode(NODE_IF);
    if (node) {
        node->left = condition;
        node->middle = then_stmt;
        node->right = else_stmt;
    }
    return node;
}

ASTNode* makeWhileNode(ASTNode* condition, ASTNode* body) {
    ASTNode* node = createNode(NODE_WHILE);
    if (node) {
        node->left = condition;
        node->right = body;
    }
    return node;
}

// Функции печати и освобождения памяти
static void print_indent(const char* indent, int is_left, int is_last) {
    printf("%s", indent);
    if (is_last) {
        printf("`__ ");
    } else {
        printf("|__ ");
    }
}

static char* make_indent(const char* indent, int is_last) {
    size_t len = strlen(indent) + 5;
    char* newindent = malloc(len);
    strcpy(newindent, indent);
    strcat(newindent, is_last ? "    " : "|   ");
    return newindent;
}

static void print_ast_tree(const ASTNode* node, const char* indent, int is_last) {
    if (!node) return;
    
    print_indent(indent, !is_last, is_last);
    
    // Выводим информацию о узле
    switch (node->type) {
        case NODE_INT_LITERAL:
            printf("INT(%d)\n", node->int_val);
            break;
        case NODE_DOUBLE_LITERAL:
            printf("DOUBLE(%g)\n", node->double_val);
            break;
        case NODE_STRING_LITERAL:
            printf("STRING(\"%s\")\n", node->string_val ? node->string_val : "NULL");
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
        default:
            printf("%s", getNodeTypeName(node->type));
            if (node->info && node->info->name) {
                printf("(\"%s\")", node->info->name);
            }
            printf("\n");
    }
    
    // Считаем количество дочерних узлов
    int child_count = 0;
    if (node->left) child_count++;
    if (node->middle) child_count++;
    if (node->right) child_count++;
    if (node->next) child_count++;
    
    if (child_count > 0) {
        char* newindent = make_indent(indent, is_last);
        int current_child = 0;
        
        if (node->left) {
            print_ast_tree(node->left, newindent, (++current_child == child_count && !node->next));
        }
        if (node->middle) {
            print_ast_tree(node->middle, newindent, (++current_child == child_count && !node->next));
        }
        if (node->right) {
            print_ast_tree(node->right, newindent, (++current_child == child_count && !node->next));
        }
        if (node->next) {
            print_ast_tree(node->next, newindent, 1);
        }
        
        free(newindent);
    }
}

void printAST(const ASTNode* root) {
    if (!root) {
        printf("(empty AST)\n");
    } else {
        print_ast_tree(root, "", 1);
    }
}

void freeAST(ASTNode* node) {
    if (!node) return;
    
    freeAST(node->left);
    freeAST(node->middle);
    freeAST(node->right);
    freeAST(node->next);
    
    if (node->string_val) {
        free(node->string_val);
    }
    
    if (node->info) {
        if (node->info->name) {
            free(node->info->name);
        }
        free(node->info);
    }
    
    free(node);
}

size_t sizeofnode(NodeType type) {
    switch (type) {
        case NODE_INT_LITERAL:
            return sizeof(int);
        case NODE_DOUBLE_LITERAL:
            return sizeof(double);
        case NODE_STRING_LITERAL:
            return sizeof(char*);
        case NODE_BOOL_LITERAL:
            return sizeof(uint8_t);
        default:
            return sizeof(ASTNode);
    }
}