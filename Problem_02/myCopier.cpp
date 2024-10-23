//Written By John Daddona
//C++ program that takes 2 command line arguements, an input and output file
//It then reads the input file line by line and copies the text and moves it to
//the output file. Example instaniation is ./myCopier start.txt destination.txt

#include<stdlib.h>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;


int main(int argc, char* argv[]){
  if(argc != 3){
    cerr << "Usage: " << argv[0] << " [source file] [destination file] " << endl;
    return 1;
  }
  
  ifstream inputFile(argv[1]);//source file for reading
  ofstream outputFile(argv[2]);//output file for writing

  if(!inputFile){// error handler with the first arg
    cerr << "Couldn't open the source file " << argv[1] << endl;
    return 1;
    }

  if(!outputFile){//error handler with the second arg
    cerr << "Couldn't open the destination file " << argv[2] << endl;
    inputFile.close();
    return 1;
    }

  string line;// Read line by line from the source file, the get it and write it to the destination
  
  while(getline(inputFile, line)){
    outputFile << line << endl;
    }
    inputFile.close();
    outputFile.close();
    cout << "Nice! The file was copied successfully." << endl;
    return 0;
  }













