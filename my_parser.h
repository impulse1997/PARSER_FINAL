#ifndef PARSE_CH_LIBRARY_H
#define PARSE_CH_LIBRARY_H
#include <stdbool.h>
#include <stdint.h>
#define MAX_LINE_CNT 100
#define STRSIZE 100

typedef struct {
    bool ok;//cand returneaza "OK" sau "ERROR"
    uint32_t line_count;// cand trimitem mai sus sa vedem cat trimitem mai sus
    char str[MAX_LINE_CNT][STRSIZE+1];

}AT_DATA;
uint8_t parse(char ch);
extern AT_DATA at;


#endif //PARSE_CH_LIBRARY_H












