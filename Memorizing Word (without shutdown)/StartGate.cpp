#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <iomanip>
#include <windows.h>
#include <strsafe.h>
#include "today.h"
using namespace std;

void error(int a);

void delay(clock_t wait)
{
	clock_t goal;
	goal=wait+clock();
	while(goal>=clock());
}

int main(){
	// ���ܾ� �ϱ� 2.1 ���� ž��, �ý��� ���� ��� ����
	today td;
	ifstream fin;
	int n=0, score=0, a=0, b=0, i, j;
	bool o=false;
	bool comment=false;
	bool win=false; 
	char line[255];
	string temp;
	string word[10000];
	string meaning[10000][4];
	int question[10000];
	int wrong[10000], w=0;
	string answer;
	string comment_mark="\"\"\"";
	
	system("taskkill /f /im explorer.exe");
		
	system("title ������ ����");
	cout<<"<������ ����>"<<setw(64)<<setiosflags(ios::right)<<"Memorizing Word"<<endl;
	
	// Get "words2.txt" from a directory where this program exists.
	// (Do not use GetCurrentDirectoryW method!)
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH);
	string buffer2 = buffer;
	buffer2 = buffer2.substr(0, buffer2.find_last_of('\\')).append("\\words2.txt").c_str();
	
	fin.open(buffer2.c_str());
	if(fin.fail()){
		error(22);
		return 1;
	}
	while(!fin.eof() && n<=10000){
		fin.getline(line,510,'\n');
		if(fin.fail()){
			error(0);
			return 1;
		}
		temp=line;
		if(temp.length()>=3 && temp.substr(0,3)==comment_mark.substr(0,3)){
			if(comment) comment=false;
			else comment=true;
			continue;
		}
		if(comment){
			// comment out multiple lines
			continue;
		}
		if(temp[0]=='#') {
			// comment out one line
			continue;
		}
		if(temp.find(':')==string::npos || temp.find_first_of(':')!=temp.find_last_of(':')){
			error(3);
			return 1;
		}
		if(temp.find(':')==0 || temp.find(':')==temp.length()-1){
			error(5);
			return 1;
		}
		word[n]=temp.substr(0,temp.find(':'));
		temp=temp.substr(temp.find(':')+1);
		a=0;
		b=0;
		i=0;
		while((a=temp.find(',',b))!=string::npos && i<3){ // temp���� b��ġ �ڿ� ','�� �ְ�(',' ��ġ�� a�� ����), ó���� ���� ������ 3�� �����̸� �ݺ�
			meaning[n][i]=temp.substr(b,a-b); // meaning�� i��° �ڸ��� temp�� i��° ��(b ��ġ���� a-b�� ���̸�ŭ �����Ͽ�) ����
			if(meaning[n][i].find(':',0)!=string::npos || meaning[n][i].empty()){ // meaning[n][i]���� ':'�� �߰ߵǰų� ��� ������(','�� �������� ������) ����ó��
				error(4);
				return 1;
			}
			b=a+1; // ',' ���� ��ġ�� �Ѿ
			i++; // i���� �� ó�� �Ϸ�
		}
		meaning[n][i]=temp.substr(b,string::npos); // ','�� �پ����� ���� ������ �� ����
		if(meaning[n][i].find(',',0)!=string::npos){ // meaning[n][i](������ ��)���� ','�� �߰ߵǸ�(���� 5�� �̻� ����) ����ó��
			error(2);
			return 1;
		}else if(meaning[n][i].find(':',0)!=string::npos){ // meaning[n][i](������ ��)���� ':'�� �߰ߵǸ� ����ó��
			error(4);
			return 1;
		}else if(meaning[n][i].empty()){ // meaning[n][i](������ ��)�� ��� ������(�� ���� ���ʿ��� ','�� �پ� ������) ����ó��
			error(5);
			return 1;
		}
		n++;
	}
	if(fin.eof() && comment){
		error(6);
		return 1;
	}
	if(fin.eof() && n==0){
		error(7);
		return 1;
	}
	fin.close();
	
	//delay(1000);
	cout<<"��ǻ�͸� ����ϱ� ���ؼ��� �� ������ �վ�߸� �Ѵ�."<<endl;
	//delay(2000);
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
	
	int c=20;
	if (n < c) c = n;
	if ((c/4)*3 <= 0) {
		error(34);
		return 1;
	}
	cout<<"������ ���ܾ� �� ���߱�. ";
	cout<<c<<"������ ��� Ǯ�� ����Ѵ�."<<endl<<endl; 
	cout<<"    ���õǴ� ���� �ܾ��� ���� �ѱ۷� �����."<<endl;
	cout<<"    ����� �Ȱ��� ����߸� ���� ������ �����ȴ�."<<endl;
	cout<<"    ���� ���� ���� �ܾ�� ��� �ϳ��� ������ �ȴ�."<<endl;
	cout<<"    ����(' ')�� �ᵵ �ǰ� �� �ᵵ �ȴ�. �󸶵���."<<endl<<endl;
	
	srand((unsigned)time(NULL));
	for(i=0;i<c;i++){
		bool retry = false;
		do {
			retry = false;
			question[i]=rand()%n;
			for(j=0;j<i;j++){
				if(question[i]==question[j]) {
					retry = true;
					break;
				}
			}
		} while(retry);
		cout<<i+1<<". "<<word[question[i]]<<" : ";
		cin.getline(line,255,'\n');
		answer=line;
		o=false;
		while((a=answer.find(' ',0))!=string::npos){
			answer.erase(a,1); // ' '(����) ����
		}
		for(j=0;j<4;j++){ // �� ���� �� �� �ϳ��� ��ġ�ϴ� ���� �ִ��� Ȯ��
			if(meaning[question[i]][j].empty()) break;
			temp=meaning[question[i]][j];
			while((a=temp.find(' ',0))!=string::npos) temp.erase(a,1); // ' '(����) ����
			if(answer==temp){
				o=true; // ����
				break;
			}
		}
		if(cin.fail() || answer.empty()){
			cin.clear();
			cout<<"Ʋ�ȴ�. �Է��� �ȹٷ� �϶�."<<endl;
			cout<<"������ ";
			for(j=0;j<4;j++){
				if(meaning[question[i]][j].empty()) break;
				cout<<"'"<<meaning[question[i]][j]<<"'";
				if(j<3 && !meaning[question[i]][j+1].empty()) cout<<",";
			}
			cout<<"�̴�."<<endl<<endl;
			wrong[w]=question[i]; // Ʋ�� ���� ��ȣ ����
			w++; // Ʋ�� ���� ���� ����
			continue;
		}else if(!o){
			cout<<"Ʋ�ȴ�. ������ ";
			for(j=0;j<4;j++){
				if(meaning[question[i]][j].empty()) break;
				cout<<"'"<<meaning[question[i]][j]<<"'";
				if(j<3 && !meaning[question[i]][j+1].empty()) cout<<",";
			}
			cout<<"�̴�."<<endl<<endl;
			wrong[w]=question[i]; // Ʋ�� ���� ��ȣ ����
			w++; // Ʋ�� ���� ���� ����
			continue;
		}else{
			cout<<"�����̴�."<<endl<<endl;
			score++;
		}
	}
	cout<<"��� ������ Ǯ����. ����� �˷�����."<<endl;
	int result=(double(score)/double(c))*100;
	if(result==100){
		cout<<"�����! ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
	}else if(result>=90){
		cout<<"�Ǹ��ϴ�! ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
	}else if(result>=80){
		cout<<"���ߴ�. ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
		cout<<"���ݸ� �� �����ϸ� ���������� ����� �� �ְڱ�."<<endl;
	}else if(result>=70){
		cout<<"�ƽ��ƽ��ϱ�. ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
		cout<<"�̹� ����� ��� �����ϸ� �и� ���� ���̴�."<<endl;
	}else if(result>=60){
		cout<<"���� ������. ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
		cout<<"Ʋ�� ������ ���� ���� �����ض�."<<endl;
	}else if(result>=40){
		cout<<"�ʹ� ����. ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
		cout<<"���°� �ɰ��ϱ�. ���� �����ض�."<<endl;
	}else{
		cout<<"�������. ������� "<<result<<"%�̴�. ("<<c<<"���� �� "<<score<<"���� ����)"<<endl;
		cout<<"�־��̴�. ���θ� �Ϸ��� ������ �ִ� ���ΰ�?"<<endl;
	}
	if(w>0){
		cout<<endl<<"Ʋ�� �ܾ� : "<<word[wrong[0]]<<endl;
		for(i=1;i<w;i++) cout<<"            "<<word[wrong[i]]<<endl;
	}
	win = true;
	
	cout<<endl<<"������ �վ���. ���� ��ǻ�͸� ����ص� ����."<<endl;
	
	system("start explorer.exe");
	system("PAUSE");
	return 0;
}

void error(int a) {
	cout<<"���� ������ �ִ� �� ����. (���� �ڵ� "<<a<<")"<<endl;
	cout<<"�����ڿ��� ���� �����ض�."<<endl;
	system("PAUSE");
} 
