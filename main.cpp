#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <cstdlib>
#include "kmpalgorithm.cpp"
#include "rabinkarpalgorithm.cpp"
#include "boyermoorealgorithm.cpp"

int main(int argc, char ** argv){
  
  std::ifstream file("alice.txt");
  std::string str((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());

  std::vector<std::string> words={"the","it","alice","rabbit","this","that","hat","queen","green","things","fghjk","sea","when","go","hello","cake","food","tall","happy","hungry"};
  std::vector<std::string> sentences={"Would the fall NEVER come to an end!","She went on growing, and growing, and very soon had to kneel down on the floor","Perhaps it hasn't one","Off with her head","I don't know what"};
  int time1=0;
  int time2=0;
  int time3=0;
  int x;
  std::string letter="a";
  for(x=0;x<50;x++){
    letter[0]='a'+ rand()%26;
    time1+=KMP(letter,str)[0].time;
    //time2+=RabinKarp(letter,str)[0].time;
    time3+=BoyerMoore(letter,str)[0].time;
  }
  std::cout << "KMP single letter search average time: "<< time1/50 << std::endl;
  std::cout << "Rabin Karp single letter search average time: "<< time2/50 << std::endl;
  std::cout << "Boyer Moore single letter search average time: "<< time3/50 << std::endl;
  time1=0;
  for(x=0;x<50;x++){
    time1+=KMP(words[rand()%20],str)[0].time;
    time2+=RabinKarp(words[rand()%20],str)[0].time;
    time3+=BoyerMoore(words[rand()%20],str)[0].time;
  }
  std::cout << "KMP word search average time: "<< time1/50 << std::endl;
  std::cout << "Rabin Karp word search average time: "<< time2/50 << std::endl;
  std::cout << "Boyer Moore word letter search average time: "<< time3/50 << std::endl;
  time1=0;
  for(x=0;x<50;x++){
    time1+=KMP(sentences[rand()%5],str)[0].time;
    time2+=RabinKarp(sentences[rand()%20],str)[0].time;
    time3+=BoyerMoore(sentences[rand()%20],str)[0].time;
  }
  std::cout << "KMP sentence search average time: "<< time1/50 << std::endl;
  std::cout << "Rabin Karp sentence search average time: "<< time2/50 << std::endl;
  std::cout << "Boyer Moore sentence search average time: "<< time3/50 << std::endl;
}
			       
