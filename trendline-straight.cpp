#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;

int main() 
{
  // Data input
  int N;
  cin >> N;
  
  vector<float> x(N), y(N);
  
  for(int i=0; i<N; i++){
    cin >> x[i] >> y[i];
  }
  
  // Calculate mean
  float x_mean = accumulate(x.begin(), x.end(), 0.0) / N;
  float y_mean = accumulate(y.begin(), y.end(), 0.0) / N;
  
  // Calculate deviations
  vector<float> x_deviation(N), y_deviation(N);
  
  for(int i=0; i<N; i++){
    x_deviation[i] = x[i] - x_mean;
    y_deviation[i] = y[i] - y_mean;
  }
  
  // Calculate variance
  float x_variation = inner_product(x_deviation.begin(), x_deviation.end(), x_deviation.begin(), 0.0) / N;
  
  // Calculate covariance
  float covariance = inner_product(x_deviation.begin(), x_deviation.end(), y_deviation.begin(), 0.0) / N;
  
  // Calculate the slope and intercept of the trend line
  float slope = covariance / x_variation;
  float intercept = y_mean - (slope * x_mean);
  
  cout << "Slope: " << slope << "\nIntercept: " << intercept << "\n";
  
  return 0;
}
