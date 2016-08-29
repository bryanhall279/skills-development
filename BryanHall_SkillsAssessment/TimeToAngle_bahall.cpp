/*
	TimeToAngle_bahall.cpp
	Author:	Bryan Hall
	Date:	August 25, 2016
	
	Input:	lines of data from data.txt
	
	Algorithm:
	1	Open data.txt and read each line of text
	2	While there remain unread lines of text in the file:
	3		Check to see if the line of text is valid input.
	4		If the text is valid input:
	5			Calculate the appropriate angle between the hour and minute hands
	6				Compute the angle of the hour hand from noon position			
	7				Compute the angle of the minute hand from noon position
	8				Calculate the smallest angle between the hands
	9			Output the angle
	10		If the text is invalid, then output INVALID
	11	Close data.txt
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;

int main(){
	cout << "TimeToAngle\nAuthor: Bryan Hall" << endl;
	
	string dataLine;
	string minuteStr;
	string hourStr;
	string parseChar;
	
	int hour;
	int minute;
	float angle;
	
	ifstream fileIn("data.txt");
	if(fileIn.is_open()){
		while( getline(fileIn, dataLine) ){
			parseChar = dataLine;
			hourStr = "";
			minuteStr = "";
			if(dataLine == ""){
				cout << "INVALID" << endl;
			}else if(dataLine.size() == 4){ // #:##
				if(!isdigit(parseChar[0])){
					cout << "INVALID" << endl;
				}else if(parseChar[1] != ':'){
					cout << "INVALID" << endl;
				}else if(!isdigit(parseChar[2]) || !isdigit(parseChar[3])){
					cout << "INVALID" << endl;
				}else{ 
					// VALID
					hour = parseChar[0] - '0';
					minuteStr.append(&parseChar[2]);
					minute = atoi(minuteStr.c_str());

					// Calculate angle of hour hand from noon position
					// Calculate angle of minute hand from noon position
					// Subtract the angle difference
					if(hour < 10 && minute < 60){
						angle = abs((0.5f*(60*hour+minute))-(6*minute));
						if(angle > 180){
							angle = 360 - angle;
						}
						if(angle > 0){
							cout << angle << " degrees (Clockwise)" << endl;
						}else if(angle == 0){
							cout << angle << " degrees" << endl;
						}else{
							cout << abs(angle) << " degrees (Counter-clockwise)" << endl;
						}
					}else{
						cout << "INVALID" << endl;
					}
					
				}
			}else if(dataLine.size() == 5){ // ##:##
				if(!isdigit(parseChar[0]) || !isdigit(parseChar[1])){
					cout << "INVALID" << endl;
				}else if(parseChar[2] != ':'){
					cout << "INVALID" << endl;
				}else if(!isdigit(parseChar[3]) || !isdigit(parseChar[4])){
					cout << "INVALID" << endl;
				}else{
					// VALID
				
					hourStr.append(&parseChar[0]);
					hour = atoi(hourStr.c_str());

					minuteStr.append(&parseChar[3]);
					minute = atoi(minuteStr.c_str());
					 
					// Calculate angle of hour hand from noon position
					// Calculate angle of minute hand from noon position
					// Subtract the angle difference
					if(hour < 24 && minute < 60){
						angle = abs((0.5f*(60*hour+minute))-(6*minute));
						if(angle > 180){
							angle = 360 - angle;
						}
						if(angle > 0){
							cout << angle << " degrees (Clockwise)" << endl;
						}else if(angle == 0){
							cout << angle << " degrees" << endl;
						}else{
							cout << abs(angle) << " degrees (Counter-clockwise)" << endl;
						}
					}else{
						cout << "INVALID" << endl;
					}
					
				}					
			}else if(dataLine.size() == 6){ // #:##am
				if(!isdigit(parseChar[0])){
					cout << "INVALID" << endl;
				}else if(parseChar[1] != ':'){
					cout << "INVALID" << endl;
				}else if(!isdigit(parseChar[2]) || !isdigit(parseChar[3])){
					cout << "INVALID" << endl;
				}else if(parseChar[4] != 'a' && parseChar[4] != 'A' && parseChar[4] != 'P' && parseChar[4] != 'p'){
					cout << "INVALID" << endl;
				}else if(parseChar[5] != 'm' && parseChar[5] != 'M'){
					cout << "INVALID" << endl;
				}else{
					// VALID
					hour = parseChar[0] - '0';
					minuteStr.append(&parseChar[2]);
					minute = atoi(minuteStr.c_str());

					// Calculate angle of hour hand from noon position
					// Calculate angle of minute hand from noon position
					// Subtract the angle difference
					if(hour < 10 && minute < 60){
						angle = abs((0.5f*(60*hour+minute))-(6*minute));
						if(angle > 180){
							angle = 360 - angle;
						}
						if(angle > 0){
							cout << angle << " degrees (Clockwise)" << endl;
						}else if(angle == 0){
							cout << angle << " degrees" << endl;
						}else{
							cout << abs(angle) << " degrees (Counter-clockwise)" << endl;
						}
					}else{
						cout << "INVALID" << endl;
					}
				}					
			}else if(dataLine.size() == 7){ // #:## am OR ##:##am
				if(parseChar[1] == ':'){ // #:## am
					if(!isdigit(parseChar[0])){
						cout << "INVALID" << endl;
					}else if(!isdigit(parseChar[2])){
						cout << "INVALID" << endl;
					}else if(!isdigit(parseChar[3])){
						cout << "INVALID" << endl;
					}else if(parseChar[4] != ' '){
						cout << "INVALID" << endl;
					}else if(parseChar[5] != 'a' && parseChar[5] != 'A' && parseChar[5] != 'P' && parseChar[5] != 'p'){
						cout << "INVALID" << endl;
					}else if(parseChar[6] != 'm' && parseChar[6] != 'M'){
						cout << "INVALID" << endl;
					}else{
						// VALID
						hour = parseChar[0] - '0';
						minuteStr.append(&parseChar[2]);
						minute = atoi(minuteStr.c_str());

						// Calculate angle of hour hand from noon position
						// Calculate angle of minute hand from noon position
						// Subtract the angle difference
						if(hour < 10 && minute < 60){
							angle = abs((0.5f*(60*hour+minute))-(6*minute));
							if(angle > 180){
								angle = 360 - angle;
							}
							if(angle > 0){
								cout << angle << " degrees (Clockwise)" << endl;
							}else if(angle == 0){
								cout << angle << " degrees" << endl;
							}else{
								cout << abs(angle) << " degrees (Counter-clockwise)" << endl;
							}
						}else{
							cout << "INVALID" << endl;
						}
					}
				}else if(parseChar[2] == ':'){ // ##:##am
					if(!isdigit(parseChar[0])){
						cout << "INVALID" << endl;
					}else if(!isdigit(parseChar[1])){
						cout << "INVALID" << endl;
					}else if(!isdigit(parseChar[3])){
						cout << "INVALID" << endl;
					}else if(!isdigit(parseChar[4])){
						cout << "INVALID" << endl;
					}else if(parseChar[5] != 'a' && parseChar[5] != 'A' && parseChar[5] != 'P' && parseChar[5] != 'p'){
					cout << "INVALID" << endl;
					}else if(parseChar[6] != 'm' && parseChar[6] != 'M'){
						cout << "INVALID" << endl;					
					}else{
						// VALID
					
						hourStr.append(&parseChar[0]);
						hour = atoi(hourStr.c_str());

						minuteStr.append(&parseChar[3]);
						minute = atoi(minuteStr.c_str());
						 
						// Calculate angle of hour hand from noon position
						// Calculate angle of minute hand from noon position
						// Subtract the angle difference
						if(hour < 24 && minute < 60){
							angle = abs((0.5f*(60*hour+minute))-(6*minute));
							if(angle > 180){
								angle = 360 - angle;
							}
							if(angle > 0){
								cout << angle << " degrees (Clockwise)" << endl;
							}else if(angle == 0){
								cout << angle << " degrees" << endl;
							}else{
								cout << abs(angle) << " degrees (Counter-clockwise)" << endl;
							}
						}else{
							cout << "INVALID" << endl;
						}
					}
				}
				
			}else if(dataLine.size() == 8){ // ##:## am
				if(!isdigit(parseChar[0]) || !isdigit(parseChar[1])){
					cout << "INVALID" << endl;
				}else if(parseChar[2] != ':'){
					cout << "INVALID" << endl;
				}else if(!isdigit(parseChar[3]) || !isdigit(parseChar[4])){
					cout << "INVALID" << endl;
				}else if(parseChar[5] != ' '){
					cout << "INVALID" << endl;
				}else if(parseChar[6] != 'a' && parseChar[6] != 'A' && parseChar[6] != 'P' && parseChar[6] != 'p'){
					cout << "INVALID" << endl;
				}else if(parseChar[7] != 'm' && parseChar[7] != 'M'){
					cout << "INVALID" << endl;
				}else{
						// VALID
					
						hourStr.append(&parseChar[0]);
						hour = atoi(hourStr.c_str());

						minuteStr.append(&parseChar[3]);
						minute = atoi(minuteStr.c_str());
						 
						// Calculate angle of hour hand from noon position
						// Calculate angle of minute hand from noon position
						// Subtract the angle difference
						if(hour < 24 && minute < 60){
							angle = abs((0.5f*(60*hour+minute))-(6*minute));
							if(angle > 180){
								angle = 360 - angle;
							}
							if(angle > 0){
								cout << angle << " degrees (Clockwise)" << endl;
							}else if(angle == 0){
								cout << angle << " degrees" << endl;
							}else{
								cout << abs(angle) << " degrees (Counter-clockwise)" << endl;
							}
						}else{
							cout << "INVALID" << endl;
						}
				}					
			}else{
				cout << "INVALID" << endl;
			}
		}
		fileIn.close();
	}
	else{
		cout << "ERROR: Could not open the file" << endl;
	}
	return 0;
}