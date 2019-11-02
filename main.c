#include <stdio.h>
#include "my_parser.h"

int main(int argc, char* argv[]) {
    int  aux;
    char ch;


    if( argc < 2 ){
        printf("Va rugam mai introduceti un parametru cu nr fisierului pe care doriti sa-l testati");
    }else {
        FILE *f;
        f = fopen(argv[1], "rb");
        if (f == NULL) { perror("Fisierul adaugat nu este valid"); }


        while (!feof(f)) {
            ch = fgetc(f);


            aux = parse(ch);

            if (aux != 0) break;
        }

        if (at.ok == false) {
            at.line_count = 0;
            printf("\nnu s-a putut trimite mai sus deoarece secventa introduse este invalida sau s-a terminat in eroare");

        } else {
            printf("line count = %d\n", at.line_count);
            for (int i = 0; i < at.line_count; i++) {
                for (int j = 0; at.str[i][j] != '\0'; ++j) {
                    printf("%c", at.str[i][j]);
                }
                printf("\n");
            }
        }


    }

    return 0;
}