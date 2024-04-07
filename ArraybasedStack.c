//Array based Implementation of Stack ADT
#include<stdio.h>
#include<string.h>
#define MAX 50
struct node{
    int roomno;
	char name[20];
	char roomtype[20];
	long long int phoneno;
	int NOD;
	float rent;
}s[MAX];
int top=-1;
void PUSH(int,char[],char[],long long int,int,float);
void display();
int POP();
int main(){
	int ch,roomno,NOD,oldval,newval;
	float rent;
	char name[20],roomtype[20];
    long long int phoneno;
	while(1){
		printf("\n------------------------------");
		printf("\n Room Booking System \n");
		printf("\n------------------------------");		
		printf("\nEnter Your Choice\n");
		printf("\n1- Book Room ");
		printf("\n2- Show Booked Rooms");
		printf("\n3- Delete a Room");
		printf("\n4- Exit\n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("\nEnter the Room Number:");
				scanf("%d",&roomno);
				printf("\nEnter your Name:");
				scanf("%s",&name);
				printf("\nEnter the Room Type: A/C or Non-A/C :");
	    		scanf("%s",&roomtype);
				printf("\nEnter your Phone Number:");	
				scanf("%lld",&phoneno);
				printf("\nEnter no of days you need to Stay:");
				scanf("%d",&NOD);
				rent=NOD*2000;
				PUSH(roomno,name,roomtype,phoneno,NOD,rent);
			break;
			case 2:
				printf("\nBooked Rooms are :\n");
				display();
			break;
			case 3:
				POP();
			break;
			case 4:
				printf("-----------------------------");
				printf("\nTHANK YOU VISIT AGAIN");
				printf("\n-----------------------------");
			return 0;
			default:
				printf("<<<<<<<<Invalid Choice!>>>>>>>>>>");
	}
	}
}
//Algorithm for PUSHion
void PUSH(int d,char a[],char b[],long long int c,int e,float f){
    if(top==MAX-1){
        printf("\nSorry All Rooms are Booked");
        return;
    }
    ++top;
	s[top].roomno=d;
	strcpy(s[top].name,a);
	strcpy(s[top].roomtype,b);
	s[top].phoneno=c;
	s[top].NOD=e;
	s[top].rent=f;
}
//Algorithm for traversal / display
void display(){
    int i;
    if(top==-1){
        printf("\nSorry Rooms are not Yet Booked");
        return;
    }
   	printf("\nRoom No\tName\tRoom Type\tPhone No\tDays\tRent");
    for(i=top;i>=0;i--)
        printf("\n %d \t %s \t %s \t %lld \t %d \t %.2f",s[i].roomno,s[i].name,s[i].roomtype,s[i].phoneno,s[i].NOD,s[i].rent);
}
//Algorithm for deletion
int POP(){
    int x;
    if(top==-1){
        printf("\nSorry Rooms are not Yet Booked");
        return -1;
    }
    x=s[top].roomno;
    --top;
    printf("Last Room Deleted Successfully!");
    return x;
}
