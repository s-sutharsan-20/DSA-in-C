//Array Based List ADT for Hotel Room Booking System
#include<stdio.h>
#include<string.h>
#define MAX 100
struct hotel{
	int roomno;
	char name[20];
	char roomtype[20];
	long long int phoneno;
	int NOD;
	float rent;
}s[MAX];

int top=-1;
void insert(int,char[],char[],long long int,int,float);
void display();
void deletedata(int);
int search(int);
void modify(int,int);

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
	printf("\n4- Search For a Room");
	printf("\n5- Change Room Number");
	printf("\n6- Exit\n");
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
			insert(roomno,name,roomtype,phoneno,NOD,rent);
		break;
		case 3:
			printf("Enter the Room Number you Need to Delete:");
			scanf("%d",&roomno);
			deletedata(roomno);
		break;
		case 2:
			printf("\nBooked Rooms are :\n");
			display();
		break;
		case 4:
			printf("Enter the Room Number you need to Find:");
			scanf("%d",&roomno);
			search(roomno);
		break;
		case 5:
			printf("Enter the Room Number you need to Change :");
			scanf("%d",&oldval);
			printf("Enter the New Room Number:");
			scanf("%d",&newval);	
			modify(oldval,newval);
		break;
				
		case 6:
			printf("-----------------------------");
			printf("\nTHANK YOU VISIT AGAIN");
			printf("\n-----------------------------");
		return 0;
		default:
			printf("Invalid Choice!");
	}
}
}

//Algorithm for insertion
void insert(int d,char a[],char b[],long long int c,int e,float f){
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

//Agorithm for display
void display(){
	int i;
	float rent;
	char roomsi[20];
	if(top==-1){
		printf("\nSorry Rooms are not yet Booked");
		return;
	}
   	printf("\n Room No \t Name \t Room Type \t Phone No \t Days \t Rent");	
	for(i=0;i<=top;i++){
		printf("\n%d\t%s\t%s\t%lld\t%d\t%.2f",s[i].roomno,s[i].name,s[i].roomtype,s[i].phoneno,s[i].NOD,s[i].rent);
	   }
}

//Agorithm for deletion
void deletedata(int d){
	int i;
	if(top==-1){
		printf("\nSorry Rooms are not Yet Booked");
		return;
	}
    for(i=0;i<=top;i++)
    if(s[i].roomno==d){
    	while(i<top){
    		s[i]=s[i+1];
    		i++;
		}
		--top;
		printf("Room is Deleted");
	}
	printf("Room Not Found");
}

//Agorithm for search
int search(int d){
   int i;
   if(top == -1) {
    	 printf("\\nSorry Rooms are not Booked Yet");
     return -1;
   }
   for(i=0;i<=top;i++)
    	if(s[i].roomno==d){
    		printf("The Room no %d Booked",s[i].roomno);
      		return i;
      }
	printf("The Room Number is Not Yet Booked");	
   	return i;
}

//Agorithm for modify
void modify(int oldval,int newval){
    int i;
    if(top==-1){
        printf("\nSorry Rooms are not Booked Yet");
        return;
    }
    for(i=0;i<=top;i++)
        if(s[i].roomno==oldval){
            s[i].roomno=newval;
            printf("\n The Room no %d is Changed to %d",oldval,newval);            
            return;
        }
    printf("\n Sorry the Room u look for is not found");        
}
