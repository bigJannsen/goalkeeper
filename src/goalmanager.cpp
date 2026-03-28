#include "goalmanager.h"

void GoalManager::addGoal(int year, const std::string& title, const std::string& details) {
    Goal goal{nextId, year, title, details, false};
    ++nextId;
    goals.push_back(goal);
}


void GoalManager::toggleGoalById(int id) {
    for (auto& goal : goals) {
        if (goal.id == id) {
            goal.done = !goal.done;
            return;
        }
    }
}

bool GoalManager::deleteGoalById(int id) {
    for (auto it = goals.begin(); it != goals.end(); ++it) {
        if (it->id == id) {
            goals.erase(it);
            return true;
        }
    }

    return false;
}

Goal* GoalManager::getGoalById(int id) {
    for (auto& goal : goals) {
        if (goal.id == id) {
            return &goal;
        }
    }

    return nullptr;
}

const Goal* GoalManager::getGoalById(int id) const {
    for (const auto& goal : goals) {
        if (goal.id == id) {
            return &goal;
        }
    }

    return nullptr;
}

bool GoalManager::updateGoalById(int id, int year, const std::string& title, const std::string& details) {
    Goal* goal = getGoalById(id);

    if (goal == nullptr) {
        return false;
    }

    goal->year = year;
    goal->title = title;
    goal->details = details;
    return true;
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

std::vector<Goal> GoalManager::getFilteredGoals(int year, const std::string& searchText) const {
    std::vector<Goal> filteredGoals;

    for (const auto& goal : goals) {
        if (goal.year != year) {
            continue;
        }

        if (searchText.empty()) {
            filteredGoals.push_back(goal);
            continue;
        }

        if (goal.title.find(searchText) != std::string::npos ||
            goal.details.find(searchText) != std::string::npos) {
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

