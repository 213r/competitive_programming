#ifndef EXCLUSIVE_ACCESS_PETERSON
#define EXCLUSIVE_ACCESS_PETERSON

#include <atomic>
#include <array>

namespace exclusive_access {

    class PetersonAlgo {
    private:
        std::array<std::atomic_bool, 2> flag;
        std::atomic_int turn;
    public:
        PetersonAlgo() {
            flag[0] = false; flag[1] = false;
            turn = 0;
        }

        ~PetersonAlgo() = default;
    
        void lock(int id){
            flag[id] = true;
            int cid = 1 ^ id;
            turn = cid;
            while (flag[cid] && turn == cid) {}
        }

        void unlock(int id) {
            flag[id] = false;
        }
    };
}

#endif // EXCLUSIVE_ACCESS_PETERSON
