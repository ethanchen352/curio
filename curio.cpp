#include "curio.h"
#include "toys.h"
#include <atomic>
#include <chrono>
#include <iostream>
#include <string>
#include <thread>

std::atomic<bool> exit_thread{ false };

void exit_curio() {
	std::cout << '\n' << "goodbye";
	std::this_thread::sleep_for(std::chrono::seconds(1));
	exit(0);
}

void initialize() {
	std::cout << "\x1b]0;" << "curio" << "\x07";
	std::cout << "hello world" << '\n';
}

std::string input_handler(std::string prompt) {
	std::string input{};
	std::cout << '\n' << prompt << "> ";
	std::getline(std::cin, input);

	return input;
}

void run_command(std::string command) {
	if (command == "exit") {
		exit_curio();
	}
	else if (command == "animation") {
		std::thread th(animation);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		exit_thread = true;
		th.join();
		exit_thread = false;
	}
	else if (command == "int2char") {
		int2char();
	}
	else if (command == "test") {
		test();
	}
	else if (command == "typer") {
		std::thread th(typer);
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		exit_thread = true;
		th.join();
		exit_thread = false;
	}
	else {
		std::cout << "i don't understand" << '\n';
	}
}