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