/// @file pa12.cpp

#include "ArrayList.h"  // Including header file
#include <iostream>
#include <cmath>

using namespace std;

// Main function
int main() {

    // Initialize n to be number to find prime numbers up to
    int n;

    // Request and extract user input
    cout << "Enter an integer: ";
    cin >> n;

    // Declare ArrayList objects
    cs202::ArrayList container(n + 1);
    cs202::ArrayList primes(1);

    int num_primes = 0; // Count num of primes numbers found


    // If max number is larger than two, begin prime numbers from 2
    if (n >= 2) {
        primes.front() = 2;
        num_primes = 1;
    }

    // Loop until max number to set elements of container
    for (int i = 0; i <= n; ++i) {
        container.at(i) = 1;    // Set elements to 1 for true
    }

    // Starting from 2, use Sieve Algorithm to calculate # of primes
    for (int i = 2; i <= sqrt(n); i++) {

        // If value is true at specified position
        if ((container.at(i)) != 0) {

            // Check for prime numbers and set non-primes to false
            for (int j = (i * i); j <=n; j += i) {
                (container.at(j)) = 0;
            }
        }
    }

    // Starting from 3 (as we know 2 is a prime) push back all primes

    for (int i = 3; i <= n; i++) {
        if (container.at(i) == 1) {
            num_primes++;   // Add to prime number counter
            primes.push_back(i);    // Append prime numbers to new pointer
            // array object
        }
    }

    // Print number of prime numbers
    cout << '\n' << "Found " << num_primes << " prime numbers:" << '\n';

    // Loop through new prime pointer array and print all prime numbers,
    // ignoring any trailing/leading zeros that filled the array during
    // construction, or that are false
    for (cs202::ArrayList::size_type i = 0; i < primes.size(); ++i) {
        if (primes.at(i) != 0) {
            cout << primes.at(i) << endl;   // Print prime number at i
        }
    }
}
