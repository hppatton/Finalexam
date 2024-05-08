#include <iostream>
#include <thread>
#include <vector>

using namespace std;

const int ARRAY_SIZE = 20;
int x[ARRAY_SIZE]; // Your array
int result_B = 0;
int result_C = 0;

void thread_B() {
    for (int i = 0; i < ARRAY_SIZE; i += 2) {
        result_B += x[i];
    }
}

void thread_C() {
    for (int i = 1; i < ARRAY_SIZE; i += 2) {
        result_C += x[i];
    }
}

void thread_D() {
    // Wait for B and C to complete (implementation would use synchronization primitives) 
    int total = result_B + result_C;
    cout << "Total sum: " << total << endl;
}

int main() {
    // Initialize array x with values...

    thread tB(thread_B);
    thread tC(thread_C);
    thread tD(thread_D);

    tB.join();
    tC.join();
    tD.join();

    return 0;
}
