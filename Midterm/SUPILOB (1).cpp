#include <iostream>
#include <cstdlib>   
#include <ctime>     
using namespace std;

int main() {
    int A[100];   
    int n = 100;  
    int i, j, temp;

    srand(time(0));  

    
    for (i = 0; i < n; i++) {
        A[i] = (rand() % 5) + 1;
    }

    
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }

    
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0;
    for (i = 0; i < n; i++) {
        if (A[i] == 1) c1++;
        else if (A[i] == 2) c2++;
        else if (A[i] == 3) c3++;
        else if (A[i] == 4) c4++;
        else if (A[i] == 5) c5++;
    }

    
    cout << "Sorted Array: " << endl;
    for (i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;

    
    cout << "\nManual Count:" << endl;
    cout << "Gab: " << c1 << endl;
    cout << "Dal: " << c2 << endl;
    cout << "Jason: " << c3 << endl;
    cout << "Gelo: " << c4 << endl;
    cout << "Lester: " << c5 << endl;

    
    int winner = 1;
    int maxVotes = c1;

    if (c2 > maxVotes) { maxVotes = c2; winner = 2; }
    if (c3 > maxVotes) { maxVotes = c3; winner = 3; }
    if (c4 > maxVotes) { maxVotes = c4; winner = 4; }
    if (c5 > maxVotes) { maxVotes = c5; winner = 5; }

    cout << "\nWinner is Candidate " << winner 
         << " with " << maxVotes << " votes!" << endl;

    return 0;
}
