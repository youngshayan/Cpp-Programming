/*
 * Programmer: Shayan Mansornia     Date:29/12/2021
 * Instructor: Seyyed Amir Hadi Minoofam
 * Term 1
 *
 */
#include <iostream>
#include <string>
using namespace std;
int main(){
    const double FIRST_RATE = 35.00;
    const double LOW_RATE = 1.10;
    const double HIGH_RATE =2.00;
    const int HIGH_HCF = 44;
    const int LOW_HCF = 31;

    cout<< "Enter unpaid balance:";
    int unpaid;
    cin>> unpaid;


    cout<< "Enter previous meter reading:";
    int initialMeter;
    cin>> initialMeter;

    cout<< "Enter current meter reading:";
    int finalMeter;
    cin>> finalMeter;

if (finalMeter<initialMeter)
    {   cout<<"---\n";
        cout<<  "The final reading must be at least as large as the initial reading.\n";
        return 1;
    }

    cin.ignore(100000,'\n');

    cout<< "Month number (1=Jan, 2=Feb, etc.): ";
    int monthNum;
    cin>> monthNum;

if (monthNum<1 || monthNum>12)
        {cout<<"---\n";
        cout<< "The month number must be in the range 1 through 12.\n";
                return 1;
        }

    int waterUsed = finalMeter - initialMeter;
    int secWater;
    double firstBill;
    double secondBill;
    double billAmount;


    if (monthNum >= 4 && monthNum <=10)
    {
        if (waterUsed <= HIGH_HCF)
            billAmount = waterUsed * FIRST_RATE;
        else
        {
            secWater = waterUsed - HIGH_HCF;
            firstBill = FIRST_RATE * HIGH_HCF;
            secondBill = secWater * HIGH_RATE;
            billAmount = firstBill + secondBill;
        }
     }


    else
    {
        if (waterUsed <= LOW_HCF)
            billAmount = waterUsed * FIRST_RATE;
        else
        {
            secWater = waterUsed - LOW_HCF;
            firstBill = FIRST_RATE * LOW_HCF;
            secondBill = secWater * LOW_RATE;
            billAmount = firstBill + secondBill +unpaid;
        }
    }

    cout.setf(ios::fixed);
    cout.precision(2);
    cout<< "---\n";
    cout<< "The bill plus $"<<unpaid<<" unpaid is $" << billAmount << endl;
}

