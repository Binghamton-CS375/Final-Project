#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "kmpalgorithm.cpp"
#include "rabinkarpalgorithm.cpp"
#include "boyermoorealgorithm.cpp"

using namespace std;


//
// typedef struct{
//
// } data;


void printSolutionOffsets(solution solutions){
    printf("OFFSETS:   ");
    for(vector<int>::iterator it = solutions.offsets.begin(); it != solutions.offsets.end(); it++){
        printf("  %d", (*it));
    }
    printf("\n\n");
}

vector<solution> BruteForce(string text, string pattern){

    vector<solution> data;
    solution temp_solution;

    temp_solution = BoyerMooreMatcher(text, pattern);

    data.push_back(temp_solution);
    return data;
}

solution BruteForceMatcher(string text, string pattern){

    solution solutions;

    /**************************************************************************/
    /*TIMING CODE**************************************************************/
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    /*TIMING CODE**************************************************************/
    /**************************************************************************/

    int text_length = text.length();
    int pattern_length = pattern.length();
    int text_index;

    for(text_index = 0 ; (text_index + pattern_length) < text_length; text_index++){
        if(pattern.compare(text_index, pattern_length, text) == 0){
            solutions.offsets.push_back(text_index);
        }
    }

    /**************************************************************************/
    /*TIMING CODE**************************************************************/
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    milliseconds_type time_span = duration_cast<milliseconds_type>(t2 - t1);
    solutions.time = duration_cast<milliseconds_type>(time_span).count();
    /*TIMING CODE**************************************************************/
    /**************************************************************************/


    return solutions;
}



//Format function for command line output for debugging purposes
// void errMessage(string text){
//     int i;
//     cout << endl;
//     for(i = 0; i < 50; i ++) cout << "=";
//     cout << endl << text << endl;
//     for(i = 0; i < 50; i ++) cout << "=";
//     cout << endl << endl;
// }
//
// void fileOutput(int data[]){
//
// }


int main(int argc, char ** argv){

    //FILE READING
    ifstream file("alice.txt");
    string str((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());

    //PATTERN STRINGS
    string letter="a";
    vector<string> words={"the","it","alice","rabbit","this","that","hat","queen","green","things","fghjk","sea","when","go","hello","cake","food","tall","happy","hungry"};
    vector<string> sentences={"Would the fall NEVER come to an end!","She went on growing, and growing, and very soon had to kneel down on the floor","Perhaps it hasn't one","Off with her head","I don't know what"};

    vector<solution> brute_solution;
    vector<solution> kmp_solution;
    vector<solution> rabin_karp_solution;
    vector<solution> boyer_moore_solution;

    //TIME VARIABLES
    double time0=0;
    double time1=0;
    double time2=0;
    double time3=0;

    //INDEX
    int x;

    ofstream kmpfile;
    ofstream rbfile;
    ofstream bmfile;
    kmpfile.open("kmpoutput.txt");
    rbfile.open("rboutput.txt");
    bmfile.open("bmoutput.txt");

    kmpfile << endl << "Letter" << endl;
    rbfile << endl << "Letter" << endl;
    bmfile << endl << "Letter" << endl;


    for(x=0; x < 50; x++){
        letter[0]='a'+ rand()%26;

        // brute_solution = BruteForce(str,letter);
        kmp_solution = KMP(str,letter);
        rabin_karp_solution = RabinKarp(str,letter);
        boyer_moore_solution = BoyerMoore(str,letter);

        // printf("Time: %f   | Pattern Length: %d\n", kmp_solution[0].time, 1);
        // printf("Time: %f   | Pattern Length: %d\n", rabin_karp_solution[0].time, 1);
        // printf("Time: %f   | Pattern Length: %d\n", boyer_moore_solution[0].time, 1);

        kmpfile << "Time:  " << kmp_solution[0].time << "\tPattern Length:  " << 1 << endl;
        rbfile << "Time:  " << rabin_karp_solution[0].time << "\tPattern Length:  " << 1 << endl;
        bmfile << "Time:  " << boyer_moore_solution[0].time << "\tPattern Length:  " << 1 << endl;

        // time0+=brute_solution[0].time;
        time1+=kmp_solution[0].time;
        time2+=rabin_karp_solution[0].time;
        time3+=boyer_moore_solution[0].time;
    }

    cout << "\t\tLETTER SEARCHES" << endl;
    // cout << "Brute force letter search average time: " << time0/50 << endl;
    cout << "KMP single letter search average time: "<< time1/50 << endl;
    cout << "Rabin Karp single letter search average time: "<< time2/50 << endl;
    cout << "Boyer Moore single letter search average time: "<< time3/50 << endl << endl;

    time0=0;
    time1=0;
    time2=0;
    time3=0;

    kmpfile << endl << "Words" << endl;
    rbfile << endl << "Words" << endl;
    bmfile << endl << "Words" << endl;


    for(x=0; x < 50; x++){

        // brute_solution = BruteForce(str,words[rand()%20]);
        kmp_solution = KMP(str,words[rand()%20]);
        rabin_karp_solution = RabinKarp(str,words[rand()%20]);
        boyer_moore_solution = BoyerMoore(str,words[rand()%20]);

        // printf("Time: %f   | Pattern Length: %d\n", kmp_solution[0].time, words[rand()%20]);
        // printf("Time: %f   | Pattern Length: %d\n", rabin_karp_solution[0].time, words[rand()%20]);
        // printf("Time: %f   | Pattern Length: %d\n", boyer_moore_solution[0].time, words[rand()%20]);

        kmpfile << "Time:  " << kmp_solution[0].time << "\tPattern Length:  " << words[rand()%20] << endl;
        rbfile << "Time:  " << rabin_karp_solution[0].time << "\tPattern Length:  " << words[rand()%20] << endl;
        bmfile << "Time:  " << boyer_moore_solution[0].time << "\tPattern Length:  " << words[rand()%20] << endl;

        // time0+=brute_solution[0].time;
        time1+=kmp_solution[0].time;
        time2+=rabin_karp_solution[0].time;
        time3+=boyer_moore_solution[0].time;
    }

    cout << "\t\tWORD SEARCHES" << endl;
    // cout << "Brute force letter search average time: " << time0/50 << endl;
    cout << "KMP word search average time: "<< time1/50 << endl;
    cout << "Rabin Karp word search average time: "<< time2/50 << endl;
    cout << "Boyer Moore word letter search average time: "<< time3/50 << endl << endl;

    time0=0;
    time1=0;
    time2=0;
    time3=0;

    kmpfile << endl << "Sentances" << endl;
    rbfile << endl << "Sentances" << endl;
    bmfile << endl << "Sentances" << endl;


    for(x=0; x < 50; x++){

        // brute_solution = BruteForce(str,sentences[rand()%5]);
        kmp_solution = KMP(str,sentences[rand()%5]);
        rabin_karp_solution = RabinKarp(str,sentences[rand()%5]);
        boyer_moore_solution = BoyerMoore(str,sentences[rand()%5]);

        // printf("Time: %f   | Pattern Length: %d\n", kmp_solution[0].time, sentences[rand()%5].length());
        // printf("Time: %f   | Pattern Length: %d\n", rabin_karp_solution[0].time, sentences[rand()%5].length());
        // printf("Time: %f   | Pattern Length: %d\n", boyer_moore_solution[0].time, sentences[rand()%5].length());

        kmpfile << "Time:  " << kmp_solution[0].time << "\tPattern Length:  " << sentences[rand()%5].length() << endl;
        rbfile << "Time:  " << rabin_karp_solution[0].time << "\tPattern Length:  " << sentences[rand()%5].length() << endl;
        bmfile << "Time:  " << boyer_moore_solution[0].time << "\tPattern Length:  " << sentences[rand()%5].length() << endl;

        // time0+=brute_solution[0].time;
        time1+=kmp_solution[0].time;
        time2+=rabin_karp_solution[0].time;
        time3+=boyer_moore_solution[0].time;
    }

    cout << "\t\tSENTANCES SEARCHES" << endl;
    // cout << "Brute force letter search average time: " << time0/50 << endl;
    cout << "KMP sentence search average time: "<< time1/50 << endl;
    cout << "Rabin Karp sentence search average time: "<< time2/50 << endl;
    cout << "Boyer Moore sentence search average time: "<< time3/50 << endl << endl;


    kmpfile.close();
    rbfile.close();
    bmfile.close();


    /*
  string str2="The quick dog jumped over the lazy fox";
  vector<string> words2={"dog","cat","th"," f","jump","do","zebo"};
  vector<string> sentences2={"The quick dog jumped over the lazy fox","whats up"};
  time1=0;
  time2=0;
  time3=0;
  for(x=0;x<100;x++){
    letter[0]='a'+ rand()%26;
    time1+=KMP(letter,str2)[0].time;
    time2+=RabinKarp(letter,str2)[0].time;
    time3+=BoyerMoore(letter,str2)[0].time;
  }
  cout << "KMP single letter search average time: "<< time1 << endl;
  cout << "Rabin Karp single letter search average time: "<< time2 << endl;
  cout << "Boyer Moore single letter search average time: "<< time3 << endl;
  time1=0;
  time2=0;
  time3=0;
  for(x=0;x<100;x++){
    time1+=KMP(words[rand()%7],str2)[0].time;
    time2+=RabinKarp(words[rand()%7],str2)[0].time;
    time3+=BoyerMoore(words[rand()%7],str2)[0].time;
  }
  cout << "KMP word search average time: "<< time1 << endl;
  cout << "Rabin Karp word search average time: "<< time2 << endl;
  cout << "Boyer Moore word letter search average time: "<< time3 << endl;
  time1=0;
  time2=0;
  time3=0;
  for(x=0;x<100;x++){
    time1+=KMP(sentences[rand()%2],str2)[0].time;
    time2+=RabinKarp(sentences[rand()%2],str2)[0].time;
    time3+=BoyerMoore(sentences[rand()%2],str2)[0].time;
  }
  cout << "KMP sentence search average time: "<< time1 << endl;
  cout << "Rabin Karp sentence search average time: "<< time2 << endl;
  cout << "Boyer Moore sentence search average time: "<< time3 << endl;*/
}
