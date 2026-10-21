#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Student {

	private:
		//All vars needed for both art and physics students
		string firstName;
		string lastName;
		//I added an ID variable because I felt that could be important
		int studentID;
		double gpa;
		int enrollYear;
		int gradYear;
		string enrollSem;
		string gradSem;
		string studType;
	public:
		//Default constructor
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
		//Default destructor
		~Student() {}
		//All needed setter functions
		void setName(string fN, string lN) {
			firstName = fN;
			lastName = lN;
		}
		void setName_ID(string fN, string lN, int IDnum) {
			firstName = fN;
			lastName = lN;
			studentID = IDnum;
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
			    int IDnum,
			    double newGPA,
			    int eYear,
			    int gYear,
			    int eSem,
			    int gSem,
			    int type) {
			firstName = fN;
			lastName = lN;
			studentID = IDnum;
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

		//All needed getter functions
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
		//Needed variable for art students
		string artEmphasis;
	public:
		//Default constructor
		ArtStudent() : Student() {
			artEmphasis = "N/A";
		}
		//Needed setter function
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
		//Needed getter function
		string getEmphasis() { return artEmphasis; }

};

class PhysicsStudent : public Student {

	private:
		//Needed variable for physics students
		string concentration;
	public:
		//Default constructor
		PhysicsStudent() : Student() {
			concentration = "N/A";
		}
		//Needed setter function
		void setConcentration(int con) {
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
		//Needed getter function
		string getConcentration() { return concentration; }

};

int main() {
	
	//Two needed vectors for art and physics students
	vector<ArtStudent *> artStudents;
	vector<PhysicsStudent *> physStudents;
	//Allocates all needed memory
	for (int i = 0; i < 5; i++) {
		artStudents.push_back(new ArtStudent);
		physStudents.push_back(new PhysicsStudent);
	}
	//All 5 art students
	//This first art student is for demonstration of the setter funcs
	artStudents[0]->setName_ID("Laura", "Johnson", 48472);
	artStudents[0]->setGPA(3.6);
	artStudents[0]->setEnroll(2024, 1, 1);
	artStudents[0]->setGrad(2028, 2);
	artStudents[0]->setEmphasis(2);

	//For all the others, I'll use the setAll func
	artStudents[1]->setAll("Dahlia", "Lianne", 68892, 3.8, 2021, 2026, 2, 1, 2);
	artStudents[1]->setEmphasis(1);

	artStudents[2]->setAll("Nik", "Natalia", 54715, 2.7, 2023, 2027, 1, 3, 1);
	artStudents[2]->setEmphasis(3);
	
	artStudents[3]->setAll("Dana", "Lennart", 37567, 4.1, 2026, 2030, 1, 2, 1);
	artStudents[3]->setEmphasis(3);
	
	artStudents[4]->setAll("Grady", "Hayden", 71524, 1.0, 2010, 2029, 3, 3, 1);
	artStudents[4]->setEmphasis(1);
	
	//All 5 physics students
	physStudents[0]->setAll("Caty", "Duncan", 17566, 4.99, 2025, 2027, 1, 3, 1);
	physStudents[0]->setConcentration(1);

	physStudents[1]->setAll("Derek", "Fuller", 77807, 2.0, 2022, 2026, 2, 2, 2);
	physStudents[1]->setConcentration(1);

	physStudents[2]->setAll("Al", "Erickson", 37097, 3.5, 2024, 2028, 1, 3, 2);
	physStudents[2]->setConcentration(2);

	physStudents[3]->setAll("Terrancy", "Rowe", 25939, 3.6, 2025, 2030, 2, 1, 1);
	physStudents[3]->setConcentration(1);

	physStudents[4]->setAll("Ted", "Walton", 44522, 4.0, 2023, 2027, 3, 1, 1);
	physStudents[4]->setConcentration(2);

	ofstream StudData("student_info.dat");

	for (int i = 0; i < artStudents.size(); i++) {
		StudData << artStudents[i]->getFullName() << ", "
			<< artStudents[i]->getID() << ", "
			<< artStudents[i]->getGPA() << ", "
			<< artStudents[i]->getEYear() << ", "
			<< artStudents[i]->getGYear() << ", "
			<< artStudents[i]->getESem() << ", "
			<< artStudents[i]->getGSem() << ", "
			<< artStudents[i]->getStudType() << ", "
			<< artStudents[i]->getEmphasis() << endl;
	}
	
	for (int i = 0; i < physStudents.size(); i++) {
		StudData << physStudents[i]->getFullName() << ", "
			<< physStudents[i]->getID() << ", "
			<< physStudents[i]->getGPA() << ", "
			<< physStudents[i]->getEYear() << ", "
			<< physStudents[i]->getGYear() << ", "
			<< physStudents[i]->getESem() << ", "
			<< physStudents[i]->getGSem() << ", "
			<< physStudents[i]->getStudType() << ", "
			<< physStudents[i]->getConcentration() << endl;
	}

	StudData.close();

	return 0;

}
