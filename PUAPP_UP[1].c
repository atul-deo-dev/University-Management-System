#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<dos.h>
#include<ctype.h>
#include<time.h>
#include<stdlib.h>
#include<process.h>
void apply(); 
void alumni(); 
void contacts_info();
void eligiblity();
void fee_struct();
#define RETURNTIME 15
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechnnical","Architecture"};
void returnfunc(void);
void mainmenu(void);
void addbooks(void);
void deletebooks(void);
void why();
void editbooks(void);
void change_password();
void searchbooks(void);
void issuebooks(void);
void viewbooks(void);
void closeapplication(void);
int  getdata();
int  checkid(int);
int t(void);
void Password();
void issuerecord();
void loaderanim();
void scholarship();
COORD coord = {0, 0}; 
COORD max_res,cursor_size;
void gotoxy (int x, int y)
{
        coord.X = x; coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
FILE *fp,*ft,*fs;
int s;
char findbook;
char password[10]={"tarunk111"};
 struct meroDate
{
    int mm,dd,yy;
};
struct books
{
    int id;
    char stname[20];
    char name[20];
    char Author[20];
    int quantity;
    float Price;
    int count;
    int rackno;
    char *cat;
    struct meroDate issued;
    struct meroDate duedate;
};
struct books a;
int library()
 { 
      loaderanim();
      Password();
      mainmenu();
      getch();
   return 0;
 }
void mainmenu()
{
	   loaderanim();
    system("cls");
    int i;
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2 MAIN MENU");
    printf(" \xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Add Books   ");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Delete books");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Search Books");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Issue Books");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 5. View Book list");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Edit Book's Record");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Close Application");
    gotoxy(20,19);
    printf("------------------------------------------");
    gotoxy(20,20);
    t();
    gotoxy(20,21);
    printf("Enter your choice:");
    switch(getch())
    {
        case '1':
        addbooks();
        break;
    case '2':
        deletebooks();
        break;
        case '3':
        searchbooks();
        break;
    case '4':
        issuebooks();
        break;
        case '5':
        viewbooks();
        break;
        case '6':
        editbooks();
        break;
        case '7':
        {
        system("cls");
        gotoxy(16,3);
        gotoxy(10,7);
        printf("Exiting in 5 second...........>");
        delay(5000);
        main();
        }
        default:
        {
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        getch();
        mainmenu();
        }
     }
}
void addbooks(void)    
{
    system("cls");
    int i;
    gotoxy(20,5);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xDB\xB2 1. Computer");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xDB\xB2 2. Electronics");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xDB\xB2 3. Electrical");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xDB\xB2 4. Civil");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xDB\xB2 5. Mechanical");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xDB\xB2 6. Architecture");
    gotoxy(20,19);
    printf("\xDB\xDB\xDB\xDB\xB2 7. Back to main menu");
    gotoxy(20,21);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,22);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==7)
    mainmenu() ;
    system("cls");
    fp=fopen("Bibek.dat","ab+");
    if(getdata()==1)
    {
    a.cat=catagories[s-1];
    fseek(fp,0,SEEK_END);
    fwrite(&a,sizeof(a),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("The record is sucessfully saved");
    gotoxy(21,15);
    printf("Save any more?(Y / N):");
    if(getch()=='n')
        mainmenu();
    else
        system("cls");
        addbooks();
    }
}
void deletebooks()    
{
    system("cls");
    int d;
    char another='y';
    while(another=='y')
    {
    system("cls");
    gotoxy(10,5);
    printf("Enter the Book ID to  delete:");
    scanf("%d",&d);
    fp=fopen("Bibek.dat","rb+");
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(a.id==d)
        {
 
        gotoxy(10,7);
        printf("The book record is available");
        gotoxy(10,8);
        printf("Book name is %s",a.name);
        gotoxy(10,9);
        printf("Rack No. is %d",a.rackno);
        findbook='t';
        }
    }
    if(findbook!='t')
    {
        gotoxy(10,10);
        printf("No record is found modify the search");
        if(getch())
        mainmenu();
    }
    if(findbook=='t' )
    {
        gotoxy(10,9);
        printf("Do you want to delete it?(Y/N):");
        if(getch()=='y')
        {
        ft=fopen("test.dat","wb+");  
        rewind(fp);
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(a.id!=d)
            {
            fseek(ft,0,SEEK_CUR);
            fwrite(&a,sizeof(a),1,ft); 
            }                             
        }
        fclose(ft);
        fclose(fp);
        remove("Bibek.dat");
        rename("test.dat","Bibek.dat"); 
        fp=fopen("Bibek.dat","rb+");    
        if(findbook=='t')
        {
            gotoxy(10,10);
            printf("The record is sucessfully deleted");
            gotoxy(10,11);
            printf("Delete another record?(Y/N)");
        }
        }
    else
    mainmenu();
    fflush(stdin);
    another=getch();
    }
    }
    gotoxy(10,15);
    mainmenu();
}
void searchbooks()
{
    system("cls");
    int d;
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB\xB2 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB\xB2 2. Search By Name");
    gotoxy( 15,20);
    printf("Enter Your Choice");
    fp=fopen("Bibek.dat","rb+"); 
    rewind(fp);   
    switch(getch())
    {
      case '1':
    {
        system("cls");
        gotoxy(25,4);
        printf("****Search Books By Id****");
        gotoxy(20,5);
        printf("Enter the book id:");
        scanf("%d",&d);
        gotoxy(20,7);
        printf("Searching........");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(a.id==d)
        {
            delay(2);
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
            gotoxy(20,10);
            printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Author:%s ",a.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Qantity:%d ",a.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            findbook='t';
        }
 
        }
        if(findbook!='t')  
        {
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchbooks();
        else
        mainmenu();
        break;
    }
    case '2':
    {
        char s[15];
        system("cls");
        gotoxy(25,4);
        printf("****Search Books By Name****");
        gotoxy(20,5);
        printf("Enter Book Name:");
        scanf("%s",s);
        int d=0;
        while(fread(&a,sizeof(a),1,fp)==1)
        {
        if(strcmp(a.name,(s))==0) 
        {
            gotoxy(20,7);
            printf("The Book is available");
            gotoxy(20,8);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            gotoxy(20,9);
            printf("\xB2 ID:%d",a.id);gotoxy(47,9);printf("\xB2");
            gotoxy(20,10);
            printf("\xB2 Name:%s",a.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Author:%s",a.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Qantity:%d",a.quantity);gotoxy(47,12);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Price:Rs.%.2f",a.Price);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("\xB2 Rack No:%d ",a.rackno);gotoxy(47,14);printf("\xB2");
            gotoxy(20,15);
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
            d++;
        }
 
        }
        if(d==0)
        {
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("Try another search?(Y/N)");
        if(getch()=='y')
        searchbooks();
        else
        mainmenu();
        break;
    }
    default :
    getch();
    searchbooks();
    }
    fclose(fp);
}
void issuebooks(void)  
{
    int t;
 
    system("cls");
    printf("********************************ISSUE SECTION**************************");
    gotoxy(10,5);
    printf("\xDB\xDB\xDB\xDb\xB2 1. Issue a Book");
    gotoxy(10,7);
    printf("\xDB\xDB\xDB\xDb\xB2 2. View Issued Book");
    gotoxy(10,9);
    printf("\xDB\xDB\xDB\xDb\xB2 3. Search Issued Book");
    gotoxy(10,11);
    printf("\xDB\xDB\xDB\xDb\xB2 4. Remove Issued Book");
    gotoxy(10,14);
    printf("Enter a Choice:");
    switch(getch())
    {
    case '1':
    {
        system("cls");
        int c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");
            gotoxy(15,4);
            printf("***Issue Book section***");
            gotoxy(10,6);
            printf("Enter the Book Id:");
            scanf("%d",&t);
            fp=fopen("Bibek.dat","rb");
            fs=fopen("Issue.dat","ab+");
            if(checkid(t)==0) 
            {
                 gotoxy(10,8);
                 printf("The book record is available");
                 gotoxy(10,9);
                 printf("There are %d unissued books in library ",a.quantity);
                 gotoxy(10,10);
                 printf("The name of book is %s",a.name);
                 gotoxy(10,11);
                 printf("Enter student name:");
                 scanf("%s",a.stname);
                 gotoxy(10,12);
                 printf("Issued date=%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
                 gotoxy(10,13);
                 printf("The BOOK of ID %d is issued",a.id);
                 a.duedate.dd=a.issued.dd+RETURNTIME;   
                 a.duedate.mm=a.issued.mm;
                 a.duedate.yy=a.issued.yy;
                 if(a.duedate.dd>30)
                 {
                 a.duedate.mm+=a.duedate.dd/30;
                 a.duedate.dd-=30;
 
                 }
                 if(a.duedate.mm>12)
                 {
                a.duedate.yy+=a.duedate.mm/12;
                a.duedate.mm-=12;
 
                 }
                 gotoxy(10,14);
                 printf("To be return:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
                 fseek(fs,sizeof(a),SEEK_END);
                 fwrite(&a,sizeof(a),1,fs);
                 fclose(fs);
                 c=1;
            }
            if(c==0)
            {
            gotoxy(10,11);
            printf("No record found");
            }
            gotoxy(10,15);
            printf("Issue any more(Y/N):");
            fflush(stdin);
            another=getche();
            fclose(fp);
        }
 
        break;
    }
    case '2':  
    {
        system("cls");
        int j=4;
        printf("*******************************Issued book list*******************************\n");
        gotoxy(2,2);
        printf("STUDENT NAME    CATEGORY    ID    BOOK NAME    ISSUED DATE    RETURN DATE");
           fs=fopen("Issue.dat","rb");
        while(fread(&a,sizeof(a),1,fs)==1)
        {
 
            gotoxy(2,j);
            printf("%s",a.stname);
            gotoxy(18,j);
            printf("%s",a.cat);
            gotoxy(30,j);
            printf("%d",a.id);
            gotoxy(36,j);
            printf("%s",a.name);
            gotoxy(51,j);
            printf("%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy );
            gotoxy(65,j);
            printf("%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
            
            gotoxy(50,25);
            j++;
 
        }
        fclose(fs);
        gotoxy(1,25);
        returnfunc();
    }
    break;
    case '3': 
    {
        system("cls");
        gotoxy(10,6);
        printf("Enter Book ID:");
        int p,c=0;
        char another='y';
        while(another=='y')
        {
 
            scanf("%d",&p);
            fs=fopen("Issue.dat","rb");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==p)
                {
                    issuerecord();
                    gotoxy(10,12);
                    printf("Press any key.......");
                    getch();
                    issuerecord();
                    c=1;
                }
 
            }
            fflush(stdin);
            fclose(fs);
            if(c==0)
            {
                gotoxy(10,8);
                printf("No Record Found");
            }
            gotoxy(10,13);
            printf("Try Another Search?(Y/N)");
            another=getch();
        }
    }
    break;
    case '4':
    {
        system("cls");
        int b;
        FILE *fg;  
        char another='y';
        while(another=='y')
        {
            gotoxy(10,5);
            printf("Enter book id to remove:");
            scanf("%d",&b);
            fs=fopen("Issue.dat","rb+");
            while(fread(&a,sizeof(a),1,fs)==1)
            {
                if(a.id==b)
                {
                    issuerecord();
                    findbook='t';
                }
                if(findbook=='t')
                {
                    gotoxy(10,12);
                    printf("Do You Want to Remove it?(Y/N)");
                    if(getch()=='y')
                    {
                        fg=fopen("record.dat","wb+");
                        rewind(fs);
                        while(fread(&a,sizeof(a),1,fs)==1)
                        {
                            if(a.id!=b)
                            {
                            fseek(fs,0,SEEK_CUR);
                            fwrite(&a,sizeof(a),1,fg);
                            }
                        }
                        fclose(fs);
                        fclose(fg);
                        remove("Issue.dat");
                        rename("record.dat","Issue.dat");
                        gotoxy(10,14);
                        printf("The issued book is removed from list");
 
                       }
 
                }
                if(findbook!='t')
                {
                    gotoxy(10,15);
                    printf("No Record Found");
                }
            }
            gotoxy(10,16);
            printf("Delete any more?(Y/N)");
            another=getch();
        }
    }
    default:
    gotoxy(10,18);
    printf("\aWrong Entry!!");
    getch();
    issuebooks();
    break;
      }
      gotoxy(1,30);
      returnfunc();
}
void viewbooks(void)  
{
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("*********************************Book List*****************************");
    gotoxy(2,2);
    printf(" CATEGORY     ID    BOOK NAME     AUTHOR       QTY     PRICE     RackNo ");
    j=4;
    fp=fopen("Bibek.dat","rb");
    while(fread(&a,sizeof(a),1,fp)==1)
    {
    gotoxy(3,j);
    printf("%s",a.cat);
    gotoxy(16,j);
    printf("%d",a.id);
    gotoxy(22,j);
    printf("%s",a.name);
    gotoxy(36,j);
    printf("%s",a.Author);
    gotoxy(50,j);
    printf("%d",a.quantity);
    gotoxy(57,j);
    printf("%.2f",a.Price);
    gotoxy(69,j);
    printf("%d",a.rackno);
    printf("\n\n");
    j++;
    i=i+a.quantity;
      }
      gotoxy(3,25);
      printf("Total Books =%d",i);
      fclose(fp);
      gotoxy(35,25);
      returnfunc();
}
void editbooks(void)  
{
    system("cls");
    int c=0;
    int d,e;
    gotoxy(20,4);
    printf("****Edit Books Section****");
    char another='y';
    while(another=='y')
    {
        system("cls");
        gotoxy(15,6);
        printf("Enter Book Id to be edited:");
        scanf("%d",&d);
        fp=fopen("Bibek.dat","rb+");
        while(fread(&a,sizeof(a),1,fp)==1)
        {
            if(checkid(d)==0)
            {
                gotoxy(15,7);
                printf("The book is availble");
                gotoxy(15,8);
                printf("The Book ID:%d",a.id);
                gotoxy(15,9);
                printf("Enter new name:");scanf("%s",a.name);
                gotoxy(15,10);
                printf("Enter new Author:");scanf("%s",a.Author);
                gotoxy(15,11);
                printf("Enter new quantity:");scanf("%d",&a.quantity);
                gotoxy(15,12);
                printf("Enter new price:");scanf("%f",&a.Price);
                gotoxy(15,13);
                printf("Enter new rackno:");scanf("%d",&a.rackno);
                gotoxy(15,14);
                printf("The record is modified");
                fseek(fp,ftell(fp)-sizeof(a),0);
                fwrite(&a,sizeof(a),1,fp);
                fclose(fp);
                c=1;
            }
            if(c==0)
            {
                gotoxy(15,9);
                printf("No record found");
            }
        }
        gotoxy(15,16);
        printf("Modify another Record?(Y/N)");
        fflush(stdin);
        another=getch() ;
    }
        returnfunc();
}
void returnfunc(void)
{
    
    printf(" Press ENTER to return to main menu");
    a:
    if(getch()==13) 
    mainmenu();
    else
    goto a;
}
int getdata()
{
    int t;
    gotoxy(20,3);
    printf("Enter the Information Below");
    gotoxy(20,4);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xB2");gotoxy(46,5);printf("\xB2");
    gotoxy(20,6);
    printf("\xB2");gotoxy(46,6);printf("\xB2");
    gotoxy(20,7);
    printf("\xB2");gotoxy(46,7);printf("\xB2");
    gotoxy(20,8);
    printf("\xB2");gotoxy(46,8);printf("\xB2");
    gotoxy(20,9);
    printf("\xB2");gotoxy(46,9);printf("\xB2");
    gotoxy(20,10);
    printf("\xB2");gotoxy(46,10);printf("\xB2");
    gotoxy(20,11);
    printf("\xB2");gotoxy(46,11);printf("\xB2");
    gotoxy(20,12);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(21,5);
    printf("Category:");
    gotoxy(31,5);
    printf("%s",catagories[s-1]);
    gotoxy(21,6);
    printf("Book ID:\t");
    gotoxy(30,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe book id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    a.id=t;
    gotoxy(21,7);
    printf("Book Name:");gotoxy(33,7);
    scanf("%s",a.name);
    gotoxy(21,8);
    printf("Author:");gotoxy(30,8);
    scanf("%s",a.Author);
    gotoxy(21,9);
    printf("Quantity:");gotoxy(31,9);
    scanf("%d",&a.quantity);
    gotoxy(21,10);
    printf("Price:");gotoxy(28,10);
    scanf("%f",&a.Price);
    gotoxy(21,11);
    printf("Rack No:");gotoxy(30,11);
    scanf("%d",&a.rackno);
    return 1;
}
int checkid(int t)  
{
    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    if(a.id==t)
    return 0;  
      return 1; 
}
int t(void) 
{
time_t t;
time(&t);
printf("Date and time:%s\n",ctime(&t));
 return 0 ;
}
 void Password(void) 
{
 
   system("cls");
   char d[25]="Password Protected";
   char ch,pass[10];
   int i=0,j;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    delay(50);
    printf("*");
    }
    for(j=0;j<20;j++)
   {
   delay(50);
   printf("%c",d[j]);
   }
   for(j=0;j<20;j++)
   {
   delay(50);
   printf("*");
   }
   gotoxy(10,10);
   gotoxy(15,7);
   printf("Enter Password:");
    while(ch!=13)
   {
    ch=getch();
     if(ch!=13 && ch!=8){
    putch('*');
    pass[i] = ch;
    i++;
    }
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {
    gotoxy(15,9);
    printf("Password match");
    gotoxy(17,10);
    printf("Press any key to countinue.....");
    getch();
      }
   else
   {
     gotoxy(15,16);
     printf("\aWarning!! Incorrect Password");
     getch();
     Password();
   }
}
void issuerecord()  
{
         system("cls");
         gotoxy(10,8);
         printf("The Book has taken by Mr. %s",a.stname);
         gotoxy(10,9);
         printf("Issued Date:%d-%d-%d",a.issued.dd,a.issued.mm,a.issued.yy);
         gotoxy(10,10);
         printf("Returning Date:%d-%d-%d",a.duedate.dd,a.duedate.mm,a.duedate.yy);
}
void loaderanim()
{
int loader;
system("cls");
gotoxy(20,10);
printf("LOADING........");
printf("\n\n");
gotoxy(22,11);
for(loader=1;loader<20;loader++)
{
delay(100);printf("%c",219);
}
}
int main()
{
static int frun;
frun++;
loaderanim();
if(frun==1)
Password();
system("cls");
int choice;
puts("\n\nPOORNIMA UNIVERSITY");
puts("\n\nenter your choice:-");
puts("\n1.admission apply");
puts("\n2.alumni");
puts("\n3.Contacts info");
puts("\n4.Eligiblity criteria for admission");
puts("\n5.Fee structure");
puts("\n6.Library");
puts("\n7.Password change");
puts("\n8.Scholarship apply");
puts("\n9.WHY PU?");
puts("\n10.EXIT");
time_t t;
time(&t);
printf("\n Date and time:%s\n",ctime(&t));
puts("\nenter here:-");
scanf("%d",&choice);
switch(choice)
{
case 1:
apply();
break;
case 2:
alumni();
break;
case 3:
contacts_info();
break;
case 4:
eligiblity();
break;
case 5:
fee_struct();
break;
case 6:
library();
case 7:
change_password();
break;
case 8:
    scholarship();
    break;
case 9:
    why();
	break;    
case 10:
puts("\n MADE BY :- ATUL DEO && TARUN KALRA");
puts("\n THANK YOU FOR USING OUR APPLICATION");
int i;
for(i=5;i>=1;i--)
{
printf("\n***EXITING***%d sec***",i);
sleep(1);
}
puts("\n\n alright its done");
exit(1);
default:
puts("\ninvalid input");
puts("\npress any key to cotinue");
getch();
main();
break;
 }
 getch();
 return 0;
}
void apply()
{
char ch;
system("cls");
int i;
int choice,k;
puts("enter choice");
puts("\n 1. apply");
puts("\n 2. exit");
scanf("%d",&choice);
switch(choice)
{
char email[50],name[30],city[15],state[15];
char mob_no[11];
case 1:
puts("APPLICATION FORM 2018-19");
puts("\n enter name :-");
scanf("%s",&name);
puts("\nenter city");
scanf("%s",&city);
getch();
puts("\nenter state");
scanf("%s",&state);
puts("\nenter your phone number");
scanf("%s",&mob_no);
puts("\nenter e-mail id");
scanf("%s",&email);	
system("cls");
puts("\nSELECT COURSE");
puts("\n1.B.tech");
puts("\n2.B.arch");
puts("\n3.B.tech in CT & IS");
puts("\n4.BCA");
puts("\n5.M.tech");
scanf("%d",&k);
switch(k)
{
case 1:
puts("\nyour application is registered");
puts("\n enter any key to continue:-");
getch();
apply();
break;
case 2:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
case 3:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
case 4:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
case 5:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
default:
	puts("wrong input try agaim");
	puts("press any key to continue");
	getch();
	goto do2;
	do2:
	{
		system("cls");
puts("\nSELECT COURSE");
puts("\n1.B.tech");
puts("\n2.B.arch");
puts("\n3.B.tech in CT & IS");
puts("\n4.BCA");
puts("\n5.M.tech");
puts("\nEnter you choice here:-");
scanf("%d",&k);
switch(k)
{
case 1:
puts("\nyour application is registered");
puts("\n enter any key to continue:-");
getch();
apply();
break;
case 2:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
case 3:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
case 4:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
case 5:
puts("\nyour application is registered");
puts("\n enter any to continue:-");
getch();
apply();
break;
default:
	puts("wrong input try agaim");
	puts("press any key to continue");
	getch();
	goto do2;	
}
}
}
break;
case 2:
main();
break;
default:
puts("\n wrong input");
puts("\n Press any key to continue");
getch();
apply();
break;
}
}
void alumni()
{
system("cls");
int one;
puts(" Poornima Alumni Association mission is to enable alumni, students, faculty and staff to maintain their contact with the University and each other for their shared benefit and for the vital support and development of Poornima Group.The Alumni Association of Poornima Group of Colleges comprises of more than 7,000 undergraduate and graduate alumni, is an exceptional enthusiastic volunteer organization. Alumni are encouraged to proliferate the use of the Alumni site to see the updates related to campus, regional activities and educational opportunities arranged by alumni association members and other Poornima organization members. Poornima Alumni Association has been functioning to maintain the relations of Poornima amongst the passed out students.With this noble thought in mind, the Executive Committee of the association has come up with a new portal for the Alumni of POORNIMA. Poornima Alumni Association committee expresses its deep gratitude to the distinguished alumni for their affection and co-operation in organizing/participating in the meets and expects the same response in future also.");
puts("\nSome of our passed out Alimni's");
puts("\nAniket Raja(B.Tech CE batch 2017-21):-i am very glad to share my journey of b.tech at Poornima university.Building my caarer in Poornima university is like a growing tree became a successful tree.I am very much thankful to all who supported me in this journey");
puts("\nNilesh Mody(B.arch,2012-17):-talent not showcased is talent wasted,Poornima university gave me an opportunity to explore my architectural skills.The CIE system is really impressive as it results in regular study");
puts("\npress 1 to return to main menu");
scanf("%d",&one);
switch(one)
{
case 1:
main();
       break;
       default:
       	puts("\n wrong choice enter again");
       	puts("\n press any key to continue");
       	getch();
       	alumni();
       	break;
}
}
void contacts_info()
{
	system("cls");
    int n;
puts("\nWhatsapp:-8875666617");
puts("\nvisit us at www.poornima.edu.in");
puts("\npress 1 to return to main menu");
scanf("%d",&n);
switch(n)
{
    case 1:
    main();
    break;
    default:
    puts("\nwrong choice enter again");
    puts("\npress any key to continue");
    getch();
    contacts_info();
    break;
}
}
void eligiblity(void)
{
	system("cls");
	char ch;
	float cgpa;
    int choice,percentage;
puts("\nSELECT COURSE");
puts("\n1.B.tech");
puts("\n2.B.arch");
puts("\n3.B.tech in CT & IS");
puts("\n4.BCA");
puts("\n5.M.tech");
puts("\n6.MAIN MENU");
puts("\nEnter you choice here:-");
    scanf("%d",&choice);
    switch(choice)
    {
	case 1:
	puts("\n1.B.tech");
	puts("\nenter 12th percentage");
	scanf("%d",&percentage);
	if(percentage>=50)
	{
	    puts("\nyou are eligible for the appropriate course ");
	    puts("\npress any key to continue");
	    getch();
		eligiblity();
		}
	
	else
	{
	 puts("\nyou are not eligible for the following course");
	 puts("\npress any key to continue");
	    getch();
		eligiblity();
	}

		case 6:
			main();
			break;
	 case 2:
	 puts("\n2.B.arch");
	 puts("\nenter your 12th percentage");
	 scanf("%d",&percentage);
	 if(percentage>=65)
	 {
	     puts("\nyou are eligible ");
	     puts("\n Press any key to continue:-");
	     getch();
	     eligiblity();
	 }
	 else
	 {
	     puts("\nyou are not eligible for the course");
	     puts("\nPress any key to continue");
	     getch();
	     eligiblity();
	 }
	 break;
	 case 3:
	 puts("\n3.B.tech in CT & IS");
	 puts("\nenter your 12th percentage");
	 scanf("%d",&percentage);
	 if(percentage>=60)
	 {
	     puts("\nyou are eligible ");
	     puts("\n Press any key to continue:-");
	     getch();
	     eligiblity();
	 }
	 else
	 {
	     puts("\nyou are not eligible for the course");
	     puts("\nPress any key to continue");
	     getch();
	     eligiblity();
	 }
	 break;
	 case 4:
	 puts("\n4.BCA");
	 puts("\nenter your 12th percentage");
	 scanf("%d",&percentage);
	 if(percentage>=50)
	 {
	     puts("\nyou are eligible ");
	     puts("\n Press any key to continue:-");
	     getch();
	     eligiblity();
	 }
	 else
	 {
	     puts("\nyou are not eligible for the course");
	     puts("\nPress any key to continue");
	     getch();
	     eligiblity();
	 }
	 break;
	 case 5:
	 puts("\n5.M.tech");
	 puts("\nenter your CGPA");
	 scanf("%f",&cgpa);
	 if(cgpa>=7.0)
	 {
	     puts("\nyou are eligible ");
	     puts("\n Press any key to continue:-");
	     getch();
	     eligiblity();
	 }
	 else
	 {
	     puts("\nyou are not eligible for the course");
	     puts("\nPress any key to continue");
	     getch();
	     eligiblity();
	 }
	 break;
	 default:
	 	puts("\n wrong choice try again");
	 	puts("\n Press any key to continue");
	 	getch();
	 	eligiblity();
    }
}
void fee_struct()
{
	system("cls");
    int n;
    char ch;
    puts("\nSelect course");
    puts("\n1.B.tech");
    puts("\n2.B.arch");
    puts("\n3.B.tech in CT & IS");
    puts("\n4.BCA");
    puts("\n5.M.tech");
    puts("\n6.main menu");
    scanf("%d",&n);
    switch(n)
    {
	case 1:
	puts("\n1.b.tech");
	puts("\nFEE PER YEAR:-115000 INR");
	puts("\n press any key to continue...");
	getch();
	fee_struct();
	break;
	case 2:
	puts("\n2.B.arch");
	puts("\nFEE PER YEAR:-150000 INR");
	puts("\n press any key to continue");
	getch();
	fee_struct();
	break;
	case 3:
	puts("\n3.B.tech in CT & IS");
	puts("\nFEE PER YEAR:-150000 INR");
	puts("\n press any key to continue");
	getch();
	fee_struct();
	break;
	case 4:
	puts("\n4.BCA");
	puts("\nFEE PER YEAR:-75000 INR");
	puts("\n press any key to continue");
	getch();
	fee_struct();
	break;
	case 5:
	puts("\n5.M.tech");
	puts("\nFEE PER YEAR:-150000 INR");
	puts("\n press any key to continue");
	getch();
	fee_struct();
	break;
	case 6:
	main();
	break;
	default:
		puts("\n invalid input");
		puts("\n press any key to continue");
		getch();
		fee_struct();
		break;
    }
}
void change_password()
{
	FILE *ptr;
	system("cls");
	char sec_pass[11];
	int ch;
	puts("\n Password change portal:-");
	puts("\n 1.Change Password");
	puts("\n 2.Main Menu");
	puts("\n enter choice");
	scanf("%d",&ch);
	   switch(ch)
       {
	  case 1:
	do1:
	system("cls");
	puts("\n enter old password");
	gets(sec_pass);
	char ch;
	int l;
	l=strcmp(sec_pass,password);
    if(l==0)
	{
		puts("\n Password matched");
		puts("\n Enter new password here");
		gets(password);
		puts("\n new settings have been saved now");
		puts("press any key to continue");
		getch();
       	change_password();
       }
       else
	{
			puts("\nwrong credentials try again");
			puts("press any key to continue");
			getch();
			goto do1;
	}	
		   break;		
		   case 2:
		   main();
		   break;
		   default:
		   puts("\n wrong input try again");
		   puts("\n press any key to continue");
		   getch();
		   change_password();	
}
    }
    void scholarship()
    {
    	system("cls");
    	puts("SCHOLARSHIP PORTAL");
    	puts("\n 1.Check your eligiblity for the Scholarship");
    	puts("\n 2.Main menu");
    	puts("\n Enter choice");
    	int ch;
    	scanf("%d",&ch);
    	int percent;
    	switch(ch)
    	{
		case 1:
    	puts("enter your 12th percentage");
    	scanf("%d",&percent);
    	if((percent>=90) && (percent<=100))
    	{
    		puts("\nyou are eligible for the 50% scholarship");
    		puts("\n Press any key to continue");
    		getch();
    		scholarship();
		}
    	if((percent<=89) && (percent>=80))
    	{
    		puts("\n you are elgible for the 40% scholarship");
    		puts("\n press any key to continue");
    		getch();
    		scholarship();
		}
		if((percent<=79) && (percent>=70))
    	{
    		puts("\n you are eligible for 30% scholarship");
    		puts("\n press any key to continue");
    		getch();
    		scholarship();
		}
	    if((percent<=69 )&& (percent>=60))
	    {
	    	puts("\n you are eligible for the 20% scholarship");
	    	puts("\n press any key to continue");
    		getch();
    		scholarship();
		}
		if(percent<=59)
		{
			puts("\nyou are not eligible for any scholarships");
			puts("\n press any key to continue");
    		getch();
    		scholarship();
		}
		break;
		case 2:
			main();
			break;
			default:
			puts("\n Wrong input try again");
			puts("\n Press any key to continue");
			getch();
			scholarship();
			break;
			}
	}
	void why()
	{   
	    system("cls");
		puts("\nWHY POORNIMA UNIVERSITY");
		puts("\n 1.ABOUT PU");
		puts("\n 2.MAIN MENU");
		int ch;
		puts("\n enter choice");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				system("cls");
puts("\n Poornima University (PU) is a Leading Private University in Rajasthan and proud constituent of Poornima Group (PG). The university is situated in Sitapura the educational hub of Jaipur in 32.67 Acres sprawling, lush green campus. State- of- the- art building area of university with independent academic & administration block, hostels, laboratories, playground etc. provide scholarly ambience for learning & liberty. It creates a warm and protective environment with a professional atmosphere to bring out best in the student to face the cut-throat global competition.Poornima University brings together a community of wide ranging interests, competencies & aspirations from Engineering, Architecture, Design, Management, Commerce, Applied Science and Art. All these programmes are approved by the University Grant Commission (UGC).Poornima University has been awarded as the best upcoming University of the India by ASSOCHAM, New Delhi. Poornima University has been awarded as the Top Private University of Rajasthan -2018.");
puts("\n press y to continue");
char c;
				scanf("%c",&c);
                 switch(c)
				 { 
				    case 'y':
				 	why();
				 	break;
				 	default:
				 		system("cls");
				 		puts("wrong choice try again");
						puts("press any key to continue");
						getch();
						goto do3;
						do3:{
							system("cls");
							puts("\n Poornima University (PU) is a Leading Private University in Rajasthan and proud constituent of Poornima Group (PG). The university is situated in Sitapura the educational hub of Jaipur in 32.67 Acres sprawling, lush green campus. State- of- the- art building area of university with independent academic & administration block, hostels, laboratories, playground etc. provide scholarly ambience for learning & liberty. It creates a warm and protective environment with a professional atmosphere to bring out best in the student to face the cut-throat global competition.Poornima University brings together a community of wide ranging interests, competencies & aspirations from Engineering, Architecture, Design, Management, Commerce, Applied Science and Art. All these programmes are approved by the University Grant Commission (UGC).Poornima University has been awarded as the best upcoming University of the India by ASSOCHAM, New Delhi. Poornima University has been awarded as the Top Private University of Rajasthan -2018.");
							
						    puts("press y to continue");
						    scanf("%c",&c);
						    switch(c)
		{
	case 'y':
	why();
    break;
	default:
	system("cls");
	puts("\nwrong input");
	puts("\npress any key to conyinue");
	getch();
	goto do3;	
		}
					}
				break;
	 } 
	break;
	case 2:
	main();
		break;
default:
	puts("wrong choice try again");
	puts("press any key to continue");
	getch();
	why();
	break;
		}
	}
