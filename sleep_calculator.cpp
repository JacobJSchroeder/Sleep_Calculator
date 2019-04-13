#include <iostream>
using namespace std;

//global year variables
int start_year;
int end_year;
//glabal month variables
int start_month;
int end_month;
//gloabal day variables
int start_day;
int end_day;
//global leapday bool
bool is_leap;
//global calculation bool
int days_tot;
bool checker;
bool starter;
int leap_count;

float sleeps;
bool calculate;
string selection;
bool again;

int main() 
{
	calculate = true;
	while (calculate == true){

	//setting individual month numbers (non leap year february)
	int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	
	// getting birth informarion
    cout << "What year were you born in ";
    cin >> start_year;

  	cout << "What month were you born in? (1-12)";
  	cin >> start_month;

  	cout << "What day were you born on? ";
  	cin >> start_day;

  	//getting day information
  	cout << "What year is it? ";
  	cin >> end_year;

  	cout << "What month is it? (1-12) ";
  	cin >> end_month;

  	cout << "What day is it? ";
  	cin >> end_day;

  	cout << "How many hours do you sleep on average each night (this can be a decimal value)? ";
  	cin >> sleeps;

  	//getting the amount of days before the month change
  	days_tot = 0;
  	checker = true;
  	starter = true;
  	leap_count = 0;
  	if (start_year > end_year and checker == true){
  		cout << "We are not going back in time Doc Brown" << endl;
  		checker = false;
  	}

  	while (start_year <= end_year){
  	//checking for bad day inputs
  		if (start_month > end_month and start_year == end_year and checker == true){
  			cout << "We are not goingf back in time Doc Brown" << endl;
  			checker = false;
  			break;
  		}
  		else if (start_month == end_month and start_day >= end_day and start_year == end_year and checker == true){
  			cout << "We are not goingfg back in time Doc Brown" << endl;
  			checker = false;
  			break;
  		}
  		else if (start_month == end_month and start_year == end_year and start_day < end_day and checker == true){
  			days_tot = end_day - start_day;
  			checker = false;
  			break;
  		}
  		else{
  			checker = false;

  		}
  	//checking for a leap year
  		if (start_year % 4 == 0 and start_year % 100 != 0 or start_year % 400 == 0){

  			is_leap = true;
  			leap_count += 1;
  		}
  		else{
  			is_leap = false;
  		}
  		
  	//bringing calculations up a a round year
  		if (starter == true){
  			days_tot = months[start_month - 1] - start_day;
  			if (is_leap == true and start_month <= 2){
  				days_tot += 1;
  			}	
  			if (start_year < end_year){
  				for (start_month; start_month <= 11; start_month++){
  					days_tot += months[start_month];
  				}
  			}
  			else if (start_year == end_year){
  				if (is_leap == true and start_month >= 2){
  					days_tot += 1;
  				}	
  				for (start_month; start_month < end_month - 1; start_month++){
  					days_tot += months[start_month];
  				}
  				days_tot += end_day;
  				break;
  			}
  			starter = false;
  			start_month = 0;
  		}
      //adjusting leap days for one year basis
  		else if (start_year < end_year and starter == false){
  			if (is_leap == true){
  				days_tot += 1;
  			}
  			for (start_month; start_month <=11; start_month++){
  				days_tot += months[start_month];
  			}
  			start_month = 0;
  		}
      //adjusting leap days for same year basis
  		else if (start_year == end_year and starter == false){
  			end_month -= 1;
  			if (is_leap == true and end_month >= 1){
  				days_tot += 1;
  			}
  			for (end_month; end_month >= 0; end_month--){
  				if (end_month > 0){
  					days_tot += months[end_month];
  				}
  				if (end_month == 0){
  					days_tot += end_day;
  				}
  			}
  		}

      //accounting for leap years
  		if (is_leap == true){
  			days_tot += 1;
  		}

  		start_year += 1;

  	}
  	
    //fixing leap year count
  	if (leap_count > 3){
  		for (leap_count; leap_count > 3; leap_count--){
  			days_tot -= 1;
  		}
  	}
  	else if (leap_count <= 3){
  		for (leap_count; leap_count < 3; leap_count++){
  			days_tot += 1;
  		}
  	}

    //outputting total days
  	cout << "You have been alive for " << days_tot << " days" << endl;
  	cout << "You have slept for " << sleeps*days_tot << " hours" << endl;
  	again = true;

    //checking if user wants to play again
  	while (again == true){
  		cout << "Do you want to calculate again? (Y/N)";
  		cin >> selection;

  		if (selection == "Y"){
 	 		calculate == true;
  			days_tot = 0;
  			again = false;
  		}
  		else if (selection == "N"){
  			calculate == false;
  			cout << "Thank you for calculating" << endl;
  			again = false;
  			calculate = false;
  			break;
  		}
 	 	else{
  			cout << "I do not understand please try again" << endl;
  		}
  }
 }
 return 0;
}

