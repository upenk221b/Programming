#include<iostream>
#include<fstream>
#include<string>
#include<string.h>
using namespace std;
#define max 300
#define max1 40
#define n 4
#define cards 30
#include <cstdlib>
#include <ctime>

int pages;
struct jobinfo
{
   int info[3];
   //info[1]= job no info[2] -> TTL [3]-> TLL
  //predefines no of lines
   int TTC=0;//time counter
   int LLC=0;//line counter
}j1,j2;


int ptrr;
int pagevalid[29];
char mainmem[max][n];
char ir[n];
bool C;
int  ic;//instruction counter in integer values
char R[n];
string buffer;
int SI,TI=0,PI=0;
bool flag1=false;// for valid page fault
bool flag2 = false;
ifstream ipfile;


void Terminate(int a);
int simulate();
int MOS();
int gd();
void pd();
void current_reg_val();

void Terminate(int a)
{


     flag2=true;
   cout<<"\n inside terminate \n";
      ofstream otfile;
      otfile.open("output2.txt",ios::out|ios::app);

      if(!otfile)
       {
         cout<<"error";
       }

      if(a==0)
      {
          cout<<" \n normal execution \n";
          otfile<<" \n normal execution ";
          //otfile.close();
      }
      else
      {
          cout<<" \n abnormal exe \n";
          otfile<<"\n abnormal execution \n";

        if(a == 1)
        {
            otfile<<" out of data error \n ";
        }
        else if(a == 2)
        {
            otfile<<" Line limit exceeded \n";
        }

        else if(a == 3)
        {
            otfile<<" time limit exceeded \n";

        }

        else if(a == 4)
        {
            otfile<<" opcode error ";

        }
        else if(a ==5)
        {
            otfile<<" operand error ";

        }
        else if( a == 6)
        {
            otfile<<" invalid page fault \n ";

        }

      }
      otfile.close();
     current_reg_val();
     return ;
     // exit(0);
}

void current_reg_val()
{
    string irr;
    cout<<"\n inside reg values \n";
    ofstream otfile;
    otfile.open("output2.txt",ios::out|ios::app);

    if(!otfile)
    {
        cout<<"error";
    }
    otfile<<"\n IR , TTL ,TLL ,TTC ,LLC, IC , R \n";

    irr =ir;
    irr[4]=' ';
    cout<<"\n irr "<<irr;
    otfile<<irr<<"  "<<j1.info[1]<<"   "<<j1.info[2]<<"   "<<j1.TTC<<"   "<<j1.LLC<<"   "<<ic<<"  "<<R<<"\n";
    otfile<<"\n----------------------------------------------------------------------------------------------------------\n";
    otfile.close();
}

int allocatemem(int location)
{
        //allocate func
      int start;

      //allocate func
       do{
         start= rand() % 30 ;//rand will return from 0-29 and we want from 1 to 30 as 0 is page table
       }while(pagevalid[start]!=0);

        cout<<"\n start "<<start;
        pagevalid[start]=1;
        int p=ptrr;
        p=p*10;
        char card[2];// from int to char to store in mem
        int a=start%10;
        int b=start/10;
       //storing and converting from int to char
       card[1]=a+48;
       card[0]=b+48;
     /*
       for(int i=0;i<2;i++)
        cout<<card[i];
      */
      //putting entry in page table
      while(mainmem[p][0]!='*'&& p< ptrr*10+10)
        p++;

         cout<<"\n place of PT entry "<<p;
         //filling the page table
       mainmem[p][0]='1';
       mainmem[p][2]=card[0];
       mainmem[p][3]=card[1];

       start =start*10;//actual memory block
      cout<<"\n"<<start<<"\n";

      return start;
}

int addressmap(int VA)
{
    int pte=ptrr*10+VA/10;
    // go to the relavant page
    cout<<"\n pte "<<pte;
    if(mainmem[pte][0] != '1')
    {
        //flag1=false;
        cout<<"\n page fault \n";
        return -1;
    }

    char loc[2];
    loc[0]=mainmem[pte][2];
    loc[1]=mainmem[pte][3];
    string str(loc);
    int location= stoi(str);
    location=location*10;
    location=location + VA%10;// mod func for actual mem
    cout<<"\n"<<location;

    return location;

}

int gd()
{
        cout<<"\n inside gd case mos\n";
    //converting the char location to int
    //CLEAN BUFFER
    for(int i=0;i<40;i++)
        buffer[i]=' ';

    char loc[2];
    loc[0]=ir[2];
    loc[1]=ir[3];
    string str(loc);
    str[2]=' ';
    int location= stoi(str);
    cout<<"\n"<<location;


    if(location > 99 || location < 10)
    {
        cout<<"inside gd mos operand err\n";
        PI=2;
        MOS();
    }

    int rlocation = addressmap(location);
     cout<<"\n rlocation is "<<rlocation;

    if(rlocation==-1)
    {
        flag1=true;
        cout<<" \t page fault valid ";
        return -1;
    }
    //rlocation = allocatemem(location);

    getline(ipfile,buffer);
    cout<<"\n";
    cout<<"\n\n"<<buffer<<"\n\n";

     //if no Dcard abort
     if(buffer[0]=='$'&&buffer[1]=='E'&&buffer[2]=='N'&&buffer[3]=='D')
         {
             cout<<"\n no data card found out of data error \n";
             Terminate(1);
         }

     int k =0;
     for(int i=rlocation;i<rlocation+10;i++)
     {

         for(int j=0;j<4;j++)
         {
             mainmem[i][j]=buffer[k];
             k++;
             if(k==39||buffer[k]=='\n')//buffer limit exceeded
               {
                 break;
               }
         }
     }
     //show the loaded data card in main mem print main mem contents
     cout<<"\n";
    for(int i=0;i<300;i++)
     {
      cout<<"M["<<i<<"]";
      for(int j=0;j<4;j++)
       {
         cout<<mainmem[i][j]<<" ";
       }
    cout<<"\n";
    }

}


void pd()
{
    cout<<"\n inside pd case \n";
       ofstream otfile;
       otfile.clear();
       otfile.open ("output2.txt", std::ofstream::out | std::ofstream::app);
      // cin.ignore();//create new if aldready exists truncate over it

       cout<<"\n";
       if(!otfile)
       {
         cout<<"error";
       }
        //converting the char location to int
    char loc[2];
    loc[0]=ir[2];
    loc[1]=ir[3];
    string str(loc);
    str[2]=' ';
    int location= stoi(str);
    cout<<"\n location"<<location;
    if(location > 99 || location < 10)
    {
        cout<<"inside pd mos operand err\n";
        PI=2;
        MOS();
    }

    int rlocation =addressmap(location);
    cout<<"\n rlocation pd   "<<rlocation;

    if(rlocation == -1)
    {

        cout<<"\n invalid page fault ";
        PI=3;
        MOS();
        return;

    }
    //putting data from main memory to buffer
    cout<<mainmem[rlocation][0];
    int k=0;
    char tempbuffer[40];
    //clean the buffer
    for(int i=0;i<40;i++)
        buffer[i]=' ';

    //2d mem to 1d array conversion
     for(int i=rlocation;i<rlocation+10;i++)
     {
         for(int j=0;j<4;j++)
         {
             if(!isalnum(mainmem[i][j])&&mainmem[i][j]!=' '&&mainmem[i][j]!='*')
             {
                 tempbuffer[k]=' ';

             }
             else
             {
                 tempbuffer[k]=mainmem[i][j];
                  k++;
             }

         }
     }
    // buffer[18]=' ';
     cout<<"\n"<<strlen(tempbuffer);
//     buffer.erase(std::remove_if(s.begin(), s.end(), my_predicate), s.end());
     cout<<"\n";
     cout<<"contents of buffer \n";
     //putting from buffer to output file
     for(int i=0;i<40;i++)
        cout<<tempbuffer[i];

     tempbuffer[40] =' ';
     otfile<<endl;
     otfile<<tempbuffer,40;
     otfile<<endl;
     cout<<"\nstring written to output file";
     j1.LLC++;
     cout<<"\n llc "<<j1.LLC;
     if(j1.LLC > j1.info[2])
     {
         cout<<"\n total line limit exceeded \n";
         Terminate(2);
     }

     otfile.close();

}

int MOS()
{
    cout<<TI<<"\t"<<PI<<"\t"<<SI<<"\n";

    if(TI==0)
    {
        if(PI==0)
        {
            if(SI==1)
            {
                cout<<"\ninside gd mos () 2\n";
                int a=gd();
                if(flag1==true)
                    return a;
            }
            else if(SI==2)
            {
                pd();
                SI=0;
            }
            else if(SI==3)
            {
                Terminate(0);
            }
        }
        else if(PI==1)
        {
            cout<<"\n opcode error \n";

            Terminate(4);
        }
        else if(PI==2)
        {
            cout<<"\n operand error \n";
            Terminate(5);

        }
        else if(PI==3)
        {
            if(flag1==true)
            {
                cout<<"\n inside valid page fault in mos \n";
                char loc[2];
                loc[0]=ir[2];
                loc[1]=ir[3];
                string str(loc);
                int location= stoi(str);
                cout<<"\n location"<<location;
                allocatemem(location);
                //reset the flag and PI
                flag1=false;
                PI=0;
                return 0;

            }
            else//invalid page fault FOR PD LR SR OR BT
            {
                cout<<"\n invalid fpage fault \n";
                Terminate(6);

            }
        }

    }
    else// time is out
    {
        if(PI==0)
        {
            if(SI==1 )// halt and gd case
            {
                cout<<" \n timeout \n";
                Terminate(3);
            }
            else if(SI==3)
            {
                cout<<"normal exe ";
                Terminate(0);
            }
            else if(SI==2)//write and terminate
            {
                pd();
                Terminate(3);
            }
            else
            {
                cout<<" \n timeout \n";
                Terminate(0);
            }

        }
        else if(PI==1)
        {
            cout<<"\n timeout \n";
            Terminate(3);
        }
        else if(PI==2)
        {
            cout<<"\n timeout \n";
            Terminate(3);
        }
        else if(PI==3)
        {
            cout<<"\n timeout \n";
            Terminate(3);
        }

    }


}//func end

int simulate()
{

    j1.TTC++;
    cout<<" ttc incremented \n"<<j1.TTC;

    if(j1.info[1] == j1.TTC)
    {
        cout<<"inside timeout in simulate \n";
        TI=2;
        MOS();
        return -1;

    }
    return 0;
}


void initt()//initialize all registers
{

    cout<<"\nchecking ttl and tlc\n\n ";
     int i=0;
     char jobid[4];
     string str ;
      flag2= false;
     for(int f=4;f<16;f=f+4)
     {

     jobid[0]=buffer[f+0];
     jobid[1]=buffer[f+1];
     jobid[2]=buffer[f+2];
     jobid[3]=buffer[f+3];

    // cout<<str;
     int intamj = stoi(jobid);
    // cout<<"\n"<<intamj;
     j1.info[i]=intamj;
     i++;

    }
    cout<<"\n"<<"jobid"<<j1.info[0];
    cout<<"\n"<<"TTL"<<j1.info[1];
    cout<<"\n"<<"TLL"<<j1.info[2];


    j1.TTC=0;
    j1.LLC=0;
    SI=0;
    TI=0;
    PI=0;

   ic=0;//will change as per page allocated
   //cleaning main mem
   for(int j=0;j<max;j++)
   {
     for(int k=0;k<n;k++)
     {
       mainmem[j][k]=' ';
     }
   }
   for( int j=0;j<40;j++)
    buffer[j]=' ';

   for( int j=0;j<n;j++)
     R[j]=' ';

   for( int j=0;j<n;j++)
     ir[j]=' ';

    C=false;


    //page table
    for(int k=0;k<29;k++)
    {
        pagevalid[k]=0;
    }
    //initializing the page table
    int x = rand() % 30 ;
    ptrr=x;
    pagevalid[x]=1;
    cout<<"\n\n card"<<ptrr;
    x=x*10;
    cout<<"\nvalue of x \n "<<x;


    int y=x;
 // initializing the page table
   for(y; y<x+10 ; y++)
   {
     for(int q=0;q<4;q++)
     {
       mainmem[y][q]='*';
     }
   }

  //printing the initialized page table

   cout<<"priting first \n";
    for(int u=0;u<max;u++)
    {
      cout<<"M["<<u<<"]";
      for(int l=0;l<4;l++)
       {
         cout<<mainmem[u][l]<<" ";
       }
    cout<<"\n";

    }
    cout<<"\n\n moving out of init func \n";
    return ;
}


void startexe()
{
     //will start from virtual address 0
    //from main memory to IR
    ic =0;
    for(ic=0; ic<20; ic++) //main loop for 10 line of mem
    {
        if(flag2==true)
        {
            break;
        }
        int ric =addressmap(ic);

        cout<<"\n"<<"ric"<<ric<<"\t"<<ic<<"\n";

        for(int j=0; j<4; j++) //one 4 byte command
        {
            ir[j]=mainmem[ric][j];//ir filled
        }

        //printing contents of current instructions
        for(int g=0; g<4; g++)
        {
            cout<<"IR"<<g<<" ";
            cout<<ir[g]<<" ";

        }
         // simnulate fuunc
        int a=simulate();

        if( a==-1)
        {
            break;
        }


        cout<<endl;

        //executing the current instruction
        if(ir[0]=='G'&&ir[1]=='D')//read in MOS
        {
            cout<<"\n inside GD\n";
            SI=1;
            int a= MOS();
            if(flag1==true && a==-1)//page fault valid
            {
                cout<<"\n inside PF in start exe \n";
                PI=3;
                MOS();
                ic--;
//                flag1=false;
//                allocatemem(a);
//                ic--;
            }
        }
        else if(ir[0]=='P'&&ir[1]=='D')//write
        {
            cout<<"\n inside pd\n";
            SI=2;
            MOS();

        }
        else if(ir[0]=='L'&&ir[1]=='R')//load to register
        {
            cout<<"\n inside LR\n";
            //convert from strig  to int location of SR
            char loc[2];
            loc[0]=ir[2];
            loc[1]=ir[3];
            string str(loc);
            str[2]=' ';
            int location= stoi(str);
            cout<<"\n location "<<location;

            if(location > 99 || location < 0)
            {
                cout<<"inside lr mos operand err\n";
                PI=2;
                MOS();
            }
            //load in register
            int rlocation = addressmap(location);
            if(rlocation ==-1)
            {
                cout<<" \n page fault invalid ";
                PI=3;
                MOS();
            }
            for(int i=0; i<4; i++)
            {
                R[i]=mainmem[rlocation][i];

            }
            // diplay
            cout<<"content of register is \n";
            for(int i=0; i<4; i++)
            {

                cout<<R[i]<<" ";

            }
            cout<<"\n\n";

        }
        else if(ir[0]=='S'&&ir[1]=='R')//store to register
        {
            cout<<"\n inside SR\n";

            char loc[2];
            loc[0]=ir[2];
            loc[1]=ir[3];
            string str(loc);
            int location= stoi(str);
            str[2]=' ';
            location=location;
            cout<<"\n location= "<<location<<"\n";
            // operand err
            if( location >99 || location <0 )
            {
                cout<<"inside sr mos operand err\n";
                PI=2;
                MOS();
            }

            int rlocation =addressmap(location);
            if(rlocation == -1)
            {
                cout<<" \n page fault valid ";
                PI=3;
                flag1=true;
                MOS();
                ic--;
                continue;
            }
            //storing in

            for(int i=0; i<4; i++)
            {
                mainmem[rlocation][i]=R[i];
            }
            //display
            cout<<"\n";
            for(int i=0; i<300; i++)
            {
                cout<<"M["<<i<<"]";
                for(int j=0; j<4; j++)
                {
                    cout<<mainmem[i][j]<<" ";
                }
                cout<<"\n";
            }

        }

        else if(ir[0]=='C'&&ir[1]=='R')//compare with register value
        {
            cout<<"\n inside CR\n";
            char loc[2];
            loc[0]=ir[2];
            loc[1]=ir[3];
            string str(loc);
            str[2]=' ';
            cout<<str<<"\n";
            int location= stoi(str);
            cout<<"\n location "<<location<<"\n";
            if( location >99 || location <= 10 )
            {
                cout<<"inside cr mos operand err\n";
                PI=2;
                MOS();
            }

            int rlocation =addressmap(location);
            if(rlocation ==-1)
            {
                cout<<" \n page fault invalid ";
                PI=3;
                MOS();
            }
            //comparing
            int flag=0;
            for(int i=0; i<4; i++)
            {
                if(R[i]!=mainmem[rlocation][i])
                {
                    flag=1;

                }
            }
            if(flag==0)
            {
                C=true;
                cout<<"register content is matching \n";
            }
            else
            {
                C=false;
                cout<<"\n register is not matching\n";
            }

        }
        else if(ir[0]=='B'&&ir[1]=='T')//skip some lines
        {
            cout<<"\ninside bt \n";
            if(C==false)//bt not executed move to nxt statement
            {
                continue;
            }
            cout<<"\n inside bt and C is true \n";
            char loc[2];
            loc[0]=ir[2];
            loc[1]=ir[3];
            string str(loc);
            str[2]=' ';
            int location= stoi(str);
            if( location >20 || location < 0 )
            {
                cout<<"inside bt mos operand err\n";
                PI=2;
                MOS();
            }
            cout<<"\n"<<location;
            cout<<" current "<<ic<<" ";
            ic=location-1;

        }
        else if(ir[0]=='H')//halt
        {
            cout<<"\n inside h\n";
            SI=3;
            MOS();
            ic=21;
            break;
        }
        else
        {
            cout<<"\n inside strexe else opcode \n";
            PI=1;
            MOS();

        }


        cout<<"\n TTC and TTL  :"<<j1.TTC<<"\n";
        /*(mainmem[ic+1][0]==' ')//no instruction in memory why 2 ?
        {
            cout<<"\n inside break1";
            break;
        }
          */
//          if(j1.info[1]==j1.TTC)
//          {
//              MOS();
//          }
        //end of block for
    }//end of main for


}//end of func STARTEXE


int main()
{
    srand (time(NULL));
 // ifstream ipfile;
  ofstream otfile;
   otfile.open("output.txt",ios::out|ios::app);
   otfile.clear();


  ipfile.open("input2.txt");

  if(!ipfile)
   {
     cout<<"error";
   }
//while loop for reading
 while(getline(ipfile,buffer))
 {
 // getline(ipfile,buffer);//one line at a time
   cout<<"\n inside while "<<buffer;
   cout<<"\n";
  if(buffer[0]=='$' && buffer[1]=='A' && buffer[2]=='M' && buffer[3]=='J')
  {
    cout<< "inside $AMJ/init \n";
    initt();
    cout<<" ";//initialize all the variables
  }
  else if(buffer[0]=='$' && buffer[1]=='D' && buffer[2]=='T' && buffer[3]=='A')
  {
    cout<<" \n inside $dta ";
    startexe();
  }

  else if(buffer[0]=='$' && buffer[1]=='E' && buffer[2]=='N' && buffer[3]=='D')
  {
    cout<<"\n inside $END";
    cout<<"\n\n\n";
    cout<<"_______________________________";


    continue;//checks for another program if none program ends
  }

  else//program execution GD PD LR etc
  {
      cout<<"\ninside load function \n";
      int start;

      //allocate func
       do{
         start= rand() % 30 ;//rand will return from 0-29 and we want from 1 to 30 as 0 is page table
       }while(pagevalid[start]==1);

       pagevalid[start]=1;

        cout<<"\n start "<<start;
       int p=ptrr;
       p=p*10;
       char card[2];// from int to char to store in mem
       int a=start%10;
       int b=start/10;
       //storing and converting from int to char
       card[1]=a+48;
       card[0]=b+48;
     /*
       for(int i=0;i<2;i++)
        cout<<card[i];
      */
      //putting entry in page table
      while(mainmem[p][0]!='*'&& p< ptrr*10+10)
        p++;

         cout<<"\n place of PT entry "<<p;
         //filling the page table
       mainmem[p][0]='1';
       mainmem[p][2]=card[0];
       mainmem[p][3]=card[1];



       start =start*10;//actual memory block
      cout<<"\n"<<start<<"\n";

        cout<<"\n inside load prog loop(gd pd) else case\n";
       int k=0;
      for(int t=start;t<start+10;t++)
     {
      for(int s=0;s<4;s++)
      {
          mainmem[t][s]=buffer[k];//buffer has gdpd prog line
          k=k+1;

           if(buffer[k]=='\0')
            {
              break;
             t=10;
              s=4;
            }
      }

      }


    //printing contents of main memory block wise
    cout<<"\n";
    for(int i=0;i<max;i++)
    {
      cout<<"M["<<i<<"]";
      for(int j=0;j<4;j++)
       {
         cout<<mainmem[i][j]<<" ";
       }
    cout<<"\n";
    }
  }//end of else
  //cleaning buffer
 for(int la=0;la<40;la++)
    buffer[la]=' ';


  cout<<"end of while \n";

  //if(getline(ipfile,buffer))
     //  cout<<buffer;
  cout.flush();
  ipfile.clear();

 }//end of while
// }//end of for loop
  ipfile.close();
}

