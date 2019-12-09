#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Registration {
public:
	//public functions overloaded with main() function variables
	void minimizeCode(vector<string>,string,int&,int);
	vector<string> studySubjects(int);
	void warning(char &, int &, bool &);
	void prompt(int);
	void displaySummary(int);
	void modify(char,int);

	//public variables initilized to vector string values
	vector < string > studyField = { "Science", "Mathematics", "Arts", "Humanities" };
	vector < string > science = { "Earth Science", "Biology", "Oceanography", "Geology", "Astronomy" };
	vector < string > mathematics = { "Pre-Algebra", "Algebra", "Geometry", "Calculus I", "Calculus II" };
	vector < string > arts = { "Music", "Painting", "Literature", "Sculpting", "Film" };
	vector < string > humanities = { "Japenese", "Creative Writing", "Elementary French", "Hispanic Literature", "California History" };
	vector <string> storeSubjects;
	
private:

};

int main()
{
	//variables outside of class ceated for making decisions
	vector <string> subject;
	string compare = "\0";
	int count = 1;
	int selection = 0;
	bool quit = false;
	char choice = '\0';

	//object for Registration
	Registration springClass;
	//reuse class registration to create summerClass, and fallClass objects

	do
	{
		springClass.prompt(count);
		cout << "You can make your selection now: ";
		cin >> selection;
		selection -= 1;

		compare = springClass.studyField.at(selection);
		subject = springClass.studySubjects(selection);
		springClass.minimizeCode(subject,compare,count,selection);
		springClass.warning(choice,count,quit);
		springClass.modify(choice,selection);

	} while (quit == false);
	springClass.displaySummary(count);
	//implement editing logic to ADD, Delete, Replace current selections

	return 0;
}

void Registration::minimizeCode(vector<string> subject, string compare, int &count, int selection) {
	if (studyField.at(selection) == compare)
	{
		for (unsigned int i = 0; i < subject.size(); i++)
		{
			cout << count << ": " << subject.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please make your class selection now: ";
		cin >> selection;
		selection -= 1;
		storeSubjects.push_back(subject.at(selection));
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
void Registration::prompt(int count) {
	cout << "Please select a field of study" << endl;
	for (unsigned int i = 0; i < studyField.size(); i++)
	{
		cout << count << ": " << studyField.at(i) << endl;
		count++;
	}
	count = 1;
}
void Registration::warning(char &choice, int &count, bool &quit) {
	if (storeSubjects.size() >= 4)
	{
		cout << "\nWe recommend that you only take 4 classes per semester, you have selected these classes: " << endl;
		cout << "------------------------" << endl;
			
		for (unsigned int i = 0; i < storeSubjects.size(); i++)
		{
			cout << count << ": " << storeSubjects.at(i) << endl;
			cout << "------------------------" << endl;
			count++;
		}
		count = 1;
		cout << "\nwould you like to add more? (Y / N): ";
		cin >> choice;
		if(choice == 'N')
		{
			quit = true;
			if (quit == true)
			{
				cout << "If you would like to DELETE or REPLACE one of the above classes type: (D) to delete / (R) to replace\nOtherwise type: (N) ";
				cin >> choice;
			}
		}
	}
}
void Registration::modify(char choice, int selection) {
	if (choice == 'D') {
		cout << "Which selection would you like to delete? from 1 to " << storeSubjects.size() << ": ";
		cin >> selection;
		selection -= 1;
		storeSubjects.erase(storeSubjects.begin() + selection);
	}
}
void Registration::displaySummary(int count) {
	cout << "\nYou have selected the following classes: " << endl;
	cout << "_________________________________________________________________________________________" << endl;
	for (unsigned int i = 0; i < storeSubjects.size(); ++i)
	{
		cout << count << ": " << storeSubjects.at(i) << "   |   ";
		if (i == 3) {
			cout << endl;
			cout << "_________________________________________________________________________________________" << endl;
		}

		count++;
	}
	count = 1;
	cout << endl;
}