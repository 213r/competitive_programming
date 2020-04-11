#include <cassert>
#include <iostream>
#include <thread>
#include "exclusive_access/example.hpp" 


void trial() {
    exclusive_access::Example mutex;
    int critical = 0;
    int count = 0;
    
    auto add_by_thread = [&mutex, &critical, &count](int th_id) {
        for (int i = 0; i < 100000; ++i) {
            mutex.lock(th_id);
            // critical session starts.  
            ++critical; 
            ++count;
            // the two simultaneous critical session must be error.  
            assert(critical < 2);
            --critical;
            // critical session ends.  
            mutex.unlock(th_id);
        } 
    };
    
    std::thread th_1(add_by_thread, 1);
    std::thread th_0(add_by_thread, 0);

    th_1.join();
    th_0.join();
    
    std::cout << count << std::endl;

};

int main()
{
    trial(); 
    return 0;
}