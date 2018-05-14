#include "stdafx.h"
#include <iostream>
#include <cstdlib>
#include "ScrambleFuncts.h"

#define MODE_ENCRYPT "-e"
#define MODE_DECRYPT "-d"


int main(int argc, char* argv[])
{
	Scrambler scrambler;

	int shiftValue, initShift;
	std::string message, key, line;
	int mode;

	//read parameters
	if (argc <= 1) {
		//run in standalone mode
		std::cout <<	"#########################" << std::endl <<
						"### WordScrambler2001 ###" << std::endl <<
						"#########################" << std::endl <<
			std::endl << "MESSAGE: ";
		getline(std::cin, line);
		message += line;
		std::cout << "KEY: ";
		getline(std::cin, line);
		key += line;
		std::cout << "INITIAL SHIFT: ";
		std::cin >> initShift;
		std::cout << "SHIFT VALUE: ";
		std::cin >> shiftValue;
		std::cout << "MODE (0: Encrypt, 1: Decrypt): ";
		std::cin >> mode;

		//set parameters
		scrambler.setOffset(initShift);
		scrambler.setShiftValue(shiftValue);

		scrambler.addOffset(shiftValue);

		if (key != "") {
			scrambler.setKey(key);
		}

		system("cls");

		//OUTPUT
		std::cout << "########## PARAMETERS ##########" << std::endl
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
			std::cout << "Invalid parameters. Usage: wordscrambler2001 -m 'message' -k 'key' -i 'initial shift' -s 'shift' -a 'mode'" << std::endl;
			return 1;
		}
		else {
			message = argv[2];
			key = argv[3];
			initShift = atoi(argv[4]);
			shiftValue = atoi(argv[5]);

			//set parameters
			scrambler.setOffset(initShift);
			scrambler.setShiftValue(shiftValue);
			scrambler.addOffset(shiftValue);

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