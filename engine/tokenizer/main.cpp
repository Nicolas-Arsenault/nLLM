#include <string>
#include <iostream>
#include <vector> 
#include <unordered_map>
#include <utility>
#include <tuple>

using namespace std;

vector<int> convertInputToVector(string& input);
tuple<int, long long> countPairs(vector<int>& i);

vector<int> BPE(string& input){
  bool changes= false;
  int nextTokenId = 256;
  vector<int> curr = convertInputToVector(input);
  do{
    vector<int> temp;
    changes = false;
    auto t = countPairs(curr);
    cout << get<0>(t) <<endl;
    if(get<0>(t) > 1){
      changes = true;
      for(size_t i = 0; i < curr.size(); i ++){
        long long k =  i <= curr.size() - 2 ? ((long long)curr[i] << 32) | curr[i+1] : -1;
        if (k == get<1>(t)){
          temp.push_back(nextTokenId);
          i++;
        }else{
          temp.push_back(curr[i]);
        }
      }
      nextTokenId++;
      
      curr = std::move(temp); //O(1)
      temp.clear();
    } 
  }while(changes);
  return curr;
}

tuple<int,long long> countPairs(vector<int>& inpt){
  unordered_map<long long, int> pairs_f;
  int maxFreq = 0;
  long long maxFreqKey;

  for (size_t i = 0; i < inpt.size() - 1; i ++){
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

  for (unsigned char c : input){
    out.push_back(static_cast<int>(c));
  }
  return out;
}

int main(){
  string input;
  cin >> input;

  vector<int> res = BPE(input);

  for(int i : res){
    cout << i << " ";
  }
  return 0;
}