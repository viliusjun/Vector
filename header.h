/*
// header.h
// Failas, kuriame pateikti visi funkcijų aprašai
// Būtina pakeisti typedef pateiktą duomenų tipą į norimą duomenų tipą prieš paleidžiant programą

// MAX_STRING_LENGTH - ilgiausias duomenų tipo pavadinimas
// MAX_VECTORS - didžiausias vektorių kiekis
// MAX_ELEMENTS - didžiausias elementų kiekis
// dataType - pakeisti šį duomen tipą į norimą duomenų tipą

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

#ifndef __HEADER_H_
#define __HEADER_H_

#define MAX_STRING_LENGTH 30 // Ilgiausias duomenų tipo pavadinimas
#define MAX_VECTORS 30 // Kiek vektorių galima sukurti daugiausiai
#define MAX_ELEMENTS 500 // Kiek daugiausiai elementų galima įdėti į vieną vektorių

// būtina pasikeisti į norimą duomenų tipą prieš paleidžiant programą!
typedef int dataType;

void createVector(dataType **vector, int *size);
void addElement(dataType **vector, int *size, dataType element, int *errorCode);
void insertElementAt(dataType **vector, int *size, dataType element, int index, int *errorCode);
void setElementAt(dataType *vector, int size, dataType element, int index, int *errorCode);
bool isEmpty(int size);
void removeElementAt(dataType **vector, int *size, int index, int *errorCode);
void removeAllElements(dataType **vector, int *size, int *errorCode);
void readInput(char string[MAX_STRING_LENGTH], dataType *element);
void printAllElements(dataType *vector, int size, char string[MAX_STRING_LENGTH]);
void checkErrors(int *errorCode);

#endif