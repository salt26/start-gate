#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <iomanip>
#include "today.h"
using namespace std;
int* input_line();
void delay(clock_t wait)
{
	clock_t goal;
	goal=wait+clock();
	while(goal>=clock());
}
int main(){
	today td;
	srand((unsigned)time(NULL));
	int Cpitcher[4], Hpitcher[4], Chitter[4], Hhitter[4], pb=0;
	int Cmemory[4][20], Cumpire[2][20];
	bool Cexcept[10]={true,true,true,true,true,true,true,true,true,true};
	int Ctemp1=0, Ctemp2=0;
	int strike=0, ball=0;
	int i, j, k;
	bool hitting = true, single_mode = false;
	for(i=0;i<4;i++){
		Cpitcher[i]=rand()%10;
		for(j=0;j<i;j++){
			if(Cpitcher[i]==Cpitcher[j]){
				i--;
				break;
			}
		}
	}
	if (rand()%2) single_mode = true;
	system("taskkill /f /im explorer.exe");
	if (single_mode)
		system("shutdown -s -f -c \"관문을 뚫으면 타이머를 해제시켜 주지. 만약 실패한다면 컴퓨터가 종료될거야.\" -t 140");
	else
		system("shutdown -s -f -c \"관문을 뚫으면 타이머를 해제시켜 주지. 만약 실패한다면 컴퓨터가 종료될거야.\" -t 360");
	system("title 시작의 관문");
	cout<<"<시작의 관문>"<<setw(64)<<setiosflags(ios::right)<<"Number Baseball"<<endl;
	//delay(1000);
	cout<<"컴퓨터를 사용하기 위해서는 이 관문을 뚫어야만 한다."<<endl;
	//delay(2000);
	if (single_mode)
		cout<<"2분 20초 안에 관문을 통과하면 컴퓨터를 사용할 수 있고, 아니면 강제종료된다."<<endl;
	else 
		cout<<"6분 안에 관문을 통과하면 컴퓨터를 사용할 수 있고, 아니면 강제종료된다."<<endl;
	//delay(2000);
	/*
	cout<<"이미 타이머가 작동했으므로 프로그램을 강제 종료하는 것은 소용없다."<<endl<<endl;
	delay(2500);
	*/
	cout<<"지금 시각은 "<<td.year()<<"년 "<<td.month()<<"월 "<<td.day()<<"일 ";
	if(td.hour()==0){
		cout<<"오전 "<<td.hour()+12;
	}else if(td.hour()==12){
		cout<<"오후 "<<td.hour();
	}else if(td.hour()<12){
		cout<<"오전 "<<td.hour();
	}else{
		cout<<"오후 "<<td.hour()-12;
	}
	cout<<"시 "<<td.minute()<<"분 "<<td.second()<<"초이다."<<endl<<endl;
	//delay(3000);
	/*
	cout<<"아직 마음의 준비가 안 되었을 테니 5초 후부터 시작하지."<<endl<<endl;
	delay(5000);
	*/
	/*
	system("shutdown -a");
	system("shutdown -s -f -c \"관문을 뚫으면 타이머를 해제시켜 주지. 만약 실패한다면 컴퓨터가 종료될거야.\" -t 480");
	*/
	//cout<<"이제 시작하겠다. 제한시간은 6분이다."<<endl<<endl;
	//delay(1000);
	if (single_mode) {
		cout<<"종목은 숫자 야구. 제한 시간이 매우 짧다."<<endl;
		cout<<"4개의 숫자로 컴퓨터의 암호를 맞히면 승리한다."<<endl<<endl; 
	}
	else {
		cout<<"종목은 숫자 야구. 컴퓨터가 당신을 상대할 것이다."<<endl; 
		cout<<"4개의 숫자로 먼저 상대의 암호를 맞히는 쪽이 승리한다."<<endl<<endl;
	}
	cout<<"    상대의 암호를 추측하여 입력하면 힌트를 줄 것이다."<<endl;
	cout<<"    볼은 숫자는 맞지만 자리가 틀린 것의 개수이다."<<endl;
	cout<<"    스트라이크는 숫자와 자리가 모두 암호와 일치하는 것의 개수이다."<<endl;
	cout<<"    4스트라이크를 달성하면 암호를 맞히게 된다."<<endl<<endl;
	//delay(2500);
	if (!single_mode){
		cout<<"당신의 암호를 정하도록. (0 ~ 9 사이의 서로 다른 자연수 4개 입력 / 입력 예: 0461)"<<endl;
		/*
		for(i=0;i<4;i++){
			Hpitcher[i]=input();
			for(j=0;j<i;j++){
				if(Hpitcher[i]==Hpitcher[j]){
					cout<<"같은 수를 여러 번 입력하지 마라. (0 ~ 9 사이의 수 입력)"<<endl;
					i--;
					break;
				}
			}
		}
		*/
		int* inp=input_line();
		for(i=0;i<4;i++){
			Hpitcher[i]=inp[i];
		}
		free(inp);
		cout<<"당신의 암호 :\t"<<Hpitcher[0]<<"\t"<<Hpitcher[1]<<"\t"<<Hpitcher[2]<<"\t"<<Hpitcher[3]<<endl;
		cout<<"컴퓨터가 당신의 암호를 맞히기 전에 컴퓨터의 암호를 알아맞히면 관문을 통과할 수 있다."<<endl<<endl;
		//delay(1000);
	}
	for(pb=0;pb<10;pb++){
		strike=0;
		ball=0;
		cout<<"------------------------"<<pb+1<<"회------------------------"<<endl;
		cout<<"0 ~ 9 사이의 서로 다른 자연수를 4개 입력하여라. (입력 예: 5893)"<<endl;
		/*
		for(i=0;i<4;i++){
			Hhitter[i]=input();
			for(j=0;j<i;j++){
				if(Hhitter[i]==Hhitter[j]){
					cout<<"같은 수를 여러 번 입력하지 마라. (0 ~ 9 사이의 수 입력)"<<endl;
					i--;
					break;
				}
			}
		}
		*/
		int* inp2=input_line();
		for(i=0;i<4;i++){
			Hhitter[i]=inp2[i];
		}
		free(inp2);
		cout<<"당신의 시도   :\t"<<Hhitter[0]<<"\t"<<Hhitter[1]<<"\t"<<Hhitter[2]<<"\t"<<Hhitter[3]<<endl;
		for(i=0;i<4;i++){
			if(Cpitcher[i]==Hhitter[i]){
				strike++;
			}else if(Cpitcher[i]==Hhitter[(i+1)%4] || Cpitcher[i]==Hhitter[(i+2)%4] || Cpitcher[i]==Hhitter[(i+3)%4]){
				ball++;
			}
		}
		if(strike==0 && ball==0){
			cout<<"\t\t-> 0스트라이크 0볼 (1아웃)"<<endl;
		}else{
			cout<<"\t\t-> "<<strike<<"스트라이크 "<<ball<<"볼"<<endl;
		}
		if(strike==4){
			cout<<endl<<"컴퓨터의 암호를 먼저 완벽하게 맞혀 승리했군."<<endl;
			system("shutdown -a");
			//delay(1000);
			cout<<"타이머를 정지시켰다. 관문을 뚫었으니 컴퓨터를 사용해도 좋다."<<endl;
			//delay(1000);
//			cout<<"Windows 탐색기를 실행해 줄테니 알아서 하도록."<<endl;
//			cout<<"작업 관리자를 실행하는 방법은 다 알고 있겠지?"<<endl;
			system("start explorer.exe");
			system("PAUSE");
			return 0;
		}
		if(!single_mode){
			cout<<"- - - - - - - - - - - - - - - - - - - - - - - - - -"<<endl;
			strike=0;
			ball=0;
			do{
				hitting = true;
				for(i=0;i<4;i++){
					Chitter[i]=rand()%10;
					for(j=0;j<i;j++){
						if(Chitter[i]==Chitter[j]){
							break;
						}
					}
					if(j<i){
						i--;
						continue;
					}
					if(!Cexcept[Chitter[i]]){
						i--;
						continue;
					}
				}
				for(i=0;i<pb;i++){
					Ctemp1=Cumpire[0][i]+Cumpire[1][i];
					Ctemp2=0;
					for(j=0;j<4;j++){
						for(k=0;k<4;k++){
							if(Chitter[j]==Cmemory[k][i]) Ctemp2++;
						}
					}
					if(Ctemp1!=Ctemp2){
						hitting = false;
						break;
					}
					Ctemp2=0;
					for(j=0;j<4;j++){
						if(Chitter[j]==Cmemory[j][i]) Ctemp2++;
					}
					if(Cumpire[0][i]!=Ctemp2){
						hitting = false;
						break;
					}
				}
			}while(!hitting);
			cout<<"컴퓨터의 시도 :";
			for(i=0;i<4;i++){
				cout<<"\t"<<Chitter[i];
				Cmemory[i][pb]=Chitter[i];
			}
			cout<<endl;
			for(i=0;i<4;i++){
				if(Hpitcher[i]==Chitter[i]){
					strike++;
				}else if(Hpitcher[i]==Chitter[(i+1)%4] || Hpitcher[i]==Chitter[(i+2)%4] || Hpitcher[i]==Chitter[(i+3)%4]){
					ball++;
				}
			}
			Cumpire[0][pb]=strike;
			Cumpire[1][pb]=ball;
			if(strike==0 && ball==0){
				cout<<"\t\t-> 0스트라이크 0볼 (1아웃)"<<endl;
				for(i=0;i<4;i++){
					Cexcept[Chitter[i]]=false;
				}
			}else{
				cout<<"\t\t-> "<<strike<<"스트라이크 "<<ball<<"볼"<<endl;
			}
			Ctemp1=strike+ball;
			if(strike==4){
				cout<<endl<<"당신의 암호를 컴퓨터가 먼저 맞혀 패배했군."<<endl;
				cout<<"컴퓨터의 암호 :\t"<<Cpitcher[0]<<"\t"<<Cpitcher[1]<<"\t"<<Cpitcher[2]<<"\t"<<Cpitcher[3]<<endl<<endl;
				system("shutdown -a");
				system("shutdown /s /f /t 10");
				//delay(3000);
				cout<<"관문을 뚫지 못했으니 10초 후에 컴퓨터가 종료될거야."<<endl;
				delay(8000);
				return 0;
			}else if(Ctemp1==4){
				for(i=0;i<10;i++) Cexcept[i]=false;
				for(i=0;i<4;i++) Cexcept[Chitter[i]]=true;
			}
		}
	}
	if(single_mode){
		cout<<endl<<"10회 안에 암호를 맞히지 못했군."<<endl; 
	}
	else {
		cout<<endl<<"양쪽 모두 10회 안에 암호를 맞히지 못하고 비겼군."<<endl;
	}
	cout<<"컴퓨터의 암호 :\t"<<Cpitcher[0]<<"\t"<<Cpitcher[1]<<"\t"<<Cpitcher[2]<<"\t"<<Cpitcher[3]<<endl<<endl;
	//delay(3000);
	cout<<"타이머를 멈추지는 않을 것이니 종료될 때까지 기다리게나."<<endl;
	//delay(2000);
	system("PAUSE");
	return 0;
}
/*
int input(){
	int a;
	while(true) {
		cin>>a;
		if(!cin){
			cin.clear();
			cin.ignore(30,'\n');
			cout<<"자연수를 입력하여라. (0 ~ 9 사이의 수 입력)"<<endl;
		}else if(a<0 || a>9){
			cout<<"범위를 넘어서지 마라. (0 ~ 9 사이의 수 입력)"<<endl;
			cin.clear();
		}
		else break;
	}
	return a;
}
*/
int* input_line(){
	cin.clear();
	char s[30];
	int* r=(int*)malloc(4*sizeof(int));
	bool fail;
	while(true){
		fail=false;
		cin.getline(s, 30);
		for(int i=0;i<4;i++){
			if(s[i]<'0'||s[i]>'9'){
				fail=true;
				cout<<"4자리의 자연수를 입력하여라. (입력 예: 0372)"<<endl;
				break; 
			}
			for (int j=0;j<i;j++){
				if(s[i]==s[j]){
					fail=true;
					cout<<"같은 수를 여러 번 입력하지 마라. (0 ~ 9 사이의 수 입력)"<<endl;
					break;
				}
			}
			if(fail) break;
			r[i]=s[i]-'0';
		}
		if(s[4]!='\0' && !fail){
			fail=true;
			cout<<"4자리의 자연수를 입력하여라. (입력 예: 0372)"<<endl;
		}
		if(fail){
			/*
			for(int i=0;i<4;i++){
				cout<<(int)s[i]<<" ";
			}
			cout<<" debug fail"<<endl;
			*/
			//cin.ignore(30, '\n');
			cin.clear();
		}
		else{
			/*
			for(int i=0;i<4;i++){
				cout<<(int)s[i]<<" ";
			}
			cout<<" debug"<<endl;
			*/
			break;
		}
	}
	cin.clear();
	/*
	for(int i=0;i<4;i++){
		cout<<r[i]<<" ";
	}
	cout<<" int"<<endl;
	*/
	return r;
}
