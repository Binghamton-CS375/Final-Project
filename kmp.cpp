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

solution KMPMatcher(string text, string pattern);
void ComputePrefixFunction(string pattern, int * preprocess_array);
vector<iteration> KMP(string text, string pattern);

/*END PROTOTYPES***************************************************************/
/******************************************************************************/
/*START MAIN*******************************************************************/
int main(int argc, char ** argv, char ** envp){


    string text = "VLAD IS HUNGRY AND VLAD IS HAPPY";
    string pattern = "VLAD";

    printf("RUNNING KMP\n");
    vector<iteration> data = KMP(text, pattern);

    for(vector<iteration>::iterator it = data.begin(); it != data.end(); it++){
        printf("TIME: %f\n", (*it).time);
    }

    return 0;
}
/*END MAIN*********************************************************************/
/******************************************************************************/
/*START FUNCTIONS**************************************************************/

vector<iteration> KMP(string text, string pattern){

    vector<iteration> data;
    iteration temp_iteration;
    solution temp_solution;

    printf("RUNNING KMPMatcher\n");
    temp_solution = KMPMatcher(text, pattern);

    temp_iteration.time = temp_solution.solving_time;
    data.push_back(temp_iteration);
    return data;
}



solution KMPMatcher(string text, string pattern){

    solution solutions;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    int text_length = text.length();
    int pattern_length = pattern.length();
    int preprocess_array[pattern_length];
    ComputePrefixFunction(pattern, preprocess_array);
    int characters_matched = 0;

    for(int i = 0; i < text_length; i++){

        while((characters_matched > 0) and (pattern[characters_matched] != text[i])){
            characters_matched = preprocess_array[characters_matched - 1];
        }

        if(pattern[characters_matched] == text[i]){
            characters_matched++;
        }

        if(characters_matched == pattern_length){
            solutions.offsets.push_back(i - (pattern_length - 1));
            characters_matched = preprocess_array[characters_matched - 1];
        }

    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    milliseconds_type time_span = duration_cast<milliseconds_type>(t2 - t1);
    solutions.solving_time = duration_cast<milliseconds_type>(time_span).count();

    return solutions;
}

void ComputePrefixFunction(string pattern, int * preprocess_array){
    int pattern_length = pattern.length();

    preprocess_array[0] = 0;

    int k = 0;

    for(int q = 1; q < pattern_length; q++){
        while((k > 0) and (pattern[k + 1] != pattern[q])){
            k = preprocess_array[k];
        }
        if(pattern[k + 1] == pattern[q]){
            k++;
        }
        preprocess_array[q] = k;
    }
}

/*END FUNCTIONS****************************************************************/
/******************************************************************************/
/******************************************************************************/
