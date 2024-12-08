#include<iostream>
using namespace std;
const int INSIDE=0;
const int LEFT=1;
const int RIGHT=2;
const int BOTTOM=4;
const int TOP =8;

const int x_min=10,y_min=10,x_max=200,y_max=200;

int computeCode(int x,int y){
	int code=INSIDE;
	if(x<x_min) code|=LEFT;
	else if (x>x_max)code|=RIGHT;
	if(y<y_min) code|=BOTTOM;
	else if(y>y_max)code|=TOP;
	return code;
}
void cohenSutherlandClip(int x1,int y1,int x2,int y2){
	int code1=computeCode(x1,y1);
	int code2=computeCode(x2,y2);
	bool accept=false;
	
	while (true){
		if((code1==0)&&(code2==0)){
			accept=true;
			break;
		}else if(code1&code2){
			break;
		}else{
			int code_out;
			int x,y;
			
			if(code1!=0)code_out=code1;
			else code_out=code2;
			
			if(code_out&TOP){
			x=x1+(x2-x1)*(y_max-y1)	/(y2-y1);
			y=y_max;
			}else if (code_out &BOTTOM){
				x=y1+(y2-y1)*(y_min-y1)/(y2-y1);
				y=y_min;
			}else if(code_out&RIGHT){
				y=y1+(y2-y1)*(x_max-x1)/(x2-x1);
				x=x_max;
			}else if(code_out &LEFT){
				y=y1+(y2-y1)*(x_min-x1)/(x2-x1);
				x=x_min;
			}
			if(code_out==code1){
				x1=x;
				y1=y;
				code1=computeCode(x1,y1);
			}else{
				x2=x;
				y2=y;
				code2=computeCode(x2,y2);
			}
		}
	}
	if(accept){
		cout<<"Garis setelah clipping:("<<x1<<","<<y1<<")ke("<<x2<<","<<y2<<")"<<endl;
	}else {
		cout<<"Garis berada di luar area tampilan."<<endl;
	}
}
int main(){
	int x1,y1,x2,y2;
	cout<<"Masukkan koordinat titik awal(x1,y1):";
	cin>>x1>>y1;
	cout<<"Masukkan koordinat titik akhir(x2,y2):";
	cin>>x2>>y2;
	
	cohenSutherlandClip(x1,y1,x2,y2);
	
	return 0;
}
	