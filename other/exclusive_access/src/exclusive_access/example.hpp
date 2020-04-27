#ifndef EXCLUSIVE_ACCESS_EXAMPLE
#define EXCLUSIVE_ACCESS_EXAMPLE

#include <atomic>
#include <array>

namespace exclusive_access {

    class Example {
    private:
        std::array<std::atomic_bool, 2> flag;
        std::atomic_int turn;
    public:
        Example() {
            flag[0] = false; flag[1] = false;
            turn = 0;
        }

        ~Example() = default;
    
        void lock(int id){
            flag[id] = true;
            while (turn != id) {
                while (flag[1^id]) {} 
                turn = id;
            }
        }
    
        void unlock(int id) {
            flag[id] = false;
        }
    };
}
#endif //EXCLUSIVE_ACCESS_EXAMPLE