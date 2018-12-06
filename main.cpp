#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "kmpalgorithm.cpp"
#include "rabinkarpalgorithm.cpp"
#include "boyermoorealgorithm.cpp"

using namespace std;

//Format function for command line output for debugging purposes
// void errMessage(string text){
//     int i;
//     cout << endl;
//     for(i = 0; i < 50; i ++) cout << "=";
//     cout << endl << text << endl;
//     for(i = 0; i < 50; i ++) cout << "=";
//     cout << endl << endl;
// }

int main(int argc, char ** argv){

    //FILE READING
    ifstream file("alice.txt");
    string str((istreambuf_iterator<char>(file)),istreambuf_iterator<char>());

    //PATTERN STRINGS
    string letter="a";
    vector<string> words={"the","it","alice","rabbit","this","that","hat","queen","green","things","fghjk","sea","when","go","hello","cake","food","tall","happy","hungry"};
    vector<string> sentences={"Would the fall NEVER come to an end!","She went on growing, and growing, and very soon had to kneel down on the floor","Perhaps it hasn't one","Off with her head","I don't know what"};

    //TIME VARIABLES
    double time1=0;
    double time2=0;
    double time3=0;

    //INDEX
    int x;
    
    for(x=0; x < 50; x++){
        letter[0]='a'+ rand()%26;
        time1+=KMP(str,letter)[0].time;
        //time2+=RabinKarp(str,letter)[0].time;
        time3+=BoyerMoore(str,letter)[0].time;
    }
    
    cout << "\t\tLETTER SEARCHES" << endl;
    cout << "KMP single letter search average time: "<< time1/50 << endl;
    cout << "Rabin Karp single letter search average time: "<< time2/50 << endl;
    cout << "Boyer Moore single letter search average time: "<< time3/50 << endl << endl;

    
    time1=0;
    time2=0;
    time3=0;

    for(x=0; x < 50; x++){
        time1+=KMP(str,words[rand()%20])[0].time;
        //time2+=RabinKarp(str,words[rand()%20])[0].time;
        time3+=BoyerMoore(str,words[rand()%20])[0].time;
    }

    cout << "\t\tWORD SEARCHES" << endl;
    cout << "KMP word search average time: "<< time1/50 << endl;
    cout << "Rabin Karp word search average time: "<< time2/50 << endl;
    cout << "Boyer Moore word letter search average time: "<< time3/50 << endl << endl;

    time1=0;
    time2=0;
    time3=0;

    for(x=0; x < 50; x++){
        time1+=KMP(str,sentences[rand()%5])[0].time;
        //time2+=RabinKarp(str,sentences[rand()%5])[0].time;
        time3+=BoyerMoore(str,sentences[rand()%5])[0].time;
    }

    cout << "\t\tSENTANCES SEARCHES" << endl;
    cout << "KMP sentence search average time: "<< time1/50 << endl;
    cout << "Rabin Karp sentence search average time: "<< time2/50 << endl;
    cout << "Boyer Moore sentence search average time: "<< time3/50 << endl << endl;
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
			       
