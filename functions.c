/*
// functions.c
// Failas, kuriame pateikti visi funkcijų apibrėžimai.
// Funkcijos yra sunuomeruotos pagal eiliškumą. 
// Ką atlieka funkcija, ką gauna ir ką grąžina, parašyta virš funkcijos.
// Jeigu neparašyta, ką funkciją grąžina, tai funkciją nieko negrąžina.

// Kintamieji:
//  dataType *vector - vector, tai vektorius (rodyklė į naudojamą duomenų tipą)
//  int size - vektoriaus dydis, size = 0, kai vektorius tuščias, size = 1, kai vektorius gali saugoti vieną reikšmę, ir t.t.
//  dataType element - elemento reikšme
//  int index - vektoriaus indeksas (skaičiuojasi nuo nulio)
//  int errorCode - įgija reikšmę 1 arba 2, kai funkcijoje įvyksta klaida, apie kurią pranešame vartotojui, yra reikšmės 0, jei klaida neįvyko
//  char string[] - simbolių masyvas, kuris saugo vektoriuje naudojamą duomenų tipą,

// Funkcijos, kurios apdorojamos programoje:
//   1. createVector - sukurti vektorių,
//   2. addElement - įdėti elementą į vektoriaus galą,
//   3. insertElementAt - įterpti elementą į norimą poziciją, negalima įterpti elemento į poziciją didesnę už vektoriaus dydį
//   4. setElementAt - pakeisti elemento reikšmę vektoriuje,
//   5. isEmpty - patikrina, ar vektorius tuščias,
//   6. removeElementAt - išima elementą iš norimos pozicjos,
//   7. removeAllElements - išima visus elementus iš vektoriaus, t.y. atlaisvina atmintį ir ištrina vektorių
//   8. printAllElements - išspausdina visus elementus esančius vektoriuje,
//   9. readInput - perskaito elemento reikšmę, kurią norime įdėti į vektorių.
//   10. checkErrors - jei įvyko klaida, išspausdinamas klaidos pranešimas
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "header.h"

// 1.
// Funkcija, kuri sukuria vektorių.
// Funkcija gauna rodyklę į kintamąjį vector ir rodyklę į kintamąjį size.
void createVector(dataType **vector, int *size){
    *vector = NULL;
    *size = 0;

    return;
}

// 2.
// Fukcija, kuri įdeda naują elementą į vektoriau galą.
// Funkcija gauna rodyklę į kintamąjį vector, rodyklę į kintamajį size, elemento reikšmę, rodyklę į kintamąjį errorCode.
// Klaidos kodas 2:
// kintamasis errorCode įgija reikšmę 2, jei vektorius yra pilnas ir nebegalim sukurti daugiau vietos naujam elementui,
// tuomet apie tai išspausdinamas pranešimas.
void addElement(dataType **vector, int *size, dataType element, int *errorCode){
    if ((*size) == MAX_ELEMENTS){
        *errorCode = 2;
        return;
    }

    (*size)++;
    *vector = (dataType *) realloc((*vector), (*size)*sizeof(dataType));
    if (*vector == NULL){
        *errorCode = 2;
        return;
    }

    *((*vector) + ((*size) - 1)) = element;

    return;
}

// 3.
// Funkcija, kuri įterpia naują elementą į norimą poziciją pagal vekoriaus indeksus (nuo nulio).
// Funkcija gauna rodyklę į kintamąjį vector, rodyklę į kintamajį size, elemento reikšmę, vektoriaus indekso numerį ir rodyklę į kintamąjį errorCode.
// Klaidos kodas 1:
// kintamasis errorCode įgija reikšmę 1, jei pateiktas indeksas yra mažesnis negu nulis arba didesnis negu vektoriaus dydis,
// tuomet apie tai išspausdinamas pranešimas.
// Klaidos kodas 2:
// kintamasis errorCode įgija reikšmę 2, jei vektorius yra pilnas ir nebegalim sukurti daugiau vietos naujam elementui,
// tuomet apie tai išspausdinamas pranešimas.
void insertElementAt(dataType **vector, int *size, dataType element, int index, int *errorCode){
    if (index < 0 || index > (*size)){
        *errorCode = 1;
        return;
    }

    if ((*size) == MAX_ELEMENTS){
        *errorCode = 2;
        return;
    }

    (*size)++;
    *vector = (dataType *) realloc((*vector), (*size)*sizeof(dataType));
    if (*vector == NULL){
        *errorCode = 2;
        return;
    }

    for (int i = (*size); i > index; --i){
        *((*vector) + i) = *((*vector) + i - 1);
    }

    *((*vector) + index) = element;

    return;
}

// 4.
// Funkcija, kuri pakeičia elemento reikšmę vektoriuje norodytu indeksu
// Funkcija gauna kintamąjį vector, vektoriaus dydį, elemento reikšmę, vektoriaus indekso numerį ir rodyklę į kintamąjį errorCode.
// Klaidos kodas 1:
// kintamasis errorCode įgija reikšmę 1, jei pateiktas indeksas yra mažesnis negu nulis arba yra didesnis arba lygūs vektoriaus dydžiui,
// tuomet apie tai išspausdinamas pranešimas.
void setElementAt(dataType *vector, int size, dataType element, int index, int *errorCode){
    if (index < 0 || index >= size){
        *errorCode = 3;
        return;
    }    

    *(vector + index) = element;

    return;
}

// 5.
// Funkcija, kuri patikrina, ar vektorius tuščias.
// Funkcija gauna vektoriaus dydį.
// Grąžina reikšmę true (tiesa), jei vektorius tuščias, ir false (klaida), jei vektorius nėra tuščias.
bool isEmpty(int size){
    if (size == 0){
        return true;
    }

    return false;
}

// 6.
// Funkcija, kuri išima elementą iš vektoriaus nurodytu indeksu.
// Funkcija gauna rodyklę į kintamąjį vector, rodyklę į kintamajį size, vektoriaus indekso numerį ir rodyklę į kintamąjį errorCode.
// Klaidos kodas 1:
// kintamasis errorCode įgija reikšmę 1, jei pateiktas indeksas yra mažesnis negu nulis arba didesnis negu vektoriaus dydis,
// tuomet apie tai išspausdinamas pranešimas.
// Klaidos kodas 2:
// kintamasis errorCode įgija reikšmę 2, jei vektorius yra pilnas ir nebegalim sukurti daugiau vietos naujam elementui,
// tuomet apie tai išspausdinamas pranešimas.
void removeElementAt(dataType **vector, int *size, int index, int *errorCode){
    if (index < 0 || index >= (*size)){
        *errorCode = 1;
        return;
    }

    for (int i = index; i < (*size) - 1; ++i){
        *((*vector) + i) = *((*vector) + i + 1);
    }

    (*size)--;
    *vector = (dataType *) realloc((*vector), (*size)*sizeof(dataType));
    if (*vector == NULL){
        *errorCode = 2;
        return;
    }

    return;
}

// 7.
// Funkcija, kuri ištrina visus elementus iš vektoriaus,
//  t.y. atlaisvina atmintį.
// Funkcija gauna rodyklę į kintamąjį vector, rodyklę į kintamajį size ir rodyklę į kintamąjį errorCode.
// Klaidos kodas 2:
// kintamasis errorCode įgija reikšmę 2, jei vektorius yra pilnas ir nebegalim sukurti daugiau vietos naujam elementui,
// tuomet apie tai išspausdinamas pranešimas.
void removeAllElements(dataType **vector, int *size, int *errorCode){
    (*size) = 0;
    *vector = (dataType *) realloc((*vector), (*size)*sizeof(dataType));
    if (*vector == NULL){
        *errorCode = 2;
        return;
    }

    return;
}

// 8.
// Funkcija, kuri išspausdina visas reikšmes esančias vektoriuje.
// Funkcija gauna kintamąjį vector, rodyklę į kintamajį size, simbolių masyvą string.
void printAllElements(dataType *vector, int size, char string[MAX_STRING_LENGTH]){

    for (int i = 0; i < size; ++i){
        if (strcmp(string, "int") == 0 || strcmp(string, "signed") == 0 || strcmp(string, "signed int") == 0){
            printf("%d ", *(vector + i));
        }
        else if (strcmp(string, "unsigned int") == 0 || strcmp(string, "unsigned") == 0){
            printf("%u ", *(vector + i));
        }
        else if (strcmp(string, "short int") == 0 || strcmp(string, "short") == 0 || strcmp(string, "signed short int") == 0 || strcmp(string, "signed short") == 0){
            printf("%hd ", *(vector + i));
        }
        else if (strcmp(string, "unsigned short int") == 0 || strcmp(string, "unsigned short") == 0){
            printf("%hu ", *(vector + i));
        }
        else if (strcmp(string, "long int") == 0 || strcmp(string, "long") == 0 || strcmp(string, "signed long") == 0 || strcmp(string, "signed long int") == 0){
            printf("%ld ", *(vector + i));
        }
        else if (strcmp(string, "unsigned long int") == 0){
            printf("%lu ", *(vector + i));
        }
        else if (strcmp(string, "long long") == 0 || strcmp(string, "long long int") == 0 || strcmp(string, "signed long long") == 0 || strcmp(string, "signed long long int") == 0){
            printf("%lld ", *(vector + i));
        }
        else if (strcmp(string, "unsigned long long") == 0 || strcmp(string, "unsigned long long int") == 0){
            printf("%llu ", *(vector + i));
        }
        else if (strcmp(string, "float") == 0 || strcmp(string, "double") == 0){
            printf("%f ", *(vector + i));
        }
        else if (strcmp(string, "long double") == 0){
            printf("%Lf ", *(vector + i));
        }
        else if (strcmp(string, "char") == 0 || strcmp(string, "signed char") == 0 || strcmp(string, "unsigned char") == 0){
            printf("%c ", *(vector + i));
        }
    }
    printf("\n");

    return;
}

// 9.
// Funkcija, kuri perskaito elemento reikšmę iš naudotoja pagal skirtingas duomenų tipų specifikacijas.
// Funkcija gauna simbolių masyvą string ir rodyklę į elemento reikšmę.
void readInput(char string[MAX_STRING_LENGTH], dataType *element){
    char temp;

    if (strcmp(string, "int") == 0 || strcmp(string, "signed") == 0 || strcmp(string, "signed int") == 0){
        while(scanf("%d%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "unsigned int") == 0 || strcmp(string, "unsigned") == 0){
        while(scanf("%u%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "short int") == 0 || strcmp(string, "short") == 0 || strcmp(string, "signed short int") == 0 || strcmp(string, "signed short") == 0){
        while(scanf("%hd%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "unsigned short int") == 0 || strcmp(string, "unsigned short") == 0){
        while(scanf("%hu%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "long int") == 0 || strcmp(string, "long") == 0 || strcmp(string, "signed long") == 0 || strcmp(string, "signed long int") == 0){
        while(scanf("%ld%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "unsigned long int") == 0){
        while(scanf("%lu%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "long long") == 0 || strcmp(string, "long long int") == 0 || strcmp(string, "signed long long") == 0 || strcmp(string, "signed long long int") == 0){
        while(scanf("%lld%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "unsigned long long") == 0 || strcmp(string, "unsigned long long int") == 0){
        while(scanf("%llu%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "float") == 0){
        while(scanf("%f%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "double") == 0){
        while(scanf("%lf%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "long double") == 0){
        while(scanf("%Lf%c", &*element, &temp) != 2 || temp != '\n'){
            printf("This is not the correct data type you entered. Try again\n");
            scanf("%*[^\n]");
        }
    }
    else if (strcmp(string, "char") == 0 || strcmp(string, "signed char") == 0 || strcmp(string, "unsigned char") == 0){
        scanf("%c", &*element);
    }

    return;
}

// 10.
// Funkcija, kuri išspausdina klaidos pranešimą pagal klaidos kodą
// Funkcija gauna rodyklę į klaidos kodo numerį
void checkErrors(int *errorCode){
    if ((*errorCode) == 1){
        printf("\nThat is not a valid index. The index cannot be smaller than zero or bigger than the size of the vector.\n");
    }
    if ((*errorCode) == 2){
        printf("\nThe vector is already full. The new value was not inserted.\n");
    }
    if ((*errorCode) == 3){
        printf("\nThat is not a valid index. The index cannot be smaller than zero or bigger or equal than the size of the vector.\n");
    }

    return;
}