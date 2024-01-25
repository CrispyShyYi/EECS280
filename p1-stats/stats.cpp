// stats.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <cassert>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<double, int> > summarize(vector<double> v) {
  
  // arrange the order
  sort(v);
  vector<pair<double, int>> vp;

  double num = v[0];
  int count = 1;

  // count frequency
  for (size_t i = 1; i < v.size(); i++){

    if (num == v[i]){
      count++;
    }
    else{
      vp.push_back({num, count});
      count = 1;
      num = v[i];
      
    }

    if (i == v.size() - 1){
      vp.push_back({num, count});
    }

  }

  return vp;
  assert(false);
}

// function of count
int count(vector<double> v) {
    int num = 0;
    num = v.size();
    
    return num;
  assert(false);
}

// function of sum
double sum(vector<double> v) {
    double total = 0;
    for (size_t i = 0; i < v.size(); i++){
        total += v[i];
    }
    
    return total;
  assert(false);
}

// function of mean
double mean(vector<double> v) {
    double ave = 0;
    ave = sum(v) / count(v);
    
    return ave;
  assert(false);
}

//function of median
double median(vector<double> v) {
    sort(v);
    double med = 0;
    int number = count(v);
    if (number % 2 == 0){
        med = (v[number / 2 - 1] + v[number / 2]) / 2;
    } 
    else{
        med = v[number / 2];
    }

    return med;
  assert(false);
}

// function of mode
double mode(vector<double> v) {

  sort(v);

  int count = 1;
  int num = 0;
  double currNum = v[0];
  double modeNum = v[0];
  int length = v.size();

  for(int i = 1; i < length; i++){

    if(v[i] == currNum){
      count ++;
    }
    else if (v[i] != currNum){
      if (count > num){
        num = count;
        modeNum = v[i - 1];
      }
      currNum = v[i];
      count = 1;
    }
  }
  return modeNum;

  assert(false);
}

// function of min

double min(vector<double> v) {
  sort(v);
  
  double minimum = v[0];
  return minimum;

  assert(false);
}

// function of max
double max(vector<double> v) {

  sort(v);

  int size = v.size();
  double maximum = v[size - 1];
  return maximum;

  assert(false);
}

// function of stdev
double stdev(vector<double> v) {

  int size = v.size();
  double ave = mean(v);
  double var = 0;
  double std = 0;
  
  for (int i =0; i < size; i++){

    var += pow((v[i] - ave), 2);

  }
  var /= size - 1;
  std = sqrt(var);
  return std;

  assert(false);
}

// function of percentile
double percentile(vector<double> v, double p) {

  sort(v);
  int size = v.size();
  double per = 0;

  double n;
  n = p * (size - 1)  + 1;
  double intPart = 0;
  double fractPart = 0;
  fractPart = modf(n , &intPart);
  if (abs(p - 1.0) < 0.0001){
    per = v[intPart - 1];
  }
  else{
    per = v[intPart - 1] + fractPart * (v[intPart] - v[intPart - 1]);
  }
  return per;

  assert(false);
}
