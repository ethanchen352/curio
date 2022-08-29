#pragma once

#include <atomic>
#include <iostream>

extern std::atomic<bool> exit_thread;

void exit_curio();
void initialize();
std::string input_handler(std::string prompt = "");
void run_command(std::string command);
void test();