#include <iostream>
#include <cmath>

using namespace std;


int factorial(int start) {
  int result = 1;
  for (int i = start; i > 0; i--){
    result = result * i;
  }
  return result;
}


int binomial_coefficient(int n, int k){
  int result = factorial(n) / (factorial(k) * factorial(n - k));
  return result;
}


float bernoulli_trial(int n, float p, int k){
  float result = binomial_coefficient(n, k) * pow(p, k) * pow(1 - p, n - k);
  return result;
}


float bernoulli_trial_range_to_0(int n, float p, int k){
  float result = 0;
  for (int i = k; i >= 0; i--){
    result = result + bernoulli_trial(n, p, i);
  }
  return result;
}


int main() {
  cout << bernoulli_trial_range_to_0(5, 0.24, 3) << endl;
  return 0;
}
