//Written By John Daddona
//C++ program that takes 2 command line arguements, an input and output file
//It then reads the input file line by line and copies the text and moves it to
//the output file. Example instaniation is ./myCopier start.txt destination.txt

#include<stdlib.h>
#include<string>
#include<iostream>
#include<fstream>

int main(int argc, char* argv[]){
  if(argc != 3){
    std::cerr << "Usage: " << argv[0] << " [source file] [destination file] " << std::endl;
    return 1;
  }
  
  std::ifstream inputFile(argv[1]);//source file for reading
  std::ofstream outputFile(argv[2]);//output file for writing

  if(!inputFile){// error handler with the first arg
    std::cerr << "Couldn't open the source file " << argv[1] << std::endl;
    return 1;
    }

  if(!outputFile){//error handler with the second arg
    std::cerr << "Couldn't open the destination file " << argv[2] << std::endl;
    inputFile.close();
    return 1;
    }

  std::string line;// Read line by line from the source file, the get it and write it to the destination
  
  while(std::getline(inputFile, line)){
    outputFile << line << std::endl;
    }

    inputFile.close();
    outputFile.close();

    std::cout << "Nice! The file was copied successfully." << std::endl;
    return 0;

  }













