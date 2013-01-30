#include <iostream>
#include <set>

using namespace std;

typedef set<int> vset;


int main(int argc, char** argv) {
  vset vals;
  int t;
  while (cin >> t) {
    vals.insert(t);
  }
  cout << vals.size() << endl;
  return 0;
}
