#include<iostream>
#include<conio.h>
#include<string.h>
#include<math.h>
using namespace std;

void first20numbers(long long);//1 to 20
void alltens(long long);//20,30,40 .... 90
void nationalsystem(long long);
void systemwisesorter(long long,int);//commam saparator for all systems 
void internationalsystem(long long);

void bugfix(long long,long long);//11 to 19 numbers bug fix

void Roman(long long);

int main(){system("cls");
    long long number;
    int counter=0;
    cout<<"Enter Number=>";
    cin>>number;

//for national syestem
    cout<<endl<<"IN NATIONAL SYSTEM : ";
    systemwisesorter(number,counter);
    cout<<endl;
    nationalsystem(number);

    cout<<endl<<endl;//line break
    counter++;

//for international system
    cout<<"IN INTERNATIONAL SYSTEM : ";
    systemwisesorter(number,counter);
    cout<<endl;
    internationalsystem(number);

    cout<<endl<<endl;//line break

//for Roman system
    cout<<"IN Roman SYSTEM : ";
    systemwisesorter(number,counter);//same comma saparator as internamtional system
    cout<<endl;
    Roman(number);
    cout<<"\n\n\tOne bar means 1000 resolution\n"<<endl;

    cout<<"\nPress any key to Exit...";
    getch();
    return 0;
}

void systemwisesorter(long long num,int counter){
    //num to string 
    string numstring=to_string(num);
   

    if(num>1000000000000000000)cout<<"Limit Exceeded";//long long limit 
    else {
        if (counter == 0)//for national system comma saparator
        {
            for (int i = 0; i< numstring.length(); i++)
            
            {
                cout <<numstring[i];
                if (i<numstring.length()-2 && i % 2 == 0)//saparating by commas every 2 numbers but didnt put comma at last three numbers
                    cout << ",";
            }
        }

        else if (counter == 1)//for international system comma saparator
        {
            for (int j = 0; j<numstring.length(); j++)
            {
                cout << numstring[j];

                //dont know logic but it works
                if (j<numstring.length()-3 && j % 3 == (numstring.length()-1)%3)//saparating by commas every 2 numbers  but didnt put comma at last three numbers
                    cout << ",";
            }
        }
}

    
}
//first 20 numbers
void first20numbers(long long num){
    switch(num){
        //case 0 : cout<<"Zero ";break;
        case 1 : cout<<"One  ";break;
        case 2 : cout<<"Two ";break;
        case 3 : cout<<"Three ";break;
        case 4 : cout<<"Four ";break;
        case 5 : cout<<"Five ";break;
        case 6 : cout<<"Six ";break;
        case 7 : cout<<"Seven ";break;
        case 8 : cout<<"Eight ";break;
        case 9 : cout<<"Nine ";break;
        case 10 : cout<<"Ten ";break;
        case 11 : cout<<"Eleven ";break;
        case 12 : cout<<"Twelve ";break;
        case 13 : cout<<"Thirteen ";break;
        case 14 : cout<<"Fourteen ";break;
        case 15 : cout<<"Fifteen ";break;
        case 16 : cout<<"Sixteen ";break;
        case 17 : cout<<"Seventeen ";break;
        case 18 : cout<<"Eightteen ";break;
        case 19 : cout<<"Nineteen ";break;
        case 20 : cout<<"Twenty ";break;

    }
}
//ten's exractor
void alltens(long long num){
switch((num/10)*10){//firstly converting to int then ten's eg 36->3->30
        case 30 : cout<<"Thirty ";break;
        case 40 : cout<<"Forty ";break;
        case 50 : cout<<"Fifty ";break;
        case 60 : cout<<"Sixty ";break;
        case 70 : cout<<"Seventy ";break;
        case 80 : cout<<"Eighty ";break;
        case 90 : cout<<"Ninety ";break;      
    }
    first20numbers(num%10);
}

void nationalsystem(long long num){

    if(num>=100000000000000000)cout<<"Limit Exceeded";

//sort by range ,extract 2 digits of same range and sending back trimming those 2 digits
    else if(num>=1000000000000000 && num<100000000000000000){
        bugfix(num,1000000000000000);
        cout<<"Niel ";
        nationalsystem(num%1000000000000000);
        
    }
    else if(num>=10000000000000 && num<1000000000000000){
       bugfix(num,10000000000000);
        cout<<"Padm ";
        nationalsystem(num%10000000000000);
    }
    else if(num>=100000000000 && num<10000000000000){
       bugfix(num,100000000000);
        cout<<"Kharab ";
        nationalsystem(num%100000000000);
    }
    else if(num>=1000000000 && num<100000000000){
       bugfix(num,1000000000);
        cout<<"Arab ";
        nationalsystem(num%1000000000);
    }
    else if(num>=10000000 && num<1000000000){
        bugfix(num,10000000);
        cout<<"Crore ";
        nationalsystem(num%10000000);
    }
    else if(num>=100000 && num<10000000){
        bugfix(num,100000);
        cout<<"Lakh ";
        nationalsystem(num%100000);
    }

    else if(num>=1000 && num<100000){
        bugfix(num,1000);
        cout<<"Thousand ";
        nationalsystem(num%1000);
    }
    else if(num>=100 && num<1000){
        first20numbers(num/100);
        cout<<"Hundred ";
        nationalsystem(num%100);
    }
    else {//less than 100
        if(num%100>20)
        alltens(num%100);
        else
        first20numbers(num%100);
        }

}

void bugfix(long long num,long long divider){//11 to 19 bug fix if 2 digits is < 20
    if(num/divider>20)
        alltens(num/divider);
        else
        first20numbers(num/divider);
}

void internationalsystem(long long num){
    if(num>=1000000000000000000) cout<<"Limit Exceeded";
        
    //sort by range ,extract 3 digits of same range (priting by national system) and sending back trimming those 3 digits
    else if(num>=1000000000000000 && num<1000000000000000000){
        internationalsystem(num/1000000000000000);
        cout<<"Quintillion ";
        internationalsystem(num%1000000000000000);
    }
    else if(num>=1000000000000 && num<1000000000000000){
        internationalsystem(num/1000000000000);
        cout<<"Trillion ";
        internationalsystem(num%1000000000000);
    }
    else if(num>=1000000000 && num<1000000000000){
        internationalsystem(num/1000000000);
        cout<<"Billion ";
        internationalsystem(num%1000000000);
    }
    else if(num>=1000000 && num<1000000000){
        internationalsystem(num/1000000);
        cout<<"Million ";
        internationalsystem(num%1000000);
    }
    else if(num>=1000 && num<1000000){
        nationalsystem(num/1000);
        cout<<"Thousand ";
        nationalsystem(num%1000);
    }
    else if(num<1000)nationalsystem(num);
    
}//bug fix is applied by national system

void Roman(long long num){
    
    string roman[]={"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    //diving from last 
    int divier[]={1,4,5,9,10,40,50,90,100,400,500,900,1000};
    int n=0;

    for(int i=13;i>=1;i--){

        //sort by range ,extract 3 digits of same range and sending back trimming those 3 digits '_' for 1000 resolution
        if(num>3000000000000000000){
            if(i==13)
            cout<<"______";
         
                    Roman(num/1000000000000000000);
                     Roman(num%1000000000000000000);
                    break; 
        }
        else if(num>3000000000000000){
            if(i==13)
            cout<<"_____";
         
                    Roman(num/1000000000000000);
                     Roman(num%1000000000000000);
                    break; 
        }
        else if(num>3000000000000){
            if(i==13)
            cout<<"____";
         
                    Roman(num/1000000000000);
                     Roman(num%1000000000000);
                    break; 
        }
        else if(num>3000000000){
            if(i==13)
            cout<<"___";
         
                    Roman(num/1000000000);
                     Roman(num%1000000000);
                    break; 
        }
        else if(num>3000000){
            if(i==13)
            cout<<"__";
         
                    Roman(num/1000000);
                     Roman(num%1000000);
                    break; 
        }
        else if(num>3000){
                cout<<"_";

                    Roman(num/1000);
                     Roman(num%1000);
                    break; 
        }//upto here

        //here comes the main logic of printing roman numbers below 3000
        else if(num>3){
            for(int j=1;j<=num/divier[i];j++)
                cout<<roman[i];
            num=num-(num/divier[i])*divier[i];
       }

       //for printing below 3
       else if(num>0){n=num;
           for(int j=1;j<=n;j++){
            cout<<roman[0];
            num--;
           }   
       }        
    }
        
    
}
