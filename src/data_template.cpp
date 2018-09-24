#include "data_template.hpp"
#include "config.hpp"
#include "utils.hpp"
#include <string>
#include <vector>
#define DATA_TEMPLATE_DEBUG 1

using std::string;
using std::vector;
/// @brief class GlobalTemplate
GlobalDataTemplate::GlobalDataTemplate(){

}

/// @brief class ElevatorInstructionTemplate

ElevatorInstructionTemplate::ElevatorInstructionTemplate()
{
    min_floor = 1;
    max_floor = 10;
    elevator_numbers = 1;
    init_time = 0.;
    current_time = init_time;
    run_floor_time = 0.5;
    InitMap();
}

ElevatorInstructionTemplate::ElevatorInstructionTemplate(int min_floor, int max_floor, int elevator_numbers, double run_floor_time)
{
    this->min_floor = min_floor;
    this->max_floor = max_floor;
    this->elevator_numbers = elevator_numbers;
    init_time = 0.;
    current_time = init_time;
    this->run_floor_time = run_floor_time;
    InitMap();
}

inline int ElevatorInstructionTemplate::GetMinFloor()
{
    return min_floor;
}

inline int ElevatorInstructionTemplate::GetMaxFloor()
{
    return max_floor;
}

string ElevatorInstructionTemplate::GetSingleInstruction()
{
    using std::to_string;
    string instruction;
    RandomGenerate generator;
    instruction.append("[");
    instruction.append(to_string(request_type_map[generator.GetRandomInt(0, 10) % type_number]));
    instruction.append(",");
    instruction.append(to_string(generator.GetRandomInt(min_floor, max_floor)));
    instruction.append(",");
    instruction.append(to_string(generator.GetRandomInt(0, 10)*run_floor_time));
    instruction.append("]");
    return instruction;
}
//vector<string> 
