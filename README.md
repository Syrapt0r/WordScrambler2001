# WordScrambler2001
<p align="center">
  <img src="https://vignette.wikia.nocookie.net/poke5forum/images/d/d3/Missingno.jpg/revision/latest?cb=20160704182408&path-prefix=de" width=150 height="auto" /> <br>
  A (fairly simple) monoalphabetic substitution cipher
</p>

This cipher works by replacing every letter in a string with the corresponding letter in the key alphabet, adding a changing offset.

## Use cases
- no

## Installation
1. Contemplate your life choices
1. Download the repository using `git clone https://github.com/Syrapt0r/WordScrambler2001`
1. Open the project in your favourite IDE

## Usage
There are two ways to use the program.
#### Standalone Mode:
1. Compile and run the program.
1. Provide the message you want to encrypt.
1. Provide your key. If you leave this blank, a random key will be generated.
1. Enter your shifting values. They determine the way the algorithm shifts the individual letters.
1. Select a mode.
1. Select if your output should be Base64 encoded.
1. Select if you want to enable verbose logging

#### Command Line Mode:
Call the program using `WordScrambler2001.exe <parameters>`
##### Command Line Parameters:
Parameter|Optional Parameter|Meaning|Optional
---------|------------------|-------|--------
--encrypt|-e|Encryption Mode|No
--decrypt|-d|Decryption Mode|No
--message|-m|Message to en-/decrypt|No
--key|-k|Cipher Key|Yes
--initial-shift|-i|Initial Cipher Shift|No
--shift-value|-s|Cipher Shift Value|No
--base64|-b64|Whether Input/Output is in Base64|Yes
--verbose|-v|Activate verbose logging|Yes

## Roadmap
- [X] Add parameter mode
- [X] Add spaces / special characters
- [X] Add Base64 to parameter mode
- [X] Improve parameter mode overall
- [ ] Improve algorithm safety
