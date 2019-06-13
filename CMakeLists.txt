cmake_minimum_required(VERSION 3.13)
project(P_O_P_Main_Project C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(P_O_P_Main_Project
        config_loader/load_configs.c
        config_loader/load_map.c
        config_loader/load_settings.c
        game_console.h
        hide_cursor.c
        initialization.c
        main.c
        player_movement.c
        print_map.c
        random_gen.c
        "welcome screen.c" cd.c)
