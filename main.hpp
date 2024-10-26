#include <iostream>
using namespace std;

void getTwoValues(int &begin, int &end);
int getNextPrime(int begin);
int getPrevPrime(int end);

// Function to ask for two integer values from the user
void getTwoValues(int &begin, int &end) {
    cout << "Enter two integer values (begin and end): ";
    cin >> begin >> end;

    // Ensure begin is less than end
    while (begin >= end) {
        cout << "Invalid input. Begin must be less than end. Please re-enter: ";
        cin >> begin >> end;
    }
}

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false; // 0 and 1 are not prime numbers
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false; // Divisible by another number
    }
    return true;
}

// Function to find the closest next prime number greater than the given number
int getNextPrime(int begin) {
    int nextNum = begin + 1; // Start checking from the next number
    while (!isPrime(nextNum)) {
        nextNum++;
    }
    return nextNum;
}

// Function to find the closest prime number less than the given number
int getPrevPrime(int end) {
    int prevNum = end - 1; // Start checking from the previous number
    while (prevNum > 1 && !isPrime(prevNum)) {
        prevNum--;
    }
    return prevNum; // Return the prime number or 1 if no prime is found
}
