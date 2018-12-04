#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include "kmpalgorithm.cpp"
#include "rabinkarpalgorithm.cpp"
//#include <istreambuf_iterator>

int main(int argc, char ** argv){
  
  std::ifstream file("alice.txt");
  std::string str((std::istreambuf_iterator<char>(file)),std::istreambuf_iterator<char>());

  std::vector<iteration> data;
  data=KMP("a",str);
  std::cout << data[0].time << std::endl;
  data=RabinKarp("a",str);
  std::cout << data[0].time << std::endl;
}
			       
