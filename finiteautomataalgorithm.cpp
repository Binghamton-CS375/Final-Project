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

solution FiniteAutomataMatcher(string text, string pattern);
void ComputeTransitionFunction(string pattern, int * preprocess_array);
vector<iteration> FiniteAutomata(string text, string pattern);

/*END PROTOTYPES***************************************************************/
/******************************************************************************/
/*START MAIN*******************************************************************/
int main(int argc, char ** argv, char ** envp){


    string text = "VLAD IS HUNGRY AND VLAD IS HAPPY";
    string pattern = "VLAD";

    vector<iteration> data = FiniteAutomata(text, pattern);

    for(vector<iteration>::iterator it = data.begin(); it != data.end(); it++){
        printf("TIME: %f\n", (*it).time);
    }

    return 0;
}
/*END MAIN*********************************************************************/
/******************************************************************************/
/*START FUNCTIONS**************************************************************/

vector<iteration> FiniteAutomata(string text, string pattern){

    vector<iteration> data;
    iteration temp_iteration;
    solution temp_solution;

    temp_solution = FiniteAutomataMatcher(text, pattern);

    temp_iteration.time = temp_solution.solving_time;
    data.push_back(temp_iteration);
    return data;
}



solution FiniteAutomataMatcher(string text, string pattern){

    solution solutions;

    /**************************************************************************/
    /*TIMING CODE**************************************************************/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    /*TIMING CODE**************************************************************/
    /**************************************************************************/




    /**************************************************************************/
    /*TIMING CODE**************************************************************/
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    milliseconds_type time_span = duration_cast<milliseconds_type>(t2 - t1);
    solutions.solving_time = duration_cast<milliseconds_type>(time_span).count();
    /*TIMING CODE**************************************************************/
    /**************************************************************************/


    return solutions;
}

ComputeTransitionFunction(){

}

/*END FUNCTIONS****************************************************************/
/******************************************************************************/
/******************************************************************************/
