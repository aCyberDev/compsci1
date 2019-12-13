#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Registration {
public:
	//public functions overloaded with main() function variables
	void minimizeCode(vector<string>, vector<int>, string, int, int);
	vector<string> studySubjects(int);
	vector<int> unitSubjects(int);
	void warning(char&, int, bool&, vector<int> unit);
	void prompt(int);
	void displaySummary(int);
	void modify(char, int, bool&);
	void displaySemester(int);
	void decideSemester(char,int,int&);
	//verify that user input follows the program
	int verifySelection(unsigned int&);

	//public variables initilized to vector string values
	vector <string> semesters = { "Spring", "Summer", "Fall" };
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
	int semester = 1;
	unsigned int selection = 0;
	bool quit = false;
	char choice = '\0';
	char dummyVar = '\0';

	//object for Registration
	Registration springClass;
	Registration summerClass;
	Registration fallClass;
	//reuse class registration to create summerClass, and fallClass objects

	cout << "Which semester would you like to register for? \n1. Spring\n2. Summer\n3. Fall\nMake your selection: ";
	cin >> semester;

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
				springClass.warning(choice, count, quit, unit);
				springClass.decideSemester(choice, quit, semester); // choice to skip summer
				springClass.modify(choice, selection, quit);
			}
			else if (semester == 2)
			{
				quit = false;
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
				summerClass.warning(choice, count, quit, unit);
				summerClass.decideSemester(choice, quit, semester); // choice to skip fall
				summerClass.modify(choice, selection, quit);
			}
			else
			{
				quit = false;
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
				fallClass.warning(choice, count, quit, unit);
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

void Registration::minimizeCode(vector<string> subject, vector<int> unit, string compare, int count, int selection) {
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
void Registration::warning(char& choice, int count, bool& quit, vector<int> unit) {
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
void Registration::decideSemester(char choice, int quit, int &semester) {
	if ((choice == 'N')||(choice == 'n')) {
		cout << "Would you like to move to the next semester? (" << semesters.at(semester) << ") (Y) to continue (N) to skip " << semesters.at(semester) << ": " << endl;;
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