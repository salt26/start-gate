//#ifndef TODAY_H
//#define TODAY_H
#include <time.h>
class today{
private:
	time_t t;
	time_t d;
	time_t d2;
	time_t h;
	time_t m;
	time_t s;
	int ye;
	int mo;
	int da;
	int ho;
	int mi;
	int se;
	bool isL;
	bool isN;
	time_t a1(){
		t=time(0)+32400;
		return t;
	}
	time_t a2(){
		t=a1();
		d2=t%(60*60*24);
		return d2;
	}
	time_t a3(){
		t=a1();
		d2=a2();
		d=t-d2;
		d=d/(60*60*24);
		return d;
	}
public: // int year(), month(), day(), hour(), minute(), second() // bool isLY(int Y), isNM(int Y, int M, int D)
	bool isLY(int Y){
		isL=true; // ������ �� true ��ȯ
		if(Y%4!=0 || (Y%4==0 && Y%100==0 && Y%400!=0)){
			isL=false; // ������ �ƴ� �� false ��ȯ
		}
		return isL;
	}
	bool isNM(int Y, int M, int D){
		isN=false; // ���� ���� �ƴ� �� false ��ȯ
		if(((M==1 || M==3 || M==5 || M==7 || M==8 || M==10 || M==12) && D>=31) || ((M==4 || M==6 || M==9 || M==11) && D>=30) || (M==2 && !isLY(Y) && D>=28) || (M==2 && isLY(Y) && D>=29)){
			isN=true; // ���� �޷� �Ѿ �� true ��ȯ (�� ���� ������ ��¥�� ���� true ��ȯ)
		}
		return isN;
	}
	int year(){
		ye=1970;
		d=a3();
		while((!isLY(ye) && d>=365) || (isLY(ye) && d>=366)){ // d�� �� �� ���Ϸ� ���� ������ �ݺ�
			if(!isLY(ye)){ // ������ �ƴ� ��
				d-=365;
				ye++;
			}else{ // ������ ��
				d-=366;
				ye++;
			}
		}
		return ye;
	}
	int month(){
		ye=1970;
		d=a3();
		while((!isLY(ye) && d>=365) || (isLY(ye) && d>=366)){
			if(!isLY(ye)){
				d-=365;
				ye++;
			}else{
				d-=366;
				ye++;
			}
		}
		mo=1;
		while(isNM(ye, mo, d)){ // d�� �� �� ���Ϸ� ���� ������ �ݺ�
			if(mo==1 || mo==3 || mo==5 || mo==7 || mo==8 || mo==10 || mo==12){ // �� ���� 31���� ��
				d-=31;
				mo++;
			}else if(mo==4 || mo==6 || mo==9 || mo==11){ // �� ���� 30���� ��
				d-=30;
				mo++;
			}else if(mo==2 && !isLY(ye)){ // 2��(�� ���� 28���� ��)
				d-=28;
				mo++;
			}else{ // 2��(�� ���� 29���� ��(����))
				d-=29;
				mo++;
			}
		}
		return mo;
	}
	int day(){
		ye=1970;
		d=a3();
		while((!isLY(ye) && d>=365) || (isLY(ye) && d>=366)){
			if(!isLY(ye)){
				d-=365;
				ye++;
			}else{
				d-=366;
				ye++;
			}
		}
		mo=1;
		while(isNM(ye, mo, d)){
			if(mo==1 || mo==3 || mo==5 || mo==7 || mo==8 || mo==10 || mo==12){
				d-=31;
				mo++;
			}else if(mo==4 || mo==6 || mo==9 || mo==11){
				d-=30;
				mo++;
			}else if(mo==2 && !isLY(ye)){
				d-=28;
				mo++;
			}else{
				d-=29;
				mo++;
			}
		}
		da=1;
		while(d>0){ // d�� 0���� �� ������ �ݺ�
			d--;
			da++;
		}
		return da;
	}
	int hour(){
		ho=0;
		d2=a2();
		h=(d2-(d2%3600))/3600;
		while(h>0){
			h--;
			ho++;
		}
		return ho;
	}
	int minute(){
		mi=0;
		d2=a2();
		m=((d2%3600)-(d2%60))/60;
		while(m>0){
			m--;
			mi++;
		}
		return mi;
	}
	int second(){
		se=0;
		d2=a2();
		s=d2%60;
		while(s>0){
			s--;
			se++;
		}
		return se;
	}
};
//#endif