#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include<time.h>
#include "helper.h"

typedef struct {
    int year;
    int month;
    int day;
} Date;

void getCurrentTime(Date* d){
    time_t rawtime = time(NULL);
    struct tm *ptm = localtime(&rawtime);

    d->year = ptm->tm_year + 1900;
    d->month = ptm->tm_mon;
    d->day = ptm->tm_mday;
}

bool valid_saisie()
{
    const char c = getchar();
    if (c == '\n')
        return true;
    else
        while (getchar() != '\n');
    return false;
}

double ask_user_double_value(char message[], double min_value, double max_value)
{
    bool saisie_ok = false;
    double choice;
    printf("%s", message);
    do
    {
        const int nbr_ret = scanf("%lf", &choice);
        if (valid_saisie() && nbr_ret == 1 && choice >= min_value && choice <= max_value)
        {
            saisie_ok = true;
        }
        else
        {
            printf("Vous devez saisir un nombre entre %.1lf et %.1lf > ", min_value, max_value);
        }
    } while (!saisie_ok);
    return choice;
}

int ask_user_int_value(char message[], int min_value, int max_value)
{
    return (int)ask_user_double_value(message, min_value, max_value);
}

int menu(){
    puts("\nVeuillez choisir une option :");
    puts("\t1. Nouveau fichier.");
    puts("\t2. Afficher le fichier.");
    puts("\t3. Ajouter une mesure.");
    puts("\t4. Afficher la moyenne.");
    puts("\t5. Quitter");
    puts("\t6. Affiche la date.");

    return ask_user_int_value("> ", 0, 6);
}

// menu actions
void print_time(){
    Date d;
    getCurrentTime(&d);

    char str[20];
    sprintf(str, "Current date : %d\n", d.year);

    printf("%s", str);
}

void new_file(){

}

void print_file(){

}

void append_measure(){

}

void print_measure(){

}

int main(int argc, char *argv[]){
 
    print_blue("Programme start\n\n");

    int menu_choice;
    do
    {
        menu_choice = menu();
        switch (menu_choice)
        {
            case 6:
                print_time();
                break;

            default:
                break;
        }
    } while (menu_choice != 5);


    return 0;
}