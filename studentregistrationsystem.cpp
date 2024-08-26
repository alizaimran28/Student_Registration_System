
#include <iostream>
#include <string>
#include <fstream>
#include <stdlib.h>
using namespace std;

            string authorisedperson="Hifza";
            int password=786;
            string s_name[5]={"Eman","Aneeba","Alina","Saniya","Shamaim"};
            string s_email[5]={"mehareman@gmail.com","aneeby@gmail.com","alina@gmail.com","saniya@gmail.com","shamaim@gmail.com"};
            int s_id[5]={54,49,50,51,52};
            long long s_phone[5];
            string address[5];
            string sem2[5]={"OOP","discrete","pstudies","physics","composition"};
            string sem1[5]={"PF","Math","Islamiyat","ICT","English"};
            string prerequistecode[5]={"EN101","EN102","EN103","EN104","EN105"};
            string feesdefaulter[5]={"no","no","yes","no","yes"};
            float CGPA[5]={3,3.5,1,3.7,4};
    int id;
    int press;
    string t_authorizedperson;
    int t_password;
    string Pre_R_C[5];
    string Pre_R_C1[5];
    string Pre_R_C2[5];

void login();
void registerstudent(string s_name,string s_email,int s_id,long long int s_phone,string s_address);
void fee_defaulter1();
void SCGPA(int id);
void prerequisitecode();
void prerequisitecode1();
void prerequisitecode2();
void s_s_id();
void s_record();

fstream file;

int main()
{
    s_record();
	cout<<"\n***WELCOME TO UMT REGISTERATION SYSTEM***\n";
	cout<<"\npress 1 to login\n"<<" ";
	int i=1;
    while(press!=6)
    {
        cin>>press;
        if(press==6)
        {
            cout<<"you are exit\n";
            break;
        }
		if(press==1)
		{
			file.open("login.txt", ios::out);
			if(file.is_open())
			{
                login();
			}
			file.close();
			file.open("login.txt" , ios::in);
			if(file.is_open())
			{
				string str;
				while(getline(file,str))
				{
					cout<<str<<endl;
				}
			}
			file.close();
        }

        cout<<"\n***********REGISTER THE STUDENT***********\n";
        cout<<"\npress 2 to register student\n";
        cin>>press;

        if(press==2)
        {
            string search_s_name;
	        string search_s_email;
	        cout<<"enter username:";
	        cin>>search_s_name;
            cout<<"enter email to login:";
	        cin>>search_s_email;
            int search_s_id;
	        long long int s_phone;
	        string s_address;
	        cout<<"Enter id:";
	        cin>> search_s_id;
	        cout<<"enter your current phone number:+92";
	        cin>>s_phone;
	        cout<<"enter your current address:";
	        cin>>s_address;

	        file.open("register.txt", ios::out);
	        if(file.is_open())
	        {
	        	registerstudent( search_s_name,  search_s_email,   search_s_id,   s_phone,   s_address );
			}
			file.close();

			file.open("register.txt", ios::in);
			if(file.is_open())
			{
				string regis;
				while(getline(file,regis))
				{
					cout<<regis<<endl;
				}
			}
			file.close();

        }


        cout<<"\n***********LIST OF FEE DEFAULTER***********\n";
        cout<<"\npress 3 to see list of fee defaulter\n";
        cin>>press;

        if(press==3)
        {
        	file.open("feedefaulter.txt", ios::out);
        	if(file.is_open())
        	{
        		fee_defaulter1();
        	}
        	file.close();

        	file.open("feedefaulter.txt", ios::in);
        	if(file.is_open())
        	{
        		string fees;
        		while(getline(file,fees))
        		{
        			cout<<fees<<"\n";
				}
			}
			file.close();
		}

        cout<<"\n***********CGPA OF STUDENTS***********\n";
        cout<<"\npress 4 to see CGPA of students\n";
        cin>>press;
        if(press==4)
        {
        	cout<<"Enter your id to know your CGPA:\n";
        	cin>>id;
        	file.open("CGPA.txt", ios::out);
        	if(file.is_open())
        	{
        		SCGPA(id);

        	}
        	file.close();
		file.open("CGPA.txt", ios::in);
        	if(file.is_open())
        	{
        		string cgp;
        		while(getline(file,cgp))
        		{
        			cout<<cgp<<"\n";
				}
			}
			file.close();
        }



    cout<<"***********PREREQUISITE CODE***********\n";
    cout<<"press 5 to register in courses\n";
    cin>>press;
    if(press==5)
    {
    cout<<"enter your id to know that in how many subjects you are registered\n";
    cin>>id;
    file.open("code.txt", ios::out);
    if(file.is_open());
    {
    prerequisitecode();
    }
    file.close();
    		file.open("code.txt", ios::in);
        	if(file.is_open())
        	{
        		string pcode;
        		while(getline(file,pcode))
        		{
        			cout<<pcode<<"\n";
				}
			}
			file.close();
        }
    cout<<"press 7 to search information of student through id\n";
    cin>>press;
    if(press==7)
    {
    cout<<"enter id to know information of required student\n";
    cin>>id;
     file.open("ID.txt", ios::out);
    if(file.is_open());
    {
    s_s_id();
    }
    file.close();
    		file.open("ID.txt", ios::in);
        	if(file.is_open())
        	{
        		string id;
        		while(getline(file,id))
        		{
        			cout<<id<<"\n";
				}
			}
			file.close();
        }

    cout<<"\npress 6 to exit or again press 1 to register more students\n";
    i++;
}
	return 0;
}

void s_record()
{

    int n=1;
    ofstream write_file("student information.txt");
       for(int i=0;i<5;i++)
       {
           write_file<<"Record of "<<" "<<n<<" "<<"student";
           write_file<<"Student Name:"<<s_name[i]<<"\n";
           write_file<<"Student ID:"<<s_id[i]<<"\n";
           write_file<<"Student CGPA:"<<CGPA[i]<<"\n";
           write_file<<"Feedefaulter yes/no:"<<feesdefaulter[i]<<"\n";
           n++;
       }
       write_file.close();

}




void login()
{

        bool c=false;
        cout<<"\n***********LOGIN YOURSELF***********\n";
        cout<<"\nenter your name to login so to register the students\n";
        cin>>t_authorizedperson;
        cout<<"enter you password please:";
        cin>>t_password;

			if(t_authorizedperson==authorisedperson && t_password==password)
			{
				file<<"\n";
				file<<"you are login successfully\n";
                file<<"the name enter by the user is  : "<<t_authorizedperson<<endl;
                file<<"the password enter by the user : "<<t_password<<endl;
				file<<"\n";
			}
			int n=1;
			for(int i=0;i<5;i++)
			{
				file<<n<<"   student Name     : "<<s_name[i]<<endl;
				file<<"    student ID       : "<<s_id[i]<<endl;
				file<<"    student CGPA     : "<<CGPA[i]<<endl;
				file<<"    fee defulter     : "<<feesdefaulter[i]<<endl;
				file<<"    student email    : "<<s_email[i]<<endl;
				n++;
			}
		if(c==false)
		cout<<"\nInvalid login";

}





void registerstudent(string search_s_name,string search_s_email,int search_s_id,long long int s_phone,string s_address)
{
       bool c=false;
       file<<"\n";
       file<<"username enter by the user is ...........:"<<search_s_name<<endl;
       file<<"Email enter the user is .................:"<<search_s_email<<endl;
       file<<"ID enter by the user is..................:"<<search_s_id<<endl;
       file<<"address enter by the user is.............:"<<s_address<<endl;
       file<<"phone num enter by the user .............:"<<s_phone<<endl;
       file<<"\n";
       for(int i=0;i<5;i++)
       {
           if(search_s_name==s_name[i] && search_s_email==s_email[i] && search_s_id==s_id[i])
           {
               c=true;
               file<<"you are founded"<<endl;
               file<<"You are registered";
               break;
           }
       }
       if(c==false)
        cout<<"\ninvalid registeration";
}






void  fee_defaulter1()
{
	file<<"list of fee defaulters"<<endl;
        for(int i=0;i<5;i++)
        {
            if(feesdefaulter[i]=="yes")
            {

            file<<s_name[i]<<" : "<<"FEESDEFAULTER:"<<feesdefaulter[i]<<"\n";
            }
        }

}




void SCGPA(int id)
{
        int n;
        file<<"the CGPA of student"<<endl;
        		for(int i=0;i<5;i++)
	            {
			       if(id==s_id[i])
			       {
			       	n=i;

					file<<"CGPA of student with student ID "<<id<<" is : "<<CGPA[n]<<"\n";
				    break;
				   }
	            }
}


void prerequisitecode()
{
    int n;
    for(int i=0;i<5;i++)
    {
        {
            if(id==s_id[i])
            {
                n=i;
                file<<id<<"As your CGPA which is "<<CGPA[n]<<"\n";
                break;
            }
        }
    }
    if(CGPA[n]<=4 && CGPA[n]>=3)
	{
		file<<"so , Student is eligible for all courses\n";
		file<<"Enter prerequisite code for all 5 subjects so to register courses. \n";
	for (int r=0;r<5;r++)
	{
	    cin>>Pre_R_C[r];
	}
	bool c=false;
	 for(int i=0;i<5;i++)
      {
          for(int j=0;j<5;j++)
          {
              if(Pre_R_C[i]==prerequistecode[j])
              {
                c=true;
              }
          }
      }
      cout<<"You are registered successfully in all courses.\n";
          if(c==false)
              file<<"You have entered invalid information/code.\n";
      }
    else if(CGPA[n]<3 && CGPA[n]>=2)
    prerequisitecode1();
    else if(CGPA[n]<2 && CGPA[n]<1)
    prerequisitecode2();
}
void prerequisitecode1()
 {
     file<<"so , student is eligible for three courses\n";
     file<<"Enter prerequisite code for three courses so to register courses. \n";
      for(int i=0;i<3;i++)
      {
          cin>>Pre_R_C1[i];
      }
      for(int i=0;i<3;i++)
      {
          for(int j=0;j<5;j++)
          {
              if(Pre_R_C1[i]==prerequistecode[j])
          {
          file<<"Your three courses are registered successfully\n";
          break;
          }
      }
 }
 }
void prerequisitecode2()
 {
     file<<"so , your 2 courses will be registered be careful for next time\n";
     file<<"Enter prerequisite code for 2 courses so to register courses. \n";
      for(int i=0;i<2;i++)
      {
          cin>>Pre_R_C2[i];
      }
      for(int i=0;i<2;i++)
      {
          for(int j=0;j<5;j++)
          {
              if(Pre_R_C2[i]==prerequistecode[j])
          {
          file<<"WARNING!You can be expelled out if you will fail once more but still your two courses are registered successfully\n";
          break;
          }
      }
      }
 }
 void s_s_id()
 {
     int n;
     file<<"find record of student by his/her id";
     for(int i=0;i<5;i++)
     {
         for(int j=0;j<5;j++)
         {
           if(id==s_id[i])
           {
            n=i;
            file<<"NAME:"<<s_name[n]<<"\n"<<"Email:"<<s_email[n]<<"\n"<<"fees:"<<feesdefaulter[n]<<"\n"<<"CGPA:"<<CGPA[n]<<"\n";
            break;
           }
         }
     }
 }
