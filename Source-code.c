#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include<ctype.h>
char filename[30]= {" "};
//filename[0] = '\0 ' ;
//NODE Declaration
struct node
{
 char firstname[20];
 char lastname[20];
 char number[15];
 struct node *next;
};
// Creates a file with Basic header data in Excel and intialize the file name
char *create_file(FILE *fp)
{
 printf("\n\t\t\t\t ....File creation.......\n\n");
 printf("Enter File name to be saved\n");
 scanf("%s",filename);
 strcat(filename,".csv");
  fp = fopen(filename,"a+");
 fprintf(fp,"First Name,Last Name,Mobile number\n");
 system("cls");
 fclose(fp);
}
// Intializing the header Node
struct node *start = NULL;
struct node *getnode() // Getnode allocates memory for Nodes
{
 return ((struct node *)malloc(sizeof(struct node)));
}

//Create a function to insert contacts 

void insert(FILE *fp)
{
 if(strlen(filename)<=1)
 {
 printf("Please create a file before inserting......!!!!!! ");
 sleep(3);
 system("cls");
 return;
 }
 system("cls");
 system("color a");
 fp = fopen(filename,"a+");
 struct node *temp, *nn;
 nn = getnode();
 temp = start;
 while (temp->next != NULL)
 {
 temp = temp->next;
 }
 printf("\n\t\t\t\t ......Contact Insertion.......\n\n");
 printf("Enter First name:\n");
 scanf("%s", &nn->firstname);
 printf("Enter Last name:\n");
 scanf("%s", &nn->lastname);
 printf("Enter number:\n");
 scanf("%s", &nn->number);
 temp->next = nn;
 fprintf(fp,"%s , %s , %s\n",nn->firstname,nn->lastname,nn->number);
 nn->next = NULL;
 fclose(fp);
 printf("Contact saved successfully\n");
 system("cls");
}

//Create a function to create a Contacts

struct node *create(FILE *fp)
{
 system("cls");
system("color a");
 create_file(fp);
 struct node *temp, *nn;
 if (start != NULL)
 insert(fp);
 else
 {
 printf("\n\t\t\t\t ....Enter Your First NODE.......\n\n");
 nn = getnode();
 start = nn;
 temp = start;
 printf("Enter First name:\n");
 scanf("%s", &nn->firstname);
 printf("Enter Last name:\n");
 scanf("%s", &nn->lastname);
 printf("Enter number:\n");
 scanf("%s", &nn->number);
 nn->next = NULL;
 fp =fopen(filename,"a+");
 fprintf(fp,"%s , %s , %s\n",nn->firstname,nn->lastname,nn->number);
 fclose(fp);
 system("cls");
 printf("Contact saved successfully\n");
 sleep(3);
 system("cls");
 }
}

//create function to search the Contacts

void search()
{
 system("color D");
 struct node *temp;
 char *f, *l;
 temp = start;
 printf("\n\t\t\t\t ...... Search Functionality .......\n\n");
 printf("Enter name to be searched:\n");
 printf("Enter first name\n");
 scanf("%s", &f);
 printf("Enter last name\n");
 scanf("%s", &l);
 while((temp->firstname==f)&&(temp->lastname==l))
 {
 temp = temp->next;
 }
 printf("%s\t\t%s\t\t%s\n", temp->firstname,temp->lastname, temp->number);
}

//Function to delete a Contacts

void del()
{
 system("color 4");
 struct node *pretemp, *temp;
 char f[20], l[20];
 printf("\n\t\t\t\t ...... Contact Deletion.......\n\n");
 temp = start;
 pretemp = start->next;
 printf("Enter first name :");
 scanf("%s", &f);
 printf("Enter last name :");
 scanf("%s", &l);
 while (temp != NULL)
 {
 if ((pretemp->firstname == f) && (pretemp->lastname == l))
 {
 printf("%s ", temp->firstname);
 printf("%s ", temp->lastname);
 printf("%s ", temp->number);
 temp->next = pretemp->next;
 free(pretemp);
 break;
 }
 else
 {
 temp = temp->next;
 pretemp = pretemp->next;
 }
 }
}

//Function to display the created Contacts

void display(struct node *start)
{
 struct node *temp;
 temp = start;
 system ("cls");
if (start == NULL)
 {
 printf(" The Contacts List is Empty..!!\n\n\n");
 }
 else{
 printf("\n\t\t\t\t ...... Display .......\n\n");
 printf("\n\n First name \t\t last name \t\t Mobile Number \t\t\n\n");
 while (temp != NULL)
 {
 printf("%s\t\t%s\t\t%s\n", temp->firstname,temp->lastname, temp->number);
 temp = temp->next;
 }
 }
 printf(" You will be redirected main menu in 3 seconds");
 sleep(3);
 system ("cls");
}

// Main function 
int main()
{
 printf("\t\t\t\t\t-----------Welcome--------\n ");
 printf("\t\t\t\t-------Contacts Management Software--------\n ");
 FILE *fp;
 int op = 0, ch;
 while (ch != 6)
 {
 system("color 6");
 printf("\n\t\t\t\t ....... Main Menu .......\n\n");
 
printf("\n\t\t\t\t1.Create\n\t\t\t\t2.Insert\n\t\t\t\t3.Display\n\t\t\t\t4.Delete\n\t\t\t\t5.Search\n\t\t\t\t6.Quit \n");
 printf("Enter your choice:");
 scanf("%d", &ch);
 switch (ch)
 {
 case 1:
        create( fp);
        break;
 case 2:
      insert(fp);
      break;
 case 3:
       display(start);
       break;
 case 4:
      del();
      break;
 case 5:
       search();
     break;
 case 6:
       exit(0);
 break;
 }
 }
 return 0;
}



