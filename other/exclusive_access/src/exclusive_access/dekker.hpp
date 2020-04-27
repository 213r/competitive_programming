#ifndef EXCLUSIVE_ACCESS_DEKKER
#define EXCLUSIVE_ACCESS_DEKKER

#include <atomic>
#include <array>

namespace exclusive_access {

    class DekkerAlgo {
    private:
        std::array<std::atomic_bool, 2> flag;
        std::atomic_int turn;
    public:
        DekkerAlgo() {
            flag[0] = false; flag[1] = false;
            turn = 0;
        }

        ~DekkerAlgo() = default;
    
        void lock(int id){
            flag[id] = true;
            while (flag[1^id]) {
                if (turn != id) {
                    flag[id] = false;
                    while (turn != id) {}
                    flag[id] = true;
                }
            }
        }

        void unlock(int id) {
            turn = 1^id;
            flag[id] = false;
        }
    };
}

#endif // EXCLUSIVE_ACCESS_DEKKER
