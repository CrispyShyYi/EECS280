// main.cpp
#include "stats.hpp"
#include "p1_library.hpp"
#include <iostream>

using namespace std;

int main() {

  string filename;
  string column_name;
  vector<double> vOriginal;

  cout << "enter a filename\n";
  cin >> filename;

  cout << "enter a column name\n";
  cin >> column_name;

  cout << "reading column " << column_name << " from " << filename << endl;
  vOriginal = extract_column(filename, column_name);

  cout << "Summary (value: frequency)\n";
  
  vector<pair<double, int>> vData;

  vData = summarize(vOriginal);

  for (size_t i = 0; i < vData.size(); i++){

    cout << vData[i].first << ": " << vData[i].second << endl;

  }

  cout << endl;

  int num = count(vOriginal);
  double summary = sum(vOriginal);
  double ave = mean(vOriginal);
  double middle = median(vOriginal);
  double modeNum = mode(vOriginal);
  double maxNum = max(vOriginal);
  double minNum = min(vOriginal);
  double stdNum = stdev(vOriginal);
  double percentileNum00 = percentile(vOriginal, 0);
  double percentileNum25 = percentile(vOriginal, 0.25);
  double percentileNum50 = percentile(vOriginal, 0.50);
  double percentileNum75 = percentile(vOriginal, 0.75);
  double percentileNum100 = percentile(vOriginal, 1.00);

  cout << "count = " << num << endl;
  cout << "sum = " << summary << endl;
  cout << "mean = " << ave << endl;
  cout << "stdev = " << stdNum << endl;
  cout << "median = "<< middle << endl;
  cout << "mode = " << modeNum << endl;
  cout << "min = " << minNum << endl;
  cout << "max = " << maxNum << endl;
  cout << "  0th percentile = " << percentileNum00 << endl;
  cout << " 25th percentile = " << percentileNum25 << endl;
  cout << " 50th percentile = " << percentileNum50 << endl;
  cout << " 75th percentile = " << percentileNum75 << endl;
  cout << "100th percentile = " << percentileNum100 << endl;

return 0;
}
