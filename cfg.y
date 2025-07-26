Program         ::= { Declaration } ;

Declaration     ::= FieldDecl
                 | ObjectDecl
                 | SystemDecl ;

FieldDecl       ::= "field" Identifier StructBlock ;

StructBlock     ::= "{" { VarDecl } "}" 
                 | "(" { VarDecl } ")" ;

VarDecl         ::= Type Identifier ";" ;

Type            ::= "int" | "string" | "double" | "bool" | "auto" | Identifier ;

ObjectDecl      ::= "object" Identifier [ ":" Identifier ] "{" { ComponentInit } "}" ;

ComponentInit   ::= Identifier Identifier "=" Expression ";"
                 | Identifier Identifier "[" "]" "=" ArrayInit ";" ;

ArrayInit       ::= "{" { Expression [ "," ] } "}" ;

SystemDecl      ::= "system" Identifier "{" { QueryDecl } RunDecl "}" ;

QueryDecl       ::= "query" [ Identifier ] "(" Identifier ")" ";" ;

RunDecl         ::= "run" "(" [ ParamList ] ")" ";" ;

ParamList       ::= Param { "," Param } ;

Param           ::= Type Identifier ;

RunBlock        ::= Identifier "." "run" "(" ParamList ")" Block ;

Block           ::= "{" { Statement } "}" ;

Statement       ::= ForLoop
                 | IfStmt
                 | Assignment
                 | Expression ";" ;

ForLoop         ::= "for" "(" "auto" Identifier ":" Accessor ")" Block ;

IfStmt          ::= "if" "(" Expression ")" Block ;

Assignment      ::= Accessor "=" Expression ";" ;

Accessor        ::= Identifier "." Identifier ;

Expression      ::= Literal
                 | Accessor
                 | Expression BinOp Expression
                 | "(" Expression ")" ;

Literal         ::= Integer | String | Double | Boolean ;

BinOp           ::= "+" | "-" | "*" | "/" | "==" | "!=" | "<" | ">" ;

Identifier      ::= ? any valid identifier ? ;

Integer         ::= ? digit+ ? ;
Double          ::= ? digit+ "." digit+ ? ;
String          ::= ? "..." ? ;
Boolean         ::= "true" | "false" ;