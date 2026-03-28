#ifndef GOALKEEPER_GOALMANAGER_H
#define GOALKEEPER_GOALMANAGER_H

#include <vector>
#include <string>
#include "goal.h"

class GoalManager {
private:
    std::vector<Goal> goals;
    int nextId = 1;

public:
    void addGoal(int year, const std::string& title, const std::string& details);

    void toggleGoalById(int id);

    bool deleteGoalById(int id);
    Goal* getGoalById(int id);
    const Goal* getGoalById(int id) const;
    bool updateGoalById(int id, int year, const std::string& title, const std::string& details);

    const std::vector<Goal>& getGoals() const;
    std::vector<Goal> getGoalsByYear(int year) const;
    std::vector<Goal> getFilteredGoals(int year, const std::string& searchText) const;

    int countGoals(int year) const;
    int countCompletedGoals(int year) const;
    float completionRate(int year) const;
};

#endif // GOALKEEPER_GOALMANAGER_H