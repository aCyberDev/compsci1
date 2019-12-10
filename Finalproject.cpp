#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Registration {
public:
	//public functions overloaded with main() function variables
	void minimizeCode(vector<string>, vector<int>, string, int&, int);
	vector<string> studySubjects(int);
	vector<int> unitSubjects(int); 
	void warning(char&, int&, bool&, vector<int> unit);
	void prompt(int);
	void displaySummary(int);
	void modify(char, int, bool&);
	//verify that user input follows the program
	int verifySelection(unsigned int&);

	//public variables initilized to vector string values
	vector < string > studyField = { "Science", "Mathematics", "Arts", "Humanities" };
	vector < string > science = { "Earth Science", "Biology", "Oceanography", "Geology", "Astronomy" };
	vector < string > mathematics = { "Pre-Algebra", "Algebra", "Geometry", "Calculus I", "Calculus II" };
	vector < string > arts = { "Music", "Painting", "Literature", "Sculpting", "Film" };
	vector < string > humanities = { "Japenese", "Creative Writing", "Elementary French", "Hispanic Literature", "California History" };
	vector <string> storeSubjects;
	vector <int> unitScience = { 3, 4, 3, 3, 2 };
	vector <int> unitMath = { 2, 4, 4, 4, 4 };
	vector <int> unitArts = { 3, 3, 4, 3, 4 };
	vector <int> unitHumanities = { 3, 4, 3, 4, 3 };
	vector <int> storeUnits;
private:

};

int main()
{
	//variables outside of class created for making decisions
	vector <string> subject;
	vector<int> unit;
	string compare = "\0";
	int count = 1;
	unsigned int selection = 0;
	bool quit = false;
	char choice = '\0';
	char dummyVar = '\0';

	//object for Registration
	Registration springClass;
	//reuse class registration to create summerClass, and fallClass objects

	do
	{
		system("CLS"); //clear

		springClass.prompt(count);
		cout << "You can make your selection now: ";
		cin >> selection;
		springClass.verifySelection(selection);

		compare = springClass.studyField.at(selection);
		subject = springClass.studySubjects(selection);
		unit = springClass.unitSubjects(selection);
		springClass.minimizeCode(subject, unit, compare, count, selection);
		springClass.warning(choice, count, quit, unit);
		springClass.modify(choice, selection, quit);

	} while (quit == false);
	springClass.displaySummary(count);
	//implement editing logic to ADD, Delete, Replace current selections

	return 0;
}

void Registration::minimizeCode(vector<string> subject, vector<int> unit, string compare, int& count, int selection) {
	if (studyField.at(selection) == compare)
	{
		char dummyVar = '\0';
		cout << endl;
		for (unsigned int i = 0; i < subject.size(); i++)
		{
			cout << count << ": " << left << setw(20) << subject.at(i) << "Units: " << unit.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please make your class selection now: ";
		cin >> selection;
		cin.ignore(100, '\n');
		selection -= 1;

		if (selection >= 0 && selection <= 4)
		{
			storeSubjects.push_back(subject.at(selection));
			storeUnits.push_back(unit.at(selection));
		}
		else
		{
			cout << "Out of range! Please select between 1 and 5. \n";
			cout << "Press Enter to continue. ";
			cin.get(dummyVar);
		}
	}
}
vector<string> Registration::studySubjects(int selection) {
	if (studyField.at(selection) == "Science") {
		return science;
	}
	else if (studyField.at(selection) == "Mathematics")
	{
		return mathematics;
	}
	else if (studyField.at(selection) == "Arts")
	{
		return arts;
	}
	else
	{
		return humanities;
	}

}
vector<int> Registration::unitSubjects(int selection) {
	if (selection == 0) 
	{
		return unitScience;
	}
	else if (selection == 1)
	{
		return unitMath;
	}
	else if (selection == 2) 
	{
		return unitArts;
	}
	else 
	{
		return unitHumanities;
	}
}
void Registration::prompt(int count) {
	cout << "Please select a field of study" << endl;
	for (unsigned int i = 0; i < studyField.size(); i++)
	{
		cout << count << ": " << studyField.at(i) << endl;
		count++;
	}
	count = 1;
}
void Registration::warning(char& choice, int& count, bool& quit, vector<int> unit) {
	if (storeSubjects.size() >= 4)
	{
		system("CLS");//clear

		cout << "We recommend that you only take 4 classes per semester, you have selected these classes: " << endl;
		cout << "----------------------------------" << endl;

		for (unsigned int i = 0; i < storeSubjects.size(); i++)
		{
			cout << count << ": " << left << setw(25) << storeSubjects.at(i) << storeUnits.at(i) << endl;
			cout << "-----------------------------------" << endl;
			count++;
		}
		count = 1;
		cout << "\nWould you like to add more? (Y / N): ";
		cin >> choice;
		if (choice == 'N' || choice == 'n')
		{
			quit = true;
			if (quit == true)
			{
				cout << "If you would like to DELETE or REPLACE one of the above classes type: (D) to delete / (R) to replace\nOtherwise type: (N): ";
				cin >> choice;
			}
		}
	}
}
void Registration::modify(char choice, int selection, bool &quit) {
	if (choice == 'D' || choice == 'd') {
		cout << "Which selection would you like to delete? from 1 to " << storeSubjects.size() << ": ";
		cin >> selection;
		selection -= 1;
		storeSubjects.erase(storeSubjects.begin() + selection);
	}
	else if (choice == 'R' || choice == 'r') {
		cout << "Which selection would you like to replace? from 1 to " << storeSubjects.size() << ": ";
		cin >> selection;
		selection -= 1;
		storeSubjects.erase(storeSubjects.begin() + selection);
		storeUnits.erase(storeUnits.begin() + selection);
		quit = false;
	}
}
void Registration::displaySummary(int count) {
	int counter = 0;

	system("CLS");//clear

	cout << "You have selected the following classes: " << endl;
	cout << "_________________________________________________________________________________________" << endl;
	for (unsigned int i = 0; i < storeSubjects.size(); ++i)
	{
		cout << count << ": " << left << setw(25) << storeSubjects.at(i) << storeUnits.at(i) << endl;
		count++;
		counter += storeUnits.at(i);
	}
	count = 1;

	cout << left << setw(28) << "\nTotal Units: " << counter;
	cout << endl;
	cout << "_________________________________________________________________________________________" << endl;
}
int Registration::verifySelection(unsigned int &selection) {
	while ((selection <= 0) || (selection > studyField.size()))
	{
		cout << "Your selection is invalid, please enter a # from 1 to " << studyField.size() << " ";
		cin >> selection;
	}
	selection -= 1;
	return selection;
}