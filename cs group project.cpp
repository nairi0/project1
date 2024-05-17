// Mesk Alsultan 2230004728
// Shahad Al Swiket 2230006322
// Raya Ghazi Al-harbi 2230005278
// Forat sadiq Alabbas 2230001270

#include <iostream>
#include <cmath>
#include <cstring>
#include "gymFunc.h"

using namespace std;

struct memberinfo {
    string username;
    double weight;
    double height;
    char sex;
    int age;
    int schedule;
    int weekdays;
    char signDone;
};

void newMember();
int searchMember(memberinfo users[], string keyname);

void healthCalc();
void membershipProgram();

char startQ;


memberinfo users[10];
int userNum = 0;
int errorLoop=0;



int main() {
    char programQ;
    int exitQ = 1;
    
    cout << "Welcome to FlexFit Gym program!";
    users[userNum].signDone = 'Y';
    
    do {
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
                    startQ='N';
                    errorLoop=0;
                    break;
                
                default:
                    cout<<"\nPlease enter the letter N for new or A for already existing.";
                    errorLoop=1;
                    break;
            }
        } while (errorLoop==1);
        
        if (startQ=='A') {
            string searchName;
            cout << "Enter your name to search for: ";
            cin >> searchName;
            int foundUser = searchMember(users, searchName);
            if (foundUser == 0) {
                cout<<"Thanks for using our program, we hope you try again soon.";
                return 0;
            }
        }
        else if (startQ=='N') {
            newMember();
            cout<<"\nThank you, your information has been registered.";
        }
    
        do {
            cout<<"\n\nAre you using the program for health calculations (C), or for the gym membership (M)?: ";
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
                    cout<<"\nPlease only enter C or M";
            }    
            
        } while (errorLoop==1);
        
    cout << "\n\nTo go back to main menu, type a positive number. To exit, write 0: ";
    cin>>exitQ;
    
    } while (exitQ > 0);
    
    cout<<"\nThanks for using our program!";
    
    return 0;
}

//////////////////////////////////////// function definitions///////////////////////////////////////////


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
    
    if (userNum == 0) {
        char newmemberQ;
        cout << "User cannot be found, do you want to create a new user? (y/n): ";
        cin >> newmemberQ;

        if (newmemberQ == 'y' || newmemberQ == 'Y') {
            newMember();
            startQ='A';
        }
    }
    
    return userNum;
}

/////////////////////////////////////////////

void newMember(){
    userNum++;
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

///////////////////////////////////////////

void healthCalc() {
    char metaQ;
    char weightchoice;
    char updateinfo;
    int choicetable;
    
    do {
        cout<<"\n\nWould you like to update your information? (y/n): ";
        cin>>updateinfo;
        
        switch (updateinfo) {
            case 'y':
            case 'Y':
                cout<<"\n\ni\tInformation\n1\tHeight\n2\tWeight\n3\tAge";
                do {
                    cout<<"\n\nWhat would you like to update? Please type a number from the table: ";
                    cin>>choicetable;
                    
                    switch (choicetable) {
                        case 1:
                            cout<<"Your old height is "<<users[userNum].height<<"cm. What is your new height?: ";
                            cin>>users[userNum].height;
                            cout<<"Confirmed. Anything else you want to update? (y/n): ";
                            cin>>updateinfo;
                            if (updateinfo == 'y' || updateinfo == 'Y') {
                                errorLoop=1;
                            }
                            else if (updateinfo=='n' || updateinfo == 'N') {
                                errorLoop=0;
                            }
                            break;
                            
                        case 2:
                            cout<<"Your old weight is "<<users[userNum].weight<<"kg. What is your new weight?: ";
                            cin>>users[userNum].weight;
                            cout<<"Confirmed. Anything else you want to update? (y/n): ";
                            cin>>updateinfo;
                            if (updateinfo == 'y' || updateinfo == 'Y') {
                                errorLoop=1;
                            }
                            else if (updateinfo=='n' || updateinfo == 'N') {
                                errorLoop=0;
                            }
                            break;
                            
                        case 3:
                            cout<<"Your old age is "<<users[userNum].age<<" years old. What is your new age?: ";
                            cin>>users[userNum].age;
                            cout<<"Confirmed. Anything else you want to update? (y/n): ";
                            cin>>updateinfo;
                            if (updateinfo == 'y' || updateinfo == 'Y') {
                                errorLoop=1;
                            }
                            else if (updateinfo=='n' || updateinfo == 'N') {
                                errorLoop=0;
                            }
                            break;
                            
                        default:
                            cout<<"Error.";
                            errorLoop=1;
                    }
                    
                } while (errorLoop==1);
                break;
                
            case 'n':
            case 'N':
                errorLoop=0;
                break;
                
            default:
                cout<<"Please only type y or n.";
                errorLoop=1;
                break;
                
        }
    } while (errorLoop==1);
    
    
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

///////////////////////////////////////////////////////////

void membershipProgram() {
    char metaQ;
    if (users[userNum].signDone='N') {
        cout<<"\n\nHere's our offered subscriptions:\nMonths\tPrice\tdiscount offer\n3\t900\t600\n6\t1500\t1300\n12\t3600\t3000";
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
                    break;
            }
        } while (errorLoop==1);
        
        cout<<"\n\nHow many days a week suits you best to exercize in (3, 4, 5)?: ";
        do {
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
        users[userNum].signDone = 'Y';
        
    }

    else if (users[userNum].signDone == 'Y') {
        cout<<"\nYou are signed up on the "<<users[userNum].schedule<<" month plan. Proceed or cancel plan? (p, c): ";
        do {
            cin>>metaQ;
            switch (metaQ) {
                case 'p':
                case 'P':
                    metaQ='P';
                    errorLoop=0;
                    break;
                case 'c':
                case 'C':
                    errorLoop=0;
                    cout<<"\nAre you sure? (y/n): ";
                    do {
                        cin>>metaQ;
                        switch (metaQ) {
                            case 'y':
                            case 'Y':
                                users[userNum].signDone='N';
                                cout<<"\nConfirmed. Sign up to a different plan (s) or delete user (d)? :";
                                do {
                                    cin>>metaQ;
                                    switch (metaQ) {
                                        case 's':
                                        case 'S':
                                            membershipProgram();
                                            break;
                                            
                                        case 'd':
                                        case 'D':
                                            users[userNum].username = "";
                                            userNum--;
                                            break;
                                        default:
                                            cout<<"\nError. Type 'p' for plan offers and 'd' to delete user.\n";
                                        }
                                } while (metaQ != 's' && metaQ != 'S' && metaQ != 'd' && metaQ != 'D');
                        }
                    } while (metaQ != 'y' && metaQ != 'Y' && metaQ != 'n' && metaQ != 'N');
                    
                default:
                    cout<<"\nPlease only enter 'p' to proceed or 'c' to cancel plan.\n";
                    errorLoop=1;
                    break;
            }
        } while (errorLoop==1);
    }
    
    if (metaQ=='P') {
        int workout;
        cout<<"\nPlese write the name of workout you want to do (U upper,L lower ,C cardio ,F Fullbody)";
        cin>> workout;
        do {
            switch (workout) {
                case 'U':
                case 'u':
                    cout<<"\n Upper workout :\nshoulders\tshoulder press\tLater raise\tRear delf\nBiceps \tCurls (preacher)\tCurls (straight arm)\nTriceps\tDips\tExtension\tTripceps press";
                    cout<<"\nBack\tLat pulldown\tSeated row\tHyper Extension\tSeated back Extension\tPull ups\nChest\tPress\tPec fly\tDips\tBench press\tPushups";
                    errorLoop=0;
                    break;
                		
                case 'L' :
                case 'l':
                    cout<<"\n Lower workout: \nAbs\tCrunches\tLeg raise\tPlank\tSide plank\tRotary torso\nThigh\tSquat\tLeg press (seated)\tLeg press (lying)\tAbduction\tCurls (seated)";
                    cout<<"\tCurls (lying)\tLunges\tDeadlift\nHip\tHip thrust\tAbduction\tGlute press\nCalves\tExtension\tSeated calf raises";
                    errorLoop=0;
                    break;
                
                case 'F':
                case 'f':
                    cout<<"\nFull body workout is Upper and lower workouts in the same days, Full body workout:";
                    cout<<"\nUpper workout :\nshoulders\tshoulder press\tLater raise\tRear delf\nBiceps \tCurls (preacher)\tCurls (straight arm)\nTriceps\tDips\tExtension\tTripceps press";
                    cout<<"\nBack\tLat pulldown\tSeated row\tHyper Extension\tSeated back Extension\tPull ups\nChest\tPress\tPec fly\tDips\tBench press\tPushups  ";
                    cout<<"\n Lower workout: \nAbs\tCrunches\tLeg raise\tPlank\tSide plank\tRotary torso\nThigh\tSquat\tLeg press (seated)\tLeg press (lying)\tAbduction\tCurls (seated)";
                    cout<<"\tCurls (lying)\tLunges\tDeadlift\nHip\tHip thrust\tAbduction\tGlute press\nCalves\tExtension\tSeated calf raises   ";
                    errorLoop=0;
                    break;
              		
                case 'C':
                case 'c':
                    cout<<"\nCardio workout :\tTreadmill\tStationary bike\tElliptical trainer\tRowing machine\tStair climber\tExercise bike ";
                    errorLoop=0;
                    break;
                			
                default:
                    cout<<"Error. Please write U,L,C (U upper,L lower ,C cardio ,F Fullbody) ";
                    errorLoop=1;
                    break;
		    }
        } while (errorLoop==1);
    }
}