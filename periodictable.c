#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

void insert_element();
void display_element();
void search_element();
void del_element();
void update_element();
void sort_element();


struct element
{
	int Atomic_Number;
	int Atomic_Mass;
	int Group_Number;
	char element_name[20];
	char Symbol[10];
	
};
      struct element e;
      


void main()
{
	int ch;
	system("cls");
	
	while(ch!=7)
{
   system("cls");	
	
	printf("\t\t*********************WELCOME TO MODERN PERIODIC TABLE PROGRAM****************\n\n");
	
	 printf("\t\t\t********AVAILABLE FUNCTIONALITIES*********\n");
	 printf("\t\t1:Insert element record\n");
	 printf("\t\t2:Display element record\n");
	 printf("\t\t3:Search element record\n");
	 printf("\t\t4:Delete element record\n");
	 printf("\t\t5:Update element record\n");
	 printf("\t\t6:Sort element record\n");
	 printf("\t\t7:exit\n\n");
	 printf("\t\tEnter your choice : ");
	 scanf("%d",&ch);
	 

	switch(ch)
	{
		case 1:
			system("cls");
			insert_element();
			break;
		
		case 2:
			system("cls");
			display_element();
			break;
			
		case 3:
			system("cls");
			search_element();
			break;
			
		case 4:
			system("cls");
			del_element();
			break;
		
		case 5:
			system("cls");
			update_element();
			break;
			
		case 6:
			system("cls");
			sort_element();
			break;
		
		case 7:exit(1);
		
		default:
		 printf("\n\nInvalid choice...Please try again...");
		 	
	}
	printf("\n\t\tpress any key to continue");
	getch();
}
	
}



void insert_element()
{

    FILE *fp;
    fp=fopen("element.txt","ab+");
 	
 	if(fp==NULL)
 	{
 		printf("\n\t\tError: Cannot open the file!!!");
 		return;
 		
	 }
	 
	printf("\t****Previous Stored Elements****");
	 display_element();
	 
	 
	printf("\n\n\t\t***ENTER NEW ELEMENT RECORD:***\n\n");
	printf("\n\t\tEnter Element Atomic Number: ");
	scanf("%d",&e.Atomic_Number);
	fflush(stdin);
	
	printf("\n\t\tEnter Element Name: ");
	gets(e.element_name);
     
	printf("\n\t\tEnter Element Symbol: ");
	gets(e.Symbol);
	
	printf("\n\t\tEnter Atomic Mass: ");
	scanf("%d",&e.Atomic_Mass);
	
	printf("\n\t\tEnter Group Number: ");
	scanf("%d",&e.Group_Number);
	
	fwrite(&e,sizeof(e),1,fp);
	{
		printf("\n\n\t  Element Record Inserted Successfully\n");
	}
   fclose(fp);
   printf("\n\t\t Updated Record !!\n");
   display_element();
	
}
void display_element()

{
  FILE *fp;
  fp=fopen("element.txt","rb");
  
  if(fp==NULL)
  {
  	printf("\n\t\tError:  Cannot open the file !!!");
  	return;
  }
  
  printf("\n\n\t\t***Element details are as follows:****\n");
  printf("\na.)Atomic number of Element \t b.)Element name \t c.)Element symbol \t d.)Element Atomic Mass \t e.)Element Group number\n\n");
  
  while(fread(&e,sizeof(e),1,fp)==1)
  {
  	printf("\n        %d   \t                   %s  \t                 %s      \t           %d    \t                    %d      ",e.Atomic_Number,e.element_name,e.Symbol,e.Atomic_Mass,e.Group_Number);
  }
  
  fclose(fp);
  

}

void search_element()
{
	int no,flag=0;
	FILE*fp;
	fp=fopen("element.txt","rb");
	if(fp==NULL)
	{
		printf("\n\t\tError Cannot Open the File!!!");
		return;
		
	}
	else
  {
	
	printf("\n\n\tEnter Element Atomic Number which you want to Search:");
	scanf("%d",&no);
	while(fread(&e,sizeof(e),1,fp)>0 && flag==0)
	{
		if(e.Atomic_Number==no)
		{
			flag=1;
			printf("\n\n\tSearch Successfull And Element Record are as follows:");
			printf("\nAtomic Number\t\tName of Element\t\tAtomic Symbol\t\tAtomic Mass\t\tGroup Number:\n\n");
			printf("\t%d\t               %s              \t%s          \t\t %d               %d        ",e.Atomic_Number,e.element_name,e.Symbol,e.Atomic_Mass,e.Group_Number);
			
		}
		
		
    }
   }
		
		
		if(flag==0)
		{
			printf("\n\n\t\tNo Such Record Found!!!\n");
			
		}
		fclose(fp);
	}
	


void del_element()
{
	
	char name[40];
	unsigned flag=0;
	FILE*fp,*ft;
	fp=fopen("element.txt","rb");
	if(fp==NULL)
	{
		printf("\n\t\tError Cannot open the file!!!");
		return;
		
	}
	else
	{
	
	printf("\n\t**** Previous Stored Data ****");
	display_element();
	printf("\n\n\tEnter Element name which you want to Delete:");
	scanf("%s",name);
	ft=fopen("element1.txt","ab+");
	while(fread(&e,sizeof(e),1,fp)==1)
	{
		if(strcmp(name,e.element_name)!=0)
		{
			printf("\n\t\tRecord Deleted Successfully \n");
			fwrite(&e,sizeof(e),1,ft);
			
		}
		else flag=1;
	}
	}if(flag==0)
	{
		printf("\n\n\t\tNo Such Record Found!!");
		
	}
	fclose(fp);
	fclose(ft);
	remove("element.txt");
	rename("element1.txt","element.txt");
	printf("\n\t\t Updated Record !!\n");
	display_element();
}

void update_element()
{
	int no,flag=0;
	FILE*fp;
	fp=fopen("element.txt","rb+");
	if(fp==NULL)
	{
		printf("\n\t\tError Cannot Open the File!!!");
		return;
		
	}
	else
	{
	
	printf("\n\n\tEnter Element Atomic Number whose Record you want to Update:");
	scanf("%d",&no);
	printf("\n\t\t****Previously Stored Record of given Atomic Number ****");
	
	while(fread(&e,sizeof(e),1,fp)>0&& flag==0)
	  {
		if(e.Atomic_Number==no)
		{
			flag=1;
			
			printf("\nAtomic Number\t\tName of Element\t\tAtomic Symbol\t\tAtomic Mass\t\tGroup Number:\n\n");
			printf("\t%d\t               %s                \t\t%s          \t%d                 %d        ",e.Atomic_Number,e.element_name,e.Symbol,e.Atomic_Mass,e.Group_Number);
			printf("\n\t\t**** Now Enter the New Record *****\n\n");
			
			printf("\n\t\tUpdated Atomic Number of Element: ");
			scanf("%d",&e.Atomic_Number);
			fflush(stdin);
			printf("\n\t\tUpdated Name of Element: ");
			gets(e.element_name);
			
			printf("\n\t\tUpdated Atomic Symbol of Element: ");
			gets(e.Symbol);
			
			printf("\n\t\tUpdated Atomic Mass of Element: ");
			scanf("%d",&e.Atomic_Mass);
		
		
			printf("\n\t\tUpdated Group Number of Element: ");
			scanf("%d",&e.Group_Number);
			
		 fseek(fp,-(long)sizeof(e),1);
		 fwrite(&e,sizeof(e),1,fp);
		 printf("\n\n\t\tRecord Updated Successfully Check the Display");
		}
	  }
   }
	
	
	
		
		fclose(fp);

}
	

void sort_element()
{
	struct element temp;
	struct element arr[50];
	 
	 int i,j,k=0;
	 FILE*fp;
	 fp=fopen("element.txt","rb");
	if(fp==NULL)
	{
		printf("\n\t\tError Cannot open the file!!!");
		
	}
  i=0;
  while(fread(&arr[i],sizeof(arr[i]),1,fp)==1)
  {
  	i++;k++;
  }
for(i=0;i<k;i++)
{
	for(j=0;j<k-i-1;j++)
	{
		if(arr[j].Atomic_Number>arr[j+1].Atomic_Number)
		{
			temp=arr[j];
			arr[j]=arr[j+1];
			arr[j+1]=temp;
			
		}
	}
	
}
printf("\n\t\tAfter Sorting Elements Details !!\n\n");
for(i=0;i<k;i++)
{
	printf("\t\t\t%d\t\t     %s\t\t     %s\t\t     %d\t\t          %d\n  ",arr[i].Atomic_Number,arr[i].element_name,arr[i].Symbol,arr[i].Atomic_Mass,arr[i].Group_Number);
}
fclose(fp);

}
