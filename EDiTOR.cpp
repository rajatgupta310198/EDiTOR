/*----------------------------------------------------------------------------------------------------------------------------|
/ This Programe is Made by Rajat Gupta with Suman Mandal as our project for computer science                                  |
/ This can run on any machine ,any OS .                                                                                       |
/Just Compile the source code in C++ compiler as per C++ 11 standerd                                                          |
/For linux system onther source sode is given Name ProLinux.cpp                                                               |
/This is for Windows System..Be sure to compile it on GNU GCC compilers as Turbo C++ has limited functions though             |
/ Another source code is given for it name ProTurbo.cpp but for best experice run it on windows xp or later and compile it    |
/ in GNU GCC only                                                                                                             |
------------------------------------------------------------------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <dir.h>
#include <conio.h>
#include <string.h>
#include <process.h>
using namespace std;
char Choice,word,Prog[20],wor[20];
char text[1000];char FileName[20],DirName[20];
void Help();
class VIEW{
	     public: void disp();
		    void cur();
		    void show();
};
// class File to begin
class File :public VIEW {
	       public:
		    void FileMenu();
		    void New();
		    void Change();
		    void MakeDirectory();
		    void OpenFile();
};// class Edit for editing docs and maintainning computer
class EDIT : public File  {
	   public :
		void EditMenu();
		void Rename();
		void DeleteFileOrDirectory();
		void Edit();
		void Search();
}; // main Menu Bar for program
void MenuBar()
{    system("cls");// system("clear") for linux
	 cout<<"##################################EDiTOR#######################################";
	 cout<<"\n[F]ile_________##______[E]dit________##_________[V]iew_____##_______[H]elp____|";
	 cout<<"\n###############################################################################";
 }

void reset();
File fi;
EDIT ed;
VIEW v;
// function to select from menu's
void Select()
{      Choice = getch();
     if(Choice=='f'||Choice=='F')
	    {
		     fi.FileMenu();
		     if(Choice=='n'||Choice=='N')
				     fi.New();
				     if(Choice=='e'||Choice=='E')
				     exit(0);
				     if(Choice=='c'||Choice=='C')
				     fi.Change();
				     if(Choice=='m'||Choice=='M')
				     fi.MakeDirectory();
				     if(Choice=='o'||Choice=='O')
				     fi.OpenFile();
					 else
					 reset();
			}
     if(Choice=='e'||Choice=='E')
	    {
		    ed.EditMenu();
		    if(Choice=='R'||Choice=='r')
		    ed.Rename();
		    if(Choice=='D'||Choice=='d')
		    ed.DeleteFileOrDirectory();
		    if(Choice=='E'||Choice=='e')
		    ed.Edit();
		    if(Choice=='S'||Choice=='s')
		    ed.Search();
		    else
		    reset();
	    }
     if(Choice=='R'||Choice=='r')
	 {  cout<<endl<<"Enter :";
	    cin>>Prog;
	    system(Prog); 
	    getch();
	    reset();
	 }
      if(Choice=='H'||Choice=='h')
	 {
	    //	Help();
	    cout<<"\nNot need.....Filhaal Bana Raha hoon.....\n";
	    getch();
	    reset();
	 }
     if(Choice=='V'||Choice=='v')
	 {
		  v.disp();
		  if(Choice=='C'||Choice=='c')
		  v.cur();
		  if(Choice=='f'||Choice=='F')
		  v.show();
		  getch();
		  reset();
	 }
	   else
	   reset();
}
int main()
{      textcolor(CYAN);
   // system("Color 2"); use this if you use dev cpp or other than turbo c++
     MenuBar();
     Select();
	 return 0;
}
// File Menu diplayed when user press F or f
void File::FileMenu()
{
	cout<<"\n[N]ew\n[O]pen\n[C]hange Directory\n[M]ake Directory\n[E]xit";
	Choice = getch();
}
// Edit Menu diplayed when user press E or e
void EDIT::EditMenu()
{
	cout<<"\n\t\t\t[R]ename File\n\t\t\t[D]lelte\n\t\t\t[E]dit File\n\t\t\t[S]earch Word";
	Choice = getch();
}
void VIEW::disp()
{
	cout<<"\n\t\t\t\t\t\t[C]urrent Path\n\t\t\t\t\t\t[F]iles And Directory";
	Choice = getch();
}
void reset()
{   
	MenuBar();
	Choice = NULL;
	//cout<<"\nreset called !";
	Select();
}
 // Funtiton defination for createFile File function
void File::New()                                                          
{     
	    MenuBar();
	    cout<<"\n Enter File Name :";
	    cin>>FileName;
	   	ofstream f(FileName,ios::app);
	    for(int i=0;i!=24;i=getch())
	        {   
		 cin.getline(text,1000);
	         f<<text;
	         }
	    f.close();
	    cout<<"\n Saved !";
	    getch();	 
}
//Function Defiantion to change directory
   void File::Change()                                                    
   {   
      MenuBar();
      cout<<"\n Directories :";
      fi.show();
      cout<<"\n Enter Name :";
      cin>>DirName;
      if(chdir(DirName)!=0)
	   {cout<<"\nWron directory or false input "; getch();}
	   else
	   {cout<<"\nChanged press key to continue..";getch();}
   }
// Funtion Defination to Create Directory
   void File::MakeDirectory()                                                 
   {    
          MenuBar();
          cout<<"\nEnter Directory Name You Want Create :";
          cin>>DirName;
          if(! mkdir(DirName))
          cout<<"\nSucessfully Created !";
          else
		 cout<<"\nNot able to create may it exits already !";  getch();        
   }
// function defination for Opennig a doument or file
   void File::OpenFile()                                                      
   {
   	    MenuBar();
   	    system("dir/p");//system("ls") for linux
   	    cout<<"\nEnter File Name from list or change directory :";
   	    cin>>FileName;
   	    ifstream f;
		f.open(FileName);
   	    while(!f.eof())
   	       {  
   	           f.get(word);
   	           cout<<word;
   	       }
   	       f.close();
   	       getch();
   }  
//funtion to rename file name                     
   void EDIT::Rename()                                                          
   {      char fil[20];
   	     MenuBar();
   	     cout<<"\nWant To See Files ? [y/n] :";
   	     Choice = getch();
   	     if(Choice=='y')
   	     system("dir/p"); // system("ls") for linux
   	     cout<<"\nEnter File Name To Change :";
   	     cin>>FileName;
   	     cout<<"\nEnter New File Name       :";
   	     cin>>fil;
   	     if(!rename(FileName,fil))
   	     cout<<"\nSucessfully Changed from "<<FileName<<" to "<<fil;
   	     else
   	     cout<<"\nNot Able to change ! may be file name incorrect ";
	     getch(); 	     
   }
// Funtion to delete files or directory
   void EDIT::DeleteFileOrDirectory()                                         
   {
   	   MenuBar();
   	   cout<<"\nEnter File Name To delete :";
   	   cin>>FileName;
   	   if(!remove(FileName))
   	   cout<<"\nSucessfully Delete "<<FileName;
   	   else
   	   cout<<"\nWrong File ";
   	   getch();
   }
//Edit menuto edit contents of file
   void EDIT::Edit()
   {
   	  ed.New();
   }
   void VIEW::cur()
   {  MenuBar();
   	  getcwd(DirName,20);
   	  cout<<"\n Path :"<<DirName;
   	  getch();
   }
   void VIEW::show()
   {
   	MenuBar();
   	cout<<"\n Directories and files :";
   	cout<<endl;
   	system("dir/p"); // system("lis") for linux
   	getch();
   }
   void EDIT::Search()
   {  long count;
   	MenuBar();
   	cout<<"\nEnter File Name:";
   	cin>>FileName;char wo[15];
	   char f='n';
   	 fstream fi(FileName,ios::app|ios::in);
   	cout<<"\nEnter Word :";
   	cin>>Prog;
   	cout<<endl<<Prog;
   	 long cout=0;
   	while(!fi.eof())
   	   {    fi>>wor;
   	       count = fi.tellg();
   	       if(strcmp(Prog,wo)==0)
   	          {
   	          	 f='y';
   	          	 break;
   	          }
   	   }
   	  cout<<count;
   	fi.close();
   	getch();
   }
//   void Help()
//   {
//   	system("cls");
//   	fstream f("help.bin",ios::binary|ios::in|ios::out);
//   	while(!f.eof())
//   	{
//   		f.get(word);
//   		cout<<word;
//   	}
//   	getch();
//   }
