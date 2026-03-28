#include <cmath>
#include <memory>

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <slint.h>
#include "app-window.h"
#include "goalmanager.h"

int main() {
/*
        slint::platform::set_window_scale_factor(1.0f); // optional override
        auto app = AppWindow::create();
        app->run();

        SetProcessDPIAware();
        auto app = AppWindow::create();
        app->run;
*/

    GoalManager manager;

    manager.addGoal(2022, "10 Buecher lesen");
    manager.addGoal(2026, "Fitness steigern");
    manager.addGoal(2027, "C++ GUI App bauen");
    manager.addGoal(2027, "Mehr Sport machen");
    manager.toggleGoalById(2);

    auto ui = AppWindow::create();
    int selectedYear = 2026;

    const auto refreshUi = [&]() {
        std::vector<GoalRow> rows;

        const std::vector<Goal> goals = manager.getGoalsByYear(selectedYear);
        rows.reserve(goals.size());

        for (const Goal& goal : goals) {
            rows.push_back(GoalRow{goal.id, slint::SharedString(goal.text), goal.done});
        }

        auto goalModel = std::make_shared<slint::VectorModel<GoalRow>>(std::move(rows));

        ui->set_goal_items(goalModel);
        ui->set_current_year(selectedYear);

        const int totalGoals = manager.countGoals(selectedYear);
        const int completedGoals = manager.countCompletedGoals(selectedYear);
        const float completionRate = std::round(manager.completionRate(selectedYear) * 1000.0f) / 1000.0f;

        ui->set_total_goals(totalGoals);
        ui->set_completed_goals(completedGoals);
        ui->set_completion_rate(completionRate);
    };

    ui->on_add_goal([&](const slint::SharedString& text) {
        const std::string goalText(text.begin(), text.end());

        if (!goalText.empty()) {
            manager.addGoal(selectedYear, goalText);
            refreshUi();
        }
    });

    ui->on_year_changed([&](int year) {
        selectedYear = year;
        refreshUi();
    });

    refreshUi();
    ui->run();

    return 0;
}
