#include <bits/stdc++.h>
using namespace std;

	int num[10]={0}; //設定九宮格格子 
	int n=0;
    char F(int a){  //設定 F函數判斷玩家1為 O，玩家2(電腦)為 X，無填入則為格子代號 
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

// 電腦判斷玩家下的位置能否連成一線，若有則阻擋，若無則優先填5的位置或隨機選取 

void right(int a){    //判斷能放左 
	if((num[a-2]==0)&&((a-2)%3==1)){
		n=(a-2);
    }
}
void left(int a){      //判斷能放右 ，若不可，放左 
	if((num[a+1]==0)&&(a+1)%3!=1){
		n=a+1;
    }else{
		right(a);
	}	
}
void up(int a){       //判斷能放上
	if(num[a-6]==0){
	    n=a-6;
    }
}
void down(int a){     //判斷能放下，若不可，放上 
	if(num[a+3]==0){
		n=a+3;
	}	
	else{
		up(a);
    }
}
    
	void ai(int a){           //電腦判斷函式 
		    
		    if(num[a]==num[a+6]){      ///直排判斷 
		    	n=a+3;
			}else if(num[a]==num[a-6]){ 
		    	n=a-3;
			}else if(num[a]==num[a+3]){
                down(a+3);
            }else	if(num[a]==num[a-3]){
                down(a);
            }
			
			else if((num[a]==num[a-2])&&(a%3==0)){                ///橫排判斷 
		    	n=a-1;
			}else if((num[a]==num[a+2])&&(a%3==1)){ 
		    	n=a+1;
			}else if((num[a]==num[a+1])&&(a%3!=0)){ 
		        left(a+1);
           	}else if((num[a]==num[a-1])&&(a%3!=1)){
		        left(a);
           	}
			else if(num[5]!=0){                                 ///交叉判斷			
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
    
//判斷函式設定完成，開始主程式 

int main(){	
    cout<<"The following numbers are the tables of tic-tac-toe. \n";  //輸出遊戲說明 
    cout<<"When 'player1' is showed, you should choose a number you want to fill 'O' in. \n";
    cout<<"When it is player2's round, computer will choose a number to fill 'X' in. \n\n";
    
    //顯示9個格子 
	F(1);F(2);F(3);cout<<endl;
    F(4);F(5);F(6);cout<<endl;
    F(7);F(8);F(9);cout<<endl;

	for(int i=0;i<9;i++){	//開始遊戲迴圈，玩家1先手 ，以運算子判斷玩家為1還2 ，並取得選取格子代號 
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
		    
		      ///判斷是否有贏家，若有則停止遊戲迴圈 
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
	
	



