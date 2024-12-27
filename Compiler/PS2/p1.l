%{
    #include <stdio.h>
    int alpCount = 0;
    int digitCount = 0;
    int spaceCount = 0;
    int splCount = 0;
    int lineCount = 0;
    int wordCount = 0;
%}

%%

[a-zA-Z]  { alpCount++; }

[0-9]     { digitCount++; }

[ ]	  { spaceCount++; wordCount++;}
 
[\n]      { lineCount++; wordCount++;}

.         {splCount++;}

%%

int yywrap(){}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return 1;
    }

    yyin = file;
    yylex();

    fclose(file);

    printf("Alphabets: %d\n", alpCount);
    printf("Digits: %d\n", digitCount);
    printf("Spaces: %d\n", spaceCount);
    printf("Special Characters: %d\n", splCount);
    printf("Lines: %d\n", lineCount);
    printf("Words: %d\n", wordCount);

    return 0;
}
