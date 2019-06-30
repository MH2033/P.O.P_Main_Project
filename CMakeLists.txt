cmake_minimum_required(VERSION 3.13)
project(P_O_P_Main_Project C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-pthread -lpdcurses")
include_directories(.)

add_executable(P_O_P_Main_Project
        config_loader/load_configs.c
        config_loader/load_map.c
        config_loader/load_settings.c
        core_functions/cd.c
        core_functions/delay.c
        movement/move_player.c
        movement/player_movement.c
        game_console.h
        initialization.c
        main.c
        print_map.c
        put_dblock.c
        random_gen.c
        run_game.c
        "welcome screen.c" movement/move_comp.c
        FindCloseFood.c END_GAME.c A_I.c show_start_window.c show_pause_window.c
        raindeath.c
        debug.c
        core_functions/cleanup.c attack.c keyboard_handle.c main_menu.c)

target_link_libraries(P_O_P_Main_Project ${CMAKE_SOURCE_DIR}/pdcurses.a)
target_link_libraries(P_O_P_Main_Project ${CMAKE_SOURCE_DIR}/bass.lib)