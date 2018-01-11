#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

int overallScore;

static int decideRand(){
srand(time(NULL));

    return rand() % 10 + 1;
}

static void printCorrect(int* number, int score){
    cout<<"You guessed the right number! It was " << *number << "\n";
	cout<<"Your overall score was: " << score << "\n";
cout<<"Play again?\n";
}

static void playGame(){
	overallScore = 0;
	int secret = decideRand();
	int guess;
	int* value = &guess;
	do{
   		cout<<"Guess a number between 1-10"<<"\n";
   		cin>> guess;
   		cin.ignore();
    		cout<<"You entered: "<< guess << "\n";
    		if(*value < secret){
    	   	 cout<<"Your guess is too low!!!"<<"\n";
    		}
    		else if(*value > secret){
    		    cout<<"Your guess is too high!!!"<<"\n";
    		}
	overallScore++;
    	} while (secret != guess);
	printCorrect(value, overallScore);
}

static void gameSelection(){
int input;
  do{
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
  }} while ( input != 2);
}

int main(){
gameSelection();
}


