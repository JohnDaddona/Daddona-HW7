//Written by john Daddona. This is a small c++ program that will take a command line argurment "blink" 
//followed by an integer and blink it as many times as
//told. An example invocation would be ./makeLED blink 5
//I am sorry for making this from scratch, in class
//you gave me the okay, but for the next hw, I will
//definately just modify the existing. Sorry again.

#include<iostream>
#include<unistd.h>
#include<fstream>
using namespace std;


int main(int argc, char* argv[]){
  if(argc != 3){
    cerr<<"Usage: " << argv[0] << " blink <n>" <<endl;//if the
    //command line doesn't have the right parameters it will throw this error
    //and inform them how to use the program
    return 1;
    }

    string command = argv[1];//pulls the name of command "blink"
    int n = stoi(argv[2]); //convert 3rd argument to an integer

    if(command != "blink"){
    cerr<<"Invalid command. Use 'blink' as the first arg." <<endl;
    return 1; 
    }

    const string ledPath = "/sys/class/leds/beaglebone:green:usr3/";
    const string brightnessPath = ledPath + "brightness";

    for(int i=0; i<n; ++i){// takes the number and decrements the # of times,
    // 3...2...1
     ofstream ledOn(brightnessPath);  
     ledOn << "1";
     ledOn.close();
     sleep(1);
     ofstream ledOff(brightnessPath);
     ledOff << "0";
     ledOff.close();
     sleep(1);
     }
    cout << "Blinked USR3 LED " << n << " times." <<endl;
    return 0;
 }






