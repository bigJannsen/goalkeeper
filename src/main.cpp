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

    manager.toggleGoal(1);

    vector<Goal> goals2026 = manager.getGoalsByYear(2026);

    cout << "Ziele fuer 2026:" << endl;
    cout << "----------------------" << endl;

    for (const auto& g : goals2026) {
        cout << "Jahr: " << g.year << endl;
        cout << "Ziel: " << g.text << endl;
        cout << "Erledigt: " << g.done << endl;
        cout << "----------------------" << endl;
    }

    return 0;
}


/*
 *  GUI hinzufügen
 *  Statistiken:
 *  Wie viele Ziele?
 *  Wie viele abgeschlossen?
 *  Prozentwerte / Diagramme usw.
 *
 *  Evtl. bei Geld Summen angeben und summieren
 *
 */