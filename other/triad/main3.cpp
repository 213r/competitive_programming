#include <thread>
#include <vector>
#include <cassert>
#include <iostream>
#include <string>

class ExclusiveAccessExp {

private:
    std::vector<bool> flag;
    int turn;
    int critical;

    int count;
    

public:
    ExclusiveAccessExp() : flag(2, false), turn(0), critical(0), count(0) {}
    ~ExclusiveAccessExp() = default;

    void exclusive_acess(int i){
        flag[i] = true;
        while (turn != i) {
            while (flag[1-i]) {} 
            turn = i;
        }
        // critical code section start 
        ++critical;
    
        // the two simultaneous critical session must be error.  
        assert(critical < 2);
        ++count;
        
        --critical;
        // critical code section end 
        flag[i] = false;
    }

    void add_count_by_thread(int th_id) {
        for (int i = 0; i < int(1E4); ++i)  {
            exclusive_acess(th_id);
        }
    }

    void calc() {
        std::thread th_1(&ExclusiveAccessExp::add_count_by_thread, this, 1);
        std::thread th_0(&ExclusiveAccessExp::add_count_by_thread, this, 0);
        th_1.join();
        th_0.join();
        std::cout << count << std::endl;
    }
};

int main()
{
    ExclusiveAccessExp obj;
    obj.calc();
    return 0;
}