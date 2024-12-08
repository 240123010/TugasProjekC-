#include <iostream>
#include <vector>
using namespace std;
void delate (vector<pair<int,int>>& points,double scaleFactor){
	for(auto&point:points){
		point.first=static_cast<int>(point.first*scaleFactor);
		point.second=static_cast<int>(point.second*scaleFactor);
	}
}
void printPoints(const vector<pair<int,int>>&points) {
	for(const auto&point:points){
		cout<<"("<<point.first<<","<<point.second<<")"<<endl;
	}
}
int main(){
	vector<pair<int,int>>object={{1,1},{2,3},{3,1}};
	
	cout<<"koordinat awal objek:"<<endl;
	printPoints(object);
	
	double scaleFactor;
	cout<<"Masukkan factor skala untuk dilatasi:";
	cin>>scaleFactor;
	
	delate(object,scaleFactor);
	
	cout<<"koordinat setelah dilatasi:"<<endl;
	printPoints(object);
	
	return 0;
	
	}