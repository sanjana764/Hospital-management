#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<unistd.h>
struct patient{
	char name[50];
	char gname[50];
	int age;
	char gender[50];
	char bg[10];
	int hno;
	char colony[50];
	char city[50];
	char state[50];
	char mno[20];
	int regno;
	char disease[50];
}p[50];
struct staff{
	char name[50];
	char gname[50];
	char gender[40];
	int id;
	int age;
	char mno[20];
	int hno;
	char colony[50];
	char city[50];
	char state[50];
	int salary;	
}s[50];
void patient(void);
void staff(void);
int login(void);
void user_main();
int i,j,n,m;
char z,ch,k,ctr,ctr1;
void user_main()
{ 
	system("COLOR B0");
	printf("\n YOU ARE....?");  
	printf("\n1.PATIENT");
    printf("\n2.STAFF");
    printf("\n\n\tEnter your choice: ");
    int ch;
    scanf("%d",&ch);
    switch(ch)
        {
            case 1:
                patient();
                break;
            case 2:
                staff();
                break;
            default:
			    printf("\n INVALID INPUT");    
        }
}
void patient()
{   
	char blood_group[10];
	char dis[50];
	char a[50],nme[50];
	char del_name[100];
	FILE *fp;
	      		fp=fopen("patient.txt","w+");
	  			if(fp==NULL)
				{
					printf("the file doesn't exist!!");
					exit(0);
				}
	do{ 
	        printf("\nPATIENT");
            printf("\n 1.read");
            printf("\n 2.sort by name");
            printf("\n 3.Sort by age");
            printf("\n 4.search by blood group");
            printf("\n 5.Search by disease");
            printf("\n 6.Delete an Entry");
            printf("\n 7.Menu");
            printf("\nEnter your choice here: ");
            scanf("%d",&ch);
            switch(ch)
            {
            	case 1:
            	system("cls()");
                printf("Enter the number of patients: ");
                scanf("%d", &n);	
				for(i=0;i<n;i++)
				{   system("cls()");
				    printf("\n ENTER DETAILS OF PATIENT %d",i+1);
					printf("\nEnter the name of the patient: ");
   					scanf("%s",p[i].name);
   					//gets(p[i].name);
					//scanf("%[^\n]%s*c,p[i].name");   
					//fgets(p[i].name,sizeof(p[i].name),stdin); 
    				printf("\nEnter the name of the Guardian: ");
    				scanf("%s",p[i].gname);
    				printf("\nEnter the age of the patient: ");
    				scanf("%d",&p[i].age);
    				printf("\nEnter the gender of the patient: ");
    				scanf("%s",p[i].gender);
    				printf("\nEnter the Blood group of the patient: ");
    				scanf("%s",p[i].bg);
    				printf("\nEnter the address of patient:");
    				printf("\nHouse no:");
    				scanf("%d",&p[i].hno);
    				printf("\ncolony:");
    				scanf("%s",p[i].colony);
    				printf("\ncity:");
    				scanf("%s",p[i].city);
    				printf("\nstate:");
    				scanf("%s",p[i].state);
    				printf("\n Enter the mobile number of patient:");
    				scanf("%s",p[i].mno);
    				if(strlen(p[i].mno)!=10)
    				{
    					printf("\nInvalid input....Mobile number must consist 10 digits");
    					printf("\n please enter again\n");
    					scanf("%s",p[i].mno);
    				    printf("\n Enter registration number of patient:");
    				    scanf("%d",&p[i].regno);
    				    printf("\n Enter the name of the disease he/she is suffering with:");
    				    scanf("%s",p[i].disease);
    				}
					else
					{ 
    				printf("\n Enter registration number of patient:");
    				scanf("%d",&p[i].regno);
    				printf("\n Enter the name of the disease he/she is suffering with:");
    				scanf("%s",p[i].disease);
					}
    				rewind(fp);
    			}
				break;    			
    			case 2:
    				system("cls()");
					for (i=0;i<n-1;i++) {
    				for (j=i+1;j<n;j++) {
    				if (strcmp(p[i].name, p[j].name)>0){
    				struct patient temp=p[i];
    				p[i]=p[j];
    				p[j]=temp;
            				}
        				}
    				}    
    				printf("\nList of patients sorted by their names:\n");
    				for (i=0;i<n;i++) 
					{
        				printf("%d.%s - %d - %s - %s\n", i + 1, p[i].name, p[i].age, p[i].gender, p[i].disease);
    				}
					break;
				case 3:
					system("cls()");
					for (i=0;i<n-1;i++) {
        			for (j=0;j<n-i-1;j++) {
            		if (p[j].age>p[j+1].age){
                	struct patient temp1=p[j];
                	p[j]=p[j+1];
                	p[j+1]=temp1;
            				}
        				}
    				}    
    				printf("\nList of patients sorted by their age:\n");
    				for (i=0;i<n;i++) 
					{
        				printf("%d.%s - %d - %s - %s\n",i+1,p[i].name,p[i].age,p[i].gender,p[i].disease);
   					 }		   
					break;
				case 4:	
				    system("cls()");				
					printf("Enter the blood group to search for: ");
					scanf("%s",blood_group);
					for (i=0;i<n;i++) 
					{
    					if (strcmp(p[i].bg,blood_group)==0) 
						{
        					printf("Patient found:\n"); 
        					printf("\n\tNAME\tAGE\tBLOOD GROUP"); 
							printf("\n\t%s\t%d\t%s",p[i].name,p[i].age,p[i].bg); 
        					ctr=1; 
    					} 
						else
						{
							printf("No patients found with the specified blood group.\n");
						}					 
					} 
					break;
				case 5:
					system("cls()");
				    printf("Enter the disease to search for: ");
					scanf("%s", dis);
				   // int ctr1 = 0;
					for (i=0;i<n;i++)
					 {
    					if (strcmp(p[i].disease,dis)==0)
						 {
        					printf("Patient with mentioned disease is found:\n");
        					printf("\n\tNAME\tAGE\tBLOOD GROUP\tDISEASE");
							printf("\n\t%s\t\t%d\t\t%s\t\t%s\n",p[i].name,p[i].age,p[i].bg,p[i].disease);
        					ctr1=1;
    					}						
					    else					
    					{
							printf("No patients found with the specified disease.\n");
						}
					}
					break;
				case 6:		
				    system("cls()");				
    				printf("Enter the name of the patient to delete: ");
    				scanf("%s", del_name);
    				for (i=0;i<n;i++) 
					{
        				if (strcmp(p[i].name,del_name)==0) 
						{
            				printf("Patient found:\n");
							printf("\n\tNAME\tAGE\tBLOOD GROUP\tDISEASE");
							printf("\n\t%s\t\t%d\t\t%s\t%s\n",p[i].name,p[i].age,p[i].bg,p[i].disease);
            				for (j=i;j<n-1;j++) 
							{
                				p[j]=p[j+1];
            					}
           					n--;
            				printf("Patient deleted successfully.\n");
							}
						}
					break;
				case 7:
					    system("cls()");
						user_main();
						break;	
				default:
				    printf("\n invalid input");	
					break;				
			}
    for (i=0;i<n;i++)
    {
        fprintf(fp,"%s,%s,%d,%s,%s\n",p[i].name,p[i].disease,p[i].mno,p[i].gname,p[i].bg);
    	}
    fclose(fp);
    printf("\n want to search again press [Y] \n");
	z=getche();
	}while(z=='Y'||z=='y');
}
void staff()
{   char ename[50],del_name[40];
    int ctr=0;
	FILE *ft; 
	ft=fopen("staff.txt","w+");
	if(ft==NULL)
	{
		printf("the file doesn't exist!!");
		exit(0);
		}
	do
	{
		printf("\nSTAFF");
        printf("\n 1.Add entry");
        printf("\n 2.search by name");
        printf("\n 3.list of employee and their details");
        printf("\n 4.Delete an Entry");
        printf("\n 5.Menu");
        printf("\nEnter your choice here: ");
        scanf("%d",&ch);
        switch(ch)
        {case 1:
            	system("cls()");
                printf("Enter the number of employees: ");
                scanf("%d",&m);	
				for(i=0;i<m;i++)
				{   system("cls()");
				    printf("\n ENTER DETAILS OF EMPLOYEE %d",i+1);
					printf("\nEnter the name of the employee: ");
   					scanf("%s",s[i].name);
    				printf("\nEnter the name of the Guardian: ");
    				scanf("%s",s[i].gname);
    				printf("\nEnter the age of the employee: ");
    				scanf("%d",&s[i].age);
    				printf("\nEnter the gender of the employee: ");
    				scanf("%s",s[i].gender);
    				printf("\nEnter the address of employee:");
    				printf("\nHouse no:");
    				scanf("%d",&s[i].hno);
    				printf("\ncolony:");
    				scanf("%s",s[i].colony);
    				printf("\ncity:");
    				scanf("%s",s[i].city);
    				printf("\nstate:");
    				scanf("%s",s[i].state);
    				printf("\n Enter the mobile number of employee:");
    				scanf("%s",s[i].mno);
    				if(strlen(s[i].mno)!=10)
    				{
    					printf("\nInvalid input....Mobile number must consist 10 digits");
    					printf("\n Enter ID of patient:");
    					scanf("%d",&s[i].id);
    					printf("\n Enter the salary of employee:");
    					scanf("%d",&s[i].salary);
					}
					else
					{
    				printf("\n Enter ID of patient:");
    				scanf("%d",&s[i].id);
    				printf("\n Enter the salary of employee:");
    				scanf("%d",&s[i].salary);
					}
    				}
    				rewind(ft);
    				break;
		case 2:
					system("cls()");
				    printf("Enter the name of the employee to search : ");
					scanf("%s",ename);
					for (i=0;i<m;i++) {
    				if (strcmp(s[i].name,ename)==0) {
        			printf("Employee with mentioned name is found:\n");
        			printf("\n\tNAME\tAGE\tGENDER\tID");
					printf("\n\t%s\t%d\t%s\t%d\n",s[i].name,s[i].age,s[i].gender,s[i].id);
        			ctr=1;
    					}
    					else
    					{
    						printf("No employee is found with the specified name.\n");
    					}
					}	
					break;
		case 3:	
				system("cls()");
				rewind(ft);
				for(i=0;i<m;i++)
				{
					printf("EMPLOYEE %d:\n",i+1);
					printf("NAME:%s\n",s[i].name);
					printf("GUARDIAN:%s\n",s[i].gname);
					printf("AGE:%d\n",s[i].age);
					printf("GENDER:%s\n",s[i].gender);
					printf("ADDRESS:%d, %s, %s, %s\n",s[i].hno,s[i].colony,s[i].city,s[i].state);
					printf("MOBILE NO.:%d\n",s[i].mno);
					printf("ID:%d\n",s[i].id);
					printf("SALARY:%d\n\n\n",s[i].salary);
							}
						break;
		case 4:
			    system("cls()");
		        printf("Enter the name of the employee   to delete: ");
    			scanf("%s", del_name);
    			for (i=0;i<m;i++) 
				{
        			if (strcmp(s[i].name, del_name)==0) {
            		printf("Employee found:\n");
					printf("\n\tNAME\tAGE\tGENDER\tID");
					printf("\n\t%s\t%d\t%s\t%d\n",s[i].name,s[i].age,s[i].gender,s[i].id);
            		for (j=i;j<m-1;j++) 
					{
                		s[j]=s[j+1];
            			}
            		m--;
            		printf("staff deleted successfully.\n");
						}
					}
					break;	
			case 5:
			       system("cls()");
				   user_main();
				   break;				
			default:
				    printf("\n invalid input");	
					break;				
		}
    for (i=0;i<m;i++) 
	{
        fprintf(ft,"%s,%d,%s,%d,%d\n",s[i].name, s[i].age,s[i].gender, s[i].id,s[i].salary);
    }
    fclose(ft);
           	printf("\n want to search again press Y \n");
		z=getche();
		}while(z=='Y'||z=='y');				
	}
int login()
{
	char profile[2][30]={"sanjana","4321"};
	char uname[30],ps[30],ch;
	int c,u,v,f;
    	login:
    	f=0;
  	do
	{
	printf("\n\n\n\t\t\tLOGIN FORM......\n\n");
	printf("\n\t\t\tUSER NAME : ");
	scanf("%s",uname);
	printf("\n\t\t\tPASSWORD : ");
	while((ch=getch())!='\r')
	{
	     ps[f++]=ch;
	     ch='*';
	    printf("%c",ch);
	}
	ps[f]='\0';
	u=strcmp(uname,profile[0]);
	v=strcmp(ps,profile[1]);
	printf("\n\n Please wait Credential Verification is in Process....");
	sleep(1);
	system("cls");
	if(u==0&&v==0)
	{
		printf("\n HOSPITAL MANAGEMENT::...................................\n");
		user_main();
		return(0);
	}
	else
	{
		printf("\n\n Credentials are wrong.....please try again.....");
		c++;
		printf("\n\n Left %d attempts",3-c);
	}	
}while(c<3);
	
}
