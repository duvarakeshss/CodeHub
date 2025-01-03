%{
#include <stdio.h>
%}
%%

"//".*               {  }
"/*"([^*]|\*+[^/])*\*+"/" { }
.                    { printf("%s", yytext); } 
\n                   { printf("\n"); } 

%%

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <source_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file; // Set the input file for lex
    yylex();     // Start the lexer
    fclose(file); // Close the file after processing
    return 0;
}

int yywrap() {
    return 1; 
}
