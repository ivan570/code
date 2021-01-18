#include <iostream>
using namespace std;

class Solution{
public:
  int count(string one, string two, int i, int j) {
    if (one.size() == 0 && two.size() == 0)
	return 1;
      else if (two.size() == 0)
	return 1;
      else if (one.size() == 0)
	return 0;
      else if (one[i] == two[j])
	return count(one, two, i - 1, j) + count(one, two, i - 1, j - 1);
      else
	return count(one, two, i - 1, j);
  }
    int countWays(string one, string two){
      return count(one, two, one.size() - 1, two.size() - 1);
    }
};


int main() {
  
  return 0;
}
