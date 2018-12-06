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

/*typedef struct{

    vector<int> offsets;
    double solving_time = 0;

} solution;

typedef struct{

    int radix;
    int prime;
    double time;

    } iteration;*/

/*END TYPE DEFENITIONS*********************************************************/
/******************************************************************************/
/*BEGIN PROTOTYPES*************************************************************/

solution RabinKarpMatcher(string text, string pattern, int radix, int prime);
int CalculatePrime(int radix);
vector<iteration> RabinKarp(string text, string pattern);

/*END PROTOTYPES***************************************************************/
/******************************************************************************/
/*START MAIN*******************************************************************/
/*int main(int argc, char ** argv, char ** envp){


    string text = "VLAD IS HUNGRY AND VLAD IS HAPPY";
    string pattern = "I";

    vector<iteration> data = RabinKarp(text, pattern);

    for(vector<iteration>::iterator it = data.begin(); it != data.end(); it++){
        printf("RADIX:\t%d\t| PRIME:\t%d\t| TIME: %f\n", (*it).radix ,(*it).prime ,(*it).time);
    }

    return 0;
    }*/
/*END MAIN*********************************************************************/
/******************************************************************************/
/*START FUNCTIONS**************************************************************/

vector<iteration> RabinKarp(string text, string pattern){


    int radix;
    int prime;

    vector<iteration> data;
    iteration temp_iteration;
    solution temp_solution;

    for(radix = 4; radix <= 1024; radix = radix * 2){

        prime = CalculatePrime(radix);

        for(int i = 0; i < 10; i++){

            temp_solution = RabinKarpMatcher(text, pattern, radix, prime);

            temp_iteration = {.radix = radix, .prime = prime, .time = temp_solution.solving_time};
            data.push_back(temp_iteration);

            prime = CalculatePrime(prime);
        }
    }

    return data;
}



solution RabinKarpMatcher(string text, string pattern, int radix, int prime){

    solution solutions;

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    int text_length = text.length();
    int pattern_length = pattern.length();
    int h = int(pow(radix, (pattern_length - 1))) % prime;
    int pattern_value = 0;
    int text_value = 0;

    for(int i = 0; i < pattern_length; i++){

        pattern_value = (radix * pattern_value + pattern[i]) % prime;           //

        text_value = (radix * text_value + text[i]) % prime;                    //

    }


    // printf("PATTERN VALUE: %d\n\nTEXT VALUE: %d\n\n", pattern_value, text_value);   //debug statement

    for(int s = 0; s <= (text_length - pattern_length); s++){

        if(pattern_value == text_value){
            // printf("MATCHING PATTERN AND TEXT\n");                              //debug statement
            if(pattern.compare(text.substr((s),(pattern_length))) == 0){        //comparing pattern to text substring
                //TODO: offset s is offset in text to find pattern
                solutions.offsets.push_back(s);
                // printf("\nOFFSET: %d\n\n", s);
                // printf("%d\n", s);                                              //debug statement
            }
        }

        if(s < (text_length - pattern_length)){                                 //if are more windows in text
            text_value = (radix * (text_value - text[s] * h) + text[s + pattern_length]) % prime;

            if(text_value < 0){
                text_value = text_value + prime;
            }
            // printf("NEW TEXT VALUE: %d\n", text_value);                         //debug statement
        }
    }

    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    milliseconds_type time_span = duration_cast<milliseconds_type>(t2 - t1);
    solutions.solving_time = duration_cast<milliseconds_type>(time_span).count();

    return solutions;
}

int CalculatePrime(int radix){

    int prime = radix + 1;
    int index;

    while(1){
        index = 2;
        while((prime % index) != 0){
            index++;
        }

        if(prime == index){
            return prime;
        } else {
            prime++;
        }
    }
}

/*END FUNCTIONS****************************************************************/
/******************************************************************************/
/******************************************************************************/
