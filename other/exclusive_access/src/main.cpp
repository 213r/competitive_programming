#include <thread>
#include <cassert>
#include <iostream>
#include "exclusive_access/example.hpp"
#include "exclusive_access/dekker.hpp"
#include "exclusive_access/peterson.hpp"
#include "exclusive_access/lamport.hpp"

template<typename ExcAcc> 
int calc_add(int n) {
    // exclusive_access::Example mutex;
    ExcAcc mutex;
    int critical = 0;
    int count = 0;
    int tot0 = n / 2;
    int tot1 = n - tot0;

    auto add_by_thread = [&mutex, &critical, &count](int th_id, int tot) {
        for (int i = 0; i < tot; ++i) {
            mutex.lock(th_id);
            // critical session starts.  
            ++critical; 
            ++count;
            // the two simultaneous critical session must be error.  
            // assert(critical < 2);
            --critical;
            // critical session ends.  
            mutex.unlock(th_id);
        } 
    };
    
    std::thread th_0(add_by_thread, 0, tot0);
    std::thread th_1(add_by_thread, 1, tot1);

    th_0.join();
    th_1.join();
    
    return count;

};

enum ExclusiveAccessMethod {
    Example = 0,
    DekkerAlgo = 1,
    PetrsonAlgo = 2,
    LamportBakeryAlgo = 3,
};

int main()
{
    int count = 0;
    std::cout << "Choose the method for exclusive access from 0(Example), 1(DekkerAlgo), 2(PersonAlgo) and 3(LamportBakeryAlgo)" << std::endl;
    int n_method;
    std::cin >> n_method; 
    std::cout << "Put the number of total count" << std::endl;
    int n;
    std::cin >> n; 
    if (n_method == ExclusiveAccessMethod::Example) {
        count = calc_add<exclusive_access::Example>(n);
    } else if (n_method == ExclusiveAccessMethod::DekkerAlgo){
        count = calc_add<exclusive_access::DekkerAlgo>(n);
    } else if (n_method == ExclusiveAccessMethod::PetrsonAlgo){
        count = calc_add<exclusive_access::PetersonAlgo>(n);
    } else if (n_method == ExclusiveAccessMethod::LamportBakeryAlgo){
        count = calc_add<exclusive_access::LamportBakeryAlgo<2>>(n);
    } else {
        std::cout << "Incorrect input." << std::endl; 
        return 0;
    }
    std::cout << "The calculated count is " << count << std::endl;
    return 0;
}