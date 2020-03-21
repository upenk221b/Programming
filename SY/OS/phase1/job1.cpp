#include<iostream>
#include<fstream>
#include<string.h>
using namespace std;
#define max 100
#define max1 40
#define n 4
#include<cstring>

char mainmem[max][n];
char ir[n];
bool C;
int  ic=0;//instruction counter in interger values
char R[n];
string buffer;
int SI;
int DTAno=0;

ifstream ipfile;

void MOS()
{

  if(SI==1)//gd case
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
    int location= stoi(str);
    cout<<"\n"<<location;
    int temp=DTAno;

   /* for(temp;temp>-1;temp--)
     {
         getline(ipfile,buffer);
     }
     */
    getline(ipfile,buffer);

    DTAno++;
    cout<<"\n\n"<<buffer<<"\n\n";



     //if no Dcard abort
     if(buffer[0]=='$'&&buffer[1]=='E'&&buffer[2]=='N'&&buffer[3]=='D')
         {
             cout<<"\n no data card found \n";
             return;
         }

     int k =0;
     for(int i=location;i<location+10;i++)
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
    for(int i=0;i<100;i++)
     {
      cout<<"M["<<i<<"]";
      for(int j=0;j<4;j++)
       {
         cout<<mainmem[i][j]<<" ";
       }
    cout<<"\n";
    }

  }//gd if loop



  else if(SI==2)//pd case
  {

       ofstream otfile;
       cout<<"\n inside pd case \n";
       cout<<"\n";
       otfile.open("output.txt",ios::out|ios::app);//create new if aldready exists truncate over it
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
    int location= stoi(str);
    cout<<"\n"<<location;

    //putting data from main memory to buffer
    cout<<mainmem[location][0];
    int k=0;
    char tempbuffer[40];
    //clean the buffer
    for(int i=0;i<40;i++)
        buffer[i]=' ';

    //2d mem to 1d array conversion
     for(int i=location;i<location+10;i++)
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

     otfile<<endl;
     otfile<<tempbuffer,40;
     otfile<<endl;
     cout<<"\nstring written to output file";

     otfile.close();
  }//end of else if loop for pd

  else if (SI==3)//halt case
  {
      cout<<"inside halt";
      ofstream otfile;
      otfile.open("output.txt",ios::out|ios::app);
      otfile<<"\n\n";
      otfile<<"--------------------";

  }


}//func end

void initt()//initialize all registers
{
   ic=0;
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

}

void startexe()
{
    //will start from 0
    //from main memory to IR

for(ic;ic<10;ic++)//main loop for 10 line of mem
    {

    cout<<"\n"<<"ic"<<ic<<"\n";

      for(int j=0;j<4;j++) //one 4 byte command
      {
        ir[j]=mainmem[ic][j];//ir filled
      }



    //printing contents of current instructions
       for(int g=0;g<4;g++)
       {
         cout<<"IR"<<g<<" ";
         cout<<ir[g]<<" ";

       }
       cout<<endl;

       //executing the current instruction
       if(ir[0]=='G'&&ir[1]=='D')//read in MOS
       {
         cout<<"\n inside GD\n";
         SI=1;
         MOS();
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
            int location= stoi(str);
            cout<<"\n"<<location;
            //load in register
            for(int i=0;i<4;i++)
            {
                R[i]=mainmem[location][i];

            }
            // diplay
            cout<<"content of register is \n";
            for(int i=0;i<4;i++)
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
            cout<<"\n"<<location;

             //storing in
             for(int i=0;i<4;i++)
             {
                 mainmem[location][i]=R[i];
             }
             //display
             cout<<"\n";
           for(int i=0;i<100;i++)
           {
            cout<<"M["<<i<<"]";
            for(int j=0;j<4;j++)
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
            int location= stoi(str);
            cout<<"\n"<<location;

            //comparing
            int flag=0;
             for(int i=0;i<4;i++)
             {
                 if(R[i]!=mainmem[location][i])
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
              int location= stoi(str);
               cout<<"\n"<<location;
               cout<<" current "<<ic<<" ";
               ic=location;

        }
        else if(ir[0]=='H')//halt
         {
               cout<<"\n inside h\n";
               SI=3;
               MOS();
         }
         if(mainmem[ic+2][0]==' ')//no instruction in memory why 2 ?
        {
            cout<<"inside break1";
            break;
        }

    //end of block for
    }//end of main for


}//end of func STARTEXE


int main()
{
 // ifstream ipfile;

  ipfile.open("input.txt");
  if(!ipfile)
   {
     cout<<"error";
   }

for(int i=0;i<3;i++)//controlling loop number of lines in file
{

//while loop for reading
 while(getline(ipfile,buffer))
 {
  //getline(ipfile,buffer);//one line at a time
  cout<<buffer;
  cout<<"\n";

  if(buffer[0]=='$' && buffer[1]=='A' && buffer[2]=='M' && buffer[3]=='J')
  {
    cout<< "inside $AMJ \n";
    initt();//initialize all the variables
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
    ofstream otfile;
       otfile.open("output.txt",ios::out|ios::app);//create new if aldready exists truncate over it
       if(!otfile)
       {
         cout<<"error";
       }
    otfile<<"\n\n";
    otfile.close();

    continue;//checks for another program if none program ends
  }

  else//program execution GD PD LR etc
  {
      cout<<"inside else \n";
      //if there is aldready a program stored it appends
      cout<<mainmem[9][3]<<"\n";
      if(isalnum(mainmem[9][3]))

      {
        cout<<"\n inside load prog loop(gd pd) if case\n";
        int k=0;
         for(int t=10;t<20;t++)
       {
         for(int s=0;s<4;s++)
         {
            mainmem[t][s]=buffer[k];//buffer has gdpd prog line
          k=k+1;

           if(!isalnum(buffer[k]))
            {
              break;
             t=20;
              s=4;
            }
      }

      }
      }
  //putting data from buffer to main memory
    else if (!isalnum(mainmem[9][4]))
    {
        cout<<"\n inside load prog loop(gd pd) else case\n";
       int k=0;
      for(int t=0;t<10;t++)
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
    }

    //printing contents of main memory block wise
    cout<<"\n";
    for(int i=0;i<100;i++)
    {
      cout<<"M["<<i<<"]";
      for(int j=0;j<4;j++)
       {
         cout<<mainmem[i][j]<<" ";
       }
    cout<<"\n";
    }
  }
  //cleaning buffer
  for(int j=0;j<40;j++)
    buffer[j]=' ';
  cout<<endl;
  //break;

 }//end of while
 }//end of for loop

  ipfile.close();
   return 0;
}




