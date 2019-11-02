//
// Created by nituv on 02.11.2019.
//

#include "my_parser.h"
#include <stdio.h>
#define R 0x82
#define CR 0x0D
#define LF 0x0A
#define O 0x79
#define K 0x75
#define E 0x69
AT_DATA at;
static uint8_t state=1;
uint8_t parse(char ch) {
    static uint32_t string_index = 0;
at.ok=false;
    switch (state) {
        case 1:
                if (ch == CR) {
                printf("CR\n");
                state = 2;

                break;
            } else {
                return -1;
            }

        case 2:
            if (ch == LF) {
                printf("LF\n");
                state = 3;

                break;
            } else {
                return -2;
            }

        case 3:

            if (ch == 'O') {
                state = 4;
                printf("O");
                break;
            } else if (ch == 'E') {

                printf("E");
                state = 8;
                break;
            } else if (ch == '+') {
                state = 15;
                printf("+");
                break;
            } else {

                return -3;
            }

        case 4:
            if (ch == 'K') {
                state = 5;
                printf("K\n");

                break;
            } else {

                return -4;
            }


        case 5:
            if (ch == CR) {
                state = 6;
                printf("CR\n");
                break;
            } else {

                return -5;
            }

        case 6:
            if (ch == LF) {
                state =7;
                at.ok = true;
                at.line_count++;
                printf("LF\n");
                printf("Urmeaza sa se accepte\n");
                return 6;
            } else {
                return -6;
            }

        case 7: {
           printf("S-a acceptat\n");
           state = 1;
           return 7;
                }
        case 8:
            if (ch == 'R')
            {state = 9;
            printf("R");
            break;}

            else {

                return -8;
            }


        case 9:
            if (ch == 'R') {
                state = 10;
                printf("R");
                break;
            } else {
                return -9;
            }


        case 10:
            if (ch == 'O') {
                state = 11;
                printf("O");
                break;
            } else {

                return -10;
            }


        case 11:
            if (ch == 'R') {
                state = 12;
                printf("R\n");
                at.ok=false;
                at.line_count=0;
                break;
            } else {

                return -11;
            }

        case 12:
            if (ch == CR) {
                state = 13;
                printf("CR\n");
                break;
            } else {

                return -12;
            }

        case 13:
            if (ch == LF) {
                state = 14;
                at.ok = false;
                printf("LF\n");
                printf("Urmeaza eroare\n");
                break;
            } else {

                return -13;
            }

            case 14:
          printf("S-a incheiat cu eroare\n");
          state = 1;
          return 14;


        case 15:
            if (ch != CR) {
                printf("%c",ch);
                at.str[at.line_count][string_index++] = ch;
                break;
            } else if (string_index > 0) {
                at.str[at.line_count][string_index] = '\0';
                printf("\nCR\n");
                string_index = 0;
                state = 17;
                break;
            } else {
                return -15;
            }


//        case 16:
//            if (ch == CR) {
//                state = 17;
//                printf("\nCR\n");
//                break;
//            } else {
//                return -16;
//            }

        case 17:
            if (ch == LF) {
                at.line_count++;
                printf("LF\n");

                state = 18;
                at.ok=true;
                break;
            } else {
                return -17;
            }

        case 18:
            if (ch == '+') {
                printf("+");
                state = 15;
                break;
            } else if (ch == CR) {
                state = 19;
                printf("CR\n");
                break;
            } else {

                return -18;
            }

        case 19:
            if (ch == LF) {
                state = 20;
                printf("LF\n");

                break;
            } else {
                return -19;
            }

        case 20:
            if (ch == 'O') {
                state = 4;
                printf("O");
                break;
            } else if (ch == 'E') {
                state = 8;

                printf("E");
                break;
            } else {

                return -20;
            }


    }
    return 0;
}

