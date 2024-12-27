%{
#include <stdio.h>

int line_number = 1;
FILE *output_file;
%}

line .*\n

%% 
{line} { fprintf(output_file, "%10d %s", line_number, yytext);
	printf("%10d %s", line_number++, yytext); } 

%% 

int yywrap() {}

int main(int argc, char* argv[]) 
{ 
    extern FILE *yyin;  

    
    yyin = fopen(argv[1], "r");
    if (yyin == NULL) {
        perror("Error opening input file");
        return 1;
    }

    
    output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        perror("Error opening output file");
        fclose(yyin);
        return 1;
    }

    
    yylex();  

    
    fclose(yyin);
    fclose(output_file);

    return 0; 
}
