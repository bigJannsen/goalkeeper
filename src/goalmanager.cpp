#include "goalmanager.h"

void GoalManager::addGoal(int year, const std::string& text) {
    Goal g;

    g.year = year;
    g.text = text;
    g.done = false;

    goals.push_back(g);
}

void GoalManager::toggleGoal(int index) {
    if (index >= 0 && index < goals.size()) {
        goals[index].done = !goals[index].done;
    }
}

const std::vector<Goal>& GoalManager::getGoals() const {
    return goals;
}

std::vector<Goal> GoalManager::getGoalsByYear(int year) const {
    std::vector<Goal> filteredGoals;

    // Läuft durch jeden Eintrag und prüft ob gesuchtes Jahr == Jahr ist,
    // falls Übereinstimmung, dann geht Kopie in filteredGoals
    for(const auto& g : goals) {
        if (g.year == year) {
            filteredGoals.push_back(g);
        }
    }
    return filteredGoals;
}
// src/goalmanager.cpp (neu ergänzt)
int GoalManager::countGoals(int year) const {
    int count = 0;

    for (const auto& g : goals) {
        if (g.year == year) {
            ++count;
        }
    }

    return count;
}

int GoalManager::countCompletedGoals(int year) const {
    int count = 0;

    for (const auto& g : goals) {
        if (g.year == year && g.done) {
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