#include<bits/stdc++.h>
using namespace std;

#define Debug cout<<"Hello"<<endl;

class Person;
class Student;
class Staff;
class Staff_student;

const string uppercases="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
const string lowercases="abcdefghijklmnopqrstuvwxyz";
const string numericals="0123456789";
const string specialchars="~!@#$%^&*->_<,.+=';:|?";

class Person
{
protected:
    string name;
    string contactNumber;
    char* password;
    void displayCommonInfo()
    {
        cout<<"Type of Person: "<<getPersonType()<<endl;
        cout<<"Name: "<<getName()<<endl;
        cout<<"Contact Number: "<<getContactNumber()<<endl;
        cout<<"Password: "<<getPassword()<<endl;
    }
public:
    Person():name(""),contactNumber("") {}
    Person(string n, string cn)
    {
        setName(n);
        setContactNumber(cn);
    }
    char* getPassword()
    {
        return password;
    }
    void setPassword(char* s)
    {
        //strcpy(password,s);
        password=s;
    }
    void setName(string s)
    {
        name=s;
    }
    void setContactNumber(string s)
    {
        contactNumber=s;
    }
    string getName()
    {
        return name;
    }
    string getContactNumber()
    {
        return contactNumber;
    }
    virtual void displayInfo()=0;///Milestone 1.
    virtual string getPersonType()=0;///Milestone 1.
    virtual char* generatePassword()=0;///Milestone 2.
    friend void addContactPrefix(Person* pp);///Milestone 4.
    virtual ~Person()
    {
        delete password;///Deallocating the dynamically allocated memory of Password char*.
    }
};
class Student:virtual public Person
{
protected:
    int studentID;
    string degree;
    string dept;
public:
    Student():Person(),studentID(-1),degree(""),dept("") {}
    Student(string n, string cn, int id, string deg, string dep):Person(n,cn)
    {
        setPassword(generatePassword());
        setID(id);
        setDegree(deg);
        setDept(dep);
    }
    char* generatePassword()
    {
        char *p=new char[13];
        int i;
        for(i=0; i<5; i++)
        {
            p[i]=uppercases[rand()%26];
        }
        for(i=5; i<9; i++)
        {
            p[i]=lowercases[rand()%26];
        }
        p[i]=numericals[rand()%10];
        for(i=10; i<12; i++)
        {
            p[i]=specialchars[rand()%22];
        }
        p[12]='\0';
        random_shuffle(p,p+12);///Built-in function to randomly shuffle the password string.
        return p;
    }
    void setID(int id)
    {
        studentID=id;
    }
    void setDegree(string d)
    {
        degree=d;
    }
    void setDept(string d)
    {
        dept=d;
    }
    int getID()
    {
        return studentID;
    }
    string getDegree()
    {
        return degree;
    }
    string getDept()
    {
        return dept;
    }
    string getPersonType()
    {
        return "Student";
    }
    void displayStudentInfo()
    {
        cout<<"Student ID: "<<getID()<<endl;
        cout<<"Program: "<<getDegree()<<" "<<getDept()<<endl;
    }
    void displayInfo()
    {
        displayCommonInfo();
        displayStudentInfo();
    }
};
class Staff:virtual public Person
{
protected:
    string joinDate;
    string designation;
    string dept;
public:
    Staff():Person(),joinDate(""),designation(""),dept("") {}
    Staff(string n, string cn, string d, string des, string dep):Person(n,cn)
    {
        setPassword(generatePassword());
        setDate(d);
        setDesignation(des);
        setDept(dep);
    }
    char* generatePassword()
    {
        char *p=new char[13];
        int i;
        for(i=0; i<2; i++)
        {
            p[i]=uppercases[rand()%26];
        }
        for(i=2; i<7; i++)
        {
            p[i]=lowercases[rand()%26];
        }
        p[i]=specialchars[rand()%22];
        for(i=8; i<12; i++)
        {
            p[i]=numericals[rand()%10];
        }
        p[12]='\0';
        random_shuffle(p,p+12);///Built-in function to randomly shuffle the password string.
        return p;
    }
    void setDate(string d)
    {
        joinDate=d;
    }
    void setDesignation(string d)
    {
        designation=d;
    }
    void setDept(string d)
    {
        dept=d;
    }
    string getDate()
    {
        return joinDate;
    }
    string getDesignation()
    {
        return designation;
    }
    string getDept()
    {
        return dept;
    }
    string getPersonType()
    {
        return "Staff";
    }
    void displayStaffInfo()
    {
        cout<<"Joining Date: "<<getDate()<<endl;
        cout<<"Designation: "<<getDesignation()<<endl;
        cout<<"Office/Department: "<<getDept()<<endl;
    }
    void displayInfo()
    {
        displayCommonInfo();
        displayStaffInfo();
    }
};
class Staff_student:public Student, public Staff///Milestone 3.
{
private:
    double numberOfCredits;
public:
    Staff_student():Person(),Student(),Staff(),numberOfCredits(-1.0) {}
    Staff_student(string n, string cn, string d, string des, string dep,int id, string deg, double nc):Person(n,cn),Student(n,cn,id,deg,dep),Staff(n,cn,d,des,dep)
    {
        setNumberOfCredits(nc);
        setPassword(generatePassword());
    }
    void setNumberOfCredits(double nc)
    {
        numberOfCredits=nc;
    }
    char* generatePassword()
    {
        return Student::generatePassword();
    }
    double getNumberOfCredits()
    {
        return numberOfCredits;
    }
    string getPersonType()
    {
        return "Staff-Student";
    }
    void displayInfo()
    {
        displayCommonInfo();
        displayStudentInfo();
        displayStaffInfo();
        cout<<fixed<<setprecision(2)<<"Number of Credits: "<<getNumberOfCredits()<<endl;
    }

};
void addContactPrefix(Person* pp)
{
    if((pp->contactNumber).substr(0,3)!="+88")///Checking if "+88" is already appended before a Contact Number or not.
    {
        string phonePrefixCode="+88";
        pp->contactNumber=phonePrefixCode+(pp->contactNumber);
    }
}
int main()
{
    /**
        create a list of people 5 Student, 5 Staff, 5 staff_student;
    */
    /**
        display all the information of each people
        display the type of people (student, staff, staff_student)
    */
    srand(time(0));
    Person* peopleList[15];
    ///A total of 15 persons, where 5 are Students, 5 are Staffs and 5 are Staff-Students.
    peopleList[0]=new Student("Syed Rifat Raiyan","01721886738",180041205,"BSc","CSE");
    peopleList[1]=new Staff("Faisal Hussain","12345678901","11-09-2001","Lecturer","CSE");
    peopleList[2]=new Staff_student("M.K. Bashar","12312312312","04-07-2020","Teaching Assistant","CSE",180041238,"BSc",21.0);
    peopleList[3]=new Student("Shah Jawad Kabir","01721887838",180041234,"BSc","CSE");
    peopleList[4]=new Staff("Abu Taher","12345678901","25-03-1971","Lecturer","CSE");
    peopleList[5]=new Staff_student("Fardin Saad","12312312312","04-03-2020","Teaching Assistant","CSE",144487,"BSc",22.0);
    peopleList[6]=new Student("Syed Md. Sartaj Ekram","01721566738",180041204,"BSc","CSE");
    peopleList[7]=new Staff("Md. Hamjajul Ashmafee","12345678901","20-04-1889","Lecturer","CSE");
    peopleList[8]=new Staff_student("Saidul Bashar","12312312312","04-02-2020","Teaching Assistant","CSE",144436,"BSc",23.5);
    peopleList[9]=new Student("Ishrak Hossain","01723256738",180041218,"BSc","CSE");
    peopleList[10]=new Staff("Rezaul Karim","12345678901","18-12-1878","Lecturer","EEE");
    peopleList[11]=new Staff_student("Anas Jawad","12312312312","16-12-1971","Lecturer","CSE",144424,"BSc",69.420);
    peopleList[12]=new Student("Shah Jawad Islam","01721883678",180041223,"BSc","CSE");
    peopleList[13]=new Staff("Shihab Rashid","12345678901","15-08-1947","Ex-Lecturer","CSE");
    peopleList[14]=new Staff_student("Melon","12312312312","04-07-2014","Technical Support","EEE",134579,"MSc",22.7);
    for(int i=0; i<15; i++)///Display function called.
    {
        cout<<i+1<<":"<<endl;
        peopleList[i]->displayInfo();
        cout<<endl;
    }
    addContactPrefix(peopleList[0]);
    addContactPrefix(peopleList[1]);
    addContactPrefix(peopleList[2]);
    addContactPrefix(peopleList[0]);
    cout<<"After calling addContactPrefix() function: "<<endl;///Appending "+88" in front.
    peopleList[0]->displayInfo();
    cout<<endl;
    peopleList[1]->displayInfo();
    cout<<endl;
    peopleList[2]->displayInfo();
    cout<<endl;
    for(int i=0; i<15; i++)
    {
        delete peopleList[i];///Deallocating the dynamically allocated memory of the objects.
    }
    return 0;
}
