#include<iostream>
#include"treasureFind.h"

using namespace std;

/* 
    treasureFind constructor method
    This function takes matrix sizes and filenames as a parameter.
    And calls functions that is needed for the search.
*/
treasureFind::treasureFind(int mapMatrixCol,int mapMatrixRow,int keyMatrixSize, char* mapFileName, char* keyFileName, char* outFileName){
    this->mapMatrixCol=mapMatrixCol;
    this->mapMatrixRow=mapMatrixRow;
    this->keyMatrixSize=keyMatrixSize;
    this->mapFileName=mapFileName;
    this->keyFileName=keyFileName;
    this->outFileName=outFileName;
    this->openFiles();
    this->allocateMatrixes();
    this->readFiles();
    this->move(0,0);
}


/*
    openFiles method
    This function opens key matrix file, map matrix file and output file.
    If there was an error while opening, exits the program.
*/
void treasureFind::openFiles(){
    this->mapFile.open(mapFileName,ios::in);
    if(!this->mapFile){
        cout<<"File opening failed!"<<endl;
        exit(0);
    }

    this->keyFile.open(keyFileName,ios::in);
    if(!this->keyFile){
        cout<<"File opening failed!"<<endl;
        exit(0);
    }

    this->outFile.open(outFileName,ios::out);
    if(!this->outFile){
        cout<<"File opening failed!"<<endl;
        exit(0);
    }  
    cout<<"Files opened succesfully!"<<endl;
}



/*
    allocateMatrixes method
    This function allocates matrix sizes with the class variables.
*/
void treasureFind::allocateMatrixes(){

    this->mapMatrix = new int[this->mapMatrixCol * this->mapMatrixRow];

    for(int i = 0; i < this->mapMatrixCol ; i++){
        for(int j = 0; j < this->mapMatrixRow; j++)
            this->mapMatrix[i * this->mapMatrixRow + j] =  0;
    }

    this->keyMatrix = new int[this->keyMatrixSize * this->keyMatrixSize];

    for(int i = 0; i < this->keyMatrixSize; i++){
        for(int j = 0; j < this->keyMatrixSize; j++){
                this->keyMatrix[i * this->keyMatrixSize + j] = 0;
        }
    }
}



/*
    printMatrixes method
    This function prints the map matrix and key matrix to the console.
*/
void treasureFind::printMatrixes(){
    for (int i = 0; i < this->mapMatrixCol*this->mapMatrixRow; i++) {
        if(i%this->mapMatrixRow==0) cout<<endl;
        cout<<this->mapMatrix[i]<<" ";
    }
    cout<<endl<<endl;
    for (int i = 0; i < this->keyMatrixSize*this->keyMatrixSize; i++) {
        if(i%this->keyMatrixSize==0) cout<<endl;
        cout<<this->keyMatrix[i]<<" ";
    }
    cout<<endl<<endl;
}



/*
    readFiles method
    This function reads values from the text files and puts the values into the matrixes.
*/
void treasureFind::readFiles(){
    for (int i = 0; i < this->mapMatrixCol*this->mapMatrixRow; i++) {
            this->mapFile >> this->mapMatrix[i];
    }
    for (int i = 0; i < this->keyMatrixSize*this->keyMatrixSize; i++) {
            this->keyFile >> this->keyMatrix[i];
    }
}



/*
    move method (recursive function)
    This function is calls calculate function and 
    determines the direction and calls itself with next index parameters.
*/
void treasureFind::move(int col,int row){
    int direction,value;
    value = this->calculate(col,row);
    direction=value%5;
    cout<<"value : "<<value<<"position:  "<<col<<","<<row<< ","<<direction<<endl;
    this->outFile << col+this->keyMatrixSize/2 << "," << row+this->keyMatrixSize/2 << ":" << value << endl;
    if(direction==0){
        this->treasureFound();
        exit(0);
    }
    this->setDirection(direction,col,row);
    this->move(col,row);
}



/*
    calculate method
    This function calculates the value in specific region 
    from the parameter using map matrix and key matrix.
*/
int treasureFind::calculate(int col,int row){
    int sum=0;
    for(int i=0;i<this->keyMatrixSize;i++){
            for(int j=0;j<this->keyMatrixSize;j++){
                sum+= this->keyMatrix[i*this->keyMatrixSize+j]*this->mapMatrix[(col+i)*this->mapMatrixRow+(row+j)];
        }
    }
    return sum;
}



/*
    setDirection method
    This function checks the direction is valid.
    If it is not valid, returns the oposite direction.
    If it is valid, returns that direction.
*/
void treasureFind::setDirection(int direction,int &col,int &row){
    if(direction==1){
        if(col<this->keyMatrixSize) col+=this->keyMatrixSize;
        else col-=this->keyMatrixSize;
    }
    else if(direction==2){
        if(col+(2*this->keyMatrixSize)>this->mapMatrixCol) col-=this->keyMatrixSize;
        else col+=this->keyMatrixSize;
    }
    else if(direction==3){
        if(row+(2*this->keyMatrixSize)>this->mapMatrixRow) row-=this->keyMatrixSize;
        else row+=this->keyMatrixSize;
    }
    else if(direction==4){
        if(row<this->keyMatrixSize) row+=this->keyMatrixSize;
        else row-=this->keyMatrixSize;
    }
}



/*
    treasureFound method
    This function is calling when treasure found.
    Prints a message that informs treasure found.
*/
void treasureFind::treasureFound(){
    cout<<"Treasure Found!"<<endl;
}