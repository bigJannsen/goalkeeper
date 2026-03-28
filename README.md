Goalkeeper

A lightweight desktop app for tracking yearly goals – built with C++ +
Slint UI.

------------------------------------------------------------------------

🚀 Current State (Phase 2)

Implemented features:

-   Create goals
-   Toggle goal status (Done / Open)
-   Year-based filtering
-   Search (live filtering)
-   Expandable goal details
-   Basic statistics (total, completed, progress)
-   Clean UI layout with sidebar navigation

------------------------------------------------------------------------

🧠 Architecture Overview

-   C++ (Core Logic)
    -   GoalManager handles all business logic
    -   ID-based operations
-   Slint (UI)
    -   Reactive UI via properties + callbacks
    -   GoalRow model

------------------------------------------------------------------------

🔧 Tech Stack

-   C++20
-   Slint
-   CMake

------------------------------------------------------------------------

📦 Build

cmake -B build cmake –build build

------------------------------------------------------------------------

🗺️ Roadmap

Phase 3 – Dialog System - Create Goal Dialog - Edit Goal Dialog - Delete
Confirmation

Phase 4 – UX - Improve search UX - Highlight matches - Empty states

Phase 5 – Persistence - Save/load goals

Phase 6 – Advanced - Tags - Deadlines

------------------------------------------------------------------------

⚠️ Known Issues

-   No persistence yet
-   Simple search

------------------------------------------------------------------------

📌 Next Step

Implement dialog system
