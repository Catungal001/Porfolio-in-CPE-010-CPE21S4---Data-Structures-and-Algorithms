#include <iostream>
#include <queue>
#include <string>
using namespace std;


class Job {
public:
    int id;
    string user;
    int pages;

    Job(int i, string u, int p) {
        id = i;
        user = u;
        pages = p;
    }
};


class Printer {
private:
    queue<Job> jobList; 

public:
    void addJob(Job j) {
        jobList.push(j);
        cout << "Job " << j.id << " added by " << j.user 
             << " (" << j.pages << " pages)" << endl;
    }

    void processJobs() {
        while (!jobList.empty()) {
            Job cur = jobList.front();
            cout << "Printing job " << cur.id << " from " 
                 << cur.user << " with " << cur.pages << " pages..." << endl;
            jobList.pop(); 
        }
        cout << "All print jobs finished." << endl;
    }
};

int main() {
    Printer printer;

    
    printer.addJob(Job(1, "Kim Dokja", 10));
    printer.addJob(Job(2, "Yoo Joonghyuk", 5));
    printer.addJob(Job(3, "Uriel", 15));
    printer.addJob(Job(4, "Sun Wukong", 7));
    printer.addJob(Job(5, "Persephone", 12));
    printer.addJob(Job(6, "Hades", 20));

    cout << "\n--- Processing Queue ---\n";
    printer.processJobs();

    return 0;
}
