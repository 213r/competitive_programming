#include <thread>
#include <vector>
#include <cassert>
#include <iostream>
#include <string>

class ExclusiveAccessByTwoProcess {
private:
    std::vector<bool> flag;
    int turn;

    int count;
    int critical;

    inline void log(char a, int i) {
        std::string log = &a; 
        std::cout << i << ":";
        std::cout << a << ":";
        std::cout << this->turn;
        std::cout << std::endl;
    }
public:
    ExclusiveAccessByTwoProcess() : flag(2, false), turn(0), count(0), critical(0) {}

    void exclusive_acess(int i, int loop) {
        this->flag[i] = true;
        while (this->turn != i) {
            while (this->flag[1-i]) {} 
            this->turn = i;
        }
        // P0 now has exclusive access, critical code section here
        ++critical;
        assert(critical < 2);
        --critical;
        
        this->flag[i] = false;
    }
    int get_count() {return this->count;}

    ~ExclusiveAccessByTwoProcess() = default;
};


void trial() {
    auto ptr = std::make_unique<ExclusiveAccessByTwoProcess>(); 
    std::thread th_b(&ExclusiveAccessByTwoProcess::exclusive_acess, std::ref(*ptr), 1, 1E3);
    std::thread th_a(&ExclusiveAccessByTwoProcess::exclusive_acess, std::ref(*ptr), 0, 1E9);

    th_a.join();
    th_b.join();

    //std::cout << ptr->get_count() << std::endl;

};

int main()
{
    for (int i = 0; i < int(1E8); ++i) {
        trial(); 
    } 
    return 0;
}