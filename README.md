Security System
This repository contains a simple C++ program that simulates a basic security system. Users can register, log in, and change their passwords. The program stores user information in a file named file.txt.

Features
Registration: Users can register with a username, password, and age. This information is saved in the file.txt file.

Login: Registered users can log in with their username and password. The program checks the provided credentials against the stored information in the file.txt file.

Change Password: Logged-in users can change their passwords. The program verifies the old password before allowing the change.

How to Use

Clone this repository to your local machine:

git clone https://github.com/your-username/security-system.git

Navigate to the repository's directory:

cd security-system

Compile the code using a C++ compiler:

g++ System.cpp -o security-system

Run the compiled program:

./security-system
Follow the on-screen instructions to register, log in, and change passwords.
Requirements
A C++ compiler (e.g., g++)
Standard C++ library
The program uses the <iostream>, <fstream>, <sstream>, and <string> standard C++ headers.
Notes
This is a simple illustrative program and not meant for production use.
The user data is stored in the file.txt file in plain text, which is not secure. In a real-world scenario, you would want to use proper encryption and security practices for storing user data.
Feel free to use, modify, or extend this code for your learning purposes.
