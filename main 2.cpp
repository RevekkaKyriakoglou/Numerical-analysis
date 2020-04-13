#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[])
{
	int n;
	float sum, x;
	int i, j;

	float *a1, *a2, **a3, *b1, *b2, **b3;

	cout<<"Enter the number n:"<<endl;
	cin>>n;

	a1 = new float[n];
	a2 = new float[n];
    	a3 = new float *[n] ;
	for( i = 0 ; i < n ; i++ )
    	{
         	a3[i] = new float[n];
    	}
    
   	for(i=0; i<=n-1; i++)
   	{	
     		cout<<"Enter x_"<<i<<":"<<endl;
      		cin>>a1[i];
   	}
	    
    	for(i=0;i<=n-1;i++)
    	{
        	cout<<"Enter the value of x_"<<i<<":"<<endl;
		cin>>a2[i];
    	}
    	
	for(j=0; j<n; j++)
    	{	
        	if(j==0)
		{	
            		for(i=0; i<n; i++)
			{
				if (i==(n-1))
				{
					a3[i][j]=0;
				}
				else
				{
					a3[i][j]=(a2[i]-a2[i+1])/(a1[i]-a1[i+1])
				}
			}
		}
		else
		{
			for(i=0; i<n; i++)
			{			
                		if(i<n-j-1)
				{
					a3[i][j]=(a3[i][j-1]-a3[i+1][j-1])/(a1[i]-a1[i+1+j]);
				}
				else
				{
					a3[i][j]=0;
                		}
			}
		}
   	}
    	cout<<"The matrix of 'diairemenwn diaforwn' is: "<<endl;
    	for(i=0; i<n; i++)
	{
             	cout<<setw(10)<<a1[i];
             	cout<<setw(10)<<a2[i];
        for (j=0; j<n; j++)
        {
             	if(j<n-i-1)
		{
			cout<<setw(10)<<a3[i][j];
		}
		else
		{
			cout<<setw(10)<<" ";
                }
             
        }
        cout<<endl<<endl;
}
        
	cout<<"Dwste to x:"<<endl;
	cin>>x;

	while(x>a1[n] || x<a1[0])
	{
		cout<<"The given x is not within the allowable limits."<<endl<<"Please give a number within the limits";
		cin>>x;
	}
	
float gin=1;
sum=a2[0];
for (i=0; i<n-1; i++)
{
	gin=gin*(x-a1[i]);
	sum=sum+a3[0][i]*gin;
}
cout<<"The solution is: "<<sum<<endl;	
	

b1 = new float[n+1];
b2 = new float[n+1];
    
b3 = new float *[n+1] ;
for( i = 0 ; i < n+1 ; i++ )
{
	b3[i] = new float[n+1];
}
    
for(i=0; i<=n; i++)
{
	if(i<n)
        {        
		b1[i]=a1[i];
        }
	else if(i=n)
        {
           	b1[i]=x;
        }
}
for(i=0; i<=n; i++)
{
       	if(i<n)
        {         
             	b2[i]=a2[i];
         }
         else if(i=n)
         {
                 b2[i]=sum;
         }
        
}  
   
      
for(j=0; j<=n-1; j++)
{	
        if(j==0)
	{	
    		for(i=0; i<=n; i++)
		{
			if (i==n)
			{
				b3[i][j]=0;
			}
			else
			{
				b3[i][j]=(b2[i]-b2[i+1])/(b1[i]-b1[i+1]);
                	}
		}
         }
	else
	{
		for(i=0; i<=n; i++)
		{			
               		if(i<n-j)
			{
				b3[i][j]=(b3[i][j-1]-b3[i+1][j-1])/(b1[i]-b1[i+1+j]);
       			}
			else if(i>=n-j)
			{
				b3[i][j]=0;
			}
          	}
	}
}


	
float sf=b3[1][n-2];

for(i=0; i<n; i++)
{
 	sf=sf*(b1[n]-b1[i]);
}

cout<<"And the error is:";
cout<<sf;
	
	
system("pause");
return EXIT_SUCCESS;
}
