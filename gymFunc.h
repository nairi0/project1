#ifndef gymFunc
#define gymFunc

using namespace std;


////////////////////////////////////////////////////


double bmiCal(double height, double weight) {
    if (height<5) {
        height= height*100;
    }
    double bmi = weight / pow((height / 100), 2);
    return bmi;
};


////////////////////////////////////////////////////


void weightLoss () {
    cout<<"\nTo lose weight, a diet with less carb is recommended.\n\nTo get the most out of the diet and to find the right excercise for you, we advise you to sign up for our gym membership.";
};


////////////////////////////////////////////////////


void weightGain () {
    cout<<"\nTo gain weight, a diet with more protein is recommended.\n\nTo get the most out of the diet and to find the right excercise for you, we advise you to sign up for our gym membership.";
};


////////////////////////////////////////////////////


double calorieCalculation (char sex, double height, double weight, int age) {
    double calorieresult;
    if (sex == 'F' || sex == 'f') {
        calorieresult = (age*4.7) - (height * 1.8) + (weight*9.6) +655;
    }
    else {
        calorieresult = (age*6.8) - (height * 5) + (weight*13.7) +66;
    }
    
    return calorieresult;
};


//////////////////////////////////////////////////


#endif