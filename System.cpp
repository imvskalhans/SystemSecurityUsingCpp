#include<iostream>
#include<fstream>  //for  files
#include<sstream>  //for templates and types that enables inter operation between string buffer and string objects
#include<string>
#include <limits> // Including this header for numeric_limits
using namespace std;

int main()
{
    int choice, i = 0;
    string text, oldpass, passchange1, passchange2, passlogin, userreg, passreg, age, userlogin, word, word1;
    string creds[2], cp[2];

    cout << endl
         << endl;

    cout << "       Security System " << endl;
    cout << "____________________________________" << endl
         << endl;
    cout << "|            1.Register            |" << endl;
    cout << "|            2.Login               |" << endl;
    cout << "|            3.Change Password     |" << endl;
    cout << "|            4.End Program         |" << endl;
    cout << "____________________________________" << endl;

    do{
        cout << endl
        << endl
        << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
        case 1:
        {
            cout << "_______________________________________" << endl
                 << endl;
            cout << "|-----------Registeration-------------|" << endl;
            cout << "_______________________________________" << endl
                 << endl;

            cout << "Please enter your username: ";
            cin >> userreg;

            // Check if the username is empty
            if (userreg.empty())
            {
                cout << "Username cannot be empty. Registration failed." << endl;
                break;
            }

            cout << "Please enter your password: ";
            cin >> passreg;

            // Check if the password is empty
            if (passreg.empty())
            {
                cout << "Password cannot be empty. Registration failed." << endl;
                break;
            }

            cout << "Please enter your age: ";
            cin >> age;

            // Check if age input is valid
            if (cin.fail() || age.find_first_not_of("0123456789") != string::npos)
            {
                cout << "Invalid age input. Registration failed." << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                break;
            }

            ofstream of1("file.txt");
            if (of1.is_open())
            {
                of1 << userreg << "\n";
                of1 << passreg << "\n";
                of1 << age << "\n";
                cout << "Registration Successful" << endl;
            }
            else
            {
                cout << "Failed to open file for writing. Registration failed." << endl;
            }
            break;
        }

            case 2:{
                i = 0;

                cout << "____________________________________" << endl
                     << endl;
                cout << "|-------------Login----------------|" << endl;
                cout << "____________________________________" << endl
                << endl;

                ifstream of2("file.txt");
                if (!of2.is_open())
                {
                cout << "Failed to open file for reading. Login failed." << endl;
                break;
                }


                cout << "Please enter your username:- ";
                cin >> userlogin;

                cout << "Please enter your Passcode:- ";
                cin >> passlogin;

                if(of2.is_open()){
                    while(!of2.eof())  //using end of file function
                    {
                        while(getline(of2, text)){      //to read the file line by line
                            istringstream iss(text);    //stream the string and store it using extraction operator
                            iss >> word;
                            creds[i] = word;
                            i++;
                        }

                        if(userlogin==creds[0] && passlogin==creds[1])
                        {
                            cout << endl
                                 << endl;
                            cout << "----------Login Succesfull------------" << endl
                            << endl
                            << endl;

                            cout << "Details: " << endl;
                            cout << "Username: " + userreg << endl;
                            cout << "Password " + passreg << endl;
                            cout << "Age: " + age << endl;
                        }

                        else{   
                            cout << endl
                                 << endl;

                            cout << "Incorrect Credentials" << endl;
                            cout << "_____________________________________________" << endl;
                            cout << "|         1.Press 2 to Login                |" << endl;
                            cout << "|         2.Press 3 to Change Password      |" << endl;
                            cout << "_____________________________________________" << endl;
                            break;
                        }
                    }
                }
                break;
            }

            case 3:
            {
                i = 0;
                cout << "---------Change Password----------" << endl;

                ifstream of0;
                of0.open("file.txt");
                cout << "Enter the old passcode:- ";
                cin >> oldpass;

                if (of0.is_open())
                {
                    while (getline(of0, text))
                    {
                        istringstream iss(text);
                        iss >> word1;
                        cp[i] = word1;
                        i++;
                    }

                    if (oldpass == cp[1])
                    {
                        of0.close();

                        ofstream of1;
                        of1.open("file.txt");
                        if (of1.is_open())
                        {
                            cout << "Enter your new password: ";
                            cin >> passchange1;

                            cout << "Enter your new password again: ";
                            cin >> passchange2;

                            if (passchange1 == passchange2)
                            {
                                of1 << cp[0] << "\n";
                                of1 << passchange1;
                                cout << "Password changed successfully :)" << endl;
                            }
                            else
                            {
                                of1 << cp[0] << "\n";
                                of1 << oldpass;
                                cout << "Password do not match" << endl;
                            }
                        }
                        else
                        {
                            cout << "Failed to open file for writing." << endl;
                        }
                    }
                    else
                    {
                        cout << "Please enter a valid password" << endl;
                    }
                }
                else
                {
                    cout << "Failed to open file for reading." << endl;
                }
                break;
            }

            case 4:
            {
                cout << "__________Thank You ! :)_____________" << endl;
                break;
            } 
            default:{
                cout << "Enter a valid choice";
            }
        }
    } while (choice != 4);
}