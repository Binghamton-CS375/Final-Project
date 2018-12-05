/*BEGIN IMPORT STATEMENTS******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<tgmath.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
#include <ctime>
#include <chrono>
#include <ratio>

/*END IMPORT STATEMENTS********************************************************/
/******************************************************************************/
/*BEGIN NAMESPACE**************************************************************/
using namespace std;
using namespace std::chrono;
/*END NAMESPACE****************************************************************/
/******************************************************************************/
/*BEGIN TYPE DEFENITIONS*******************************************************/

#define NUMBER_OF_CHARACTERS 256

typedef std::chrono::duration<double,std::milli> milliseconds_type;

typedef struct{

    vector<int> offsets;
    double solving_time = 0;

} solution;

typedef struct{

    int radix;
    int prime;
    double time;

} iteration;

/*END TYPE DEFENITIONS*********************************************************/
/******************************************************************************/
/*BEGIN PROTOTYPES*************************************************************/

solution BoyerMooreMatcher(string text, string pattern);
vector<iteration> BoyerMoore(string text, string pattern);

void PreprocessBadCharacter(string pattern, int * bad_characters)
void PreprocessGoodSuffixCase1(string pattern, int * shift, int * border_position){
void PreprocessGoodSuffixCase2(string pattern, int * shift, int * border_position){


/*END PROTOTYPES***************************************************************/
/******************************************************************************/
/*START MAIN*******************************************************************/
int main(int argc, char ** argv, char ** envp){


    string text = "VLAD IS HUNGRY AND VLAD IS HAPPY";
    string pattern = "VLAD";

    vector<iteration> data = BoyerMoore(text, pattern);

    for(vector<iteration>::iterator it = data.begin(); it != data.end(); it++){
        printf("TIME: %f\n", (*it).time);
    }

    return 0;
}
/*END MAIN*********************************************************************/
/******************************************************************************/
/*START FUNCTIONS**************************************************************/

vector<iteration> BoyerMoore(string text, string pattern){

    vector<iteration> data;
    iteration temp_iteration;
    solution temp_solution;

    temp_solution = BoyerMooreMatcher(text, pattern);

    temp_iteration.time = temp_solution.solving_time;
    data.push_back(temp_iteration);
    return data;
}

solution BoyerMooreMatcher(string text, string pattern){

    solution solutions;

    /**************************************************************************/
    /*TIMING CODE**************************************************************/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    /*TIMING CODE**************************************************************/
    /**************************************************************************/

    //TODO

    /**************************************************************************/
    /*TIMING CODE**************************************************************/
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    milliseconds_type time_span = duration_cast<milliseconds_type>(t2 - t1);
    solutions.solving_time = duration_cast<milliseconds_type>(time_span).count();
    /*TIMING CODE**************************************************************/
    /**************************************************************************/


    return solutions;
}

/*END FUNCTIONS****************************************************************/
/******************************************************************************/
/*START PREPROCESSING FUNCTIONS************************************************/

void PreprocessGoodSuffixCase1(string pattern, int * shift, int * border_position){

    int pattern_length = pattern.length();

    int i = pattern_length;
    int j = pattern_length + 1;

    border_position[i] = j;

    while(i > 0){
        while((j >= pattern_length) && (pattern[i - 1] != pattern[j - 1])){
            if(shift[j] == 0){
                shift[j] = j - 1;
                j = border_position[j];
            }
        }
        i--;
        j--;
        border_position[i] = j;
    }
}

void PreprocessGoodSuffixCase2(string pattern, int * shift, int * border_position){

    int pattern_length = pattern.length();

    int i;
    int j;

    j = border_position[0];
    for(i = 0; i <= pattern_length; i++){
        if(shift[i] == 0){
            shift[i] = j;
        }

        if(i == j){
            j = border_position[j];
        }
    }

}

void PreprocessBadCharacter(string pattern, int * bad_characters){

    for(int i = 0; i < NUMBER_OF_CHARACTERS; i++){
        bad_characters[i] = -1;
    }

    for(int j = 0; j < pattern.length(); j++){
        bad_characters[((int) pattern[j])] = j;
    }
}
/*END PREPROCESSING FUNCTIONS**************************************************/
/******************************************************************************/
/******************************************************************************/
