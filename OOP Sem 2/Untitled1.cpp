#include<iostream>
#include<math.h>
using namespace std;
class Point{
	int x;
	int y;
	public:
		Point(int a,int b){
			x=a;
			y=b;
		}
		double distance(Point &temp)
		{
			double distance =sqrt((x-temp.x)*(x-temp.x)+(y-temp.y)*(y-temp.y));
			return distance;
			
		}
};
int main(){
	Point p1(0,0),p2(5,5);
	cout<<p1.distance(p2)<<endl;
	return 0;
}
