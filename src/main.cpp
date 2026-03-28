#include <cmath>
#include <memory>
#include <string>
#include <vector>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

#include <slint.h>
#include "app-window.h"
#include "goalmanager.h"

int main() {
    GoalManager manager;

    manager.addGoal(2022, "10 Buecher lesen", "Jeden Monat mindestens ein Buch lesen.");
    manager.addGoal(2026, "Fitness steigern", "Zwei- bis dreimal pro Woche trainieren.");
    manager.addGoal(2027, "C++ GUI App bauen", "Goalkeeper mit sauberer Slint-Oberflaeche fertigstellen.");
    manager.addGoal(2027, "Mehr Sport machen", "Mehr Bewegung in den Alltag einbauen.");
    manager.toggleGoalById(2);

    auto ui = AppWindow::create();
    int selectedYear = 2026;

    const auto refreshUi = [&]() {
        std::vector<GoalRow> rows;

        std::string searchText;
        {
            auto slintSearchText = ui->get_search_text();
            searchText = std::string(slintSearchText.begin(), slintSearchText.end());
        }

        const std::vector<Goal> goals = manager.getFilteredGoals(selectedYear, searchText);
        rows.reserve(goals.size());

        for (const Goal& goal : goals) {
            rows.push_back(GoalRow{
                    goal.id,
                    slint::SharedString(goal.title),
                    slint::SharedString(goal.details),
                    goal.done,
                    slint::SharedString(goal.done ? "Erledigt" : "Offen")
            });
        }

        auto goalModel = std::make_shared<slint::VectorModel<GoalRow>>(rows);

        ui->set_goal_items(goalModel);
        ui->set_current_year(selectedYear);

        const int totalGoals = manager.countGoals(selectedYear);
        const int completedGoals = manager.countCompletedGoals(selectedYear);
        const float completionRate =
                std::round(manager.completionRate(selectedYear) * 1000.0f) / 1000.0f;

        ui->set_total_goals(totalGoals);
        ui->set_completed_goals(completedGoals);
        ui->set_completion_rate(completionRate);
    };

    ui->on_add_goal([&](const slint::SharedString& text) {
        const std::string goalTitle(text.begin(), text.end());

        if (!goalTitle.empty()) {
            manager.addGoal(selectedYear, goalTitle, "");
            refreshUi();
        }
    });

    ui->on_year_changed([&](int year) {
        selectedYear = year;
        refreshUi();
    });

    ui->on_request_toggle_status([&](int id) {
        manager.toggleGoalById(id);
        refreshUi();
    });

    ui->on_search_text_changed([&]() {
        refreshUi();
    });

    refreshUi();
    ui->run();

    return 0;
}