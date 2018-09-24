#include "config.hpp"
#include "utils.hpp"
#include <random>
#include <iostream>
#include <string>
#define UTILS_DEBUG 1
using std::cout;
using std::endl;
using std::uniform_real_distribution;
using std::uniform_int_distribution;

/// @brief class DebugPrint
void DebugPrint::SimplePrint(const string error_description, const int error_code, const int LOCAL_DEBUG)
{
    if(GLOBAL_DEBUG & LOCAL_DEBUG){
        cout<<error_description<<endl;
        cout<<"Judge Error Code: "<<error_code<<endl;
    }
}

/// @brief class RandomGenerate
RandomGenerate::RandomGenerate(){
    int tmp = time(0);
    current_seed = tmp;
    current_engine.seed(tmp);
}

RandomGenerate::RandomGenerate(int user_seed){
    current_seed = user_seed;
    current_engine.seed(user_seed);
}

void RandomGenerate::SetSeed(int user_seed){
    current_seed = user_seed;
    current_engine.seed(user_seed);
}

unsigned RandomGenerate::GetRandomUnsigned(unsigned min_limit, unsigned max_limit){
    uniform_int_distribution<unsigned> u(min_limit, max_limit);
    return u(current_engine);
}

int RandomGenerate::GetRandomInt(int min_limit, int max_limit){
    uniform_int_distribution<int> u(min_limit, max_limit);
    return u(current_engine);
}

double RandomGenerate::GetRandomDouble(double min_limit, double max_limit){
    uniform_real_distribution<double> u(min_limit, max_limit);
    return u(current_engine);
}

template<typename T> T RandomGenerate::GetMaxLimit(){
    return current_engine.max();
}

template<typename T> T RandomGenerate::GetMinLimit(){
    return current_engine.min();
}
