#include <stdio.h>
#include<stdlib.h>
int calender(int d,int m,int y)
{
	int y1,y2,y3,leap,normal,k,doy,modday,modyear,value,days_in_feb=28;
	doy=d;
	if(y<2000)
	{
		y1=(y-1600)%100;
		y2=y-y1-1600;
		y3=y1-1;
	}
	else if(y>2000)
	{
		y1=(y-2000)%100;
		y2=y-y1-2000;
		y3=y1-1;
	}
	if(y2==100)
		k=5;
	else if(y2==200)
		k=3;
	else if(y2==300)
		k=1;
	else
		k=0;
	if( (y % 4 == 0 && y % 100 != 0 ) || (y % 400 == 0) )
    {
        days_in_feb = 29;
    }
    switch(m)
    {
        case 2:
            doy += 31;
            break;
        case 3:
            doy += 31+days_in_feb;
            break;
        case 4:
            doy += 31+days_in_feb+31;
            break;
        case 5:
            doy += 31+days_in_feb+31+30;
            break;
        case 6:
            doy += 31+days_in_feb+31+30+31;
            break;
        case 7:
            doy += 31+days_in_feb+31+30+31+30;
            break;            
        case 8:
            doy += 31+days_in_feb+31+30+31+30+31;
            break;
        case 9:
            doy += 31+days_in_feb+31+30+31+30+31+31;
            break;
        case 10:
            doy += 31+days_in_feb+31+30+31+30+31+31+30;            
            break;            
        case 11:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31;            
            break;                        
        case 12:
            doy += 31+days_in_feb+31+30+31+30+31+31+30+31+30;            
            break;                                    
    }
    leap=y3/4;
    normal=y3-leap;
    modyear=((leap*2)+normal)%7;
    modday=doy%7;
    value=abs((k+modyear+modday)-7);
    switch(value)
    {
        case 0:
            printf("Sunday\n");
            break;
        case 1:
            printf("Monday\n");;
            break;
        case 2:
            printf("Tuesday\n");
            break;
        case 3:
            printf("Wednesday\n");
            break;
        case 4:
            printf("Thrusday\n");
            break;
        case 5:
            printf("Friday\n");
            break; 
        case 6:
            printf("Saturday\n");
            break;                                            
    }
}
int main()
{
	int d,m,y;
	printf("Enter the DATE MONTH and YEAR in format (dd/mm/yyyy)\n");
	scanf("%d/%d/%d",&d,&m,&y);
	if(m==2)
	{
		if((d>28)&&(y%4!=0))
		{
			printf("Fool,Invalid date in February of non leap year.The maximum value is 28");
		}
		if((d>29)&&(y%4==0))
		{
			printf("Fool,Invalid date in February of leap year.The maximum value is 29");
		}
	}
	else if((m==1)||(m==3)||(m==5)||(m==7)||(m==8)||(m==10)||(m==12))
	{
		if(d>31)
		{
			printf("Fool,Invalid date in %d th month.The maximum value is 31",m);
		}
	}
	else if(((m==4)||(m==6)||(m==9)||(m==11))&&(d>30))
	{
		printf("Fool,Invalid date in the %d th month.The maximum value 30",m);
		if((d>31))
		{
			printf("Enter valid date");
		}
	}
	else
	{
		calender(d,m,y);
	}
   return 0;
}
