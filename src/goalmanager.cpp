#include "goalmanager.h"

void GoalManager::addGoal(int year, const std::string& text) {
    Goal goal{nextId, year, text, false};
    ++nextId;
    goals.push_back(goal);
}

void GoalManager::toggleGoal(int index) {
    if (index < 0 || index >= static_cast<int>(goals.size())) {
        return;
    }

    toggleGoalById(goals[index].id);
}

void GoalManager::toggleGoalById(int id) {
    for (auto& goal : goals) {
        if (goal.id == id) {
            goal.done = !goal.done;
            return;
        }
    }
}

const std::vector<Goal>& GoalManager::getGoals() const {
    return goals;
}

std::vector<Goal> GoalManager::getGoalsByYear(int year) const {
    std::vector<Goal> filteredGoals;

    for (const auto& goal : goals) {
        if (goal.year == year) {
            filteredGoals.push_back(goal);
        }
    }

    return filteredGoals;
}

int GoalManager::countGoals(int year) const {
    int count = 0;

    for (const auto& goal : goals) {
        if (goal.year == year) {
            ++count;
        }
    }

    return count;
}

int GoalManager::countCompletedGoals(int year) const {
    int count = 0;

    for (const auto& goal : goals) {
        if (goal.year == year && goal.done) {
            ++count;
        }
    }

    return count;
}

float GoalManager::completionRate(int year) const {
    const int totalGoals = countGoals(year);

    if (totalGoals == 0) {
        return 0.0f;
    }

    const int completedGoals = countCompletedGoals(year);
    return static_cast<float>(completedGoals) / static_cast<float>(totalGoals);
}
