#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Registration {
public:
	//public functions overloaded with main() function variables
	void minimizeCode(vector<string>, vector<int>, string, int,unsigned int);
	vector<string> studySubjects(int);
	vector<int> unitSubjects(int);
	void warning(char&, int, bool&, vector<int> unit,int);
	void prompt(int);
	void displaySummary(int);
	void modify(char, int, bool&);
	void displaySemester(int);
	void decideSemester(char,int,int&);
	//verify that user input follows the program
	int verifySelection(unsigned int&);

	//public variables initilized to vector string values
	const vector <string> semesters = { "Spring", "Summer", "Fall" };
	const vector < string > studyField = { "Science", "Mathematics", "Arts", "Humanities" };
	const vector < string > science = { "Earth Science", "Biology", "Oceanography", "Geology", "Astronomy" };
	const vector < string > mathematics = { "Pre-Algebra", "Algebra", "Geometry", "Calculus I", "Calculus II" };
	const vector < string > arts = { "Music", "Painting", "Literature", "Sculpting", "Film" };
	const vector < string > humanities = { "Japenese", "Creative Writing", "Elementary French", "Hispanic Literature", "California History" };
	vector <string> storeSubjects;
	//public variables initilizied to vector integer values
	const vector <int> unitScience = { 3, 4, 3, 3, 2 };
	const vector <int> unitMath = { 2, 4, 4, 4, 4 };
	const vector <int> unitArts = { 3, 3, 4, 3, 4 };
	const vector <int> unitHumanities = { 3, 4, 3, 4, 3 };
	vector <int> storeUnits;
};

int main()
{
	//variables outside of class created for making decisions
	vector <string> subject;
	vector<int> unit;
	string compare = "\0";
	int count = 1;
	int semester = 1;
	unsigned int selection = 0;
	bool quit = false;
	char choice = '\0';

	//object for Registration
	Registration springClass;
	Registration summerClass;
	Registration fallClass;
	//reuse class Registration to create springClass, summerClass, and fallClass objects

	cout << "Which semester would you like to register for? \n1. Spring\n2. Summer\n3. Fall\nMake your selection: ";
	cin >> semester;
	while ((semester <= 0) || (semester > 3))
	{
		cin.clear();
		cin.ignore();
		cout << "Please select one of the options above: ";
		cin >> semester;
	}

	for (;semester < 4; semester++)
	{
		do
		{
			if (semester == 1) {
				system("CLS"); //clear
				springClass.displaySemester(semester); // display the semester

				springClass.prompt(count);
				cout << "You can make your selection now: ";
				cin >> selection;
				springClass.verifySelection(selection);

				compare = springClass.studyField.at(selection);
				subject = springClass.studySubjects(selection);
				unit = springClass.unitSubjects(selection);
				springClass.minimizeCode(subject, unit, compare, count, selection);
				springClass.warning(choice, count, quit, unit, semester);
				springClass.decideSemester(choice, quit, semester); // choice to skip summer
				springClass.modify(choice, selection, quit);
			}
			else if (semester == 2)
			{
				quit = false;
				choice = '\0'; //reset choice
				system("CLS"); //clear

				summerClass.displaySemester(semester); // display the semester

				summerClass.prompt(count);
				cout << "You can make your selection now: ";
				cin >> selection;
				summerClass.verifySelection(selection);

				compare = summerClass.studyField.at(selection);
				subject = summerClass.studySubjects(selection);
				unit = summerClass.unitSubjects(selection);
				summerClass.minimizeCode(subject, unit, compare, count, selection);
				summerClass.warning(choice, count, quit, unit, semester);
				summerClass.decideSemester(choice, quit, semester); // choice to skip fall
				summerClass.modify(choice, selection, quit);
			}
			else
			{
				quit = false;
				choice = '\0'; // reset choice
				system("CLS"); //clear

				fallClass.displaySemester(semester); // display the semester

				fallClass.prompt(count);
				cout << "You can make your selection now: ";
				cin >> selection;
				fallClass.verifySelection(selection);

				compare = fallClass.studyField.at(selection);
				subject = fallClass.studySubjects(selection);
				unit = fallClass.unitSubjects(selection);
				fallClass.minimizeCode(subject, unit, compare, count, selection);
				fallClass.warning(choice, count, quit, unit, semester);
				//implement editing logic to ADD, Delete, Replace current selections
				fallClass.modify(choice, selection, quit);
			}
		} while (quit == false);
	}
	system("CLS");
	// summary for spring
	springClass.displaySemester(1);
	springClass.displaySummary(count);
	// summary for summer
	summerClass.displaySemester(2);
	summerClass.displaySummary(count);
	// summary for fall
	fallClass.displaySemester(3);
	fallClass.displaySummary(count);
	

	return 0;
}

void Registration::minimizeCode(vector<string> subject, vector<int> unit, string compare, int count, unsigned int selection) {
	if (studyField.at(selection) == compare)
	{
		cout << endl;
		for (unsigned int i = 0; i < subject.size(); i++)
		{
			cout << count << ": " << left << setw(20) << subject.at(i) << "Units: " << unit.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please make your class selection now: ";
		cin >> selection;
		while ((selection <= 0) || (selection > subject.size()))
		{
			cin.clear();
			cin.ignore();
			cout << "Your selection is invalid, please enter a # from 1 to " << subject.size() << " ";
			cin >> selection;
		}
		selection -= 1;
		storeSubjects.push_back(subject.at(selection));
		storeUnits.push_back(unit.at(selection));
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
void Registration::warning(char& choice, int count, bool& quit, vector<int> unit,int semester) {
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
	else if ((storeSubjects.size() >= 2) && (semester == 2))
	{
		system("CLS");//clear

		cout << "We recommend that you only take 2 classes during summer, you have selected these classes: " << endl;
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
void Registration::decideSemester(char choice, int quit, int &semester) {
	if ((choice == 'N')||(choice == 'n')) {
		cout << "Would you like to move to the next semester? (" << semesters.at(semester) << ") (Y) to continue (N) to skip " << semesters.at(semester) << ": ";
		cin >> choice;
		if ((choice == 'N')||(choice == 'n')) {
			semester++;
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
	if ((counter >= 12) && (counter <= 14))
	{
		cout << "You are considered a full time student because you have " << counter << " Units." << endl;
		cout << "Please Note: if you are eligible for Cal Grant then you qualify to recieve $547 dollars per semester." << endl;
		cout << "In addition, Chaffey College will grant you an SSCG grant of $647 dollars per semester.\n" << endl;
	}
	else if (counter >= 15)
	{
		cout << "You are considered a full time student because you have " << counter << " Units." << endl;
		cout << "Please Note: if you are eligible for Cal Grant then you qualify to recieve $547 dollars per semester." << endl;
		cout << "In addition, Chaffey College will grant you an SSCG grant of $2000 dollars per semester.\n" << endl;
	}
	else
	{
		cout << "You are not considered a full time student because you only have " << counter << " Units.\n" << endl;
	}
}
int Registration::verifySelection(unsigned int &selection) {
	while ((selection <= 0) || (selection > studyField.size()))
	{
		cin.clear();
		cin.ignore();
		cout << "Your selection is invalid, please enter a # from 1 to " << studyField.size() << " ";
		cin >> selection;
	}
	selection -= 1;
	return selection;
}
void Registration::displaySemester(int semester) {
	semester -= 1;
	cout << "These selections are for the (" << semesters.at(semester) << ") semester:" << endl;
}