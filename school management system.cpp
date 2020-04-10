//this project is created by shahzad Ali, TajammalRsool ang their 2 team members
//first of all you will make files on that location where your program is located.
//then make files name..student..teacher..temp.. of .txt file.

#include<iostream>
#include<iomanip> //used for setw() function
#include<cstring>
#include<fstream> //used for file handleing
using namespace std;

struct Student
{	
	string rollno;
    string studentname;
	string fathername;
	string dateofbirth;
	string gender;
	string bform;
	string address;
	string phoneno;
	string Class;
};

struct Teacher
{
    string teachername;
	string fathername;
	string experience;
	string gender;
	string CNIC;
	string gmail;
	string phoneno;
	string qualification;
	string address;
};

void board();
void student();
void teacher();
void stRegister();
void teRegister();
void stdisplayall();
void tedisplayall();
void stsearch(string find);
void tesearch(string find);
void stdeleting();
void tedeleting(string mail);
int stLoginCheck (string user, string pass);
int teLoginCheck (string user, string pass);

string user;
string pass;
Student p1;
Teacher t1;
int main()
{
	label :
	system("cls"); //to clear screen
	board();
	cout<<"Please Enter Your Choice"<<endl<<endl;
	cout<<"If you are a Student press 1"<<endl; 
	cout<<"If you are a  Teacher press 2"<<endl;
	cout<<"If you are Admin press 3"<<endl;
	cout<<"Press 4 to exit the program :"<<endl;
	int choice;
	cin>>choice;
	
	system("cls");
	
	string username,passward;
	int loginattempts;
	switch (choice)
	{
		
		case 1:
		{
			cout<<setw(20)<<"login"<<endl; //setw(20) used to give 20 spaces
			
			
			while (stLoginCheck(user, pass)==0)
    	    {
    	        loginattempts++;
    	        cout << "Username: ";
    	        cin >> user;
    	        cout << "Password: ";
    	        cin >> pass;
    	        if (stLoginCheck(user, pass)!=0) //it can check the login function
    	        {
    	        	stsearch(user);
    	    	}
				else if (loginattempts==3) //we give 3 loin attempts
    	        {
    	            cout << "Maximum login attempts exceeded." << endl;
    	            break;
    	        }
    	        else
    	        {
    	            cout << "Invalid username/password combination" << endl;
    	            cout<< "enter 3 to change password"<<endl;
	
	            }
	            
	        }
	        break ;
	
		}
	
		case 2:
		{
			cout<<setw(20)<<"login"<<endl;
			
			while (teLoginCheck(user, pass)==0) //this function check the login of user
    	    {
    	        loginattempts++;
    	        cout << "Username(Gmail): ";
    	        cin >> user;
    	        
    	        
    	        char at = '@'; // used for to check email address ..to right or wrong
				string str;
				str =  user;
    			bool Gmail = false; //if user can't use @ symbole ..program give it false
    			char ch; 
    			int l = str.length(); 
    			for (int i = 0; i < l; i++) 
				{
    	    		ch = str.at(i); 
   	    			if(ch == at)
					{
						Gmail = true;	//if user use @ symbole than it give true
					} 
		    	}
		    	
		    	if(Gmail == true) //then check the log in function
	    		{
    	        	cout << "Password: ";
    	        	cin >> pass;
    	        	if (teLoginCheck(user, pass)==0) //if user give true password it will go forward
    	        	{
    	        		tesearch(user);
    	        		break;
    	    		}
					else if (loginattempts==3)//if user enter three time wrong password
    	        	{
    	        	    cout << "Maximum login attempts exceeded." << endl;
    	        	    break;
    	        	}
    	        	else
    	        	{
    	        	    cout << "Invalid password " << endl;
    	        	   // cout<< "enter 3 to change password"<<endl;
	
	            	}
	        	}
	        	
	        	else
				{
					cout<<"invalid email. @ is missing";
				}
	            
	        }
			
			break ;
		
		}
	
		case 3:
		{
		
			cout<<setw(20)<<"login"<<endl<<endl;
			int adminchoice;
			int a = 1;//1 is used for admin
			if(a == 1)
			{
				cout<<setw(23)<<"**WELCOME**"<<endl<<endl;
				cout<<"Please Enter a choice to Perform Required Operation :"<<endl<<endl<<endl;	
				cout<<" 1. for Student's Records "<<endl;
				cout<<" 2. for Teacher's  Records "<<endl;
				
				cout<<endl<<endl<<endl;
				cout<<"Enter your chice here :";
				
				cin>>adminchoice;
				system("cls");
				if(adminchoice==1)
				{
					int b;
					cout<<"1. Enter New Record :"<<endl;
					cout<<"2. Display all records :"<<endl;
					cout<<"3. Delet Existing Record :"<<endl;
					cout<<"4. Open Main Menu :"<<endl<<endl<<endl;
					cout<<"Enter your choice here :";
					cin>>b;
				
					if(b==1)
					{
						//cout<<"Please Enter the following information :"<<endl;
						again :
						system("cls");	
						cout <<"Please set username(Roll Number) and password for student "<<endl;						
						stRegister();//for new registrion
						student();
						string c;
						cout<<"Press 1 to enter new record or any other key to exit ";
						getline(cin,c);
						if(c=="1") //for new recorde
						{
							goto again; //if input is wrong it will go to back on 194 line where again: is used.
						}
						else 
						{
							goto exit ; //if password is true..it will go next
						}
					}
					
					else if(b==2) //for show all recorda that are in the file..
					{
						cout<<"All Records are\n===========================================\n :";
						 stdisplayall();
					}
					else if(b==3) //for delet any record from file through program
					{
						cout<<"Enter the roll no. to delet record :";
						stdeleting();
					}
					else if(b==4) //used to send back to label function
					{
						goto label;
					}
					else
					{
						cout<<"You entered invalid number";
					}
					
				}
				else if(adminchoice==2)
				{
					int adchoice;
					cout<<"1. Enter New Record :"<<endl;
					cout<<"2. Display All Records :"<<endl;
					cout<<"3. Delet Existing Record :"<<endl;
					cout<<"4. Open Main Menu :"<<endl<<endl<<endl;
					cout<<"Enter your choice here :";
					cin>>adchoice;
					
					
					if(adchoice==1)
					{
						onceagain : //for retun program to that line
						system("cls");	
						cout <<"Please set username(Gmail) and password for Teacher "<<endl;						
						teRegister();
						teacher();		
						string d;
						cout<<"Enter 1 to enter another record or any key to exit :"<<endl;
   						getline(cin,d);//getline work as cin>> it is used to put values in file directly
   						if(d=="1")
						{
							goto onceagain; //send program back..
						}
						else 
						{
							goto exit ;
						}
   
					}
					
					
					else if(adchoice==2)
					{
						cout<<"All Records are\n===========================================\n :";
						tedisplayall();//for display all records
					}
					else if(adchoice==3)
					{
						cout<<"Enter the Gmail to delet record :";
						
						char at = '@';
						string str;
    					bool Gmail = false;
    					char ch; 
   					 	int l = str.length(); //is a function call
						
						
						string gmail;
						cin>>gmail;
						str = gmail;
						for (int i = 0; i < l; i++) 
						{
    					    ch = str.at(i); 
        					if(ch == at)
							{
								Gmail = true;	
							} 
					    }
    					if(Gmail == true)
    					{
    						tedeleting(gmail);
						}
						else
						{
						cout<<"invalid email. @ is missing";
						}
						
						
						
						
					}
					else if(adchoice==4)
					{
						goto label;
					}
					else
					{
						cout<<"You entered invalid number";
					}
					
					
					
				}	
			}
			else
			{ 
				cout<<"Please Enter a valid username or password";	
			}
			break ;
		}
		
		case 4:
		{
			goto exit;
			break ;
			
		}
	
		default :
		cout <<"Please Enter a Valid choic :";
}
		exit :
	
	return 0;	
}



void stRegister()
{
	
	//cout<<"\t\t\t\t\t========================="<<endl;
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm;
    file.open("studentp.txt", ios::app);//ios::app is used to find the end of file and the enter the new record at then end..and all records remain same
    newuser.open("studentp.txt", ios::app);//"student.txt" is a file that we made in our computer to save records..
    bool uservalid=false;
   // cout<<"\t\t\t\t\t=========================="<<endl;
    while (!uservalid) //if user not valid in file...it take new record
    {
        cout << "\tUsername: ";
        cin >> username;
        cout << "\tPassword: ";
        cin >> password;
        cout << "\tConfirm password: ";
        cin >> passwordconfirm;
        int m=0;
        int k=0;
        while (file >> user >> pass)
        {
            m++;//to increse and check users in file one by one
            if (username!=user)
            k++;//to go forward
        }
        if (m==k && password==passwordconfirm)
            uservalid=true;
        else if (m!=k)
            cout << "There is already a user with this username." << endl;//if user enter same password or name that is already in the file.
        else
            cout << "The passwords given do not match." << endl;
    }
    newuser << username << "\n" << password << endl;
    file.close();
    newuser.close();
}

int stLoginCheck (string user, string pass)//used to check login function with peremeters
{
    ifstream file;
    string username, password;
    int n=0;
    file.open("studentp.txt");//to open the file.from the location of program
    if (file.is_open())
    {
    		//cout<<"\t\t\t\t\t=============================="<<endl;
        while (!file.eof())//! it can change the functionality of program..change ture to false and false to true..to go at the end of file
        {
           file >> username >> password;
            n++;
            if (user==username && pass==password) //if user name and password are same in the file
        	return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }
    return 0;
}




void board()
{
	cout<<endl;
	cout<<endl;
	cout<<"\t\t\t\t******************************************************************************"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<< "Welcome to School Management System" <<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t******************************************************************************"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"Group Members"<<"\t"<<"\t"<<"\t"<<"\t"<<"Roll No"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"______________"<<"\t"<<"\t"<<"\t"<<"\t"<<"________"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"______________"<<"\t"<<"\t"<<"\t"<<"\t"<<"________"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"______________"<<"\t"<<"\t"<<"\t"<<"\t"<<"________"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"______________"<<"\t"<<"\t"<<"\t"<<"\t"<<"________"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t**"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"\t"<<"    "<<"**"<<endl;
	cout<<"\t\t\t\t******************************************************************************"<<endl;
    cout<<"\t\t\t\t******************************************************************************"<<endl;
}


void student()
{
	string m;
	system("cls");
		
	fstream myfile;
	myfile.open ("student.txt", fstream::app);//.open used to open file...::app end of file
	
	//now take the data of student
	cout <<"Enter the information of student "<<endl<<endl;
	getline(cin,m);
	
	cout<<"Enter Roll Number :";
	getline(cin,p1.rollno);
	cout<<endl;
	
	cout<<"Enter Name :";
	getline(cin,p1.studentname);
	cout<<endl;
	
	cout<<"Enter Father Name :";
	getline(cin,p1.fathername);
	cout<<endl;
	
	cout<<"Enter Date of Birth  :";
	getline(cin,p1.dateofbirth);
	cout<<endl;
	
	cout<<"Enter Gender :";
	getline(cin,p1.gender);
	cout<<endl;
	
	cout<<"Enter Class :";
	getline(cin,p1.Class);
	cout<<endl;
	
	cout<<"Enter the phone No. :";
	getline(cin,p1.phoneno);
	cout<<endl;
	
	cout<<"Enter the address. :";
	getline(cin,p1.address);
	cout<<endl;
	    
	cout<<"Enter B-form Number :";
	getline(cin,p1.bform);
	cout<<endl;

	string z = "=====================";
	myfile<<"\n"<< p1.rollno<<"\n"<< p1.studentname<<".\n"<< p1.fathername<<".\n" << p1.dateofbirth<<".\n"<< p1.gender<<".\n" << p1.Class<<".\n"<< p1.phoneno<<".\n"<< p1.bform<<".\n"<<z<<"\n";
    
	myfile.close();//used to close file..it is important to close file
    
    cout<<endl;
    
    cout <<"Record saved successfully "<<endl<<endl;
	cout<<"=============================="<<endl<<endl;
   

}


void stsearch(string find)//this function used to search anay thing from studebt file
{
	ifstream myfile ("student.txt");
	int notFound = 0;
	while( !myfile.eof())
	{ 
	
		getline(myfile,p1.rollno);
	
		if(p1.rollno==find)
		{
			notFound = 1;//it will open
			
			//now show the data tha we searched
			cout<<"Roll Number: "<<p1.rollno<<endl;
			
			
			getline(myfile,p1.studentname);
			cout<<"Name: "<<p1.studentname<<endl;
			getline(myfile,p1.fathername);
			cout<<"Father Name: "<<p1.fathername<<endl;
	 		getline(myfile,p1.dateofbirth);
			cout<<"Date of Birth : "<<p1.dateofbirth<<endl;
		 	getline(myfile,p1.gender);
			cout<<"Gender : "<<p1.gender<<endl;
			getline(myfile,p1.Class);
			cout<<"Class: "<<p1.Class<<endl;
			getline(myfile,p1.phoneno);
			cout<<"Phone Number : "<<p1.phoneno<<endl;
			
			getline(myfile,p1.address);
			cout<<"Address : "<<p1.address<<endl;
			
			getline(myfile,p1.bform);
			cout<<"Registration No number: "<<p1.bform<<endl<<endl;
		}
	}
	if(notFound == 0) //for closeing when data not found
	{
		cout<<"No Record Found"<<endl;
	}
	myfile.close();	//file will close
}

void teacher()
{
	string x;
	
	string g;
	fstream myfile;
	myfile.open ("teacher.txt",fstream::app);//new file for teacher
	Teacher t1;
		
		//data of teacher entered by admin
	cout <<"Enter the information of Teacher "<<endl<<endl;
	getline(cin,g);
	
	cout<<"enter the gmail :";
	getline(cin,t1.gmail);
	cout<<"\n";
	
	
	char at = '@';
	string str = t1.gmail;
    bool Gmail = false;
    char ch; 
    int l = str.length(); 
    for (int i = 0; i < l; i++) 
	{
        ch = str.at(i); 
        if(ch == at)
		{
			Gmail = true;	
		} 
    }
    if(Gmail == true)
    {
	
	
	
		
	
		cout<<"Enter Name :";
		getline(cin,t1.teachername);
		cout<<endl;

		cout<<"Enter Father Name :";
		getline(cin,t1.fathername);
		cout<<endl;
	
		cout<<"Enter experience  :";
		getline(cin,t1.experience);
		cout<<endl;

		cout<<"Enter Gender :";
		getline(cin,t1.gender);
		cout<<endl;

		cout<<"Enter qualification :";
		getline(cin,t1.qualification);
		cout<<endl;
		
		cout<<"Enter Address :";
		getline(cin,t1.address);
		cout<<endl;


		cout<<"Enter the phone No. :";
		getline(cin,t1.phoneno);
		cout<<"\n";
		
		cout<<"Enter CNIC :";
		getline(cin,t1.CNIC);
		cout<<endl;
		
		//all data save in the file using myfile<<...<< used to enter data in file i reversed order
		myfile<<"\n"<< t1.gmail<<"\n"<< t1.teachername<<"\n"<< t1.fathername<<"\n"<< t1.experience;
		myfile<<"\n"<< t1.qualification<<"\n"<< t1.phoneno<<"\n" <<t1.CNIC<<"\n"<< t1.gender<<"\n";
    
   		cout <<"Record saved successfully "<<endl;
		cout<<"=============================="<<endl<<endl;
	}
	else
	{
		cout<<"invalid email. @ is missing";
	}
    
}

void tesearch(string find)
{
	system("cls");
	ifstream myfile ("teacher.txt");
	int notFound = 0;//if you does not save or make a file name teacher exction.txt.
	while( !myfile.eof())
	{ 
		getline(myfile,t1.gmail);
	
		if(t1.gmail==find)
		{
			notFound = 1;
			//enter the data of teacher
			cout<<"Gmail : "<<t1.gmail<<endl;
			getline(myfile,t1.teachername);
			cout<<"Name: "<<t1.teachername<<endl;
			getline(myfile,t1.fathername);
			cout<<"Father Name: "<<t1.fathername<<endl;
	 		getline(myfile,t1.experience);
			cout<<"Experience : "<<t1.experience<<endl;
			getline(myfile,t1.gender);
			cout<<"Gender : "<<t1.gender<<endl;
			getline(myfile,t1.qualification);
			cout<<"Qualification : "<<t1.qualification<<endl;
			 getline(myfile,t1.address);
			cout<<"Address : "<<t1.address<<endl;
			 getline(myfile,t1.phoneno);
			cout<<"Phone Number : "<<p1.phoneno<<endl;
			getline(myfile,t1.CNIC);
			cout<<"CNIC : "<<t1.CNIC<<endl<<endl;
			
		}
	}
	if(notFound == 0)
	{
		cout<<"No Record Found"<<endl;
	}
	myfile.close();	
}

void teRegister()
{
	
	//cout<<"\t\t\t\t\t========================="<<endl;
    ifstream file;
    ofstream newuser;
    string username, password, passwordconfirm;//passwords
    file.open("teacherp.txt", ios::app);
    newuser.open("teacherp.txt", ios::app);
    bool uservalid=false;
   // cout<<"\t\t\t\t\t=========================="<<endl;
    while (!uservalid)
    {
        cout << "\tUsername: ";
        cin >> username;
        
        
        char at = '@';
		string str = username;
    	
    	bool Gmail = false;
    	char ch; 
    	int l = str.length(); 
    	for (int i = 0; i < l; i++) 
		{
    	    ch = str.at(i); 
    	    if(ch == at)
			{
				Gmail = true;	
			} 
    	}
    	if(Gmail == true)
    	{
        
        
        	cout << "\tPassword: ";
        	cin >> password;
        	cout << "\tConfirm password: ";
        	cin >> passwordconfirm;
        	int m=0;
        	int k=0;
        	while (file >> user >> pass)
        	{
        	    m++;
       		    if (username!=user)
       		    k++;
       	 	}
        	if (m==k && password==passwordconfirm)
        	    uservalid=true;
        	else if (m!=k)
            	cout << "There is already a user with this username." << endl;
        	else
            	cout << "Th	e passwords given do not match." << endl;
   		}
   		
   		else
		{
			cout<<"invalid email. @ is missing";
		}
   		
	}
    newuser << username << "\n" << password << endl;
    file.close();
    newuser.close();//newuser is a file that we created
}

int teLoginCheck (string user, string pass)
{
    ifstream file;
    string username, password;
    int n=0;
    file.open("teacherp.txt");
    if (file.is_open())
    {
    		//cout<<"\t\t\t\t\t=============================="<<endl;
        while (!file.eof())
        {
           file >> username >> password;
            n++;
            if (user==username && pass==password)
        	return n;
        }
    }
    else
    {
        cout << "file not open" << endl;
    }
    return 0;
}


void stdisplayall()//function used to display student data
{
	fstream myfile;
	char y;
	string fultext;
	myfile.open("student.txt");
	if(myfile.fail())
	{
		cout<<"file is not Loaded";
	}
	else
	{
		cout<<"File is loaded"<<endl;
		while(!myfile.eof())
		{
			myfile.get(y);
			fultext = fultext+y;//this is used to collect all data from file same to same with spaces
		}
		cout<<fultext;
	}
	
}



void tedisplayall()//display teacher's data
{
	fstream myfile;
	char y;
	string fultext;
	myfile.open("teacher.txt");
	if(myfile.fail())
	{
		cout<<"file is not Loaded";
	}
	else
	{
		cout<<"File is loaded"<<endl;
		while(!myfile.eof())
		{
			myfile.get(y);
			fultext = fultext+y;
		}
		cout<<fultext;
	}
	
}



void stdeleting()
{
    string line, name;
    cout << "Please Enter the name of record you want to delete: ";
    cin >> name;
    ifstream f2;//if an of stream work as a data ype of file
    ofstream temp;
    f2.open("student.txt");
    temp.open("temp.txt");//new file
    while (getline(f2, line))
    {
        if (line != name)
            temp << line << endl;
    }
    cout << "The record with the name " << name << " has been deleted if it exsisted" << endl;
    f2.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}


void tedeleting(string mail)
{
    string line;
    
    ifstream f2;
    ofstream temp;
    f2.open("student.txt");
    temp.open("temp.txt");
    while (getline(f2, line))
    {
        if (line != mail)
            temp << line << endl;
    }
    cout << "The record  has been deleted " << endl;
    f2.close();
    temp.close();
    remove("student.txt");
    rename("temp.txt", "student.txt");
}
