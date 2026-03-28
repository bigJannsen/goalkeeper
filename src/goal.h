#ifndef GOALKEEPER_GOAL_H
#define GOALKEEPER_GOAL_H

#include <string>

struct Goal {
    int id;
    int year;
    std::string title;
    std::string details;
    bool done;
};

#endif //GOALKEEPER_GOAL_H