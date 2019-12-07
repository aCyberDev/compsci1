#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Registration {
public:
	void subjectScience();
	void subjectMath();
	void subjectArt();
	void subjectHumanities();
	void field();
	int studySelection(int);
	void setSelection(int);
	void storedSubjects();

	vector<string> studyField = { "Science", "Mathematics", "Arts", "Humanities" };
	vector<string> science = { "Earth Science", "Biology", "Oceanography", "Geology", "Astronomy" };
	vector<string> mathematics = { "Pre-Algebra", "Algebra", "Geometry", "Calculus I", "Calculus II" };
	vector<string> arts = { "Music", "Painting", "Literature", "Sculpting", "Film" };
	vector<string> humanities = { "American Sign Lang", "Creative Writing: Fiction", "Elementary French","Hispanic Literature","California History" };
	vector<string> storeSubject;
	int count = 1;

private:

};
void Registration::field() {
	for (unsigned int i = 0; i < studyField.size(); i++)
	{
		cout << count << ": " << studyField.at(i) << endl;
		count++;
	}
	count = 1;
}
int Registration::studySelection(int study_Selection) {
	cout << "You have chosen: " << studyField.at(study_Selection) << endl;
	return study_Selection;
}
void Registration::setSelection(int study_selection) {
	
	if (studyField.at(study_selection) == "Science")
	{
		for (unsigned int i = 0; i < science.size(); i++)
		{
			cout << count << ": " << science.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please select one of the study subjects: ";
		cin >> study_selection;
		study_selection -= 1;
		storeSubject.push_back(science.at(study_selection));
	}
	else if (studyField.at(study_selection) == "Mathematics")
	{
		for (unsigned int i = 0; i < mathematics.size(); i++)
		{
			cout << count << ": " << mathematics.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please select one of the study subjects: ";
		cin >> study_selection;
		study_selection -= 1;
		storeSubject.push_back(mathematics.at(study_selection));
	}
	else if (studyField.at(study_selection) == "Arts")
	{
		for (unsigned int i = 0; i < arts.size(); i++)
		{
			cout << count << ": " << arts.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please select one of the study subjects: ";
		cin >> study_selection;
		study_selection -= 1;
		storeSubject.push_back(arts.at(study_selection));
	}
	else if (studyField.at(study_selection) == "Humanities")
	{
		for (unsigned int i = 0; i < humanities.size(); i++)
		{
			cout << count << ": " << humanities.at(i) << endl;
			count++;
		}
		count = 1;
		cout << "Please select one of the study subjects: ";
		cin >> study_selection;
		study_selection -= 1;
		storeSubject.push_back(humanities.at(study_selection));
	}

}
void Registration::storedSubjects() {
	for (unsigned int i = 0; i < storeSubject.size(); i++)
	{
		cout << count << ": " << storeSubject.at(i) << endl;
		count++;
	}
	count = 1;
}

int main() {
	int selection = 0;
	char Quit = 'N';

	Registration studentClasses;

	cout << "Spring registration is open please choose a field of study from the following: (between 1 and 4)\n" << endl;
	do
	{
		if (Quit == 'Y')
		{
			cout << "Please choose a field of study again." << endl;
		}
		studentClasses.field();
		cout << endl;
		cout << "Please make your selection now: ";
		cin >> selection;
		selection -= 1;
		cout << endl;

		studentClasses.studySelection(selection);
		studentClasses.setSelection(selection);
		cout << endl;

		cout << "Would you like to add more classes? (Y / N) ";
		cin >> Quit;
	} while (Quit == 'Y');
	
	cout << "You have signed up to the following: " << endl;
	studentClasses.storedSubjects();

	//create a function that verifies that the input is correct/within the menu options.
	//if subject is Science
		//then display field of study (example: 1.Earth Science, 2.Oceanography, 3.Biology etc.)
		//create a vector that holds amount of units for each subject
	//save options for future summary.


	//selection -= 1;
	//array(selection);

	//unitAmount += vectorValue(selection);
	//provide summary 

	 // unitAmount"/12" << endl;

	return 0;
}