#include <thread>
#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include <algorithm>
#include <atomic>
#include <array>

const int N = 4;
std::array<std::atomic_bool, N> enter;
std::array<std::atomic_int, N> pri;
int count;
int critical;

void exclusive_acess(int i){
    enter[i] = true;
    pri[i] = 1 + *std::max_element(pri.begin(), pri.end());
    enter[i] = false;

    for (int j = 0; j < N; ++j) {
        // std::cout << 'x' << i << j << std::endl;
        while (enter[j]) {};
        // std::cout << 'a' << i << j << std::endl;
        while ((pri[j] != 0) && 
            ((pri[j] < pri[i]) || ((pri[j] == pri[i]) && (j < i)))) {};
        // std::cout << 'b' << i << j  << std::endl;
    } 
    // critical code section start 
    ++critical;
    // the two simultaneous critical session must be error.  
    assert(critical < 2);
    ++count;
    --critical;
    // critical code section end 
    pri[i] = 0;
}

void add_count_by_thread(int th_id) {
    for (int i = 0; i < int(1E5); ++i) {
        //if (i%1==0) std::cout << "itr:" << i << ",p:" << th_id << std::endl;
        exclusive_acess(th_id);
    }
}

void trial() {
    // initialize
    for (int i = 0; i < N; ++i) {
        enter[i] = false;
        pri[i] = 0;
    }
    count = 0;
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