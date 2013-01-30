#include <iostream>
#include <cstring>
#include <sstream>
#include <set>
#include <functional>
#include <stdint.h>

#include "hash.h"

using namespace std;

typedef set<double, greater<double> > mvset;


int main(int argc, char** argv) {
  size_t k = 0;
  if (argc > 1) {
    stringstream ss(argv[1]);
    ss >> k;
    unsigned int seed = time(NULL);
    if (argc > 2) {
      stringstream ss2(argv[2]);
      ss2 >> seed;
    }
    init_siphash(seed);
  } else {
    cout << "usage: stream k [seed]" << endl;
    exit(1);
  }

  mvset minvals;
  int t;

  while (cin >> t) {
    double d = hash(t);
    if (minvals.size() < k) {
      minvals.insert(d);
    } else if (d < *minvals.begin()) {
      if (minvals.find(d) == minvals.end()) {
	// new minvalue, remove maximum, insert new
	minvals.erase(minvals.begin());
	minvals.insert(d);
      }
    }
  }
  // write estimate
  double minest = 0;
  if (minvals.size() > 0) {
    //cout << "min" <<  *minvals.begin() << endl;
    minest = ((double) k)/(*minvals.begin()) - 1.0; 
  }
  cout << minest << endl;    
  return 0;
}
