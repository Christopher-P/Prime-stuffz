//NOTICE: The last few numbers of the possible prime list are not correct do to faulty addition algorythm
#include <list>
#include <iostream>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>

using std::list;
using std::cout;
using std::cin;
using std::endl;

void displayList(list<int>);								//Displays the current list of possible primes
void displayList(list<int>, int);							//Displays the current list of possible primes with multiples of a certain number highlighted
void PrintListWithMultiples(list<int>, int);				//Prints the current list of possible primes with multiples of a certain number  highlighted to a file		
void removeStuff(int, int, int);							//No longer Used
void removeStuff(int, std::vector<int>);					//Removes numbers from the current list of possible primes based on starting position and a pattern
void PrintPattern(list<int>, int);							//Prints the positional difference of numbers thar are multiples of a cerain number


list<int> myList;											//Used to hold list of potential primes
list<int>::iterator iter;									//Used to iterate through the list above

int main(){
	
	list<int> myPrimes;										//Used to hold list of confirmed primes (not really used at this point)
	int n = 1000000;											//Amount of numbers to go through

	for (int i = 2; i < n; i++){
		myList.push_back(i);								//Fills array to n integers
	}
	
	//*******************START BASE FORMAT************************//
	myPrimes.push_back(myList.front());						//The front of the list of numbers is confirmed to be prime so TWO is confirmed to be prime!
	myList.pop_front();										//removes the confirmed prime from the potential prime list


	//Apply step one: Remove all even numbers
	std::vector<int> arr = { 2 };							//Used to hold the pattern that satisfies the accurate removel of all composite numbers with factor 2
	cout << "\nApply step one!" << endl;					//Alerts user that the process has started
	removeStuff(2, arr);									//Removes all composite numbers with factor 2 starting at some position (the first parameter) then going through the pattern given by the vector(every 2)

	//*******************END BASE FORMAT************************//

	myPrimes.push_back(myList.front());						//The front of the list of numbers is confirmed to be prime so THREE is confirmed to be prime!
	myList.pop_front();


	//Apply Step two: Remove all numbers divisible by three
	std::vector<int> arr1 = { 3 };							
	cout << "\nApply step two!" << endl;
	removeStuff(3, arr1);
	

	//Five is confirmed to be prime!
	myPrimes.push_back(myList.front());
	myList.pop_front();


	//Apply Step three: Remove all numbers divisible by five
	std::vector<int> arr2 = { 3, 7 };
	cout << "\nApply step three!" << endl;
	removeStuff(7, arr2);
	//displayList(myList);


	//Seven is confirmed to be prime!
	myPrimes.push_back(myList.front());
	myList.pop_front();


	//Apply Step four: Remove all numbers divisible by seven
	cout << "\nApply step four!" << endl;
	std::vector<int> arr3 = { 7, 4 };
	removeStuff(12, arr3);


	//Eleven is confirmed to be prime!
	myPrimes.push_back(myList.front());
	myList.pop_front();


	PrintListWithMultiples(myList, 11);


	cout << "\nApply step five!!" << endl;
	std::vector<int> arr4 = { 5 , 9 , 5 , 10,  15,  28 };
	removeStuff(26, arr4);
	
	//13 is confirmed to be prime!
	myPrimes.push_back(myList.front());
	myList.pop_front();

	cout << "\nApply step five!!" << endl;
	std::vector<int> arr5 = { 8, 6, 27, 6, 15, 10, 5, 10, 5, 11, 17, 19, 10,
		6, 27, 15, 5, 15, 16, 11, 5, 10, 15, 21, 11, 6, 10, 5,
		25, 6, 16, 12, 4, 9, 15, 16, 6, 41, 5, 10, 23, 15, 10,
		4, 11, 5, 11, 16, 5, 26, 15, 6, 26, 4, 16, 11, 16, 5,
		10, 37, 11, 6, 24, 16, 4, 33 };
	removeStuff(34, arr4);
	displayList(myList, 17);
	system("PAUSE");
	PrintListWithMultiples(myList, 17);
	PrintPattern(myList, 17);
}

void removeStuff(int startPos, int firstStep, int secStep){
	iter = myList.begin();
	std::advance(iter, startPos - 1);
	while (*iter < (myList.back() - (firstStep + secStep + 4))){
		iter = myList.erase(iter)--;	
		std::advance(iter, firstStep - 1);	
		iter = myList.erase(iter)--;	
		std::advance(iter, secStep - 1);	
	}
}

void removeStuff(int startPos, std::vector<int> pattern){
	int pos = 0;
	iter = myList.begin();
	std::advance(iter, startPos - 1);
	do{
		iter = myList.erase(iter)--;
		std::advance(iter, (pattern[pos] - 1));
		pos++;
		if (pos > (pattern.size() - 1)){
			pos = 0;
		}
		
	} while (*iter < (myList.back() - pattern[pos] - 10));
	cout << pattern.size() << endl;
}

void displayList(list<int> myList){
	int temp = 0;
	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		cout << *iter << " ";
		temp++;
		if (temp >= 15){
			cout << endl;
			temp = 0;
		}
	}
}

void PrintListWithMultiples(list<int> myList, int divid){
	std::string Str = "Show Multiples of " + std::to_string(divid) + ".txt";
	std::ofstream myfile;
	myfile.open(Str);
	int temp = 0;
	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		if (*iter % divid == 0)
		{
			myfile << "\"" << *iter << "\" ";
		}
		else
		{
			myfile << " " << *iter << "  ";
		}
		temp++;
		if (temp >= 15){
			myfile << endl;
			temp = 0;
		}
	}
	myfile.close();
}

void PrintPattern(list<int> myList, int divid){
	int dif = 0;
	std::string Str = "Show positional difference of " + std::to_string(divid) + ".txt";
	std::ofstream myfillet;
	myfillet.open(Str);
	int temp2 = 0;
	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		if (*iter % divid == 0){
			myfillet << " " << dif << " ";
			temp2++;
			dif = 0;
		}
		if (temp2 >= 15){
			myfillet << endl;
			temp2 = 0;
		}
		dif++;
	}
	myfillet.close();
}

void displayList(list<int> myList, int divid){
	int temp = 0;
	for (list<int>::iterator iter = myList.begin(); iter != myList.end(); iter++){
		if (*iter % divid == 0)
		{
			cout << "\"" << *iter << "\" ";
		}
		else
		{
			cout << " " << *iter << "  ";
		}
		temp++;
		if (temp >= 10){
			cout << endl;
			temp = 0;
		}
	}
}