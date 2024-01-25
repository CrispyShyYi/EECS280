/* stats_tests.cpp
 *
 * Unit tests for the simple statistics library
 *
 * EECS 280 Project 1
 *
 * Protip #1: Write tests for the functions BEFORE you implement them!  For
 * example, write tests for median() first, and then write median().  It sounds
 * like a pain, but it helps make sure that you are never under the illusion
 * that your code works when it's actually full of bugs.
 *
 * Protip #2: Instead of putting all your tests in main(),  put each test case
 * in a function!
 */


#include "stats.hpp"
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>
using namespace std;

double threshold = 0.00001;

// Add prototypes for you test functions here.
void test_sum_small_data_set();
void test_count_small_data_set();
void test_mean_small_data_set();
void test_median_small_data_set();
void test_mode_small_data_set();
void test_min_small_data_set();
void test_max_small_data_set();
void test_stdev_small_data_set();
void test_percentile_small_data_set();
void test_summarize_samll_data_set();


int main() {
  test_sum_small_data_set();
  // Call your test functions here
  test_count_small_data_set();
  test_mean_small_data_set();
  test_median_small_data_set();
  test_mode_small_data_set();
  test_min_small_data_set();
  test_max_small_data_set();
  test_stdev_small_data_set();
  test_percentile_small_data_set();
  test_summarize_samll_data_set();

  return 0;
}

// test sum function
void test_sum_small_data_set() {
  cout << "test_sum_small_data_set" << endl;

  vector<double> data;
  data.push_back(1);
  data.push_back(2);
  data.push_back(3);

  assert(sum(data) == 6);

  cout << "PASS!" << endl;

  vector<double> d = {-12.3, 23.4, 45.6};
  assert(abs(sum(d) - 56.7) < threshold);
  cout << "PASS!" << endl;

  vector<double> d1 = {1, 23.4, 4};
  assert(abs(sum(d1) - 28.4) < threshold);
  cout << "PASS!" << endl;

  vector<double> d2 = {0, 0, 0};
  assert(sum(d2) == 0);
  cout << "PASS!" << endl;

  cout << "test_sum_small_data_set" << endl << endl;

}

// Add the test function implementations here.

// test count function
void test_count_small_data_set(){

  cout << "test_count_small_data_set" << endl;

  vector<double> data1 = {12, 23, 42, 53};
  assert(count(data1) == 4);
  cout << "PASS!" << endl;

  vector<double> data2 = {10.3, 32.6, 54.3, 76.3, 36.4};
  assert(count(data2) == 5);
  cout << "PASS!" << endl;

  vector<double> data3 = {12, 32.3, 54.7, 67};
  assert(count(data3) == 4);
  cout << "PASS!" << endl;

  vector<double> data4 = {0, 0, 34, 54.7, 120};
  assert(count(data4) == 5);
  cout << "PASS!" << endl;

  cout << "PASS test_count_small_data_set" << endl << endl;
}

// test mean function
void test_mean_small_data_set(){

  cout << "test_mean_small_data_set" << endl;

  vector<double> data5 = {10, -20, 30, 40};
  assert(mean(data5) == 15);
  cout << "PASS!" << endl;

  vector<double> data6 = {2.4, 4.7, 12.5, 23.2};
  assert(abs(mean(data6) - 10.7) < threshold);
  cout << "PASS!" << endl;

  vector<double> data7 = {1, 4.7, 12.6, 32};
  assert(abs(mean(data7) - 12.575) < threshold);
  cout << "PASS!" << endl;

  vector<double> data8 = {0, 0, 0};
  assert(mean(data8) == 0);
  cout << "PASS!" << endl;

  cout << "PASS test_mean_small_data_set" << endl << endl;
}

// test median function
void test_median_small_data_set(){

  cout << "test_median_small_data_set" << endl;

  vector<double> data9 = {-7, 13, -2, 4};
  assert(abs(median(data9) - 1) < threshold);
  cout << "PASS!" << endl;

  vector<double> data10 = {4.6, 2.3, 13.6, 10.1, 15.7};
  assert(abs(median(data10) - 10.1) < threshold);
  cout << "PASS!" << endl;

  vector<double> data11 = {1, 2.3, 2.3, 16.7, 10.1};
  assert(abs(median(data11) - 2.3) < threshold);
  cout << "PASS!" << endl;

  vector<double> data12 = {0, 0, 0, 0, 0};
  assert(median(data12) == 0);
  cout << "PASS!" << endl;

  vector<double> data13 = {1, 2, 7, 5, 3};
  assert(median(data13) == 3);
  cout << "PASS!" << endl;

  cout << "PASS test_median_small_data_set" << endl << endl;
}

// test mode function
void test_mode_small_data_set(){

  cout << "test_mode_small_data_set" << endl;

  vector<double> data14 = {-11, 2, 5, 6, 2, 7, 2};
  assert(mode(data14) == 2);
  cout << "PASS!" << endl;

  vector<double> data15 = {1.2, 2, 5.4, 6, 2.4, 7.2, 2.4};
  assert(mode(data15) == 2.4);
  cout << "PASS!" << endl;

  vector<double> data16 = {1, 1, 5, 6, 2, 7, 2, 6};
  assert(mode(data16) == 1);
  cout << "PASS!" << endl;

  vector<double> data17 = {2, 3, 3, 2, 1, 1};
  assert(mode(data17) == 1);
  cout << "PASS!" << endl;

  cout << "PASS test_mode_small_data_set" << endl << endl;
}

// test min function
void test_min_small_data_set(){

  cout << "test_min_small_data_set" << endl;

  vector<double> data18 = {1, 2, 5, 6, 2, 7, 2};
  assert(min(data18) == 1);
  cout << "PASS!" << endl;

  vector<double> data19 = {1, 2.3, 5, 6.7, 0.9, 7, 2};
  assert(abs(min(data19) - 0.9) < threshold);
  cout << "PASS!" << endl;

  vector<double> data20 = {-1.1, 2.3, 5, 6.7, 0.9, 7, 2};
  assert(abs(min(data20) - (-1.1)) < threshold);
  cout << "PASS!" << endl;

  cout << "PASS test_min_small_data_set" << endl << endl;
}

// test max function
void test_max_small_data_set(){

  cout << "test_max_small_data_set" << endl;

  vector<double> data21 = {1, 2, 5, 6, 2, 7, 2};
  assert(max(data21) == 7);
  cout << "PASS!" << endl;

  vector<double> data22 = {1, 2.3, 5, 6.7, 0.9, 7.6, 2};
  assert(abs(max(data22) - 7.6) < threshold);
  cout << "PASS!" << endl;

  vector<double> data23 = {-1.1, -2.3, -5, -6.7, -0.9, -7, -2};
  assert(abs(max(data23) - (-0.9)) < threshold);
  cout << "PASS!" << endl;

  cout << "PASS test_max_small_data_set" << endl << endl;
}

// test stdev function
void test_stdev_small_data_set(){

  cout << "test_stdev_small_data_set" << endl;

  vector<double> data24 = {1, 2, 3, 4};
  assert(abs(stdev(data24) - 1.290994) < threshold);
  cout << "PASS!" << endl;

  vector<double> data25 = {1.2, 2.1, 3.4, 4};
  assert(abs(stdev(data25) - 1.263263) < threshold);
  cout << "PASS!" << endl;

  vector<double> data26 = {-1.2, -2.1, -3.4, 4};
  assert(abs(stdev(data26) - 3.2448677) < threshold);
  cout << "PASS!" << endl;

  cout << "PASS test_stdev_small_data_set" << endl << endl;

}

// test percentile function
void test_percentile_small_data_set(){

  cout << "test_percentile_small_data_set" << endl;

  vector<double> data27 = {1, 2, 3, 4};
  assert(abs(percentile(data27, 0.25) - 1.75) < threshold);
  cout << "PASS!" << endl;

  vector<double> data28 = {1, 2.3, 3, 6.4, 2.1};
  assert(abs(percentile(data28, 0.75) - 3) < threshold);
  cout << "PASS!" << endl;
  
  vector<double> data29 = {-11, 2.3, 3, 6.4, -2.1};
  assert(abs(percentile(data29, 1.00) - 6.4) < threshold);
  cout << "PASS!" << endl;

  cout << "PASS test_percentile_small_data_set" << endl << endl;

}

// test summarize function
void test_summarize_samll_data_set(){

  cout << "test_summarize_small_data_set" << endl;

  vector<double> data30 = {1, 2, 3, 4, 5, 6};
  vector<pair<double, int>> vp = summarize(data30);
  for(size_t i = 0; i < vp.size(); i++){
    cout << vp[i].first << ": " << vp[i].second << endl;
  }

  cout << endl;

  vector<double> data31 = {1, 0.9, -3, 4.6, -3.5, 6};
  vector<pair<double, int>> vp2 = summarize(data31);
  for(size_t i = 0; i < vp2.size(); i++){
    cout << vp2[i].first << ": " << vp2[i].second << endl;
  }

  cout << endl;

  vector<double> data32 = {1, -2, 1, 0, 1, -2, 0, -2};
  vector<pair<double, int>> vp3 = summarize(data32);
  for(size_t i = 0; i < vp3.size(); i++){
    cout << vp3[i].first << ": " << vp3[i].second << endl;
  }

  cout << "PASS test_summarize_small_data_set" << endl << endl;
  }