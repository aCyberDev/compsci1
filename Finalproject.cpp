#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

class Registration {
public:
	//public functions overloaded with main() function variables
	void minimizeCode(vector<string>, vector<int>, string, int&, int);
	void warning(char&, int&, bool&, vector<int> unit);
	void prompt(int);
	void displaySummary(int);
	void modify(char, int, bool&);
	//verify that user input follows the program
	int verifySelection(unsigned int&);

	//public variables initilized to vector string values
	vector < string > studyField = { "Science", "Mathematics", "Arts", "Humanities" };
	vector <string> storeSubjects;
	vector <int> storeUnits;
private:

};

class springClass : public Registration {
public:
	vector < string > science = { "Earth Science", "Biology", "Oceanography", "Geology", "Astronomy" };
	vector < string > mathematics = { "Pre-Algebra", "Algebra", "Geometry", "Calculus I", "Calculus II" };
	vector < string > arts = { "Music", "Painting", "Literature", "Sculpting", "Film" };
	vector < string > humanities = { "Japenese", "Creative Writing", "Elementary French", "Hispanic Literature", "California History" };
	vector <int> unitScience = { 3, 4, 3, 3, 2 };
	vector <int> unitMath = { 2, 4, 4, 4, 4 };
	vector <int> unitArts = { 3, 3, 4, 3, 4 };
	vector <int> unitHumanities = { 3, 4, 3, 4, 3 };
};
class summerClass : public Registration {
public:
	vector < string > science = { "Physics", "Chemistry", "Forensic Science", "Environmental Science", "MicroBiology" };
	vector < string > mathematics = { "Linear Algebra", "Statistics", "Differential Equations", "Problem Solving", "Trigonometry" };
	vector < string > arts = { "Ceramics", "Singing", "Dancing", "Woodshop", "Acting" };
	vector < string > humanities = { "Korean History", "English I", "English II", "World History", "New Jersey History" };
	vector <int> unitScience = { 5, 4, 4, 2, 5 };
	vector <int> unitMath = { 5, 2, 3, 3, 4 };
	vector <int> unitArts = { 2, 3, 3, 3, 4 };
	vector <int> unitHumanities = { 3, 4, 4, 3, 2 };
};
class fallClass : public Registration {
public:
	vector < string > science = { "Ecology", "Organic Chemistry", "Basic Science", "Marine Biology", "Nursing" };
	vector < string > mathematics = { "Elementary Algebra", "Intermediate Algebra", "Modules", "Analytic Geometry", "Finite Mathematics" };
	vector < string > arts = { "Photography", "Printmaking", "Animation", "Art Appreciation", "Architecture" };
	vector < string > humanities = { "Anthropology", "Archaeology", "Philosophy", "Law", "Politics" };
	vector <int> unitScience = { 3, 5, 2, 4, 5 };
	vector <int> unitMath = { 2, 3, 4, 4, 4 };
	vector <int> unitArts = { 2, 2, 3, 2, 4 };
	vector <int> unitHumanities = { 3, 3, 3, 5, 3 };
};
template <typename Type> //lets you use any data type
vector<string> studySubjects(int selection, Type& semester) {
	if (semester->studyField.at(selection) == "Science") {
		return semester->science;
	}
	else if (semester->studyField.at(selection) == "Mathematics")
	{
		return semester->mathematics;
	}
	else if (semester->studyField.at(selection) == "Arts")
	{
		return semester->arts;
	}
	else
	{
		return semester->humanities;
	}
}
template <typename Type> //lets you use any data type
vector<int> unitSubjects(int selection, Type& semester) {
	if (selection == 0)
	{
		return semester->unitScience;
	}
	else if (selection == 1)
	{
		return semester->unitMath;
	}
	else if (selection == 2)
	{
		return semester->unitArts;
	}
	else
	{
		return semester->unitHumanities;
	}
}
template <typename Type> //lets you use any data type
void start(Type& semester) {
	//variables outside of class created for making decisions
	vector <string> subject;
	vector<int> unit;
	string compare = "\0";
	int count = 1;
	unsigned int selection = 0;
	bool quit = false;
	char choice = '\0';
	char dummyVar = '\0';

	do
	{
		system("CLS"); //clear

		semester->prompt(count);
		cout << "You can make your selection now: ";
		cin >> selection;
		semester->verifySelection(selection);

		compare = semester->studyField.at(selection);
		subject = studySubjects(selection, semester);
		unit = unitSubjects(selection, semester);
		semester->minimizeCode(subject, unit, compare, count, selection);
		semester->warning(choice, count, quit, unit);
		semester->modify(choice, selection, quit);

	} while (quit == false);
	semester->displaySummary(count);
}
int main()
{
	char userSem = '\0';

	do {
		system("CLS");

		cout << "Semester you are attending: " << endl;
		cout << "1: Summer" << endl;
		cout << "2: Spring" << endl;
		cout << "3: Fall" << endl << endl;
		cout << "Choice: ";
		cin >> userSem;
	} while (userSem != '1' && userSem != '2' && userSem != '3');

	if (userSem == '1') {
		summerClass* semester = new summerClass;
		start(semester);
	}
	else if (userSem == '2') {
		springClass* semester = new springClass;
		start(semester);
	}
	else {
		fallClass* semester = new fallClass;
		start(semester);
	}

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
void Registration::modify(char choice, int selection, bool& quit) {
	if (choice == 'D' || choice == 'd') {
		cout << "Which selection would you like to delete? from 1 to " << storeSubjects.size() << ": ";
		cin >> selection;
		selection -= 1;
		storeSubjects.erase(storeSubjects.begin() + selection);
		storeUnits.erase(storeUnits.begin() + selection);
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
int Registration::verifySelection(unsigned int& selection) {
	while ((selection <= 0) || (selection > studyField.size()))
	{
		cout << "Your selection is invalid, please enter a # from 1 to " << studyField.size() << " ";
		cin >> selection;
	}
	selection -= 1;
	return selection;
}
