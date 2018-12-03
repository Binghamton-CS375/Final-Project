/*BEGIN IMPORT STATEMENTS******************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<tgmath.h>
#include<string>
#include<iostream>
#include<fstream>
#include<vector>
/*END IMPORT STATEMENTS********************************************************/
/******************************************************************************/
/*BEGIN NAMESPACE**************************************************************/
using namespace std;
/*END NAMESPACE****************************************************************/
/******************************************************************************/
/*BEGIN STRUCTS****************************************************************/

//none here

/*END STRUCTS******************************************************************/
/******************************************************************************/
/*BEGIN PROTOTYPES*************************************************************/

vector<int> RabinKarpMatcher(string text, string pattern, int radix, int prime);
int CalculatePrime(int radix);

/*END PROTOTYPES***************************************************************/
/******************************************************************************/
/*START MAIN*******************************************************************/
int main(int argc, char ** argv, char ** envp){


    string text = "VLAD IS HUNGRY AND VLAD IS HAPPY";
    string pattern = "IS";
    int radix = 256;

    int prime = CalculatePrime(radix);

    printf("prime is %d\n", prime);


    vector<int> solutions = RabinKarpMatcher(text, pattern, radix, prime);


    printf("SIZE OF %d\n", int(solutions.size()));

    for(vector<int>::iterator it = solutions.begin(); it != solutions.end(); it++){
        cout << (*it) << "\t" << text.substr((*it), pattern.length()) << endl;

    }


    return 0;
}
/*END MAIN*********************************************************************/
/******************************************************************************/
/*START FUNCTIONS**************************************************************/

vector<int> RabinKarpMatcher(string text, string pattern, int radix, int prime){

    vector<int> solutions;

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
                solutions.push_back(s);
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
