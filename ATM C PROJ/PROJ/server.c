#include<stdio.h>
#include<string.h>
#include"server.h"

int confirm(account_t *p,char name[],int pin)
{
	for(int i=0;i<3;i++)
	{
		if(strcmp((p+i)->name,name)==0&&((p+i)->pin==pin))
			return 1;
	}
	return 0;
}

account_t details(account_t *p,char name[],int pin)
{
	account_t e;
	for(int i=0;i<3;i++)
	{
		if(strcmp((p+i)->name,name)==0&&((p+i)->pin==pin))
		{
			strcpy(e.name,(p+i)->name);
			e.pin = (p+i)->pin;
			e.savings = (p+i)->savings;
		}
	}
	return e;
}

float withdraw(float sav_amt)
{
	float amt;
	printf("Enter the amount you want to withdraw : ");
	scanf("%f",&amt);
	
	if(amt>sav_amt)
		printf("\nInsufficient Balance\n");
	else if(sav_amt<=0)
		printf("\nInsufficient Balance\n");
	else
	{
		printf("\n------------------------------------------------\n");
		printf("Amount withdrawn : %.2f\n",sav_amt);
		sav_amt-=amt;
		printf("Account Balance : %.2f",sav_amt);
		printf("\n------------------------------------------------\n");
	}
	return sav_amt;
}

float deposit(float sav_amt)
{
	float amt;
	printf("Enter the amount you want to Deposit : ");
	scanf("%f",&amt);
	printf("Amount deposited : %.2f\n",amt);
	sav_amt+=amt;
	printf("Amount balance : %.2f\n",sav_amt);
	return sav_amt;
}

void bal(account_t *p2)
{
	printf("\n------------------------------------------------\n");
	printf("Balance Amount : %.2f",p2->savings);
	printf("\n------------------------------------------------\n");
}	

int pit(int mpin)
{
	int new_pin;
	printf("Enter the new pin : ");
	scanf("%d",&new_pin);
	printf("PIN changed successfully\n");
	mpin =new_pin;

	return mpin;
}


void denom(float sav_amt)
{
	int x,y,z;
	x=(sav_amt)/(10);
	y=(sav_amt)/(100);
	z=(sav_amt)/(1000);
	
	printf("\n------------------------------------------------\n");
	printf("Number of 10's in Balance: %.d",x);
	printf("\nNumber of 100's in Balance: %d",y);
	printf("\nNumber of 1000's in Balance: %d\n",z);
	printf("------------------------------------------------\n");
}

void update(account_t *p1,account_t *p2)
{
	for(int i=0;i<3;i++)
	{
		if(strcmp((p1+i)->name,p2->name)==0)
		{
			strcpy((p1+i)->name,p2->name);
			(p1+i)->pin = p2->pin;
			(p1+i)->savings = p2->savings;
		}
	}
}