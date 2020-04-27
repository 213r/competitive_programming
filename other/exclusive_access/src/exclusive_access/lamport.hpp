#ifndef EXCLUSIVE_ACCESS_LAMPORT
#define EXCLUSIVE_ACCESS_LAMPORT

#include <atomic>
#include <array>
#include <algorithm>

namespace exclusive_access {

    template<unsigned int N> 
    class LamportBakeryAlgo {
    private:
        std::array<std::atomic_bool, N> enter;
        std::array<std::atomic_int, N> pri;;
    public:
        LamportBakeryAlgo() {
            for (int i = 0; i < N; ++i) {
                enter[i] = false;
                pri[i] = 0;
            }
        }

        ~LamportBakeryAlgo() = default;
    
        void lock(int id){
            enter[id] = true;
            pri[id] = 1 + *std::max_element(pri.begin(), pri.end());
            enter[id] = false;

            for (int j = 0; j < N; ++j) {
                while (enter[j]) {};
                while ((pri[j] != 0) && 
                    ((pri[j] < pri[id]) || ((pri[j] == pri[id]) && (j < id)))) {};
            } 
        }

        void unlock(int id) {
            pri[id] = 0;;
        }
    };
}

#endif // EXCLUSIVE_ACCESS_LAMPORT