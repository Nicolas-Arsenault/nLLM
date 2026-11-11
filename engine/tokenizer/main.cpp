#include <string>
#include <iostream>
#include <vector> 
#include <unordered_map>
#include <utility>
#include <tuple>

using namespace std;

//TODO:
// Random integer picker and validate it has not been used yet
// This will be used to replace the most frequent character.
// Make the function to replace
// Iterate until no changes made
// Build a map of all used integers in count() func 

tuple<int,long long> countPairs(vector<int>& inpt){
  unordered_map<long long, int> pairs_f;
  int maxFreq = 0;
  long long maxFreqKey;

  for (int i = 0; i < inpt.size() - 1; i ++){
    long long k =  ((long long)inpt[i] << 32) | inpt[i+1]; //bit packing for the key. same as using a pair but more efficient
    pairs_f[k] = pairs_f[k] + 1;
    if(pairs_f[k] > maxFreq){
      maxFreqKey = k;
      maxFreq = pairs_f[k];
    }
  }
  return {maxFreq, maxFreqKey};
} 

vector<int> convertInputToVector(string &input){
  vector<int> out;

  for (char c : input){
    out.push_back(static_cast<int>(c));
  }
  return out;
}

int main(){
  string input;
  cin >> input;

  auto converted = convertInputToVector(input);
  for (int i : converted){
    cout << i;
  }
  cout <<endl;
  auto t = countPairs(converted);
  cout << get<0>(t) << " " << get<1>(t);
  return 0;
}