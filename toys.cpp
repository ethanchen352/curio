#include "curio.h"
#include "toys.h"
#include <iostream>
#include <string>
#include <thread>

void animation() {
	std::string frames[]{ "-", "\\", "|", "/" };

	int i = 0;
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(100));

		if (i >= 3) { // change this
			i = 0;
		}
		else {
			i++;
		}

		if (!exit_thread) {
			std::cout << '\b';
			std::cout << frames[i];
		}
		else {
			std::cout << "exiting animation" << '\n';
			break;
		}
	}
}

void int2char() {
	std::cout << "input an integer and its character equivalent will be printed" << "\n";

	while (true) {
		std::string input = input_handler("int2char ");
		
		if (input == "exit") {
			std::cout << "exiting int2char" << '\n';
			break;
		}
		else {
			try {
				int ansi = std::stoi(input);
				std::cout << ansi << ": " << char(ansi) << '\n';
			}
			catch (std::invalid_argument) {
				std::cerr << "you might want to check your input" << '\n';
			}
		}
	}
}

void typer() {
	srand(time(NULL));
	std::cout << "press enter to stop" << '\n';

	char character = ' ';
	while (true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 80 + 80));

		if (rand() % 30 < 1) {
			std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 3000));
		}

		if (rand() % 60 < 1) {
			character = '\n';
		}
		else if (rand() % 5 < 1 && character != ' ' && character != '\n') {
			character = ' ';
		}
		else {
			character = char(rand() % 224 + 32);
		}

		if (!exit_thread) {
			std::cout << character;
		}
		else {
			std::cout << "exiting typer" << '\n';
			break;
		}
	}
}

void test() {
	std::cout << "here is a test line" << char(13);
	std::this_thread::sleep_for(std::chrono::milliseconds(2400));
}