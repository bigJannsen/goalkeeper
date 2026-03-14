#ifndef GOALKEEPER_GOALMANAGER_H
#define GOALKEEPER_GOALMANAGER_H

#include <vector>
#include <string>
#include "goal.h"

class GoalManager {
    private:
        std::vector<Goal> goals;

    public:
        void addGoal(int year, const std::string& text);
        void toggleGoal(int index);
        const std::vector<Goal>& getGoals() const;
        std::vector<Goal> getGoalsByYear(int year) const;
    };


#endif //GOALKEEPER_GOALMANAGER_H
