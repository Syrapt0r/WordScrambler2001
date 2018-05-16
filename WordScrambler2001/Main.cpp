#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "ScrambleFuncts.h"

#define MODE_ENCRYPT "-e"
#define MODE_DECRYPT "-d"
#define MODE_HELP "-help"


int main(int argc, char* argv[])
{
	//seed the randomizer
	std::srand(std::time(nullptr));

	//initialize variables and instances
	Scrambler scrambler;
	int shiftValue, initShift;
	std::string message, key, line;
	int mode;

	const int SPLASH_AMOUNT = 25;
	const char* splashs[SPLASH_AMOUNT] = {	"This is a splash message!", 
											"Completely random output!",
											"97% Bug Free!", 
											"Magic inside!", 
											"GOTO a", 
											"Where is my mind?", 
											"Snake? Snake! SNAAAAAKE!", 
											"Powered by C++!", 
											"Perfectly formatted source code!", 
											"EXTERMINATE!", 
											"This splash message will never appear! Wait...", 
											"Use a better encryption please!", 
											"Hello, World!", 
											"Hi Chris!", 
											"The most useless waste of HDD space!", 
											"Also try NodeScrambler2001!", 
											"Crazy letter manipulation!", 
											"Uses cstrings!", 
											"Also try DROP!", 
											"Also try Commodore Combat!", 
											"Half Life 3 confirmed!", 
											"AEIOU.", 
											"Shoutouts to SimpleFlips", 
											"[ REDACTED ]", 
											"https://www.youtube.com/watch?v=oHg5SJYRHA0"};
	std::string chosenSplash = splashs[rand() % SPLASH_AMOUNT];

	//read parameters
	if (argc <= 1) {
		//run in standalone mode
		std::cout <<	" __        __            _ ____                           _     _          ____   ___   ___  _ " << std::endl <<
						" \\ \\      / | _  _ __ __| / ___|  ___ _ __ __ _ _ __ ___ | |__ | | ___ _ _|___ \\ / _ \\ / _ \\/ |" << std::endl <<
						"  \\ \\ /\\ / / _ \\| \'__/ _` \\___ \\ / __| \'__/ _` | \'_ ` _ \\| \'_ \\| |/ _ | \'__|__) | | | | | | | |" << std::endl <<
						"   \\ V  V | (_) | | | (_| |___) | (__| | | (_| | | | | | | |_) | |  __| |  / __/| |_| | |_| | |" << std::endl <<
						"    \\_/\\_/ \\___/|_|  \\__,_|____/ \\___|_|  \\__,_|_| |_| |_|_.__/|_|\\___|_| |_____|\\___/ \\___/|_|" << std::endl << std::endl <<
						"Version 1.3.1, (c) 2018 Syrapt0r" << std::endl <<
						chosenSplash << std::endl <<

		//read parameters
		std::endl << "MESSAGE: ";
		getline(std::cin, line);
		message += line;
		std::cout << "KEY (leave blank for random): ";
		getline(std::cin, line);
		key += line;
		std::cout << "INITIAL SHIFT: ";
		std::cin >> initShift;
		std::cout << "SHIFT VALUE: ";
		std::cin >> shiftValue;
		std::cout << "MODE (0: Encrypt, 1: Decrypt): ";
		std::cin >> mode;

		//set scrambler parameters
		scrambler.setOffset(initShift);
		scrambler.setShiftValue(shiftValue);

		scrambler.addOffset(shiftValue);

		//generate key if no key was given
		if (key == "") {
			key = scrambler.getRandomKey();
		}
		scrambler.setKey(key);

		std::cout << std::endl;

		//OUTPUT
		std::cout	<< "################################" << std::endl << std::endl
					<< "MESSAGE:       " << message << std::endl
					<< "KEY:           " << key << std::endl
					<< "INITIAL SHIFT: " << initShift << std::endl
					<< "SHIFT VALUE:   " << shiftValue << std::endl;

		if (mode == 0) {
			std::cout << "MODE:          ENCRYPTION";
		}
		else if (mode == 1) {
			std::cout << "MODE:          DECRYPTION";
		}
		else {
			std::cout << "MODE:          This should be impossible to do but better safe than sorry";
		}

		std::cout << std::endl << std::endl << "OUTPUT: ";

		//encrypt / decrypt
		if (mode == 0) {
			for (int i = 0; i < message.length(); i++) {
				std::cout << scrambler.encryptLetter(message.at(i));
			}
		}
		else if (mode == 1) {
			for (int i = 0; i < message.length(); i++) {
				std::cout << scrambler.decryptLetter(message.at(i));
			}
		}
		else {
			std::cout << "Unrecognized mode parameter, aborting" << std::endl;
		}


		std::cout << std::endl << std::endl;

		system("PAUSE");
	}
	else {
		//run in parameter mode
		if (argc < 5) {
			if (strcmp(argv[1], MODE_HELP) == 0) {
				//show help
				std::cout	<< "                           WordScrambler2001 Help" << std::endl
							<< "------------------------------------------------------------------------------" << std::endl
							<< "Syntax: wordscrambler2001 <mode> <message> <key> <initial shift> <shift value>" << std::endl
							<< "Mode: -e for encrypt, -d for decrypt" << std::endl
							<< "Message: The message to encrypt/decrypt" << std::endl
							<< "Key: The cipher key (blank for random key)" << std::endl
							<< "Initial shift: The shift value to start with" << std::endl
							<< "Shift value: The value to shift each letter" << std::endl;

				return 0;
			}
			else {
				std::cout << "Invalid parameters. Use -help to see help." << std::endl;
				return 1;
			}
		}
		else {
			if (argc == 6) {				//key given
				message = argv[2];
				key = argv[3];
				initShift = atoi(argv[4]);
				shiftValue = atoi(argv[5]);
			}

			if (argc == 5) {				//no key given
				message = argv[2];
				key = "";
				initShift = atoi(argv[3]);
				shiftValue = atoi(argv[4]);
			}

			//set parameters
			scrambler.setOffset(initShift);
			scrambler.setShiftValue(shiftValue);
			scrambler.addOffset(shiftValue);

			if (key == "") {
				key = scrambler.getRandomKey();
				std::cout << key << "|";
			}

			scrambler.setKey(key);

			//encrypt / decrypt
			if (strcmp(argv[1], MODE_ENCRYPT) == 0) {
				for (int i = 0; i < message.length(); i++) {
					std::cout << scrambler.encryptLetter(message.at(i));
				}
			} 
			else if (strcmp(argv[1], MODE_DECRYPT) == 0) {
				for (int i = 0; i < message.length(); i++) {
					std::cout << scrambler.decryptLetter(message.at(i));
				}
			}
			else {
				std::cout << "Unrecognized operation.";
				return 1;
			}
		}
	}

    return 0;
}