/*Problem Statement:
Given a data file, BMI_Data.txt (which contains "Weight" and "Height" data of a group of 
Adult and Children), find the maximum BMI of the whole dataset and each group.
Use Vector to store the data in two subclasses, Adult and Child, derived from Person
base class.*/ 

#include<iostream>
#include<fstream>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;
//Base Class Person
class Person{
public:
  	Person(string name);
  	string getName();
    virtual ~Person();
  	virtual double getBMI() const = 0;
  		
private:
  string person_name;
};

//Function definition
Person::Person(string name):person_name(name){}
Person::~Person(){}
string Person::getName(){return person_name;}
//------------------------------------------
//Derived Class Adult
class Adult : public Person{
public:
  	Adult(double weight, double height);
    ~Adult();//destructor 
    const Adult& operator = (const Adult& other);//assignment overload
  	virtual double getBMI() const;
  	double getWeight() const;
	double getHeight() const;
  
private:
  void copy(const Adult& other);//copy helper
  void clear();//destroy helper
	double * cntnr;
};

//Functions definition:

void Adult::copy(const Adult& other){
    cntnr = new double[2];
    cntnr[0] = other.getWeight();
    cntnr[1] = other.getHeight();
}
void Adult::clear(){
    delete []cntnr;
    cntnr = NULL;
}
Adult::Adult(double weight, double height):Person("Adult"){
    cntnr = new double[2];
    cntnr[0] = weight;
    cntnr[1] = height;
}

Adult::~Adult(){
    clear();
}
const Adult& Adult::operator = (const Adult& other){
    copy(other);
    return *this;
}
//**************************************************************//
double Adult::getBMI()const{
    if (cntnr)
        return cntnr[0] /(cntnr[1]*cntnr[1]);
    else
        return 0;
}

double Adult::getWeight()const{return cntnr? cntnr[0]:0;}
double Adult::getHeight()const{return cntnr? cntnr[1]:0;}

//--------------------------------------
//Derived Class Child
class Child : public Person{
public:
  	Child(double weight, double height);
    ~Child();//destructor overload
    const Child& operator = (const Child& other);//assignment overload
  	virtual double getBMI() const;
  	double getWeight() const;
	double getHeight() const;
  
private:
  void copy(const Child& other);//copy helper
  void clear();//destroy helper
  double * cntnr;
};
//---Function Definition------------
void Child::copy(const Child& other){
    cntnr = new double[2];
    cntnr[0] = other.getWeight();
    cntnr[1] = other.getHeight();
}
void Child::clear(){
    delete []cntnr;
    cntnr = NULL;
}
Child::Child(double weight, double height):Person("Child"){
    cntnr = new double[2];
    cntnr[0] = weight;
    cntnr[1] = height;
}

Child::~Child(){
    clear();
}
const Child& Child::operator = (const Child& other){
    copy(other);
    return *this;
}
//**************************************************************//
double Child::getBMI()const{
    if (cntnr)
        return cntnr[0] /(cntnr[1]*cntnr[1]);
    else
        return 0;
}

double Child::getWeight()const{return cntnr? cntnr[0]:0;}
double Child::getHeight()const{return cntnr? cntnr[1]:0;}

//-----Vector Creation-----------
vector<Person*> CreatePerson(char* file_name){
    ifstream ifs (file_name, std::ifstream::in);
    double num_persons = 0;
    ifs >> num_persons;
    vector<Person*> person_ptrs(num_persons, NULL);    
    for(int i = 0; i < num_persons; ++i){
        string name; 
        ifs >> name;
        if(name == "Adult"){
            double w, h;
            ifs >> w >> h;
            person_ptrs[i] = new Adult(w, h);
        }
        else if(name == "Child"){
            double w, h;
            ifs >> w >> h;
            person_ptrs[i] = new Child(w, h);
        }
    }
    ifs.close();
    return person_ptrs;
    
}
//---Finding MaxBMI Function------------
double MaxBMI(vector<Person*> person){
    double max_bmi = 0;
    
    for(size_t i = 0; i < person.size(); ++i){

        max_bmi = max(max_bmi, person[i]->getBMI());

    }
    return max_bmi;
}

//---Finding ChildMaxBMI Function------------
double ChildMaxBMI(vector<Person*> person){
    double max_bmi = 0;
    
    for(int i = 0; i < person.size(); ++i){

		if ((person[i]->getName())=="Child")

        max_bmi = max(max_bmi, person[i]->getBMI());

    }
    return max_bmi;
}


//---Main Function------------
int main(int argc, char *argv[])
{
   if(argc != 2) {
    	cerr << "USAGE: ./calculate_bmi BMI_Data.txt" << endl; 
    	return -1;
  	}
	vector<Person*> person_ptrs = CreatePerson(argv[1]);
	cout << "max BMI = " << MaxBMI(person_ptrs) << endl;	
	cout << "max Child BMI = " << ChildMaxBMI(person_ptrs) << endl;
  	return 0;         
}
