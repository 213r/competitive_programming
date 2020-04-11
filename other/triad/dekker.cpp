#include <thread>
#include <vector>
#include <cassert>
#include <iostream>
#include <string>

std::vector<bool> flag;
int turn;
int count;
int critical;

void exclusive_acess(int i){
    flag[i] = true;
    while (flag[1^i]) {
        if (turn != i) {
            flag[i] = false;
            while (turn != i) {}
            flag[i] = true;
        }
    }
    // critical code section start 
    ++critical;
    // the two simultaneous critical session must be error.  
    assert(critical < 2);
    ++count;
    --critical;
    // critical code section end 
    turn = 1^i;
    flag[i] = false;
}

void add_count_by_thread(int th_id) {
    for (int i = 0; i < int(1E6); ++i) {
        if (i%1000==0) std::cout << "itr:" << i << ",p:" << th_id << std::endl;
        exclusive_acess(th_id);
    }
}

void trial() {
    // initialize
    flag = std::vector<bool>(2, false);
    count = 0;
    turn = 0;
    critical = 0;
    
    std::thread th_1(add_count_by_thread, 1);
    std::thread th_0(add_count_by_thread, 0);

    th_1.join();
    th_0.join();

    std::cout << count << std::endl;

};

int main()
{
    trial(); 
    return 0;
}