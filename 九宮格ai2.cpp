#include <bits/stdc++.h>
using namespace std;

	int num[10]={0}; //�]�w�E�c���l 
	int n=0;
    char F(int a){  //�]�w F��ƧP�_���a1�� O�A���a2(�q��)�� X�A�L��J�h����l�N�� 
	if(num[a]==1){
		cout<<"O ";
	}	
	if(num[a]==2){
       cout<< "X ";
	}
	if(num[a]==0){
		cout<<a<<" ";
	}
}

// �q���P�_���a�U����m��_�s���@�u�A�Y���h���סA�Y�L�h�u����5����m���H����� 

void right(int a){    //�P�_��� 
	if((num[a-2]==0)&&((a-2)%3==1)){
		n=(a-2);
    }
}
void left(int a){      //�P�_���k �A�Y���i�A�� 
	if((num[a+1]==0)&&(a+1)%3!=1){
		n=a+1;
    }else{
		right(a);
	}	
}
void up(int a){       //�P�_���W
	if(num[a-6]==0){
	    n=a-6;
    }
}
void down(int a){     //�P�_���U�A�Y���i�A��W 
	if(num[a+3]==0){
		n=a+3;
	}	
	else{
		up(a);
    }
}
    
	void ai(int a){           //�q���P�_�禡 
		    
		    if(num[a]==num[a+6]){      ///���ƧP�_ 
		    	n=a+3;
			}else if(num[a]==num[a-6]){ 
		    	n=a-3;
			}else if(num[a]==num[a+3]){
                down(a+3);
            }else	if(num[a]==num[a-3]){
                down(a);
            }
			
			else if((num[a]==num[a-2])&&(a%3==0)){                ///��ƧP�_ 
		    	n=a-1;
			}else if((num[a]==num[a+2])&&(a%3==1)){ 
		    	n=a+1;
			}else if((num[a]==num[a+1])&&(a%3!=0)){ 
		        left(a+1);
           	}else if((num[a]==num[a-1])&&(a%3!=1)){
		        left(a);
           	}
			else if(num[5]!=0){                                 ///��e�P�_			
		        if((num[1]==num[5])&&(num[1]!=0)){
		            if(num[9]==0){
		             	n=9;
					 }
                }else if((num[3]==num[5])&&(num[3]!=0)){
		            if(num[7]==0){
		             	n=7;
					 }
                }else if((num[9]==num[5])&&(num[9]!=0)){
		            if(num[1]==0){
		             	n=1;
					 }
                }else if((num[7]==num[5])&&(num[7]!=0)){
		            if(num[3]==0){
		                n=3;
					}
				}else{
					for(int i=1;i<10;i++){
            		    if(num[i]==0){
            			n=i;
            			i=9;
					    }
				    }
				}
            }else n=5;
	}
    
//�P�_�禡�]�w�����A�}�l�D�{�� 

int main(){	
    cout<<"The following numbers are the tables of tic-tac-toe. \n";  //��X�C������ 
    cout<<"When 'player1' is showed, you should choose a number you want to fill 'O' in. \n";
    cout<<"When it is player2's round, computer will choose a number to fill 'X' in. \n\n";
    
    //���9�Ӯ�l 
	F(1);F(2);F(3);cout<<endl;
    F(4);F(5);F(6);cout<<endl;
    F(7);F(8);F(9);cout<<endl;

	for(int i=0;i<9;i++){	//�}�l�C���j��A���a1���� �A�H�B��l�P�_���a��1��2 �A�è��o�����l�N�� 
	    cout<<"player:"<<((i%2)+1)<<endl;
	    
	    if(((i%2)+1)==1){
	    	cin>>n; 			
		}else{
			ai(n);					
		}if(num[n]!=0){
		    cout<<"again,";
	        i--;
    	}else{
		    num[n]=((i%2)+1);
            cout<<endl;
            F(1);F(2);F(3);cout<<endl;
            F(4);F(5);F(6);cout<<endl;
            F(7);F(8);F(9);cout<<endl;
		    
		      ///�P�_�O�_��Ĺ�a�A�Y���h����C���j�� 
			for(int x=1;x<4;x++){	           			
	            	if(((num[x]==num[x+3])&&(num[x+6]==num[x+3]))&&(num[x+6]!=0)){
                        cout<<"Player "<<((i%2)+1)<<" is the winner";
                        x=3;
                        i=8;
                    }
             	}	
	        for(int x=1;x<8;x+=3){
		            if(((num[x]==num[x+1])&&(num[x+2]==num[x+1]))&&(num[x+2]!=0)){
		                cout<<"Player "<<((i%2)+1)<<" is the winner";
                        x=7;
                        i=8;
                    }
           	} 
			
		    if(((num[1]==num[5])&&(num[9]==num[5]))&&(num[9]!=0)){
		                cout<<"Player "<<((i%2)+1)<<" is the winner";
                        i=8;
                    } 
			if(((num[3]==num[5])&&(num[7]==num[5]))&&(num[7]!=0)){
		                cout<<"Player "<<((i%2)+1)<<" is the winner";
                        i=8;}
        }
 	}	
		
}
	
	



