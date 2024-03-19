#include "Customer.h"

float Customer::netWorth() {
  float sum = 0;
  for (Account account : accounts) {
    sum += account.getBalance();
  }
  return sum;
}
