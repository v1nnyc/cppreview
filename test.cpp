#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int overallScore;
int secretNumber;

static int decideRand(){
srand(time(NULL));

    return rand() % 10 + 1;
}

static void printCorrect(){
    cout<<"You guessed the right number! It was " << secretNumber << "\n";
	cout<<"Your overall score was: " << overallScore << "\n";
cout<<"Play again?\n";
}

static void playGame(){
	overallScore = 0;
	secretNumber = decideRand();
	int guess;
	int* value = &guess;
	do{
   		cout<<"Guess a number between 1-10"<<"\n";
   		cin>> guess;
   		cin.ignore();
    		cout<<"You entered: "<< guess << "\n";
    		if(*value < secretNumber){
    	   	 cout<<"Your guess is too low!!!"<<"\n";
    		}
    		else if(*value > secretNumber){
    		    cout<<"Your guess is too high!!!"<<"\n";
    		}
	overallScore++;
    	} while (secretNumber != guess);
	printCorrect();
}

static void gameSelection(){
int input;
cout<<" 1. Play game\n";
  cout<<" 2. Exit\n ";
  cout<<"Selection: ";
  cin>> input;
  switch ( input ) {
  case 1:            // Note the colon, not a semicolon
    playGame();
    break;
  case 2:            // Note the colon, not a semicolon
    cout<<"Thank you for playing!\n";
    break;
  default:            // Note the colon, not a semicolon
    cout<<"Error, bad input, quitting\n";
    break;
  }
}

int main(){
gameSelection();
}


