#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <conio.h>
struct passenger
{
    char names[30]; // SNP
    int luggage_ocup; //How many places are ocupated by luggage
    int weight; //FULL WEIGHT
} fp;

void inputfile(char*, int);
void printfile(char*);
void addnew(char*);
void find_del(char*);
void find_edit(char*);
int main()
{
    char c;
    char p[100];
    srand(time(NULL));
    while (1)
    { 
        puts("  1 - new file create");
        puts("  2 - file read");
        puts("  3 - add new line to file");
        puts("  4 - deleting");
        puts("  5 - Weight editing to Full Name");
        puts("  0 - quit");
        c = _getch();
            switch(c)
        { 
            case '1':
                printf("Enter N: ");
                int N;
                scanf("%d", &N);
                printf("\nEnter file name: ");
                scanf("%s", &p);
                inputfile(p, N);
                break;
            case '2':
                printf("\nEnter file name: ");
                scanf("%s", &p);
                printfile(p);
                break;
            case '3':
                printf("\nEnter file name: ");
                scanf("%s", &p);
                addnew(p);
                break;
            case '4':
                printf("\nEnter file name: ");
                scanf("%s", &p);
                find_del(p);
                break;
            case '5':
                printf("\nEnter file name: ");
                scanf("%s", &p);
                find_edit(p);
                break;
            case '0':
                return 0;
            default : printf("\n\nWrong type\n\n");
        }
    }
    
}

void inputfile(char *name, int size)
{ 
    char ch;  FILE *file;
    int i = 0;
    file = fopen(name,"wb");
    system("CLS");
    printf("\n Creating file numz \n");
    do
    { 
        printf("\n Full Name: "); 
        scanf("%s",&fp.names);
        printf(" Luggage ocupation: "); 
        scanf("%i",&fp.luggage_ocup);
        printf(" Weight of luggage: "); 
        scanf("%i",&fp.weight);
        fwrite(&fp,sizeof(fp),1,file);
        printf("\n");
        i++;
    }
    while (i < size);
    fclose(file);
}

void printfile(char *name)
{ 
    int i; FILE *file;
    system("CLS");
    file = fopen (name,"rb"); // открытие бинарного файла для чтения
    i = 1;
    while (fread(&fp,sizeof(fp),1,file))
    { 
        printf("\n  %5d Full Name: %12s Luggage ocupation: %3i Weight of luggage: %3i",i,fp.names,fp.luggage_ocup,fp.weight);
        i++;
    }
    printf("\n");
    fclose(file);
}

void addnew(char *name)
{ 
    char ch; FILE *file;
    file = fopen(name ,"ab"); // открытие бинарного файла для добавления
    system("CLS");
    printf("\n Full Name: "); 
    scanf("%s",&fp.names);
    printf(" Luggage ocupation: "); 
    scanf("%i",&fp.luggage_ocup);
    printf(" Weight of luggage: "); 
    scanf("%i",&fp.weight);
    fwrite(&fp,sizeof(fp),1,file);
    printf("\n");
    fclose(file);
}

void find_del(char *name)
{ 
    char c, wt = 10; FILE *file, *file_;
    long int i;
    file = fopen(name,"rb");
    file_ = fopen("tmp.bin", "wb");
    puts("Delete people with average weight of luggage under 10 \n");
    while (fread(&fp, sizeof(fp), 1, file))
    {  
        printf("Weight: %i\n", fp.weight);
        if (fp.weight < 10)
        {   
            continue;
        }
        else
        {
            fwrite(&fp, sizeof(fp), 1, file_);
        }
    }
    fclose(file);
    fclose(file_);
    remove(name);
	rename("tmp.bin", name);
}

void find_edit(char *name)
{ 
    char c,tov[30]; FILE *file;
    long int i;
    file = fopen(name,"rb+"); // открытие файла для чтения и записи
    printf("FULL NAME: ");
    scanf("%s", &tov);
    while (fread(&fp, sizeof(fp), 1, file))
    {  if (strcmp(fp.names, tov)==0)
        {
            {  
                printf("\n Weight: ");
                scanf("%d",&fp.weight);
                fseek(file,-sizeof(fp),1); // переход на одну запись в файле
                fwrite(&fp,sizeof(fp),1,file); // вывод в файл измененной записи
                fflush(file);//очистка буферов ввода-вывода
            }
        }
    }
    fclose(file);
}

