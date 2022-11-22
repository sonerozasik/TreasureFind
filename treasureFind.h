#ifndef TREASUREFIND_H
#define TREASUREFIND_H
#include<iostream>
#include<fstream>

using namespace std;

/*
    treasureFind class
    This class holds dynamic arrays for matrixes and tries to find treasure
    with move, calculate, setDirection methods.
*/
class treasureFind{
    private:
        fstream mapFile,keyFile; //input files
        fstream outFile; //output file
        int mapMatrixCol,mapMatrixRow,keyMatrixSize; //matrix sizes
        char*mapFileName,* keyFileName,* outFileName; //file names
        int *mapMatrix; //map matrix
        int *keyMatrix; //key matrix

        void openFiles();
        void allocateMatrixes();
        void readFiles();
        void move(int col,int row);
        int calculate(int col,int row);
        void setDirection(int direction,int &row,int &col);
        void treasureFound();

    public:
        treasureFind(int mapMatrixCol,int mapMatrixRow,int keyMatrixSize, char* mapFileName,char* keyFileName, char* outFileName);
        void printMatrixes();
};

#endif