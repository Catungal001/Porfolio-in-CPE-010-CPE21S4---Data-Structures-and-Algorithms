#include <iostream>
#include <queue>
#include <string>

int main() {
    std::queue<std::string> q;
    std::string characters[] = {
        "Kim Dokja",
        "Yoo Joonghyuk",
        "Uriel",
        "Sun Wukong",
        "Persephone",
        "Hades"
    };

    
    for (auto& name : characters) {
        std::cout << "Enqueue: " << name << std::endl;
        q.push(name);
    }

   
    std::cout << "Queue after enqueues: ";
    std::queue<std::string> temp = q;  
    while (!temp.empty()) {
        std::cout << temp.front() << " ";
        temp.pop();
    }
    std::cout << "\n";

    
    while (!q.empty()) {
        std::cout << "Dequeue: " << q.front() << std::endl;
        q.pop();
    }

    return 0;
}
