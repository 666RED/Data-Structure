#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#define numOfSubject 4

//Structure

typedef struct user{
    char name[51];
    char matricNo[10];
    double ptrPa;
    double ptrChemi;
    double ptrMTOrMMorICT;
    double ptrBioOrPhys;
    double totalPtr;
    double CGPA;
}user;

//Function Declaration

int getNumOfStudent();
int validNumber(char*);
void getNameOfStudent(user user[], int);
void lower(char*);
int validName(char*);
void capitalized(char*);
int repeatName(user student[], int);
void getMatricNo(user student[], int);
int validMatricNo(user student[], int*);
int repeatMatricNo(user student[], int);
void getResult(user student[], int);
void calculateTotalPtr(user student[], int);
void calculateCGPA(user student[], int);
void display(user student[], int);
void detPosition(user student[], int);

int main(){
  int numberOfStudent, validity;

  numberOfStudent = getNumOfStudent();

  user student[numberOfStudent];

  for (int i = 0; i < numberOfStudent; i++){
    getNameOfStudent(student, i);
    getMatricNo(student, i);
    getResult(student, i);
    calculateTotalPtr(student, i);
    calculateCGPA(student, i);
  }
  display(student, numberOfStudent);
  detPosition(student, numberOfStudent);
  return 0;
}

//Function Definition

int getNumOfStudent(){
  int result, numberOfStudent, validity;
  char size[3];
  do{
    printf("\nNumber of Student: ");
    scanf("\n%[^\n]s", size);
    result = validNumber(size);
    numberOfStudent = atoi(size);
  }while(result != 1);
  return numberOfStudent;
}

int validNumber(char* size){
  if(size[0] == 48){
    printf("You shouldn't input the number starting from 0.\n");
    return 0;
  }else if(size[0] == 45){
    printf("The number should be a positive value.\n");
    return 0;
  }else if(size[strlen(size) - 1] == 32){
    printf("You shouldn't leave a space at the end of the number.\n");
    return 0;
  }
  for(int i = 0; i < strlen(size); i++){
    if(size[i] == 32){
      printf("Invalid number, please input again.\n");
      return 0;
    }else if(size[i] < 48 || size[i] > 57){
      printf("Invalid number, please input again.\n");
      return 0;
    }else if(i == strlen(size) - 1){
      return 1;
    }
  }
}

void getNameOfStudent(user student[], int i){
  int result, repeat;
  do{
    printf("\n%d)Please enter name: ",i+1);
    scanf("\n%[^\n]s",student[i].name);
    lower(student[i].name);
    result = validName(student[i].name);
    repeat = repeatName(student, i);
  }while(result == 0 || repeat == 1);
}

void lower(char* name){

  for(int i = 0; i < strlen(name); i++){
    name[i] = tolower(name[i]);
  }
}

int validName(char* name){
  if(strlen(name) < 3){
    printf("The name shouldn't less than 3 characters, please input again.\n");
    return 0;
  }else if(strlen(name) > 50){
    printf("The name shouldn't more than 50 characters, please input again.\n");
    return 0;
  }else if(name[strlen(name) - 1] == 32){
    printf("You shouln't leave a space at the end of the name.\n");
    return 0;
  }
  for(int i = 0; i < strlen(name); i++)
  {
    if(name[i+1] == 32 && name[i] == 32){
      printf("You shouldn't space more than once between words of the name.\n");
      return 0;
    }else if((name[i] < 97 || name[i] > 122) && name[i] != 32){
      printf("Incorrect name, please input again.\n");
      return 0;
    }else if(i == strlen(name) - 1){
      return 1;
    }
  }
}

void capitalized(char* name){
   name[0]=toupper(name[0]);
    for(int i = 0; i < strlen(name); i++){
      if(name[i]==32){
        name[i+1]=toupper(name[i+1]);
      }
    }
}

int repeatName(user student[],int i){
  int repeatedName;
  capitalized(student[i].name);
    for (int t = 0; t < i; t++){
      repeatedName = strcmp(student[i].name, student[t].name);
      if(repeatedName == 0){
          printf("The name is repeated.\n");
          return 1;
      }
    }
  return 0;
}

void getMatricNo(user student[], int i){
  int result, repeat;
  do{
    printf("Please enter No.matric: ");
    scanf("\n%[^\n]s", student[i].matricNo);
    result = validMatricNo(student, &i);
    repeat = repeatMatricNo(student, i);
  }while(repeat == 1 || result == 0);
}

int validMatricNo(user student[],int* i){
 int result;
  for (int j = 0; j < 10; j++){
    student[*i].matricNo[j] = toupper(student[*i].matricNo[j]);
  }
  if (strlen(student[*i].matricNo) < 8){
    printf("!!!Too Less!!!\n");
    result = 0;
  }else if(strlen(student[*i].matricNo) > 8){
    printf("!!!Too More(8-digit)!!!\n");
    result = 0;
  }else if(student[*i].matricNo[1] < 65 || student[*i].matricNo[1] > 90 || student[*i].matricNo[0] < 65 || student[*i].matricNo[0] > 90){
  printf("!!!You enter a wrong no.matric.!!!\n");
  result = 0;
  }else{
    for(int k = 2; k < 8; k++){
      if(student[*i].matricNo[k] < 48 || student[*i].matricNo[k] > 57){
        printf("!!!You enter a wrong no.matric.!!!\n");
        result = 0;
        break;
      }else{
        result = 1;
      }
    }
  }
  return result;
}

int repeatMatricNo(user student[], int i){
  int repeat;
  for(int t = 0; t < i; t++){
    if(strcmp(student[i].matricNo, student[t].matricNo) == 0){
      printf("The Matric No is repeated.\n");
      return 1;
    }
  }
  return 0;
}

void getResult(user student[], int i){
  printf("Enter the pointer of the subjects.\n");
  do{
    printf("\nPengajian Am: ");
    scanf("%lf",&student[i].ptrPa);
    if(student[i].ptrPa < 0.0 || student[i].ptrPa > 4.0){
      printf("Invalid pointer.\n");
    }
  }while(student[i].ptrPa < 0.0 || student[i].ptrPa > 4.0);
  do{
    printf("Chemitry: ");
    scanf("%lf",&student[i].ptrChemi);
    if(student[i].ptrChemi < 0.0 || student[i].ptrChemi > 4.0){
      printf("Invalid pointer.\n");
    }
  }while(student[i].ptrChemi < 0.0 || student[i].ptrChemi > 4.0);
  do{
    printf("Mathematics (T) / Mathematics(M) / Ict: ");
    scanf("%lf",&student[i].ptrMTOrMMorICT);
    if(student[i].ptrMTOrMMorICT < 0.0 || student[i].ptrMTOrMMorICT > 4.0){
      printf("Invalid pointer.\n");
    }
  }while(student[i].ptrMTOrMMorICT < 0.0 || student[i].ptrMTOrMMorICT > 4.0);
  do{
    printf("Physics / Biology: ");
    scanf("%lf",&student[i].ptrBioOrPhys);
    if(student[i].ptrBioOrPhys < 0.0 || student[i].ptrBioOrPhys > 4.0){
      printf("Invalid pointer.\n");
    }
  }while(student[i].ptrBioOrPhys < 0.0 || student[i].ptrBioOrPhys > 4.0);
}

void calculateTotalPtr(user student[], int i){
  student[i].totalPtr = student[i].ptrPa + student[i].ptrChemi + student[i].ptrMTOrMMorICT + student[i].ptrBioOrPhys;
}

void calculateCGPA(user student[], int i){
  student[i].CGPA = student[i].totalPtr / numOfSubject;
}

void display(user student[], int numberOfStudent){
  printf("\nStudent Data:\n----------------------------------------------\n");
  for (int i = 0; i < numberOfStudent; i++){
    printf("%d)Name: %s\n", i+1, student[i].name);
    printf("  Matric.No: %s\n", student[i].matricNo);
    printf("  Pengajian Am: %.2lf\n", student[i].ptrPa);
    printf("  Chemistry: %.2lf\n", student[i].ptrChemi);
    printf("  Mathematics (T) / Mathematics(M) / Ict: %.2lf\n", student[i].ptrMTOrMMorICT);
    printf("  Physics / Biology: %.2lf\n", student[i].ptrBioOrPhys);
    printf("  CGPA: %.2lf\n", student[i].CGPA);
  }
}

void detPosition(user student[], int numberOfStudent){
  printf("\nAbove 3.00:\n");
  for(int i = 0; i < numberOfStudent; i++){
    if(student[i].CGPA >= 3.00){
      printf("->%s (%.2lf)\n", student[i].name, student[i].CGPA);
    }
  }
  printf("\nAbove 2.00:\n");
  for(int i = 0; i < numberOfStudent; i++){
    if(student[i].CGPA >= 2.00 && student[i].CGPA < 3.00){
      printf("->%s (%.2lf)\n", student[i].name, student[i].CGPA);
    }
  }
  printf("\nBelow 2.00:\n");
  for(int i = 0; i < numberOfStudent; i++){
    if(student[i].CGPA < 2.00){
      printf("->%s (%.2lf)\n", student[i].name, student[i].CGPA);
    }
  }
}
