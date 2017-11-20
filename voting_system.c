#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct Voters
{
	char name[30];
	int Id;
	int flag;
};

char description();

int main()
{
	description();
	system("cls");
	struct Voters vot[4]={
		{"Kajal",100,0},
		{"Sheetal",101,0},
		{"Swati",102,0},
		{"Deekshya",103,0}
	};
	int ch,opt,c1=0,c2=0,c3=0,c4=0,i,j,id,k;
	char nam[]="Sheetal_Sahoo@",name[20],pasw[20],ch1,ch2=2;
    char pass[]="sheetal";
	printf("\n\t\t  ~~~~~~~~~~~~~ VOTING SYSTEM ~~~~~~~~~~~~~\n");
	printf("\nLISTED VOTERS ARE\n");
	printf("-----------------------------------------------------------------------------\n");
	for(i=0;i<4;i++)
	{
		printf("NAME-%s\tVOTER_ID-%d\n\n",vot[i].name,vot[i].Id);
	}
	printf("\n----------------------------------------------------------------------------\n");
	printf("Press any key to continue.....");
	getch();
	system("cls");
	while(1)
	{
	   printf("\n\n\t\t   ~~~~~~~~~ YOUR VOICE, YOUR VOTE ~~~~~~~~~~\t\t\t");
	   printf("\n\t\t   1.VOTNG\n\n\t\t   2.ADMIN\n\n\t\t   3.QUIT\n");
	   printf("\n----------------------------------------------------------------------------\n");
	   printf("\nENTER YOUR CHOICE:");
	   scanf("%d",&ch);
	   switch(ch)
	   {  
	   	case 1:
		    printf("\nPLEASE, ENTER YOUR VOTER_ID:");
		    scanf("%d",&id);
		    while(id<100 || id>103)
				{
					printf("\n\nENTERED ID IS INVALID\n\nPLEASE ENTER VALID VOTER_ID:");
					scanf("%d",&id);
				}
				system("cls");
			for(j=0;j<4;j++){
			  if(id==vot[j].Id)
			  {
				vot[j].flag++;
				if(vot[j].flag==1){//for uniqueness of voter_id
				  printf("\t\t\t\t\t\tWELCOME %s!!\n\n",vot[j].name);
				  printf("THE NOMINIES FOR GENERAL SECRETARY ARE:\n\n");
				  printf("\n1.DEBJANI MISHRA\t2.ASHWIN SAHOO\n\n");
	   		      printf("\nPLEASE, ENTER YOUR VOTE:");
	   		     scanf("%d",&opt);
	   		      while(opt>2 ||opt<0)
	   		      {
	   		      	printf("\nINVALID INPUT, PLEASE TRY AGAIN.");
				scanf("%d",&opt);
				}
			printf("\n\nYOU HAVE SUCCESSFULLY VOTED!!");
			printf("\n\n%c THANK YOU %c",ch2,ch2);
	   		      //vote to the desired nominies
					switch (opt)
	   		      {
	   			    case 1:
	   			        c1++;	
	   			        break;
	   			    case 2:
				         c2++;	
				         break;
				   	default:
				   		printf("\nINVALID CHOICE");			
			      }
				 break;
				 }
			     else{
			     	printf("\n\t\t\t! YOU ARE ALREADY VOTED !\n");
					 break;
				 }
			 }	
		    }
			 break;
		case 2:
			//authentication to see the countings
			printf("\nENTER USER_NAME:");
			scanf("%s",name);
			printf("\nENTER PASSWORD:");
			for(k=0;k<8;k++)
			{
				ch1=getch();
				pasw[k]=ch1;
				ch1='*';
				printf("%c",ch1);
			}
			if(strcmp(name,nam)==0)
			{
				if(strcmp(pasw,pass)==0)
				 printf("\t\t\tWELCOME ADMIN!!!\t\t\t\n");
				 system("cls");
				 //counting of votes
				 printf("\n********** COUNTING VOTES **********\n");
	             printf("\nNO. OF VOTES FOR DEBJANI MISHRA:%d\n",c1);
	             printf("\nNO. OF VOTES FOR ASHWIN SAHOO:%d\n",c2);
	                if(c1>c2)
	                {
	                	printf("\n\t\tDebjani Mishra Wins !!!");
					}
	               else
	               {
					   if(c1==c2)
			           {
				           printf("\n\n\n! No one Wins !");
			            }
			            else
			            {
				           printf("\n\n\nAshwin Sahoo Wins !!!");
			            }
		            }
			}
			else
			{
				printf("\nENTERED LOGIN ID OR PASSOWRD IS WRONG.\n");
			}
			
			break;
		case 3:
			 system("cls");
			 printf(" \n\n\t\t\t    *** THANK YOU **** \n\n\n\n");
			 exit(1);
			 break;
		default:
				printf("\n\nENTERD INVALID CHOICE...PLEASE TRY AGAIN.\n\nPress any key to continue...");
	   }
	   getch();
	   system("cls");
	}
	
return 0;
}
char description()//breif description to the voting system
{
	printf("->VOTERS WILL HAVE TO PROVE THEIR IDENTITY BY GIVING THEIR VOTER_ID \n\n\n"); 
    sleep(1);
	printf("->A AUTHENTICATED USER WILL BE ABLE TO CAST THE VOTE.\n\n\n");
    sleep(1);
	printf("->A USER WHO HAS CASTED THE VOTE CANNOT CAST AGAIN.\n\n\n");
    sleep(1);
	printf("->ADMIN IS ONLY ABLE TO SEE THE COUNTIG\n\n\n");
    sleep(1);
	printf("PLEASE PRESS ENTER TO CONTINUE & Esc. TO EXIT.....");
    char ch;
    for(;;) 
    { 
      ch=getch(); 
      if(ch==13) 
      break; 
      else 
        if(ch==27) 
        exit(-1); 
        else 
        printf("\n\n\t\t\t\a ! WRONG KEY ENTERED !"); 
        sleep(1); 
        printf("\n\n\n\t\t\t    \"PRESS ENTER\" "); 
    } 
return 0; 
}
