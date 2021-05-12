/*
// Vilius Junevičius, 4 grupė, 1 pogrupis
// vilius.junevicius@mif.stud.vu.lt


// Programa, kuri realizuoja abstraktų duomenų tipą vektorių.
// Pakeiskite typedef dataType duomenų tipą į norimą duomenų tipą prieš paleidžiant programą.
// Programos paleidimas:
//   make

// Programa suskaidyta į 3 dalis:
// 1. main.c - naudotojo interfeisas, kreipimasis į funkcijas;
// 2. header.h - headerio failas, kuriama surašyti funkcijų aprašai ir maskimalios reikšmės bei vektoriuje naudojamas duomenų tipas, kurį galima pakeisti;
// 3. functions.c - funkcijų failas, kuriame surašyti visi funkcijų apibrėžimai (9 sunumeruotos funkcijos) ir informacija apie funkcijas.


// Funkcijos, kurios apdorojamos programoje:
//   1. createVector - sukurti vektorių,
//   2. addElement - įdėti elementą į vektoriaus galą,
//   3. insertElementAt - įterpti elementą į norimą poziciją,
//   4. setElementAt - pakeisti elemento reikšmę vektoriuje,
//   5. isEmpty - patikrina, ar vektorius tuščias,
//   6. removeElementAt - išima elementą iš norimos pozicjos,
//   7. removeAllElements - išima visus elementus iš vektoriaus, t.y. atlaisvina atmintį ir ištrina vektorių
//   8. printAllElements - išspausdina visus elementus esančius vektoriuje,
//   9. readInput - perskaito elemento reikšmę, kurią norime įdėti į vektorių.
//   10. checkErrors - jei įvyko klaida, išspausdinamas klaidos pranešimas

// Naudojamas bibliotekos:
//  header.h - funkcijų aprašų failas,
//  stdio.h - scanf, printf: skaitymui ir išvedimui,
//  stdlib.h - realloc, free: dinaminės atminties priskyrimui ir atlaisvinimui,
//  stdbool.h - bool: duomenų tipo bool naudojimui,
//  string.h - strcmp: tekstinių eilučių palyginimui.

// Kintamieji:
//  struct vectors allVectors[] - masyvas, kurio elementai struktūros, kuriuose du kintmieji vector ir size (programoje kreiptis į vektorių nuo 1):
//      dataType *vector - vector, tai vektorius (rodyklė į naudojamą duomenų tipą),
//      int size - vektoriaus dydis, size = 0, kai vektorius tuščias, size = 1, kai vektorius gali saugoti vieną reikšmę, ir t.t.,
//  dataType element - elemento reikšme,
//  int index - vektoriaus indeksas (skaičiuojasi nuo 0),
//  int errorCode - įgija reikšmę 1, kai funkcijoje įvyksta klaida, apie kurią pranešame vartotojui, yra reikšmės 0, jei klaida neįvyko,
//  char string[] - simbolių masyvas, kuris saugo vektoriuje naudojamą duomenų tipą,
//  int flag - saugo, vartotojo įvestą reikšmę, pagal kurią paleidžia atitinkamą funkciją,
//  int created - kintamasis, kuris praneša, ar yra sukurtas bent vienas vektorius su kuriuo galima atlikti visas funkcijas

// Klaidų kodai(errorCode):
// errorCode = 0, jeigu klaida neįvyko
// errorCode = 1, jeigu pateiktas indeksas netinka, nes indeksas negali būti mažesnis negu 0 ir negali būti didesnis negu vektoriaus dydis
// errorCode = 2, jeigu vektorius sukurti atminties nepavyko arba virsytas vektoriaus elementų kiekis
// errorCode = 3, jeigu pateiktas indeksas netinka, nes indeksas negali būti mažesnis negu 0 ir negali būti didesnis arba lygus vektoriaus dydžiui

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

struct vectors{
    dataType *vector;
    int size;
};

int main(){
    struct vectors allVectors[MAX_VECTORS];
    dataType element;
    int whichVector, index, numberOfVectors = 0, errorCode = 0, flag = 0, created = 0;
    char string[MAX_STRING_LENGTH];

    printf("\nVECTOR\n");

    printf("\nWhat data type will you be using (it should be the same as the typedef in the program)?\n");
    scanf("%[^\n]", &string);

    // Įvesto duomenų tipo validacija
    while (strcmp(string, "int") != 0 && strcmp(string, "signed") != 0 && strcmp(string, "signed int") != 0 && strcmp(string, "unsigned int") != 0 && strcmp(string, "unsigned") != 0 && strcmp(string, "short int") != 0 && strcmp(string, "short") != 0 && strcmp(string, "signed short int") != 0 && strcmp(string, "signed short") != 0 && strcmp(string, "unsigned short int") != 0 && strcmp(string, "unsigned short") != 0 && strcmp(string, "long int") != 0 && strcmp(string, "long") != 0 && strcmp(string, "signed long") != 0 && strcmp(string, "signed long int") != 0 && strcmp(string, "unsigned long int") != 0 && strcmp(string, "long long") != 0 && strcmp(string, "long long int") != 0 && strcmp(string, "signed long long") != 0 && strcmp(string, "signed long long int") != 0 && strcmp(string, "unsigned long long") != 0 && strcmp(string, "unsigned long long int") != 0 && strcmp(string, "float") != 0 && strcmp(string, "double") != 0 && strcmp(string, "long double") != 0 && strcmp(string, "char") != 0 && strcmp(string, "signed char") != 0 && strcmp(string, "unsigned char") != 0){
        printf("\nThis is not a valid data type. Try again.\n");
        printf("What data type will you be using?\n");
        getchar();
        scanf("%[^\n]", &string);
    }


    // Ciklas, kuris vyksta vieną arba daugiau kartų, kol neįvedamas 9
    do {
        flag = 0;
        printf("\nPress 1 create a vector.\n");
        printf("Press 2 to add an element to the end of the vector.\n");
        printf("Press 3 to insert an element at a specific index of the vector.\n");
        printf("Press 4 to set an element to a specific value at a specific index of the vector.\n");
        printf("Press 5 to check if the vector is empty.\n");
        printf("Press 6 to remove an element at a certain index.\n");
        printf("Press 7 to remove all elements from the vector.\n");
        printf("Press 8 to print out all the value of the vector.\n");
        printf("Press 9 to end the program.\n");

        scanf("%d", &flag);
        getchar();

        if (flag == 1){ // sukurti vektorių
            if (numberOfVectors == MAX_VECTORS){
                printf("You have reached the limit of vectors you can create.\n");
            }
            else {
                numberOfVectors++;
                createVector(&(allVectors[numberOfVectors - 1].vector), &(allVectors[numberOfVectors - 1].size));
                printf("\nThe vector number %d is created\n", numberOfVectors);
                flag = 0;
                created = 1;
            }
        }
        else if (flag == 2){ // Įterpti naują reikšmę į vektoriaus galą
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                printf("\nIn to which vector whould you like to insert this value (vectors are counted from 1)?\n");
                while (scanf("%d", &whichVector) != 1 || whichVector <= 0 || whichVector > numberOfVectors){
                    printf("\nBad input. The vector with this number does not exist. Vectors are counted from 1. Try again.\n");
                    scanf("%*[^\n]");
                }

                printf("\nInput the value you would like to add to the end of the vector.\n");
                readInput(string, &element);
                
                addElement(&(allVectors[whichVector - 1].vector), &(allVectors[whichVector - 1].size), element, &errorCode);
                checkErrors(&errorCode);

                errorCode = 0;
                flag = 0;
            }   
        }
        else if (flag == 3){ // Įterpti naują reikšmę į vektorių nurodytu indeksu
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                printf("\nIn to which vector whould you like to insert this value (vectors are counted from 1)?\n");
                while (scanf("%d", &whichVector) != 1 || whichVector <= 0 || whichVector > numberOfVectors){
                    printf("\nBad input. The vector with this number does not exist. Vectors are counted from 1. Try again.\n");
                    scanf("%*[^\n]");
                }

                printf("\nInput the value you would like to add into the vector.\n");
                readInput(string, &element);

                printf("\nInput the index of the vector where the value is going to be inserted (index is counted from 0).\n");
                scanf("%d", &index);

                insertElementAt(&(allVectors[whichVector - 1].vector), &(allVectors[whichVector - 1].size), element, index, &errorCode);
                checkErrors(&errorCode);

                errorCode = 0;
                flag = 0;
            }
        }
        else if (flag == 4){ // Pakeisti elemento reikšmę vektoriuje nurodytu indeksu
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                printf("\nIn which vector will you change the vector element's value (vectors are counted from 1)?\n");
                while (scanf("%d", &whichVector) != 1 || whichVector <= 0 || whichVector > numberOfVectors){
                    printf("\nBad input. The vector with this number does not exist. Vectors are counted from 1. Try again.\n");
                    scanf("%*[^\n]");
                }

                printf("\nInput the index at which you will change the value of the vector (index is counted from 0).\n");
                scanf("%d", &index);

                printf("\nInput the value that it is going to change to.\n");
                readInput(string, &element);

                setElementAt(allVectors[whichVector - 1].vector, allVectors[whichVector - 1].size, element, index, &errorCode);
                checkErrors(&errorCode);

                errorCode = 0;
                flag = 0;
            }
        }
        else if (flag == 5){ // Patikrinti, ar veiktorius tuščias
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                printf("\nWhich vector fo you want to check if it's empty (vectors are counted from 1)?\n");
                while (scanf("%d", &whichVector) != 1 || whichVector <= 0 || whichVector > numberOfVectors){
                    printf("\nBad input. The vector with this number does not exist. Vectors are counted from 1. Try again.\n");
                    scanf("%*[^\n]");
                }

                bool empty = isEmpty(allVectors[whichVector - 1].size);

                if (empty == true){
                    printf("\nThe vector is empty.\n");
                }
                else {
                    printf("\nThe vector is NOT empty.\n");
                }

                flag = 0;
            }
        }
        else if (flag == 6){ // Išimti elementą iš vektoriaus nurodytu indeksu
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                printf("\nFrom which vector do you want to remove an element (vectors are counted from 1)?\n");
                while (scanf("%d", &whichVector) != 1 || whichVector <= 0 || whichVector > numberOfVectors){
                    printf("\nBad input. The vector with this number does not exist. Vectors are counted from 1. Try again.\n");
                    scanf("%*[^\n]");
                }

                printf("\nInput the index of the element you want to remove (index is counted from 0).\n");
                scanf("%d", &index);

                removeElementAt(&(allVectors[whichVector - 1].vector), &(allVectors[whichVector - 1].size), index, &errorCode);
                checkErrors(&errorCode);

                errorCode = 0;
                flag = 0;
            }
        }
        else if (flag == 7){ // Išimti visus elementus iš vektoriaus
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                printf("\nFrom which vector do you want to remove all elements (vectors are counted from 1)?\n");
                while (scanf("%d", &whichVector) != 1 || whichVector <= 0 || whichVector > numberOfVectors){
                    printf("\nBad input. The vector with this number does not exist. Vectors are counted from 1. Try again.\n");
                    scanf("%*[^\n]");
                }

                removeAllElements(&(allVectors[whichVector - 1].vector), &(allVectors[whichVector - 1].size), &errorCode);
                checkErrors(&errorCode);

                errorCode = 0;
                flag = 0;

                // Istriname atlaisvintą vektorių
                for (int i = whichVector - 1; i < numberOfVectors - 1; ++i){
                    allVectors[i] = allVectors[i + 1];
                }
                numberOfVectors--;

                if (numberOfVectors == 0){
                    created = 0;
                }
            }
        }
        else if (flag == 8){ // Išspausdinti visus elementus esančius vektoriuje
            if (created == 0){
                printf("\nPlease create the vector first.\n");
            }
            else {
                for (int i = 0; i < numberOfVectors; ++i){
                    printf("\nVector number %d has these values:\n", i + 1);
                    if(allVectors[i].size == 0){
                        printf("empty\n");
                    }
                    else {
                        printAllElements(allVectors[i].vector, allVectors[i].size, string);
                    }
                }

                flag = 0;
            }
        }

    } while (flag != 9);

    return 0;
}