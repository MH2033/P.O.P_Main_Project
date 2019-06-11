cmake_minimum_required(VERSION 3.14)
project(P_O_P_Main_Project C)

set(CMAKE_C_STANDARD 99)

add_executable(P_O_P_Main_Project main.c config_loader/load_configs.c game_console.h config_loader/load_map.c config_loader/load_settings.c random_gen.c initialization.c print_map.c hide_cursor.c player_movement.c)