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
		system("shutdown -s -f -c \"������ ������ Ÿ�̸Ӹ� �������� ����. ���� �����Ѵٸ� ��ǻ�Ͱ� ����ɰž�.\" -t 140");
	else
		system("shutdown -s -f -c \"������ ������ Ÿ�̸Ӹ� �������� ����. ���� �����Ѵٸ� ��ǻ�Ͱ� ����ɰž�.\" -t 360");
	system("title ������ ����");
	cout<<"<������ ����>"<<setw(64)<<setiosflags(ios::right)<<"Number Baseball"<<endl;
	//delay(1000);
	cout<<"��ǻ�͸� ����ϱ� ���ؼ��� �� ������ �վ�߸� �Ѵ�."<<endl;
	//delay(2000);
	if (single_mode)
		cout<<"2�� 20�� �ȿ� ������ ����ϸ� ��ǻ�͸� ����� �� �ְ�, �ƴϸ� ��������ȴ�."<<endl;
	else 
		cout<<"6�� �ȿ� ������ ����ϸ� ��ǻ�͸� ����� �� �ְ�, �ƴϸ� ��������ȴ�."<<endl;
	//delay(2000);
	/*
	cout<<"�̹� Ÿ�̸Ӱ� �۵������Ƿ� ���α׷��� ���� �����ϴ� ���� �ҿ����."<<endl<<endl;
	delay(2500);
	*/
	cout<<"���� �ð��� "<<td.year()<<"�� "<<td.month()<<"�� "<<td.day()<<"�� ";
	if(td.hour()==0){
		cout<<"���� "<<td.hour()+12;
	}else if(td.hour()==12){
		cout<<"���� "<<td.hour();
	}else if(td.hour()<12){
		cout<<"���� "<<td.hour();
	}else{
		cout<<"���� "<<td.hour()-12;
	}
	cout<<"�� "<<td.minute()<<"�� "<<td.second()<<"���̴�."<<endl<<endl;
	//delay(3000);
	/*
	cout<<"���� ������ �غ� �� �Ǿ��� �״� 5�� �ĺ��� ��������."<<endl<<endl;
	delay(5000);
	*/
	/*
	system("shutdown -a");
	system("shutdown -s -f -c \"������ ������ Ÿ�̸Ӹ� �������� ����. ���� �����Ѵٸ� ��ǻ�Ͱ� ����ɰž�.\" -t 480");
	*/
	//cout<<"���� �����ϰڴ�. ���ѽð��� 6���̴�."<<endl<<endl;
	//delay(1000);
	if (single_mode) {
		cout<<"������ ���� �߱�. ���� �ð��� �ſ� ª��."<<endl;
		cout<<"4���� ���ڷ� ��ǻ���� ��ȣ�� ������ �¸��Ѵ�."<<endl<<endl; 
	}
	else {
		cout<<"������ ���� �߱�. ��ǻ�Ͱ� ����� ����� ���̴�."<<endl; 
		cout<<"4���� ���ڷ� ���� ����� ��ȣ�� ������ ���� �¸��Ѵ�."<<endl<<endl;
	}
	cout<<"    ����� ��ȣ�� �����Ͽ� �Է��ϸ� ��Ʈ�� �� ���̴�."<<endl;
	cout<<"    ���� ���ڴ� ������ �ڸ��� Ʋ�� ���� �����̴�."<<endl;
	cout<<"    ��Ʈ����ũ�� ���ڿ� �ڸ��� ��� ��ȣ�� ��ġ�ϴ� ���� �����̴�."<<endl;
	cout<<"    4��Ʈ����ũ�� �޼��ϸ� ��ȣ�� ������ �ȴ�."<<endl<<endl;
	//delay(2500);
	if (!single_mode){
		cout<<"����� ��ȣ�� ���ϵ���. (0 ~ 9 ������ ���� �ٸ� �ڿ��� 4�� �Է� / �Է� ��: 0461)"<<endl;
		/*
		for(i=0;i<4;i++){
			Hpitcher[i]=input();
			for(j=0;j<i;j++){
				if(Hpitcher[i]==Hpitcher[j]){
					cout<<"���� ���� ���� �� �Է����� ����. (0 ~ 9 ������ �� �Է�)"<<endl;
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
		cout<<"����� ��ȣ :\t"<<Hpitcher[0]<<"\t"<<Hpitcher[1]<<"\t"<<Hpitcher[2]<<"\t"<<Hpitcher[3]<<endl;
		cout<<"��ǻ�Ͱ� ����� ��ȣ�� ������ ���� ��ǻ���� ��ȣ�� �˾Ƹ����� ������ ����� �� �ִ�."<<endl<<endl;
		//delay(1000);
	}
	for(pb=0;pb<10;pb++){
		strike=0;
		ball=0;
		cout<<"------------------------"<<pb+1<<"ȸ------------------------"<<endl;
		cout<<"0 ~ 9 ������ ���� �ٸ� �ڿ����� 4�� �Է��Ͽ���. (�Է� ��: 5893)"<<endl;
		/*
		for(i=0;i<4;i++){
			Hhitter[i]=input();
			for(j=0;j<i;j++){
				if(Hhitter[i]==Hhitter[j]){
					cout<<"���� ���� ���� �� �Է����� ����. (0 ~ 9 ������ �� �Է�)"<<endl;
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
		cout<<"����� �õ�   :\t"<<Hhitter[0]<<"\t"<<Hhitter[1]<<"\t"<<Hhitter[2]<<"\t"<<Hhitter[3]<<endl;
		for(i=0;i<4;i++){
			if(Cpitcher[i]==Hhitter[i]){
				strike++;
			}else if(Cpitcher[i]==Hhitter[(i+1)%4] || Cpitcher[i]==Hhitter[(i+2)%4] || Cpitcher[i]==Hhitter[(i+3)%4]){
				ball++;
			}
		}
		if(strike==0 && ball==0){
			cout<<"\t\t-> 0��Ʈ����ũ 0�� (1�ƿ�)"<<endl;
		}else{
			cout<<"\t\t-> "<<strike<<"��Ʈ����ũ "<<ball<<"��"<<endl;
		}
		if(strike==4){
			cout<<endl<<"��ǻ���� ��ȣ�� ���� �Ϻ��ϰ� ���� �¸��߱�."<<endl;
			system("shutdown -a");
			//delay(1000);
			cout<<"Ÿ�̸Ӹ� �������״�. ������ �վ����� ��ǻ�͸� ����ص� ����."<<endl;
			//delay(1000);
//			cout<<"Windows Ž���⸦ ������ ���״� �˾Ƽ� �ϵ���."<<endl;
//			cout<<"�۾� �����ڸ� �����ϴ� ����� �� �˰� �ְ���?"<<endl;
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
			cout<<"��ǻ���� �õ� :";
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
				cout<<"\t\t-> 0��Ʈ����ũ 0�� (1�ƿ�)"<<endl;
				for(i=0;i<4;i++){
					Cexcept[Chitter[i]]=false;
				}
			}else{
				cout<<"\t\t-> "<<strike<<"��Ʈ����ũ "<<ball<<"��"<<endl;
			}
			Ctemp1=strike+ball;
			if(strike==4){
				cout<<endl<<"����� ��ȣ�� ��ǻ�Ͱ� ���� ���� �й��߱�."<<endl;
				cout<<"��ǻ���� ��ȣ :\t"<<Cpitcher[0]<<"\t"<<Cpitcher[1]<<"\t"<<Cpitcher[2]<<"\t"<<Cpitcher[3]<<endl<<endl;
				system("shutdown -a");
				system("shutdown /s /f /t 10");
				//delay(3000);
				cout<<"������ ���� �������� 10�� �Ŀ� ��ǻ�Ͱ� ����ɰž�."<<endl;
				delay(8000);
				return 0;
			}else if(Ctemp1==4){
				for(i=0;i<10;i++) Cexcept[i]=false;
				for(i=0;i<4;i++) Cexcept[Chitter[i]]=true;
			}
		}
	}
	if(single_mode){
		cout<<endl<<"10ȸ �ȿ� ��ȣ�� ������ ���߱�."<<endl; 
	}
	else {
		cout<<endl<<"���� ��� 10ȸ �ȿ� ��ȣ�� ������ ���ϰ� ��屺."<<endl;
	}
	cout<<"��ǻ���� ��ȣ :\t"<<Cpitcher[0]<<"\t"<<Cpitcher[1]<<"\t"<<Cpitcher[2]<<"\t"<<Cpitcher[3]<<endl<<endl;
	//delay(3000);
	cout<<"Ÿ�̸Ӹ� �������� ���� ���̴� ����� ������ ��ٸ��Գ�."<<endl;
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
			cout<<"�ڿ����� �Է��Ͽ���. (0 ~ 9 ������ �� �Է�)"<<endl;
		}else if(a<0 || a>9){
			cout<<"������ �Ѿ�� ����. (0 ~ 9 ������ �� �Է�)"<<endl;
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
				cout<<"4�ڸ��� �ڿ����� �Է��Ͽ���. (�Է� ��: 0372)"<<endl;
				break; 
			}
			for (int j=0;j<i;j++){
				if(s[i]==s[j]){
					fail=true;
					cout<<"���� ���� ���� �� �Է����� ����. (0 ~ 9 ������ �� �Է�)"<<endl;
					break;
				}
			}
			if(fail) break;
			r[i]=s[i]-'0';
		}
		if(s[4]!='\0' && !fail){
			fail=true;
			cout<<"4�ڸ��� �ڿ����� �Է��Ͽ���. (�Է� ��: 0372)"<<endl;
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
