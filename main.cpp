#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <stdlib.h>     
#include <time.h>  
using namespace std;

int get_Reminder_Day();
void print_Heading(ofstream &outFile, int);
string read_Month(ifstream &inFile);
int read_Num_Days(ifstream &inFile);
int print_Month(ofstream &outFile, ofstream &out_File, string, string, int, int, int, int);

int main() {
  int days, remind;
  int year = 2020;
  int start_day = 3;
  string month,day_of_week;
  ifstream inFile;
  ofstream outFile, out_File;

  srand(time(NULL));  

  inFile.open("infile.txt");
  outFile.open("outputfile.txt");
  out_File.open("reminders.txt");

  print_Heading(outFile, year);

  remind = get_Reminder_Day();

  if (remind == 0) {
    day_of_week = "Sunday";
  }
  else if (remind == 1) {
    day_of_week = "Monday";
  }
  else if (remind == 2) {
    day_of_week = "Tuesday";
  }
  else if (remind == 3) {
    day_of_week = "Wednesday";
  }
  else if (remind == 4) {
    day_of_week = "Thursday";
  }
  else if (remind == 5) {
    day_of_week = "Friday";
  }
  else if (remind == 6) {
    day_of_week = "Saturday";
  }
  
  for (int i = 0; i < 12; i++) {
  month = read_Month(inFile);
  days = read_Num_Days(inFile);
  start_day = print_Month(outFile, out_File,month, day_of_week, days, start_day, year, remind);
  }
}

int get_Reminder_Day() {
  int day;
  cout << "What day would you like to be reminded on <0 = Sun, 1 = Mon, 2 = Tue, 3 = Wed, 4 = Thu, 5 = Fri, 6 = Sat: ";
  cin >> day;
  return day;
}
void print_Heading(ofstream &outFile, int year) {
  outFile << setw(20) << right << "INvestME Calendar" << endl << setw(20) << right << "YEAR -- " << year << endl << endl;
}
string read_Month(ifstream &inFile) {
  string month;
  inFile >> month;
  return month;
}
int read_Num_Days(ifstream &inFile) {
  int days;
  inFile >> days;
  return days;
}
int print_Month(ofstream &outFile, ofstream &out_File, string month, string day_of_week, int days, int start, int year, int remind) {
  int k, leap_year,n;
  outFile << endl << setw(24) << right << month << endl;
  outFile << "Sun| \tMon| \tTue| \tWed| \tThu| \tFri| \tSat|" << endl;

  for(k = 0; k < start; k++) {
    outFile << "\t\t\t";
    if (k == 5) {
      outFile << " ";
    }
  }

  leap_year = year % 4;

  if (month == "February" && leap_year == 0) {
    days = 29;
  }
  for(int j = 1; j <= days; j++){
    if (remind == k) {
      if (j > 9) {
        outFile << j << setw(5) << left << "*";
      }
      else {
      outFile << j << setw(6) << left << "*";
      }
      n = rand() % 6 + 1;
      switch(n) {
        case 1: out_File << "Money doesn't grow on trees. Go check in with INvestME to sprout some seeds." << endl << endl; 
        break;
        case 2: out_File << "You gotta spend money to make money. Open up the INvestME app and learn how to, wisely." << endl << endl;
        break;
        case 3: out_File << "You give a poor man a credit card and give him money for a day. You teach him how to build his credit and you give him money for a lifetime." << endl << endl;
        break;
        case 4: out_File << "Open the app this time and learn how to switch a penny for a dime." << endl << endl;
        break;
        case 5: out_File << "Dr. Martin Luther King Jr. once said, \"If I cannot do great things, I can do small things in a great way.\" This can be you fixing your credit. Learn how in the INvestME app." << endl << endl;
        break;
        case 6: out_File << "To quote Bill Gates, \"To win big, you have to take big risks.\" Come read about investments in your INvestME app!" << endl << endl;
        break;
        default: out_File << "Today is " << day_of_week << " " << month << " " << j << ", " << year << "." << endl << "This is a reminder to check your INvestMe app!" << endl << endl;
      }
    }
    else {
    outFile << setw(6) << left << j;
    }

    if (++k > 6) {
      k = 0;
      outFile << "\n";
    }
  }
  return k;
}