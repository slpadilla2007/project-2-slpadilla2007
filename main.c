#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {

	private:
		string firstName;
		string lastName;
		int studentID;
		double gpa;
		int enrollYear;
		int gradYear;
		string enrollSem;
		string gradSem;
		string studType;
	public:
		Student() {
			firstName = "fn";
			lastName = "ln";
			studentId = 0;
			gpa = 0.0;
			enrollYear = 2026;
			gradYear = 2030;
			enrollSem = "N/A";
			gradSem = "N/A";
			studType = "N/A";
		}
		~Student() {}
		void setName_ID(string fN, string lN, int ID) {
			firstName = fN;
			lastName = lN;
			studentID = ID;
		}
		void setGPA(double newGPA) {
			gpa = newGPA;
		}
		void setEnroll(int year, int sem, int type) {
			enrollYear = year;
			/*For the semesters and student type variables, I've decided to
			  use switch statements with one integer value to set them.
			  This way, typing out the full name of the semester or student
			  type when the func is called isn't needed and checking for
			  validity of a string provided when the func is called isn't
			  needed.*/
			switch (sem) {
				case 1:
					enrollSem = "Fall";
				break;
				case 2:
					enrollSem = "Spring";
				break;
				case 3:
					enrollSem = "Summer";
				break;
				default:
					enrollSem = "N/A";
			}
			switch (type) {
				case 1:
					studType = "Undergraduate";
				break;
				case 2:
					studType = "Graduate";
				break;
				default:
					studType = "N/A";
			}
		}
		void setGrad(int year, int sem) {
			gradYear = year;
			switch (sem) {
				case 1:
					gradSem = "Fall";
				break;
				case 2:
					gradSem = "Spring";
				break;
				case 3:
					gradSem = "Summer";
				break;
				default:
					gradSem = "N/A";
			}
		}
		void setAll(string fN,
			    string lN,
			    int ID, 
			    double newGPA,
			    int eYear,
			    int gYear,
			    int eSem,
			    int gSem,
			    int type) {
			firstName = fN;
			lastName = lN;
			studentID = ID;
			gpa = newGPA;
			enrollYear = eYear;
			gradYear = gYear;
			
			switch (eSem) {
				case 1:
					enrollSem = "Fall";
				break;
				case 2:
					enrollSem = "Spring";
				break;
				case 3:
					enrollSem = "Summer";
				break;
				default:
					enrollSem = "N/A";
			}

			switch(gSem) {
				case 1:
					gradSem = "Fall";
				break;
				case 2:
					gradSem = "Spring";
				break;
				case 3:
					gradSem = "Summer";
				break;
				default:
					gradSem = "N/A";
			}

			switch(type) {
				case 1:
					studType = "Undergraduate";
				break;
				case 2:
					studType = "Graduate";
				break;
				default:
					studType = "N/A";
			}
		}
		string getFirstName() { return firstName; }
		string getLastName() { return lastName; }
		string getFullName() { return firstName + " " + lastName }
		int getID() { return studentID; }
		double getGPA() { return gpa;}
		int getEYear() { return enrollYear;}
		int getGYear() { return gradYear;}
		string getESem() { return enrollSem; }
		string getGSem() { return gradSem; }
		string getStudType() { return studType; }

};

class ArtStudent : public Student {

	private:
		string artEmphasis;
	public:
		ArtStudent() : Student() {
			artEmphasis = "N/A";
		}
		void setEmphasis(int emph) {
			switch (emph) {
				case 1:
					artEmphasis = "Art Studio";
				break;
				case 2:
					artEmphasis = "Art History";
				break;
				case 3:
					artEmphasis = "Art Education";
				break;
				default:
					artEmphasis = "N/A";
			}
		}
		string getEmphasis() { return artEmphasis; }

};

class PhysicsStudent : public Student {

	private:
		string concentration;
	public:
		PhysicsStudent() : Student() {
			concentration = "N/A";
		}
		void setConcentration(int con) {
			concentration.clear();
			switch (con) {
				case 1:
					concentration = "Biophysics";
				break;
				case 2:
					concentration = "Earth and Planetary Sciences";
				break;
				default:
					concentration = "N/A";
			}
		}
		string getConcentration() { return concentration; }

};

int main() {

	//Code will go here

}
