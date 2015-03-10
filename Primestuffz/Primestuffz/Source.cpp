//#include <iostream>
//#include <vector>
//
//using std::cout;
//using std::cin;
//using std::endl;
//using std::vector;
//
//void displayArray(vector<int>);
//
//int main(){
//	int temp;
//	vector<int> vect;
//	for (int i = 2; i < 1000; i++){
//		vect.push_back(i);
//	}
//	displayArray(vect);
//	cout << "\nApply step one - Remove evens:" << endl;
//	for (int i = 2; i < vect.size(); i += 2){
//		vect[i] = 0;
//	}
//	displayArray(vect);
//	cout << "\nApply step two - Remove divisible by threes:" << endl;
//	for (int i = 7; i < vect.size(); i += 6){
//		vect[i] = 0;
//	}
//	displayArray(vect);
//	cin >> temp;
//}
//
//void displayArray(vector<int> myVect){
//	for (int i = 0; i < myVect.size(); i++)
//	{
//		if (myVect[i] != 0)
//			cout << myVect[i] << " ";
//		if (i % 15 == 0)
//		{
//			cout << "\n";
//		}
//	}
//}