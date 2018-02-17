#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>

#include<string.h>

#include<fstream.h>

#include<process.h>

#include<time.h>



#define ESC 27

#define UP 72

#define LEFT 75

#define RIGHT 77

#define DOWN 80

#define SPACE 32

#define ENTER 13





struct date d;	//Strructure For Getting The System Date

		//For Determining The Date The Book Should Be Returned.





/***********************************************************************************

			    Class - AdminOptions

************************************************************************************/



	class AdminOptions

	{

		public:



		int BookCode,BookCopies;



		char BookName[20],AuthorName[20],BookType[10];



		int AddBook();		//Add A Book To Binary File.

		int DeleteBook();       //Delete A Book From Binary File.

		void DisplaySelBook();  //Search And Display A Selected Book.

		void DisplayBooks();    //Display All Books.





		int MemCode,MemYears;



		char MemName[20],MemSName[20],MemGender[10];



		int AddMem();		//Add A Member To Binary File.

		int DeleteMem();        //Delete A Member From Binary File.

		void DisplaySelMem();   //Search And Display A Selected Member.

		void DisplayMem();      //Display All Members.





		void GetBookData()  //Get Book Details From The Administrator

		{                   //To Store In The Binary File.



		clrscr();



		textcolor(LIGHTBLUE);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |           Add New Book - Please Provide The Following Details              | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



			gotoxy(15,6);

			cout<<"Enter The Book Code: ";

			cin>>BookCode;



			gotoxy(15,7);

			cout<<"Enter The Name Of The Book: ";

			gets(BookName);



			gotoxy(15,8);

			cout<<"Enter The Author Name: ";

			gets(AuthorName);



			gotoxy(15,9);

			cout<<"Enter The Book Type (Fiction, Non-Fiction etc...) : ";

			gets(BookType);



			gotoxy(15,10);

			cout<<"Enter The Number Of Copies: ";

			cin>>BookCopies;

		}



		void PutBookData()	//Displays The Book Details.

		{



			cout.width(9);	cout<<BookCode;



			cout.width(15); cout<<BookName;



			cout.width(15); cout<<AuthorName;



			cout.width(16); cout<<BookType;



			cout.width(14); cout<<BookCopies;



			cout<<"\n";

		}



		void GetMemData()	//Get Member Details From The Administrator

		{	   		//To Store In The Binary File.



		clrscr();



		textcolor(LIGHTCYAN);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |         Add New Member - Please Provide The Following Details              | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);





			gotoxy(15,6);

			cout<<"Enter The Member Code: ";

			cin>>MemCode;



			gotoxy(15,7);

			cout<<"Enter The First Name Of The Member: ";

			gets(MemName);



			gotoxy(15,8);

			cout<<"Enter The Surname Of The Member: ";

			gets(MemSName);



			gotoxy(15,9);

			cout<<"Enter The Gender(M/F): ";

			gets(MemGender);



			gotoxy(15,10);

			cout<<"Enter The Number Of Years Of Membership: ";

			cin>>MemYears;

		}



		void PutMemData()

		{



			cout.width(8); cout<<MemCode;



			cout.width(16); cout<<MemName;



			cout.width(14); cout<<MemSName;



			cout.width(12); cout<<MemGender;



			cout.width(15); cout<<MemYears;



			cout<<"\n";

		}





	};



	AdminOptions Book1,Book2,Book3,Book4,Book5,Book6;  //Global Objects

	AdminOptions Mem1,Mem2,Mem3,Mem4,Mem5;       //Of Class AdminOptions.



/***********************************************************************************

		Class AdminOptions - Member Function -- AddBook()

************************************************************************************/



	int AdminOptions::AddBook()

	{

		clrscr();



		char Ch1='y';



		/*Creating a Binary File Named LibraryBooks

		  To Store The List Of Books Available*/



		ofstream SBk1;	//To Write Into The File.

		SBk1.open("LibraryBooks.dat",ios::app|ios::binary);



		while(Ch1=='y')

		{

			Book1.GetBookData();	//Get Book Details From

						//Administrator.



			SBk1.write((char*)&Book1,sizeof(AdminOptions));





			gotoxy(15,13);

			cout<<"New Book Details Appended To FIle! ";



			gotoxy(15,14);

			cout<<"Do You Want To Enter More? (Y/N): ";

			cin>>Ch1;

		}



		gotoxy(10,16);

		cout<<"Press 'Up' or 'Down' Arrow Key To Return To The Previous Menu!";



		SBk1.close();



		return 0;



	}  //End Of AdminOptions::AddBook().



/***********************************************************************************

		Class AdminOptions - Member Function -- AddMem()

************************************************************************************/



	int AdminOptions::AddMem()

	{

		clrscr();



		char Ch2='y';



		/*Creating a Binary File Named LibraryMembers

		  To Store The Registered Member Details*/



		ofstream SMem1;	//To Write Into The File.

		SMem1.open("LibraryMembers.dat",ios::app|ios::binary);



		while(Ch2=='y')

		{

			Mem1.GetMemData();   //Get Member Details From

					     //The Administrator.



			SMem1.write((char*)&Mem1,sizeof(Mem1));



			gotoxy(15,13);

			cout<<"New Member Details Added To FIle!";



			gotoxy(15,14);

			cout<<"Do You Want To Enter More? (Y/N): ";

			cin>>Ch2;

		}



		gotoxy(10,16);

		cout<<"Press 'Up' or 'Down' Arrow Key To Return To The Previous Menu!";



		SMem1.close();



		return 0;

	}  //End Of AdminOptions::AddMem().



/***********************************************************************************

		Class AdminOptions - Member Function -- DeleteBook()

************************************************************************************/



	int AdminOptions::DeleteBook()  //Delete A Book From The Binary File.

	{

		clrscr();



		ifstream SBk2;  //Read From The File Containing Book Details.

		SBk2.open("LibraryBooks.dat",ios::app|ios::binary);



		ofstream SBk3("TemporaryFile.dat",ios::out|ios::binary);  //Opening A Temperory File.



		char BkName1[20],Found1='f',Confirm1='n';



		textcolor(CYAN);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |            Delete Book - Please Provide The Following Details              | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);





		gotoxy(15,5);

		cout<<"Enter The Name Of The Book To Be Deleted: ";

		gotoxy(15,7);

		gets(BkName1);



		   while(SBk2.read((char*)&Book2,sizeof(Book2)))

		   {

			if(strcmp(Book2.BookName,BkName1)==0)

			{



			cout<<"\n\n";

			cout<<"|------------------------------------------------------------------------------|";

			cout<<"| | Book Code |  Book Name  |  Book Author  |  Book Type  | Number Of Copies | |";

			cout<<"|------------------------------------------------------------------------------|";



			Book2.PutBookData();

			Found1='t';



				gotoxy(15,15);

				cout<<"Are You Sure You Want To Delete This Book? (Y/N): ";

				cin>>Confirm1;



				   if(Confirm1=='n')

				   SBk3.write((char*)&Book2,sizeof(AdminOptions));



				   gotoxy(10,17);

				   cout<<"Book Removed From Database!";

			}

			else

			SBk3.write((char*)&Book2,sizeof(Book2));



		   }



		   if(Found1=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Book You've Searched For Is Not In The Database.\n";

		   }



		   gotoxy(10,18);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";



		   SBk2.close();

		   SBk3.close();



		   remove("LibraryBooks.dat");               //Delete LibraryBooks Binary File.

		   rename("TemporaryFile.dat","LibraryBooks.dat");   //'TemperoryFile1' File Renamed To The 'LibraryBooks'.



		return 0;

	}  //End Of AdminOptions::DeleteBook().



/***********************************************************************************

		Class AdminOptions - Member Function -- DeleteMem()

************************************************************************************/



	int AdminOptions::DeleteMem()  //Delete A Member From The Binary File.

	{

		clrscr();



		ifstream SMem2;  //Read The Member Details From The File.

		SMem2.open("LibraryMembers.dat",ios::app|ios::binary);



		ofstream SMem3("TemporaryFile2.dat",ios::out|ios::binary);  //Open A Temporary FIle Named 'TemporaryFile2'.



		char MbName1[20],Found2='f',Confirm2='n';



		textcolor(LIGHTBLUE);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |          Delete Member - Please Provide The Following Details              | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);





		gotoxy(15,5);

		cout<<"Enter The Name Of The Member To Be Deleted: ";

		gotoxy(15,7);

		gets(MbName1);



		   while(SMem2.read((char*)&Mem2,sizeof(Mem2)))

		   {

			if(strcmp(Mem2.MemName,MbName1)==0)

			{



			cout<<"\n\n";

			cout<<"|------------------------------------------------------------------------------|";

			cout<<"| |   Code   |    Name    |    Surname    |   Gender  |  Year Of Membership  | |";

			cout<<"|------------------------------------------------------------------------------|";



			Mem2.PutMemData();

			Found2='t';



				gotoxy(15,15);

				cout<<"Are You Sure You Want To Delete This Member? (Y/N): ";

				cin>>Confirm2;



				   if(Confirm2=='n')

				   SMem3.write((char*)&Mem2,sizeof(AdminOptions));



				    gotoxy(10,17);

				    cout<<"Member Removed From Database!";



			}

			else

			SMem3.write((char*)&Mem2,sizeof(Mem2));



		   }



		   if(Found2=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Member You've Searched For Is Not In The Database.\n";

		   }

		   gotoxy(10,18);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";





		   SMem2.close();

		   SMem3.close();



		   remove("LibraryMembers.dat");  //Deleting File Named LibraryMembers.

		   rename("TemporaryFile2.dat","LibraryMembers.dat");   //'TemporaryFile2' File Renamed To The 'LibraryMembers'.



		return 0;

	}  //End Of AdminOptions::DeleteMem().



/***********************************************************************************

	  Class AdminOptions - Member Function -- DisplaySelBook()

************************************************************************************/



	void AdminOptions::DisplaySelBook()  //Search And Display Selected Book.

	{

		clrscr();



		ifstream SBk4;  //Open File Containing Book List.

		SBk4.open("LibraryBooks.dat",ios::app|ios::binary);

		SBk4.seekg(0);



		char Found3='f';

		char BkName2[20];



		textcolor(RED);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |            Search Book - Please Provide The Following Details              | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(15,5);

		cout<<"Enter The Name Of The Book To Be Displayed: ";

		gotoxy(15,7);

		gets(BkName2);



		   while(SBk4.read((char*)&Book3,sizeof(Book3)))

		   {

			   if(strcmp(Book3.BookName,BkName2)==0)

			   {



			   cout<<"\n\n";

			   cout<<"|------------------------------------------------------------------------------|";

			   cout<<"| | Book Code |  Book Name  |  Book Author  |  Book Type  | Number Of Copies | |";

			   cout<<"|------------------------------------------------------------------------------|";



				Book3.PutBookData();



				Found3='t';

			   }



		   }   //End Of While Loop.



		   if(Found3=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Book You've Searched For Is Not In The Database.\n";

		   }

		   gotoxy(10,18);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";



		   SBk4.close();



	}   //End Of AdminOptions::DisplaySelBook().



/***********************************************************************************

		Class AdminOptions - Member Function -- DisplaySelMem()

************************************************************************************/



	void AdminOptions::DisplaySelMem()  //Search And Display Selected Member.

	{

		clrscr();



		ifstream SMem4;  //Open File Containing Member List.

		SMem4.open("LibraryMembers.dat",ios::app|ios::binary);





		char Found4='f';

		char MbName2[20];



		textcolor(RED);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |          Search Member - Please Provide The Following Details              | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(15,5);

		cout<<"Enter The First Name Of The Member To Be Displayed: ";

		gotoxy(15,7);

		gets(MbName2);



		   while(SMem4.read((char*)&Mem3,sizeof(Mem3)))

		   {

			   if(strcmp(Mem3.MemName,MbName2)==0)

			   {



			   cout<<"\n\n";

			   cout<<"|------------------------------------------------------------------------------|";

			   cout<<"| |   Code   |    Name    |    Surname    |   Gender  |  Year Of Membership  | |";

			   cout<<"|------------------------------------------------------------------------------|";



				Mem3.PutMemData();

				Found4='t';

			   }



		   }   //End Of while Loop.



		   if(Found4=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Member You've Searched For Is Not In The Database.\n";

		   }

		   gotoxy(10,18);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";



		   SMem4.close();



	}   //End Of AdminOptions::DisplaySelMem().



/***********************************************************************************

		Class AdminOptions - Member Function -- DisplayBooks()

************************************************************************************/



	void AdminOptions::DisplayBooks()

	{

		ifstream SBk5; //Open LibraryBooks.dat for Reading.

		SBk5.open("LibraryBooks.dat",ios::in|ios::binary);

		SBk5.seekg(0);



		clrscr();



		textcolor(LIGHTGREEN);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |                         List Of Books In Database                          | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		cout<<"\n";

		cout<<"|------------------------------------------------------------------------------|";

		cout<<"| | Book Code |  Book Name  |  Book Author  |  Book Type  | Number Of Copies | |";

		cout<<"|------------------------------------------------------------------------------|";



		while(!SBk5.eof())

		{

			SBk5.read((char*)&Book4,sizeof(AdminOptions));



			if(SBk5.eof())   break;



			Book4.PutBookData();

		}

		SBk5.close();

	}  //End Of AdminOptions::DisplayBooks().



/***********************************************************************************

		Class BookOptions - Member Function -- DisplayMem()

************************************************************************************/



	void AdminOptions::DisplayMem()

	{

		ifstream SMem5;  //Open LibraryBooks.dat for Reading.

		SMem5.open("LibraryMembers.dat",ios::in|ios::binary);

		SMem5.seekg(0);



		clrscr();



		textcolor(MAGENTA);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |                       List Of Members In Database                          | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		cout<<"\n";

		cout<<"|------------------------------------------------------------------------------|";

		cout<<"| |   Code   |    Name    |    Surname    |   Gender  |  Year Of Membership  | |";

		cout<<"|------------------------------------------------------------------------------|";



		while(!SMem5.eof())

		{

		    SMem5.read((char*)&Mem4,sizeof(AdminOptions));



		    if(SMem5.eof())   break;



		    Mem4.PutMemData();

		}



		SMem5.close();

	}  //End Of AdminOptions::DisplayMem().





/***********************************************************************************

			    Class - UserOptions

************************************************************************************/





	class UserOptions : public AdminOptions	//Inheriting Class UserOptions Publicly.

	{

		public:



		void IssueBook();

		int ReturnBook();

		void AccountDetails();

		void AboutUs();





	};



	UserOptions User1,User2,User3; //Global Objects Of Class UserOptions.



/***********************************************************************************

		Class UserOptions - Member Function -- IssueBook()

************************************************************************************/



	void UserOptions::IssueBook()

	{

		clrscr();



		/*Creating A Binary File Named IssuedBooks

		  To Store The Issued Book Details.*/



		ofstream SUser1;

		SUser1.open("IssuedBooks.dat",ios::app|ios::binary);





		ifstream SUser2;

		SUser2.open("LibraryMembers.dat",ios::in|ios::binary);

		SUser2.seekg(0);



		char Found5='f';

		char MbName3[20],Ch1;



		 textcolor(LIGHTGREEN);



		 cprintf(" |----------------------------------------------------------------------------| ");

		 cprintf(" |          Search Member - Please Provide The Following Details              | ");

		 cprintf(" |----------------------------------------------------------------------------| ");



		 textcolor(WHITE);



		gotoxy(15,5);

		cout<<"Enter The First Name Of The Member: ";

		gotoxy(15,7);

		gets(MbName3);



		   while(SUser2.read((char*)&Mem5,sizeof(AdminOptions)))

		   {

			   if(strcmp(Mem5.MemName,MbName3)==0)

			   {



			   cout<<"\n";

			   cout<<"|------------------------------------------------------------------------------|";

			   cout<<"| |   Code   |    Name    |    Surname    |   Gender  |  Year Of Membership  | |";

			   cout<<"|------------------------------------------------------------------------------|";



				Mem5.PutMemData();



				cout<<"\n";

				gotoxy(25,16);

				cout<<"Press Enter To Continue...";

				getch();



				clrscr();



			   textcolor(LIGHTGREEN);



			   cprintf(" |----------------------------------------------------------------------------| ");

			   cprintf(" |          Search Member - Please Provide The Following Details              | ");

			   cprintf(" |----------------------------------------------------------------------------| ");



			   textcolor(WHITE);





				cout<<"\n";

				cout<<"\t   Welcome "<<MbName3<<"! Whhich Book Would You Like To Borrow? ";





				User1.MemCode=Mem5.MemCode;

				strcpy(User1.MemName,Mem5.MemName);



				Found5='t';



			   }  //End Of if Statement.



		   }   //End Of while Loop.



		if(Found5=='f')

		{

		   gotoxy(10,9);

		   cout<<"Sorry! The Member You've Searched For Is Not In The Database.\n";

		   gotoxy(10,18);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";

		}

		else

		{



		   fstream SUser3;  //Both Read and Write Into Binary File.

		   SUser3.open("LibraryBooks.dat",ios::in|ios::out|ios::binary);

		   SUser3.seekg(0);



		   char Found6='f';

		   char BkName3[20],Ch1;



		   //gotoxy(10,16);

		   //cout<<"Please Enter The Name Of The Book Which You Would Like To Borrow: ";

		   gotoxy(12,7);

		   gets(BkName3);



		   while(SUser3.read((char*)&Book5,sizeof(Book5)))

		   {

			   if((strcmp(Book5.BookName,BkName3)==0)&&(Book5.BookCopies>0))

			   {

				Found6='t';



				cout<<"\n";

				cout<<"|------------------------------------------------------------------------------|";

				cout<<"| | Book Code |  Book Name  |  Book Author  |  Book Type  | Number Of Copies | |";

				cout<<"|------------------------------------------------------------------------------|";



				Book5.PutBookData();



				gotoxy(12,15);

				cout<<"Do You Want To Borrow This Book? : ";

				cin>>Ch1;



					if(Ch1=='Y'||Ch1=='y')

					{



					User1.BookCode=Book5.BookCode;

					User1.BookCopies=Book5.BookCopies;

					strcpy(User1.BookName,Book5.BookName);

					strcpy(User1.AuthorName,Book5.AuthorName);



					int Pos=-sizeof(Book5);

					--Book5.BookCopies;

					SUser3.seekp(Pos,ios::cur);



					SUser1.write((char*)&User1,sizeof(User1));

					SUser3.write((char*)&Book5,sizeof(Book5));



					}

					else

					break;



			   }  //End Of if Statement.



		   }   //End Of While Loop.



		   if(Found6=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Book You've Searched For Is Not In The Database.\n";

		   }

		   gotoxy(10,20);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";



		   SUser1.close();

		   SUser2.close();

		   SUser3.close();





		}  //End Of else Statement.



	}  //End Of UserOptions::IssueBook().



/*********************************************************************************

		Class UserOptions - Member Function -- ReturnBook()

************************************************************************************/



	int UserOptions::ReturnBook()

	{

		clrscr();



		ifstream SUser4;  //Reading From IssuedBooks.dat.

		SUser4.open("IssuedBooks.dat",ios::in|ios::binary);



		ofstream SUser5("TemporaryFile3.dat",ios::out|ios::binary);  //Creating A Temporary File Named TemporaryFile3.





		 fstream SUser6;  //Book Reading and Writing Into FIle.

		 SUser6.open("LibraryBooks.dat",ios::in|ios::out|ios::binary);  //Opening LibraryBooks.dat.

		 SUser6.seekg(0);



		char MbName5[20],Found7='f',Confirm3='n';



		textcolor(MAGENTA);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |                       List Of Members In Database                          | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(15,5);

		cout<<"Enter The Member Name Whose Book You Want To Return: ";

		gotoxy(15,7);

		gets(MbName5);





		   while(SUser4.read((char*)&User2,sizeof(User2)))

		   {

			if(strcmp(User2.MemName,MbName5)==0)

			{



			cout<<"\n";

			cout<<"|------------------------------------------------------------------------------|";

			cout<<"| |   Code   |    Name    |   Book Code   |    Issued Book    |    Author    | |";

			cout<<"|------------------------------------------------------------------------------|";





			cout.width(8); cout<<User2.MemCode;



			cout.width(16); cout<<User2.MemName;



			cout.width(12); cout<<User2.BookCode;



			cout.width(17); cout<<User2.BookName;



			cout.width(19); cout<<User2.AuthorName;



			cout<<"\n";



				Found7='t';



				gotoxy(15,18);

				cout<<"Are You Sure You Want To Return This Book? (Y/N)";

				cin>>Confirm3;



				   if(Confirm3=='n')

				   {

				   SUser5.write((char*)&User2,sizeof(UserOptions));

				   goto A;

				   }



			}

			else

			{

			SUser5.write((char*)&User2,sizeof(User2));

			}



			 while(SUser6.read((char*)&Book5,sizeof(Book5)))

			    {

				if(strcmp(Book5.BookName,User1.BookName)==0)

				{

					int Pos1=-sizeof(Book5);

					++Book5.BookCopies;

					SUser6.seekp(Pos1,ios::cur);



					SUser6.write((char*)&Book5,sizeof(Book5));

					break;

				}

			    }  //End of while Iteration.



		   }  //End Of while Iteration.



	A:

		   if(Found7=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Member You've Searched For Is Not In The Database.\n";

		   }

		   gotoxy(10,20);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";





		   SUser4.close();

		   SUser5.close();

		   SUser6.close();





		   remove("IssuedBooks..dat");  //Delete Binary File Named IssuedBooks.

		   rename("TemporaryFile3.dat","IssuedBooks.dat");   //Rename TemporaryFile3.dat to IssuedBooks.dat.





	       return 0;

	     }  //End Of UserOptions::ReturnBook().



/***********************************************************************************

		Class UserOptions - Member Function -- AccountDetails()

************************************************************************************/



	void UserOptions::AccountDetails()

	{

		clrscr();



		ifstream SUser7;  //Open File IssuedBooks.dat.

		SUser7.open("IssuedBooks.dat",ios::app|ios::binary);

		SUser7.seekg(0);



		char Found8='f';

		char MbName6[20];



		textcolor(LIGHTBLUE);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |                Account Details Of Members In Database                      | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(15,5);

		cout<<"Enter The Member Name : ";

		gotoxy(15,7);

		gets(MbName6);



		   while(SUser7.read((char*)&User3,sizeof(User3)))

		   {





			   if(strcmp(User3.MemName,MbName6)==0)

			   {



			   cout<<"\n";

			   cout<<"|------------------------------------------------------------------------------|";

			   cout<<"| |   Code   |    Name    |   Book Code   |    Issued Book    |    Author    | |";

			   cout<<"|------------------------------------------------------------------------------|";





				cout.width(8); cout<<User3.MemCode;



				cout.width(16); cout<<User3.MemName;



				cout.width(12); cout<<User3.BookCode;



				cout.width(17); cout<<User3.BookName;



				cout.width(19); cout<<User3.AuthorName;



				cout<<"\n";



				int Day=d.da_day+5;

				int Month=d.da_mon;

				int Year=d.da_year;

				const Day1=d.da_day+5;

				gotoxy(15,18);

				cout<<"The Return Date For This Book Is: "; cprintf("%d/%d/%d",Day1,Month,Year);



				Found8='t';

			   }  //End Of if Statement.



		   }   //End Of While Loop.



		   if(Found8=='f')

		   {

		   gotoxy(10,9);

		   cout<<"Sorry! The Member You've Searched For Is Not In The Database.\n";

		   }

		   gotoxy(10,20);

		   cout<<"Press 'Up' Or 'Down' Arrow Key To Return To The Previous Menu!";





		   SUser7.close();



	}   //End Of UserOptions::AccountDetails().





/***********************************************************************************

       AdminOpt() Function ( Displays All Options Required By The Manager )

************************************************************************************/



	void AdminOpt()

	{

		clrscr();



		AdminOptions Book;  //Object Of BookOptions To Access The Member Funtions.





		textcolor(CYAN);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |               Administrator Facilities: What Would You Like To Do?         | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(20,5);

		cout<<"Use Arrow Keys For Navigation!";



		gotoxy(20,7);

		printf("Book Options: \n");



		gotoxy(20,9);

		printf("Add A Book. \n");

		gotoxy(20,10);

		printf("Delete A Book. \n");

		gotoxy(20,11);

		printf("Search And Display A Selected Book. \n");

		gotoxy(20,12);

		printf("Display The Book List. \n");



		gotoxy(20,14);

		printf("Member Options: \n");



		gotoxy(20,16);

		printf("Add A Member. \n");

		gotoxy(20,17);

		printf("Delete A Member. \n");

		gotoxy(20,18);

		printf("Search And Display A Selected Member. \n");

		gotoxy(20,19);

		printf("Display The Member List. \n");



		int l=0;   //Counter Used During Arrow Key Navigation For Menu.



		int Mng1;



		Mng1=getch();



		while(Mng1!=27)

		{

			if(kbhit())

			{

				int Mng2=getch();



				switch(Mng2)

				{



				case UP:



				if(l>8)	 l=8;   //Resets The Counter.





				   if(l==8)

				   {

					clrscr();

					l--;



					textcolor(YELLOW);

					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					cprintf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");

					textcolor(WHITE);



					   int Mng3;

					   Mng3=getch();



					   if(Mng3==ENTER)

					   {



					   Book.DisplaySelMem();

					   }

					   else

					   continue;



					break;

				   }	//End Of if Statement.



				   if(l==7)

				   {

					clrscr();

					l--;



					textcolor(YELLOW);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					cprintf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng4;

					   Mng4=getch();



					   if(Mng4==ENTER)

					   {



					   Book.DeleteMem();

					   }

					   else

					   continue;



					break;

				   }   //End Of if Statement.



				   if(l==6)

				   {

					clrscr();

					l--;



					textcolor(YELLOW);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					cprintf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");





					textcolor(WHITE);



					   int Mng5;

					   Mng5=getch();



					   if(Mng5==ENTER)

					   {



					   Book.AddMem();

					   }

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(l==5)

				   {

					clrscr();

					l--;



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					cprintf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");





					textcolor(WHITE);



					   int Mng6;

					   Mng6=getch();



					   if(Mng6==ENTER)

					   {



					   Book.DisplayBooks();

					   }

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(l==4)

				   {

					clrscr();

					l--;



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					cprintf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");





					textcolor(WHITE);



					   int Mng7;

					   Mng7=getch();



					   if(Mng7==ENTER)

					   {



					   Book.DisplaySelBook();

					   }

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(l==3)

				   {

					clrscr();

					l--;



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					cprintf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");





					textcolor(WHITE);



					   int Mng8;

					   Mng8=getch();



					   if(Mng8==ENTER)

					   {



					   Book.DeleteBook();

					   }

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(l==2)

				   {

					clrscr();

					l--;



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					cprintf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");





					textcolor(WHITE);



					   int Mng9;

					   Mng9=getch();



					   if(Mng9==ENTER)

					   {



					   Book.AddBook();

					   }

					   else

					   continue;



					break;

				   }   //End Of if Statement.







				break;	//break; Statement For case UP:.



				case DOWN:



				  l++;



				   if(l==1)

				   {

					clrscr();



					textcolor(GREEN);

					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					cprintf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng10;

					   Mng10=getch();



					   if(Mng10==ENTER)

					   {



					   Book.AddBook();

					   }

					   else

					   continue;



				 }   //End Of if Statement.



				 if(l==2)

				 {

					clrscr();



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					cprintf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng11;

					   Mng11=getch();



					   if(Mng11==ENTER)

					   {



					   Book.DeleteBook();

					   }

					   else

					   continue;



				 }   //End Of if Stetement.



				 if(l==3)

				 {

					clrscr();



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					cprintf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng12;

					   Mng12=getch();



					   if(Mng12==ENTER)

					   {



					   Book.DisplaySelBook();

					   }

					   else

					   continue;

				 }   //End Of if Statement.



				 if(l==4)

				 {

					clrscr();



					textcolor(GREEN);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					cprintf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng13;

					   Mng13=getch();



					   if(Mng13==ENTER)

					   {



					   Book.DisplayBooks();

					   }

					   else

					   continue;

				 }   //End Of if Statement.



				 if(l==5)

				 {

					clrscr();



					textcolor(YELLOW);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					cprintf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng14;

					   Mng14=getch();



					   if(Mng14==ENTER)

					   {



					   Book.AddMem();

					   }

					   else

					   continue;

				 }   //End Of if Statement.





				 if(l==6)

				 {

					clrscr();



					textcolor(YELLOW);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					cprintf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng15;

					   Mng15=getch();



					   if(Mng15==ENTER)

					   {



					   Book.DeleteMem();

					   }

					   else

					   continue;

				 }   //End Of if Statement.





				 if(l==7)

				 {

					clrscr();



					textcolor(YELLOW);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					cprintf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					printf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng16;

					   Mng16=getch();



					   if(Mng16==ENTER)

					   {



					   Book.DisplaySelMem();

					   }

					   else

					   continue;

				 }   //End Of if Statement.





				 if(l==8)

				 {

					clrscr();



					textcolor(YELLOW);



					gotoxy(15,3);

					cprintf("Administrator Facilities: What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Use Arrow Keys For Navigation!";



					gotoxy(20,7);

					printf("Book Options: \n");



					gotoxy(20,9);

					printf("Add A Book. \n");

					gotoxy(20,10);

					printf("Delete A Book. \n");

					gotoxy(20,11);

					printf("Search And Display A Selected Book. \n");

					gotoxy(20,12);

					printf("Display The Book List. \n");



					gotoxy(20,14);

					printf("Member Options: \n");



					gotoxy(20,16);

					printf("Add A Member. \n");

					gotoxy(20,17);

					printf("Delete A Member. \n");

					gotoxy(20,18);

					printf("Search And Display A Selected Member. \n");

					gotoxy(20,19);

					cprintf("Display The Member List. \n");



					textcolor(WHITE);



					   int Mng17;

					   Mng17=getch();



					   if(Mng17==ENTER)

					   {



					   Book.DisplayMem();

					   }

					   else

					   continue;

				 }   //End Of if Statement.





				 if(l==9) break;



				break;   //break; Statement For case DOWN:.



				}  //End Of Switch-Case Statement.



			}   //End Of If Statement.



			Mng1=getch();

		}   //End Of While Statement.





	}



/***********************************************************************************

       PubOpt() Function ( Displays All Options Required By The User )

************************************************************************************/



	void PubOpt()

	{

		clrscr();



		AdminOptions Book;



		UserOptions User;





		textcolor(CYAN);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |                     Welcome: What Would You Like To Do?                    | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(20,5);

		cout<<"Use Arrow Keys For Navigation!";



		gotoxy(20,7);

		printf("Browse Through Book List. \n");

		gotoxy(20,8);

		printf("Search For A Book. \n");

		gotoxy(20,9);

		printf("Issue A Book. \n");

		gotoxy(20,10);

		printf("Return A Book.");

		gotoxy(20,11);

		printf("Check Account Details.");



		int w=0;   //Counter Used During Arrow Key Navigation For Menu.



		int Ch4,Ch5;



		Ch4=getch();



		while(Ch4!=27)

		{

			if(kbhit())

			{

				Ch5=getch();



				switch(Ch5)

				{



				case UP:



				if(w>5)	 w=5;   //Resets The Counter.





				   if(w==5)

				   {

					clrscr();

					w--;

					textcolor(CYAN);



					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					cprintf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");





					textcolor(WHITE);



					   int Ch6;

					   Ch6=getch();



					   if(Ch6==ENTER)

					   User.ReturnBook();

					   else

					   continue;



					break;

				   }	//End Of if Statement.



				   if(w==4)

				   {

					clrscr();

					w--;

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					cprintf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch7;

					   Ch7=getch();



					   if(Ch7==ENTER)

					   User.IssueBook();

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(w==3)

				   {

					clrscr();

					w--;

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					cprintf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch8;

					   Ch8=getch();



					   if(Ch8==ENTER)

					   Book.DisplaySelBook();

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(w==2)

				   {

					clrscr();

					w--;

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					cprintf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch9;

					   Ch9=getch();



					   if(Ch9==ENTER)

					   Book.DisplayBooks();

					   else

					   continue;



					break;

				   }   //End Of if Statement.









				break;	//break; Statement For case UP:.



				case DOWN:



				  w++;



				  if(w==1)

				   {

					clrscr();

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					cprintf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch10;

					   Ch10=getch();



					   if(Ch10==ENTER)

					   Book.DisplayBooks();

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(w==2)

				   {

					clrscr();

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					cprintf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch11;

					   Ch11=getch();



					   if(Ch11==ENTER)

					   Book.DisplaySelBook();

					   else

					   continue;



					break;

				   }   //End Of if Statement.







				 if(w==3)

				   {

					clrscr();

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					cprintf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch12;

					   Ch12=getch();



					   if(Ch12==ENTER)

					   User.IssueBook();

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				   if(w==4)

				   {

					clrscr();

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					cprintf("Return A Book.");

					gotoxy(20,11);

					printf("Check Account Details.");



					textcolor(WHITE);



					   int Ch13;

					   Ch13=getch();



					   if(Ch13==ENTER)

					   User.ReturnBook();

					   else

					   continue;



					break;

				   }   //End Of if Statement.





				    if(w==5)

				   {

					clrscr();

					textcolor(CYAN);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("Browse Through Book List. \n");

					gotoxy(20,8);

					printf("Search For A Book. \n");

					gotoxy(20,9);

					printf("Issue A Book. \n");

					gotoxy(20,10);

					printf("Return A Book.");

					gotoxy(20,11);

					cprintf("Check Account Details.");



					textcolor(WHITE);



					   int Ch14;

					   Ch14=getch();



					   if(Ch14==ENTER)

					   User.AccountDetails();

					   else

					   continue;



					break;

				   }   //End Of if Statement.







				 if(w==6)   break;



				break;   //break; Statement For case DOWN:.



				}  //End Of Switch-Case Statement.



			}   //End Of If Statement.



			Ch4=getch();

		}   //End Of While Statement.



	}  //End Of PubOpt().



/***********************************************************************************

			       main() Function

************************************************************************************/



	void main()

	{

		clrscr();



		textcolor(LIGHTBLUE);

		cout<<endl<<endl;

		cout<<"\t\t";cprintf("   LL     ");cout<<endl;

		cout<<"\t\t";cprintf("   LL     ");cout<<endl;

		cout<<"\t\t";cprintf("   LL     ");cout<<endl;

		cout<<"\t\t";cprintf("   LL     ");cout<<endl;

		cout<<"\t\t";cprintf("   LLLLLLLL ");cout<<endl;



		delay(500);



		clrscr();

		textcolor(BLUE);

		cout<<endl<<endl;

		cout<<"\t\t";cprintf("   LL       DDDDD  ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD ");cout<<endl;

		cout<<"\t\t";cprintf("   LLLLLLLL DDDDD   ");cout<<endl;



		delay(500);



		clrscr();

		textcolor(CYAN);

		cout<<endl<<endl;

		cout<<"\t\t";cprintf("   LL       DDDDD    BBBBBB  ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BB    B ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BBBBBBB ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BB    B ");cout<<endl;

		cout<<"\t\t";cprintf("   LLLLLLLL DDDDD    BBBBBB  ");cout<<endl;



		delay(500);



		clrscr();

		textcolor(LIGHTGREEN);

		cout<<endl<<endl;

		cout<<"\t\t";cprintf("   LL       DDDDD    BBBBBB   MM    MM ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BB    B  MMM  MMM ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BBBBBBB  MM MM MM ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BB    B  MM    MM ");cout<<endl;

		cout<<"\t\t";cprintf("   LLLLLLLL DDDDD    BBBBBB   MM    MM ");cout<<endl;



		delay(500);



		clrscr();

		textcolor(CYAN);

		cout<<endl<<endl;

		cout<<"\t\t";cprintf("   LL       DDDDD    BBBBBB  MM    MM  SSSSS");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BB    B MMM  MMM  SS    ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BBBBBBB MM MM MM    SS  ");cout<<endl;

		cout<<"\t\t";cprintf("   LL       DD   DD  BB    B MM    MM      SS");cout<<endl;

		cout<<"\t\t";cprintf("   LLLLLLLL DDDDD    BBBBBB  MM    MM  SSSSSS ");cout<<endl;



		delay(1000);



		char Name5[50]={"Library Database Management System"};



		gotoxy(23,10);



		for(int j=0;j<34;j++)

		{

			textcolor(LIGHTGREEN);

			cprintf("%c",Name5[j]);

			delay(180);

		}

		cout<<endl;





		char Name1[50]={"Project By:"};



		gotoxy(34,15);



		for(int i=0;i<11;i++)

		{

			textcolor(LIGHTCYAN);

			cprintf("%c",Name1[i]);

			delay(120);

		}

		cout<<endl;



		char Name2[50]={"Nagaraj Archak"};



		gotoxy(32,17);



		for(int p=0;p<14;p++)

		{

			textcolor(LIGHTBLUE);

			cprintf("%c",Name2[p]);

			delay(180);

		}

		cout<<endl;



		char Name3[50]={"and"};



		gotoxy(38,18);



		for(int l=0;l<3;l++)

		{

			textcolor(LIGHTCYAN);

			cprintf("%c",Name3[l]);

			delay(80);

		}



		char Name4[50]={"Aadithya Vidyasagar"};



		gotoxy(30,19);



		for(int m=0;m<19;m++)

		{

			textcolor(LIGHTBLUE);

			cprintf("%c",Name4[m]);

			delay(180);

		}



		delay(1000);



		clrscr();



//*********************************************************************************



		textbackground(BLACK);



		clrscr();



		getdate(&d);

		clrscr();



		textcolor(LIGHTGREEN);



		cprintf(" |----------------------------------------------------------------------------| ");

		cprintf(" |                     Welcome: What Would You Like To Do?                    | ");

		cprintf(" |----------------------------------------------------------------------------| ");



		textcolor(WHITE);



		gotoxy(20,5);

		cout<<"Use Arrow Keys For Navigation!";



		gotoxy(20,7);



		cprintf("1. Manager Options. \n");

		gotoxy(20,8);

		printf("2. User Options. \n");

		gotoxy(20,9);

		printf("3. Exit \n");



		int k=0;   //Counter Used During Arrow Key Navigation For Menu.



		int Ch1;



		Ch1=getch();



		while(Ch1!=27)

		{

			if(kbhit())

			{

				int Ch2=getch();



				switch(Ch2)

				{



				case UP:



				if(k>3)	 k=3;   //Resets The Counter.





				   if(k==3)

				   {

					clrscr();

					k--;

					textcolor(LIGHTBLUE);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";









					gotoxy(20,7);

					printf("1. Manager Options. \n");

					gotoxy(20,8);							gotoxy(20,8);

					cprintf("2. User Options. \n");

					gotoxy(20,9);

					printf("3. Exit \n");



					textcolor(WHITE);



					   int Ch3;

					   Ch3=getch();



					   if(Ch3==ENTER)

					   PubOpt();

					   else

					   continue;



					break;

				   }	//End Of if Statement.



				   if(k==2)

				   {

					clrscr();

					k--;

					textcolor(LIGHTBLUE);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					cprintf("1. Manager Options. \n");

					gotoxy(20,8);

					printf("2. User Options. \n");

					gotoxy(20,9);

					printf("3. Exit \n");



					textcolor(WHITE);



					   int Ch4;

					   Ch4=getch();



					   if(Ch4==ENTER)

					   AdminOpt();

					   else

					   continue;



					break;

				   }   //End Of if Statement.



				break;	//break; Statement For case UP:.



				case DOWN:



				  k++;



				   if(k==1)

				   {

					clrscr();



					textcolor(LIGHTBLUE);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";





					gotoxy(20,7);

					cprintf("1. Manager Options. \n");

					gotoxy(20,8);

					printf("2. User Options. \n");

					gotoxy(20,9);

					printf("3. Exit \n");



					textcolor(WHITE);



					   int Ch5;

					   Ch5=getch();



					   if(Ch5==ENTER)

					   AdminOpt();

					   else

					   continue;



				 }   //End Of if Statement.



				 if(k==2)

				 {

					clrscr();

					textcolor(LIGHTBLUE);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("1. Manager Options. \n");

					gotoxy(20,8);

					cprintf("2. User Options. \n");

					gotoxy(20,9);

					printf("3. Exit \n");



					textcolor(WHITE);



					   int Ch6;

					   Ch6=getch();



					   if(Ch6==ENTER)

					   PubOpt();

					   else

					   continue;



				 }   //End Of if Stetement.



				 if(k==3)

				 {

					clrscr();

					textcolor(LIGHTBLUE);

					gotoxy(15,3);

					cprintf("Welcome! What Would You Like To Do?");

					gotoxy(20,5);

					cout<<"Press Enter To Choose The Highlighted Option!";







					gotoxy(20,7);

					printf("1. Manager Options. \n");

					gotoxy(20,8);

					printf("2. User Options. \n");

					gotoxy(20,9);

					cprintf("3. Exit \n");



					textcolor(WHITE);



					   int Ch7;

					   Ch7=getch();



					   if(Ch7==ENTER)

					   exit(0);

					   else

					   continue;

				 }   //End of if Statement.



				 if(k==4)   break;



				break;   //break; Statement For case DOWN:.



				}  //End Of Switch-Case Statement.



			}   //End Of If Statement.



			Ch1=getch();

		}   //End Of While Statement.



	}   //End of main();.
