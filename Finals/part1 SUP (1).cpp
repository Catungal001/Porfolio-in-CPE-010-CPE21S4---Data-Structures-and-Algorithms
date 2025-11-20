#include <iostream>
#include <thread>
using namespace std;

int total = 0; 

void addValue(int num) {
    total += num;
}

int main() {
    thread t1(addValue, 5);
    thread t2(addValue, 10);
    thread t3(addValue, 15);

    cout << "Starting value of total = " << total << endl;

    t1.join();
    cout << "After t1.join(), total = " << total << endl;

    t2.join();
    cout << "After t2.join(), total = " << total << endl;

    t3.join();
    cout << "After t3.join(), total = " << total << endl;

    cout << "End of program, final total = " << total << endl;

    return 0;
}
