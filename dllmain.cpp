#include "matdll.h"



/*per il calcolo del determinanate nxn*/
void ridottaj(double a[100][100],int dim,double s[100][100],int c, int &d)
{
    
    int i,j;
    d=0;
    
    for(i=0;i<dim-1;i++)
    {
        
        d++;
        for(j=0;j<dim-1;j++)
            
        {
            if(j<c)
            {
                s[i][j]=a[i+1][j];
            }
            else
            {
                s[i][j]=a[i+1][j+1];
            }
            
            
        }
      
        
    }
      
    
}

/*detrminanate*/
long double dete(double a[100][100],int dim)
{
 
    
    int d;//dimensione
    long double risultato=0;
    double temp[100][100];
   
   
    if(dim>2)
    {
        
        for(int j=0;j<dim;j++)
        {
            
            ridottaj(a,dim,temp,j,d);
            risultato+=(double)((1-2*(j%2))*a[0][j]*dete(temp,d));
            
        }
        
   
    }
    else
    {
    	
        risultato=(double)((a[0][0]*a[1][1]-a[0][1]*a[1][0]));
    }
    
    return risultato;
    
    
    
    
}


	//CALCOLA IL DETERMINANTE CON LA Regola di Sarrus.....sostituita  la regole Sviluppo di Laplace
	//double det(double m[3][3])
	//{
	
		//	return (m[0][0]*m[1][1]*m[2][2] + m[0][1]*m[1][2]*m[2][0] + m[0][2]*m[1][0]*m[2][1])-(m[2][0]*m[1][1]*m[0][2]+m[1][2]*m[2][1]*m[0][0]+ m[2][2]*m[1][0]*m[0][1]);
	
	//}



/*opz =1 cresc, opz=2 dec,,, default opz=2*/
void ordina(double **m,int r,int c,int opz)
{
	
	int i=0,j=0;
	bool ci_sono_scambi=true;
	while(ci_sono_scambi)
	{
		ci_sono_scambi=false;
		for( i=0;i<r;i++)
		{
		
			for( j=0;j<c-1;j++)
			{
			    switch(opz)
			    {
			    	case 1:
			    		if(m[i][j]>m[i][j+1])
			    		{
			    		   swap(m[i][j],m[i][j+1]);
			    		   ci_sono_scambi=true;
						}
						break;
					case 2:
						if(m[i][j]<m[i][j+1])
			    		{
			    		     swap(m[i][j],m[i][j+1]);
			    		     ci_sono_scambi=true;
						} 
						break;
				       
				}
			    
			}
			if(i==r-1 && j==c-1)
		   	{
		   		break;
		   	}
			switch(opz)
			    {
			    	case 1:
			    		if(m[i+1][0]<m[i][j])
			    		{
			    		   swap(m[i+1][0],m[i][j]);
			    		   ci_sono_scambi=true;
						}
						break;
					case 2:
						if(m[i+1][0]>m[i][j])
			    		{
			    		     swap(m[i+1][0],m[i][j]);
			    		     ci_sono_scambi=true;
						} 
						break;
				       
				}
		}
	}
	
	
}
/*determinanate 2x2*/
double det2x2(double m[2][2])
{
	return m[0][0]*m[1][1]-m[1][0]*m[0][1];
}

/*determinante di una 3x3 calcolato con la regole Sviluppo di Laplace*/
double det(double m[3][3])
{
	double min[2][2];
	
	double d=0;
	for(int i=0;i<3;i++)
	{
		minore(m,min,0,i);
		d+=(double)pow(-1,i)*m[0][i]*det2x2(min);
	}
	return d;
}


/*minore 3x3* di riga rig e colonna col*/
void minore(double m[3][3], double min[2][2], int rig, int col)
{

    int x=0,y=0;
    int i,j;
	for(i=0;i<3;i++)
	{
		for( j=0;j<3;j++)
		{
			if(j!=col && i!=rig )
			{
				min[x][y++]=m[i][j];
					
			}
		
		}
		if(i!=rig)
		x++;
		y=0;
		
	}
}

/*minore di una 3x4: si ottengono togliendo le colonne una alla volta */
void minore3x4(double m[3][4], double min[3][3],  int col)
{

    int x=0,y=0;
    int i,j;
	for(i=0;i<3;i++)
	{
		for( j=0;j<4;j++)
		{
			if(j!=col )
			{
				min[x][y++]=m[i][j];
					
			}
		
		}
	   
		x++;
		y=0;
		
	}
}

/*minore 2x2*/
void minore2x2(double m[2][2], double &min,int riga,int col)
{

    int i,j;
	for(i=0;i<2;i++)
	{
		for( j=0;j<2;j++)
		{
			if(j!=col && i!=riga )
			{
				min=m[i][j];
					
			}
		
		}

		
	}
}


/*
  rango 3x4 scritta indipendentemente da int rango3x3
  Poteva anche essere implementata con l'ausilio della int rango3x3
*/
int rango3x4(double m[3][4])
{
	
	double min[3][3];
	for(int j=0;j<4;j++)
	{
		minore3x4(m,min,j);
		if(det(min)!=0)
		return 3;
		
	}
	/*si poteva ache più semplicemente richiamare int rango3x3*/
	double min2[2][2];
	for(int j=0;j<4;j++)
	{
		minore3x4(m,min,j);
		for(int jjj=0;jjj<3;jjj++)
		{
			for(int jj=0;jj<3;jj++)
			{
				minore(min,min2,jjj,jj);
				if(det2x2(min2)!=0)
					return 2;
			}
		}
		
		
	}
	double min1;
	for(int j=0;j<4;j++)
	{
		minore3x4(m,min,j);
		for(int jj=0;jj<3;jj++)
		{
			minore(min,min2,0,jj);
			// bastava anche vedere se un min2 contiene almeno un ele !=0
		    for(int jjj=0;jjj<2;jjj++)
		    {
		    	for(int jjjj=0;jjjj<2;jjjj++)
		    	{
		    		if(min2[jjj][jjjj]!=0)
		    		return 1;
				}
		    	
		    	
			}
		}
		
		
	}
	
	return 0;
	
}


/*rango 3x3: puo essere 3,2,1,0*/
int rango3x3(double m[3][3])
{
	if(det(m)!=0)
	return 3; // se det!=0 è 3
	
	//altrimenti vado vedere se c'è almeno un determinante 2x2 diverso da zero
	double min2[2][2];
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			minore(m,min2,i,j);
	    	if(det2x2(min2)!=0)
			   return 2;	
		
		}
	
	
	double min1;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
		{
			//per ogni minore 2x2 provo vedere se esiste un determinante 1x1
			minore(m,min2,i,j);
			// bastava anche vedere se un min2 contiene almeno un ele !=0
			for(int jj=0;jj<2;jj++)
			{
			
				for(int jjj=0;jjj<2;jjj++)
				{
					if(min2[jj][jjj]!=0)
					   return 1;
				}
			
		
			}
		
		
		}
	
	return 0;
	
}


/*
Funzione che prende un p e a seconda del valore di p trova il determinate di d,dx,dy,dz ---> vedi Cramer
0 d, 1 dx, 2 dy, 3 dz
*/
double mxyz(double ma[3][4],int p)
{
     	double m[3][3];
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				m[i][j]=ma[i][j];
			}
		}
	
		switch(p)
		{
			case 0:
			
			return det(m);
		
			case 1:
			
			m[0][0]=ma[0][3];
			m[1][0]=ma[1][3];
			m[2][0]=ma[2][3];
			
			return det(m);
			
			case 2:
			m[0][1]=ma[0][3];
			m[1][1]=ma[1][3];
			m[2][1]=ma[2][3];
			
			
			return det(m);
			
			case 3:
			m[0][2]=ma[0][3];
			m[1][2]=ma[1][3];
			m[2][2]=ma[2][3];
			
			return det(m);
		
	}
}

/*Risolve il sistema con Cramer, RITORNA -1 SE impossibile, 1 se indeterminato, 0 se possibile*/
int sistema(double &x, double &y,double &z,double m[3][4],double ma[3][3])
{
            
		
            int rma=rango3x3(ma);
            int rm= rango3x4(m);
             	
            if(rm!=rma)
            	return -1;
            else if(rma==rm && rma<3)
            {
                return 1;	
			}
			else 
            {
            	double d=mxyz(m,0);
				double dx=mxyz(m,1);
				double dy=mxyz(m,2);
				double dz=mxyz(m,3);
			
				x=dx/d;
				y=dy/d;
				z=dz/d; 
				return 0;
			}
	
	
}


BOOL APIENTRY DllMain( HINSTANCE hModule,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}

