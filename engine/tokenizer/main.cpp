#include <string>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <tuple>

using namespace std;

tuple<int,string> countPairs(string& inpt){
  unordered_map<string, int> pairs_f;
  int maxFreq = 0;
  string maxFreqKey = "";
  for (int i = 0; i < inpt.length() - 1; i ++){
    string key = {inpt[i], inpt[i+1]};
    pairs_f[key] = pairs_f[key] + 1;
    if(pairs_f[key] > maxFreq){
      maxFreqKey = key;
      maxFreq = pairs_f[key];
    }
  }
  return {maxFreq, maxFreqKey};
} 

int main(){
  string input;
  cin >> input;

  tuple<int,string> t = countPairs(input);
  cout << get<0>(t) << " " << get<1>(t);
  return 0;
}