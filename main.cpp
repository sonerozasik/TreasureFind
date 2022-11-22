#include <stdio.h>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include"treasureFind.h"

using namespace std;

void allocateSize(char* str,int &col,int&row);



/*
    main function
*/
int main(int argc, char *argv[]){
    if(argc!=6){ //check argc for valid input
        printf("Invalid input!");
    }
    int col,row;
    allocateSize(argv[1],col,row);
    treasureFind treasurefind(col,row,atoi(argv[2]),argv[3],argv[4],argv[5]); //class declaration
    return 0;
}



/*
    allocateSize function
    This function takes a string and converts the string to two integers.
    Ex: str = "12x18"  --> col = 12 , row = 18
*/
void allocateSize(char* str,int &col,int &row){
    int i=0,flag=false;
    col=0;
    row=0;
    while(str[i]){
        if(str[i]=='x'){
            flag=true;
        }
        else{
            if(flag==false){
                col=col*10+(int)(str[i]-'0');
            }
            else{
                row=row*10+(int)(str[i]-'0');
            }
        }
        i++;
    }
}