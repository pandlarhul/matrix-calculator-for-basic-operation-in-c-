			#include<iostream>
		//	#include<conio.h>
			#include<math.h>
			#include<stdlib.h>
			using namespace std;
			class MatrixOperation
			{
			int array[10][10],column,row;
			public:
			void cleanMatrix();
			void pageMatrix();
			void startMatrix();
			void readMatrix();
			void showMatrix();
			friend MatrixOperation operator +(MatrixOperation,MatrixOperation);
			friend MatrixOperation operator-(MatrixOperation,MatrixOperation);
			friend MatrixOperation operator *(MatrixOperation,MatrixOperation);
			MatrixOperation transposeMatrix();
			MatrixOperation adjointMatrix();
			int checkAdjoint();
			int cofactor(int [10][10],int,int);
			int detMatrix();
			MatrixOperation invMatrix();
			int checkInv();
			};
			typedef MatrixOperation mo;
			MatrixOperation MatrixOperation::invMatrix()
			{
			MatrixOperation m1;
			m1=this->adjointMatrix();
			return m1;
			}
			int MatrixOperation::checkInv()
			{
			int check;
			if(this->detMatrix()==0)
			check=0;
			else
			check=1;
			return check;
			}


			int MatrixOperation::detMatrix()
				{
				int det=0,i,j;
				for(i=0;i<=0;i++)
				for(j=0;j<column;j++)
				det+=(pow(-1,i+j)*cofactor(array,i,j))*(array[i][j]);
				return det;
				}
			int MatrixOperation::cofactor(int a[10][10],int i1,int j1)
			{
			int length;
			length=row;
				int i,j,b[4][4],k=0,l=0;
				for(i=0;i<length;i++)
					{
					for(j=0;j<length;j++)
					if(i1!=i && j1!=j)
					{
					b[k][l++]=a[i][j];
					}
					if(l==length-1)
						{
						k=k+1;
						l=0;
						}
					}
		     if(length==2)
		     i=b[0][0];
		     else
		     i=b[0][0]*b[1][1]-b[0][1]*b[1][0];
		     return i;
			}//cofactor for matrix adjoint



			MatrixOperation MatrixOperation::adjointMatrix()
			{
			MatrixOperation m4;
			m4.row=row;
			m4.column=column;
			int i=0,k=0;
			for(i=0;i<column;i++)
			for(k=0;k<column;k++)
			m4.array[i][k]=pow(-1,(i+k))*(cofactor(array,i,k));
			m4=m4.transposeMatrix();
			return m4;
			}
			int MatrixOperation::checkAdjoint()
			{
			int c=0;
			if(row==column)
			c=1;
			return c;
			}
			MatrixOperation MatrixOperation::transposeMatrix()     //****transpose of matrix
			{
			int i,j;
			mo m1;
			m1.row=column;
			m1.column=row;
			for(i=0;i<row;i++)
				{
				for(j=0;j<column;j++)
					{
					m1.array[j][i]=array[i][j];
					}
				}

			return m1;
			}                            //*******transpose matrix
			mo operator *(mo o1,mo o2)   //******* multiplication of two matrix
			{
			int i=0,j=0,temp=0,a,b,k=0;
			mo o3,o4;
			if(o1.column==o2.row)
				{
				     o3.row=o1.row;
				     o3.column=o2.column;
				     for(i=0;i<o1.row;i++)
				     {

				     for(j=0;j<o2.column;j++)
					{
					temp=0;
					for(k=0;k<o2.row;k++)
					      {
						a=o1.array[i][k];
						b=o2.array[k][j];
						temp=temp+(a*b);
					      }


				     o3.array[i][j]=temp;
					}
				     }
				}
			  else
			  {
			  o4.row=0;
			  o4.column=0;
			  cout<<"\n matrix can`t multiply due to different order";
			  return o4;
			  }             //subtraction of two matrix
			 return o3;


			}                            //******** multiplication matrix
			mo operator -(mo o1,mo o2)    //******* subtraction of matrix
			{
			int i=0,j=0;
			mo o3,o4;
			if(o1.row==o2.row && o1.column==o2.column)
				{
				     o3.row=o1.row;
				     o3.column=o1.column;
				     for(int i=0;i<o1.row;i++)
				     for(j=0;j<o1.column;j++)
				     o3.array[i][j]=o1.array[i][j]-o2.array[i][j];

				}
			  else
			  {
			  o4.row=0;
			  o4.column=0;
			  cout<<"\n matrix can`t subtract due to different order";
			  return o4;
			  }             //subtraction of two matrix
			 return o3;
			}

			mo operator +(mo o1,mo o2)   //******** addition operation of matrix
			{
			int i=0,j=0;
			mo o3,o4;

			if(o1.row==o2.row && o1.column==o2.column)
				{
				     o3.row=o1.row;
				     o3.column=o1.column;
				     for(int i=0;i<o1.row;i++)
				     for(j=0;j<o1.column;j++)
				     o3.array[i][j]=o1.array[i][j]+o2.array[i][j];

				}
			  else
			  {
			  o4.row=0;
			  o4.column=0;
			  cout<<"\n Matrix can`t add due to different order";
			  return o4;
			  }             //************addition of two matrix
			 return o3;
			}
			void MatrixOperation::cleanMatrix()
			{
			cout<<"\n\n		press any key to continue";
			//getch();
			//clrscr();
			}
			void MatrixOperation::showMatrix()
			{

			for(int i=0;i<row;i++)
			   {
			   cout<<"\n";
			   for(int j=0;j<column;j++)
				{
				cout.width(4);
				cout<<array[i][j]<<"  ";
				}
			   }
			}   //show the content of matrix
			void MatrixOperation::readMatrix()
		{
			cout<<"\nenter the order of the Matrix as row column=";
			cin>>row;
			cin>>column;
			int i,j;
			for(i=0;i<row;i++)
			{
			cout<<"enter the values of "<<i+1<<" row\n";
			  for(j=0;j<column;j++)
				{
				cin>>array[i][j];
				}
			}
		}//function for matrix read
			void MatrixOperation::pageMatrix()
			{
			cout<<"\n\nenter the choice";
			cout<<"\n1.Particular matrix show";
			cout<<"\n2.matrix addition";
			cout<<"\n3.matrix subtraction";
			cout<<"\n4.matrix multiplication";
			cout<<"\n5.matrix transpose";
			cout<<"\n6.matrix adjoint";
			cout<<"\n7.determinent of matrix";
			cout<<"\n8.inverse of matrix ";
			cout<<"\n9.for enter new matrix";
			cout<<"\n10.exit\n";
			}        //print the menu of matrix
			void MatrixOperation::startMatrix()
			{
			MatrixOperation m1[10],addMatrix[7];
			int number=0,i,matrixNumber=0;
			int choice,choose1,choose2,determinent;
		while(1)
		{
			pageMatrix();
			cin>>choice;
			//clrscr();
			switch(choice)
			{
			case 1:
			if(number==0)
				{
				cout<<"\nMatrix is not available";
			break;
				}
				else
				{
			cout<<"\n enter the Matrix number=";
			cin>>matrixNumber;
			if(matrixNumber<=number)
			m1[matrixNumber-1].showMatrix();
			else
			cout<<"\nMatrix is not available=";
				}
			break;
			case 2:
			if(number==0)
				{
			cout<<"\nMatrix is not exist";
				}
			else
				{
				if(number>2)
					 {
					cout<<"\nChoose the first matrix";
					cin>>choose1;
					cout<<"Enter the second matrix";
					cin>>choose2;
					addMatrix[6]=m1[choose1-1]+m1[choose2-1];
					addMatrix[6].showMatrix();
					 }
				  else if(number==2)
				  {
				  addMatrix[6]=m1[0]+m1[1];
				  addMatrix[6].showMatrix();
				  cleanMatrix();
				  }
				  else if(number==1)
				  {
				  m1[0].showMatrix();

				  }
				  else
				  cout<<"\n Matrix is not exists";

				}

			break;
			case 3:
			if(number==0)
				{
			cout<<"\nMatrix is not exist";
				}
			else
				{
				if(number>2)
					 {
					cout<<"\nChoose the first matrix";
					cin>>choose1;
					cout<<"Enter the second matrix";
					cin>>choose2;
					addMatrix[6]=m1[choose1-1]-m1[choose2-1];
					addMatrix[6].showMatrix();
					 }
				  else if(number==2)
				  {
				  addMatrix[6]=m1[0]-m1[1];
				  addMatrix[6].showMatrix();
				  cleanMatrix();
				  }
				  else if(number==1)
				  {
				  m1[0].showMatrix();

				  }
				  else
				  cout<<"\n Matrix is not exists";

				}


			break;
			case 4:
			if(number==0)
				{
			cout<<"\nMatrix is not exist";
				}
			else
			      {
				if(number>2)
					 {
					cout<<"\nChoose the first matrix";
					cin>>choose1;
					cout<<"Enter the second matrix";
					cin>>choose2;
					addMatrix[6]=m1[choose1-1]*m1[choose2-1];
					addMatrix[6].showMatrix();
					 }
				  else if(number==2)
					{
					addMatrix[6]=m1[0]*m1[1];
					addMatrix[6].showMatrix();
					cleanMatrix();
					}
				  else if(number==1)
				  {
				  addMatrix[5]=m1[0]*m1[0];
				  addMatrix[5].showMatrix();
				  }
				  else
				  cout<<"\n Matrix is not exists";
			      }
			break;
			case 5:
			if(number==0)
				{
			   cout<<"Matrix is not exist";
				}
			 else  if(number==1)
			 {
			 addMatrix[5]=m1[0].transposeMatrix();
			 addMatrix[5].showMatrix();
			 }
			 else
			 {
			 cout<<"\n Choose the matrix";
			 cin>>choose1;
			 addMatrix[5]=m1[choose1-1].transposeMatrix();
			 addMatrix[5].showMatrix();
			 }
			break;
			case 6:
			if(number==0)
			  {
				cout<<"\n Please submit the element";
			  }
			else if(number==1)
			   {
				if(m1[0].checkAdjoint()==1)
				    {
					addMatrix[4]=m1[0].adjointMatrix();
					addMatrix[4].showMatrix();
				     }
				else
				{
					cout<<"\n Matrix must be square";
				}

			   }
			else
			  {
				cout<<"\n Choose the matrix";
				cin>>choose1;
				if(m1[choose1-1].checkAdjoint()==1)
				    {
					addMatrix[4]=m1[choose1-1].adjointMatrix();
					addMatrix[4].showMatrix();
				    }
				else
				    {
				    cout<<"\n The matrix order must be square";
				    }
			  }
			break;
			case 7:
			    if(number==0)
			  {
				cout<<"\n Please submit the element";
			  }

			else if(number==1)
			   {
				if(m1[0].checkAdjoint()==1)
				    {
					determinent=m1[0].detMatrix();
					cout<<"\ndet(1)="<<determinent;
				     }

					else
					{
						cout<<"\n Matrix must be square";
					}

			   }
			else
			  {
				cout<<"\n Choose the matrix";
				cin>>choose1;
				if(m1[choose1-1].checkAdjoint()==1)
				    {
					determinent=m1[choose1-1].detMatrix();
					cout<<"\ndet("<<choose1<<")="<<determinent;
				    }
				else
				    {
				    cout<<"\n Matrix order must be square ";
				    }
			  }
			break;
			case 8:
			if(number==0)
			  {
				cout<<"\n Please submit the element";
			  }

			else if(number==1)
			   {
				if(m1[0].checkAdjoint()==1)
				    {
				       if(m1[0].checkInv()==0)
						{
						cout<<"\ndeterMinent is 0";
						}
					else
						{

						addMatrix[5]=m1[0].invMatrix();
						addMatrix[5].showMatrix();
						determinent=m1[0].detMatrix();
						cout<<"\ndet(1)="<<determinent;
						}
				    }

				     else
				     {
						cout<<"\n Matrix must be square";
				     }

			   }
			else
			  {
				cout<<"\n Choose the matrix";
				cin>>choose1;
				if(m1[choose1-1].checkAdjoint()==1)
				    {
					if(m1[choose1-1].checkInv()==1)
						{
						addMatrix[5]=m1[choose1-1].invMatrix();
						addMatrix[5].showMatrix();
						determinent=m1[choose1-1].detMatrix();
						cout<<"\ndet("<<choose1<<")="<<determinent;
						}
				    }
				else
				    {
				    cout<<"\n Matrix order must be square ";
				    }
			  }

			break;
			case 9:
			cout<<"\n How many matrix you want to enter=";
			cin>>number;
			for(i=0;i<number;i++)
				{
				cout<<"Provide the element of"<<i+1<<" matrix=";
				m1[i].readMatrix();
				}
			break;
			case 10:
			exit(10);
			break;
			}
		}//iterator for matrix function
			}
		    int main()
		    {
		    //clrscr();
		    MatrixOperation m1;
		    m1.startMatrix();
		    //getch();

		    }
