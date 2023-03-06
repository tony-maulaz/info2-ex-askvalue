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
    d->month = ptm->tm_mon + 1;
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

void new_file(char* filename){
    FILE* f = fopen(filename, "w");
    fclose(f);
}

void print_file(char* filename){
    FILE* f = fopen(filename, "r");
    if( f == NULL ){
        print_red("Erreur d'ouverture du fichier\n");
        return;
    }

    do{
        char buffer[100];
        char* c = fgets(buffer, sizeof(buffer), f);

        if( c == NULL ){
            fclose(f);
            return;
        }

        fprintf(stdout, "%s", buffer);
    }while(true);
}

void append_measure(char* filename){
    FILE* f = fopen(filename, "a");
    if( f == NULL ){
        print_red("Erreur d'ouverture du fichier\n");
        return;
    }

    Date d;
    getCurrentTime(&d);

    double val = ask_user_double_value("Nombre\n>",-1000.0,1000.0);

    fprintf(f, "%d-%d-%d,%.2lf\n", d.year, d.month, d.day, val);

    fclose(f);
}

void print_measure(char* filename){
    FILE* f = fopen(filename, "r");
    if( f == NULL ){
        print_red("Erreur d'ouverture du fichier\n");
        return;
    }

    double sum = 0;
    int cpt = 0;
    do{
        char buffer[100];
        char* c = fgets(buffer, sizeof(buffer), f);

        if( c == NULL ){
            fprintf(stdout, "La moyenne sur %d valeurs : %.2lf\n", cpt, 
                cpt == 0 ? 0.0 : sum/cpt);

            fclose(f);
            return;
        }

        double val;
        if( sscanf(buffer, "%*d-%*d-%*d,%lf", &val) == 1 ){
            sum += val;
            cpt++;
        }

    }while(true);
}

int main(int argc, char *argv[]){
 
    print_blue("Programme start\n\n");

    char filename[] = "measure.csv";

    int menu_choice;
    do
    {
        menu_choice = menu();
        switch (menu_choice)
        {
            case 1:
                new_file(filename);
                break;

            case 2:
                print_file(filename);
                break;

            case 3:
                append_measure(filename);
                break;

            case 4:
                print_measure(filename);
                break;

            case 6:
                print_time();
                break;

            default:
                break;
        }
    } while (menu_choice != 5);


    return 0;
}