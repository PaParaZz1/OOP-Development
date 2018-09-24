#ifndef DATA_TEMPLATE_H_
#define DATA_TEMPLATE_H_
#include <string>
#include <vector>
#include <map>

using std::string;
using std::vector;
using std::map;

class GlobalDataTemplate{
    public:
        GlobalDataTemplate();
    private:
};

typedef enum{
    FLOAR_REQUEST,
    ELEVATOR_REQUEST
}requset_type_t;
typedef map<int, requset_type_t> request_type_map_t;

typedef enum{
    UP,
    DOWN
}request_direction_t;
typedef map<int, request_direction_t> request_direction_map_t;

class ElevatorInstructionTemplate : public GlobalDataTemplate{
    public:
        ElevatorInstructionTemplate();
        ElevatorInstructionTemplate(int min_floor, int max_floor, int elevator_numbers, double run_floor_time = 0.5);
        int GetMinFloor();
        int GetMaxFloor();
        int GetElevatorNumbers();
        string GetSingleInstruction();
        vector<string> GetMultipleInstruction(int numbers, bool is_same_time);
    private:
        int min_floor;
        int max_floor;
        int elevator_numbers;
        double init_time;
        double current_time;
        double run_floor_time;
        request_direction_map_t request_direction_map;
        request_type_map_t request_type_map;
        const int direction_number = 2;
        const int type_number = 2;
        void InitMap(){
            request_type_map[0] = FLOAR_REQUEST;
            request_type_map[1] = ELEVATOR_REQUEST;
            request_direction_map[0] = UP;
            request_direction_map[1] = DOWN;
        }
};
#endif // DATA_TEMPLATE_H_
