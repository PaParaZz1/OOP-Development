#ifndef UTILS_H_
#define UTILS_H_
#include <ctime>
#include <random>
#include <string>

using std::default_random_engine;
using std::string;

class RandomGenerate{
    public:
        RandomGenerate();
        explicit RandomGenerate(int user_seed);
        void SetSeed(int user_seed);
        unsigned GetRandomUnsigned(unsigned min_limit, unsigned max_limit);
        int GetRandomInt(int min_limit, int max_limit);
        double GetRandomDouble(double min_limit, double max_limit);
        template<typename T> T GetMaxLimit();
        template<typename T> T GetMinLimit();
    private:
        default_random_engine current_engine;
        int current_seed;
};

class DebugPrint{
    static void SimplePrint(const string str, const int error_code, const int LOCAL_DEBUG);
};
#endif // UTILS_H_
