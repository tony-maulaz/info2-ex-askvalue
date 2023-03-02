#include <stdio.h>
#include "helper.h"

void print_blue(char* str){
    print_color(str, 34);
}

void print_red(char* str){
    print_color(str, 31);
}

void print_green(char* str){
    print_color(str, 32);
}

void print_yellow(char* str){
    print_color(str, 33);
}

void print_color(char* str, int color){
    printf("\033[%dm%s\033[0m", color, str);
}