#include <iostream>
#include "goalmanager.h"

using namespace std;

int main() {
    GoalManager manager;

    cout << boolalpha;

    manager.addGoal(2022, "10 Buecher lesen");
    manager.addGoal(2026, "Fitness steigern");
    manager.addGoal(2027, "C++ GUI App bauen");
    manager.addGoal(2027, "Mehr Sport machen");

    manager.toggleGoalById(2);

    vector<Goal> goals2026 = manager.getGoalsByYear(2026);

    cout << "Ziele fuer 2026:" << endl;
    cout << "----------------------" << endl;

    for (const auto& g : goals2026) {
        cout << "ID: " << g.id << endl;
        cout << "Jahr: " << g.year << endl;
        cout << "Ziel: " << g.text << endl;
        cout << "Erledigt: " << g.done << endl;
        cout << "----------------------" << endl;
    }

    return 0;
}
