cmake_minimum_required(VERSION 3.23)
project(floodit)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(CMAKE_PREFIX_PATH "/home/jussymi/Qt/6.3.1/gcc_64/lib/cmake")

find_package(Qt6 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(floodit main.cpp model/board.cpp model/board.h
        model/game.cpp model/game.h controller/application.cpp
        controller/application.h gui/game_info.cpp gui/game_info.h
        gui/game_info.ui gui/floodit_gui.cpp gui/floodit_gui.h
        gui/floodit_gui.ui gui/color_button.cpp gui/color_button.h)
target_link_libraries(floodit
        Qt::Core
        Qt::Gui
        Qt::Widgets
        )

