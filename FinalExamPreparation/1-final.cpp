#include<bits/stdc++.h>
using namespace std;
int a[]= {0,1,2,3,4,5,6,7,8,9,12,10};
int a_len=sizeof(a)/sizeof(a[0]);

bool check(int m,int find) {
	return find<=a[m];
}
int bs(int l,int r,int find) {
	while(l<r) {
		int m=(l+r)/2;
		if(check(m,find))
			r=m;
		else
			l=m+1;
	}
	return l;
}
bool cmp(int a,int b)
{
	return a>b;
} 
int main() {
	//先排序，再查找
	sort(a,a+a_len);//小到大
//	sort(a,a+a_len,cmp);//大到小 
	for(int i=0; i<a_len; i++)
		cout<<a[i]<<" ";
	//查找 
	cout<<endl;
	while(1) {
		int num;
		cin>>num;
		cout<<"bs = "<<bs(0,a_len-1,num)<<endl;
		cout<<"binary_search = "<<binary_search(a,a+a_len,num)<<endl;
		cout<<"lower_bound - a = "<<lower_bound(a,a+a_len,num)-a<<endl;//>=find的第一个下标 
		cout<<"upper_bound - a = "<<upper_bound(a,a+a_len,num)-a<<endl;//>find的第一个下标
	}
	return 0;
}