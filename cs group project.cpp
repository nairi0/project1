// Mesk Alsultan 2230004728
// Shahad Al Swiket 2230006322
// Raya Ghazi Al-harbi 2230005278
// Forat sadiq Alabbas 2230001270

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

struct memberinfo {
    string username;
    double weight;
    double height;
    char sex;
    int age;
    int schedule;
    int weekdays;
};

void newMember();

void healthCalc();
void membershipProgram();

double bmiCal(double height, double weight);

int searchMember(memberinfo users[], string keyname);

void weightLoss ();
void weightGain ();

char startQ;


double calorieCalculation (char sex, double height, double weight, int age);

memberinfo users[10];
int userNum = 0;
errorLoop=0

int main()
{
    char programQ;
    int exitQ = 1;
    
    cout << "Welcome to FlexFit Gym program!";
    
    do {
        do{
            cout<<"\n\nAre you using the program for health calculations (C), or to sign up for membership (M)?: ";
            cin>>programQ;
        
            switch (programQ) {
                case 'c':
                case 'C':
                healthCalc();
                errorLoop=0;
                break;
                
                case 'm':
                case 'M':
                membershipProgram();
                errorLoop=0;
                break;
                
                default:
                errorLoop=1;
                cout<<"\nPlease only enter C or M.";
            
            }
        }while (errorLoop==1);
        
        cout << "\n\nTo go back to main menu, type a positive number. To type, write 0: ";
        cin>>exitQ;
    
    } while (exitQ > 0);
    
    return 0;
}








double bmiCal(double height, double weight) {
    if (height<5) {
        height= height*100;
    }
    double bmi = weight / pow((height / 100), 2);
    return bmi;
}

void newMember() {
    cout << "\n\nWhat is your name?: ";
    cin >> users[userNum].username;
    cout << "Are you M or F?: ";
    cin >> users[userNum].sex;
    cout << "How much do you weigh in kg?: ";
    cin >> users[userNum].weight;
    cout << "What is your height in cm?: ";
    cin >> users[userNum].height;
    cout<<"What is your age?: ";
    cin>> users[userNum].age;
}

int searchMember(memberinfo users[], string keyname) {
    char searchconfirm;
    for (int i = 0; i < 10; i++) {
        if (users[i].username == keyname) {
            do {
                cout << "\nAre you " << users[i].username << ", sex " << users[i].sex << "? (y/n): ";
                cin >> searchconfirm;
                
                switch (searchconfirm) {
                    case 'Y':
                    case 'y':
                        userNum = i;
                        searchconfirm = 'Y';
                        errorLoop=0;
                        break;
                        
                    case 'n':
                    case 'N':
                        searchconfirm = 'N';
                        errorLoop=0;
                        break;
                        
                    default:
                        cout << "Please only write y for yes and n for no.\n";
                        errorLoop=1;
                        break;
                }
            } while (errorLoop==1);
        }
    }
    
    if (userNum == -1) {
        char newmemberQ;
        cout << "User cannot be found, do you want to create a new user? (y/n): ";
        cin >> newmemberQ;

        if (newmemberQ == 'y' || newmemberQ == 'Y') {
            // newMember();
        }
    }
    
    return userNum;
}

void weightLoss () {
    cout<<"\nTo lose weight, a diet with less carb is recommended.\n\nTo get the most out of the diet and to find the right excercise for you, we advise you to sign up for our gym membership.";
}

void weightGain () {
    cout<<"\nTo lose weight, a diet with more protein is recommended.\n\nTo get the most out of the diet and to find the right excercise for you, we advise you to sign up for our gym membership.";
}

double calorieCalculation (char sex, double height, double weight, int age) {
    double calorieresult;
    if (sex == 'F' || sex == 'f') {
        calorieresult = (age*4.7) - (height * 1.8) + (weight*9.6) +655;
    }
    else {
        calorieresult = (age*6.8) - (height * 5) + (weight*13.7) +66;
    }
    
    return calorieresult;
}

void healthCalc() {
    char metaQ;
    char weightchoice;
    do {
        cout << "\n\nNew member (N) or already existing? (A): ";
        cin >> startQ;
        
        switch (startQ) {
            case 'a':
            case 'A':
                startQ = 'A';
                errorLoop=0;
                break;
                
            case 'n':
            case 'N':
                startQ = 'N';
                errorLoop=0;
                break;
                
            default:
                cout << "\nPlease enter the letter N for new or A for already existing.";
                errorLoop=1;
                break;
        }
    } while (errorLoop==1);
    
    if (startQ == 'N') {
        userNum++;
        cout << "Please enter your information:";
        newMember();
        
        double bmi = bmiCal(users[userNum].height, users[userNum].weight);
        
        if (bmi < 18.5) {
            cout << "You are underweight, it is advised to gain more.";
            weightLoss();
        }
        else if (bmi >= 18.5 && bmi < 25) {
            do {
                cout << "You have a perfect weight. What do you want to do, (G) gain weight or (L) lose weight? ";
                cin >> weightchoice;
        
                switch (weightchoice) {
                    case 'g':
                    case 'G':
                        weightGain();
                        errorLoop=0;
                        break;
                
                    case 'l':
                    case 'L':
                        weightLoss();
                        errorLoop=0;
                        break;
                
                    default:
                        cout << "\nPlease enter the letter G for gain or L for loss.";
                        errorLoop=1;
                        break;
                }
            } while (errorLoop==1);
        }
        else if (bmi >= 25 && bmi < 30) {
            cout << "You are overweight.";
            weightLoss();
        }
        else if (bmi >= 30 && bmi < 35) {
            cout << "You are first degree obese, it is advised to lose weight.";
            weightLoss();
        }
        else if (bmi >= 35 && bmi < 40) {
            cout << "You are second degree obese, it is advised to lose weight.";
            weightLoss();
        }
        else if (bmi >= 40) {
            cout << "You are excessively obese, you must lose weight for your health.";
            weightLoss();
        }
        
        do {
            cout<<"\n\nWould you like to know your metabolic rate and recommended calories ? (y/n): ";
            cin>>metaQ;
            
            switch (metaQ) {
                case 'y':
                case 'Y':
                    cout<<"\nYour metabolic rate is: "<< calorieCalculation(users[userNum].sex, users[userNum].height, users[userNum].weight, users[userNum].age);
                    cout<<"\n\nThe amount of recommended calorie intake is: "<<(calorieCalculation(users[userNum].sex, users[userNum].height, users[userNum].weight, users[userNum].age)*1.55);
                    errorLoop=0;
                    break;
                
                case 'n':
                case 'N':
                    cout<<"\nConfirmed.";
                    errorLoop=0;
                    break;
                
                default:
                    cout<<"\nPlease only enter y or n.";
                    errorLoop=1;
                    break;
            }
        } while (errorLoop==1);
        
    }
    else {
        string searchName;
        cout << "Enter your name to search for: ";
        cin >> searchName;
        
        int foundUser = searchMember(users, searchName);
        
        if (foundUser == -1) {
            cout << "User not found.";
        }
        else {
            // Code for existing user options
        }
    }
}

void membershipProgram() {
    int errorSched=0;
    do {
        cout << "\n\nNew member (N) or already existing? (A): ";
        cin >> startQ;
        
        switch (startQ) {
            case 'a':
            case 'A':
                startQ = 'A';
                errorLoop=0;
                break;
                
            case 'n':
            case 'N':
                startQ = 'N';
                errorLoop=0;
                break;
                
            default:
                cout << "\nPlease enter the letter N for new or A for already existing.";
                errorLoop=1;
                break;
        }
    } while (errorLoop==1);
    
    if (startQ == 'N') {
        userNum++;
        cout << "Please enter your information:";
        newMember();
        cout<<"\n\nHere's our offered subscriptions:\nMonths\tPrice\n3\t600\n6\t1300\n12\t3000";
        do {
            cout<<"\n\nPlease choose from the options (3, 6, 12): ";
            cin>>users[userNum].schedule;
            switch (users[userNum].schedule) {
                case 3:
                case 6:
                case 12:
                errorLoop=0;
                cout<<"Confirmed.";
                break;
                
                default:
                errorLoop=1;
                cout<<"Error. Please only type 3 or 6 or 12.";
            }
            
        } while (errorLoop==1);
        
        do {
            cout<<"\n\nHow many days a week suits you best to exercize in (3, 4, 5)?: ";
            cin>>users[userNum].weekdays;
            switch (users[userNum].weekdays) {
                case 3:
                cout<<"\nRecommended schedule:\nDay 1\tLower\nDay 2\tUpper\nDay 3\tCardio";
                errorLoop=0;
                break;
                
                case 4:
                cout<<"\nRecommended schedule:\nDay 1\tLower\nDay 2\tUpper\nDay 3\tCardio\nDay 4\tFullbody";
                errorLoop=0;
                break;
                
                case 5:
                cout<<"\nRecommended schedule:\nDay 1\tLower\nDay 2\tUpper\nDay 3\tCardio\nDay 4\tFullbody\nDay 5\tCardio";
                errorLoop=0;
                break;
                
                default:
                cout<<"Error. Please only type 3 or 4 or 5.";
                errorLoop=1;
                break;

            }
        } while (errorLoop==1);
        
    }
    else {
        string searchName;
        cout << "Enter your name to search for: ";
        cin >> searchName;
        
        int foundUser = searchMember(users, searchName);
        
        if (foundUser == -1) {
            cout << "User not found.";
        }
        else {
            // Code for existing user options
        }
    }
        
}
