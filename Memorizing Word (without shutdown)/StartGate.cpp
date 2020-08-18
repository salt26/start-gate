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
	// 영단어 암기 2.1 버전 탑재, 시스템 종료 기능 제거
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
		
	system("title 시작의 관문");
	cout<<"<시작의 관문>"<<setw(64)<<setiosflags(ios::right)<<"Memorizing Word"<<endl;
	
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
		while((a=temp.find(',',b))!=string::npos && i<3){ // temp에서 b위치 뒤에 ','가 있고(',' 위치를 a에 저장), 처리한 뜻의 개수가 3개 이하이면 반복
			meaning[n][i]=temp.substr(b,a-b); // meaning의 i번째 자리에 temp의 i번째 뜻(b 위치부터 a-b의 길이만큼 추출하여) 저장
			if(meaning[n][i].find(':',0)!=string::npos || meaning[n][i].empty()){ // meaning[n][i]에서 ':'가 발견되거나 비어 있으면(','가 연속으로 있으면) 에러처리
				error(4);
				return 1;
			}
			b=a+1; // ',' 다음 위치로 넘어감
			i++; // i개의 뜻 처리 완료
		}
		meaning[n][i]=temp.substr(b,string::npos); // ','가 붙어있지 않은 마지막 뜻 저장
		if(meaning[n][i].find(',',0)!=string::npos){ // meaning[n][i](마지막 뜻)에서 ','이 발견되면(뜻을 5개 이상 쓰면) 에러처리
			error(2);
			return 1;
		}else if(meaning[n][i].find(':',0)!=string::npos){ // meaning[n][i](마지막 뜻)에서 ':'이 발견되면 에러처리
			error(4);
			return 1;
		}else if(meaning[n][i].empty()){ // meaning[n][i](마지막 뜻)이 비어 있으면(줄 끝에 불필요한 ','가 붙어 있으면) 에러처리
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
	cout<<"컴퓨터를 사용하기 위해서는 이 관문을 뚫어야만 한다."<<endl;
	//delay(2000);
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
	
	int c=20;
	if (n < c) c = n;
	if ((c/4)*3 <= 0) {
		error(34);
		return 1;
	}
	cout<<"종목은 영단어 뜻 맞추기. ";
	cout<<c<<"문제를 모두 풀면 통과한다."<<endl<<endl; 
	cout<<"    제시되는 영어 단어의 뜻을 한글로 적어라."<<endl;
	cout<<"    정답과 똑같이 적어야만 맞은 것으로 인정된다."<<endl;
	cout<<"    답이 여러 개인 단어는 어느 하나만 맞혀도 된다."<<endl;
	cout<<"    띄어쓰기(' ')는 써도 되고 안 써도 된다. 얼마든지."<<endl<<endl;
	
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
			answer.erase(a,1); // ' '(띄어쓰기) 제거
		}
		for(j=0;j<4;j++){ // 네 개의 뜻 중 하나라도 일치하는 것이 있는지 확인
			if(meaning[question[i]][j].empty()) break;
			temp=meaning[question[i]][j];
			while((a=temp.find(' ',0))!=string::npos) temp.erase(a,1); // ' '(띄어쓰기) 제거
			if(answer==temp){
				o=true; // 정답
				break;
			}
		}
		if(cin.fail() || answer.empty()){
			cin.clear();
			cout<<"틀렸다. 입력을 똑바로 하라."<<endl;
			cout<<"정답은 ";
			for(j=0;j<4;j++){
				if(meaning[question[i]][j].empty()) break;
				cout<<"'"<<meaning[question[i]][j]<<"'";
				if(j<3 && !meaning[question[i]][j+1].empty()) cout<<",";
			}
			cout<<"이다."<<endl<<endl;
			wrong[w]=question[i]; // 틀린 문제 번호 저장
			w++; // 틀린 문제 개수 증가
			continue;
		}else if(!o){
			cout<<"틀렸다. 정답은 ";
			for(j=0;j<4;j++){
				if(meaning[question[i]][j].empty()) break;
				cout<<"'"<<meaning[question[i]][j]<<"'";
				if(j<3 && !meaning[question[i]][j+1].empty()) cout<<",";
			}
			cout<<"이다."<<endl<<endl;
			wrong[w]=question[i]; // 틀린 문제 번호 저장
			w++; // 틀린 문제 개수 증가
			continue;
		}else{
			cout<<"정답이다."<<endl<<endl;
			score++;
		}
	}
	cout<<"모든 문제를 풀었군. 결과를 알려주지."<<endl;
	int result=(double(score)/double(c))*100;
	if(result==100){
		cout<<"놀랍군! 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
	}else if(result>=90){
		cout<<"훌륭하다! 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
	}else if(result>=80){
		cout<<"잘했다. 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
		cout<<"조금만 더 공부하면 안정적으로 통과할 수 있겠군."<<endl;
	}else if(result>=70){
		cout<<"아슬아슬하군. 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
		cout<<"이번 결과가 어떻든 공부하면 분명 오를 것이다."<<endl;
	}else if(result>=60){
		cout<<"아직 부족해. 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
		cout<<"틀린 문제를 보고 당장 공부해라."<<endl;
	}else if(result>=40){
		cout<<"너무 낮아. 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
		cout<<"상태가 심각하군. 당장 공부해라."<<endl;
	}else{
		cout<<"형편없군. 정답률은 "<<result<<"%이다. ("<<c<<"문제 중 "<<score<<"문제 정답)"<<endl;
		cout<<"최악이다. 공부를 하려는 의지는 있는 것인가?"<<endl;
	}
	if(w>0){
		cout<<endl<<"틀린 단어 : "<<word[wrong[0]]<<endl;
		for(i=1;i<w;i++) cout<<"            "<<word[wrong[i]]<<endl;
	}
	win = true;
	
	cout<<endl<<"관문을 뚫었다. 이제 컴퓨터를 사용해도 좋다."<<endl;
	
	system("start explorer.exe");
	system("PAUSE");
	return 0;
}

void error(int a) {
	cout<<"뭔가 문제가 있는 것 같군. (오류 코드 "<<a<<")"<<endl;
	cout<<"개발자에게 당장 연락해라."<<endl;
	system("PAUSE");
} 
