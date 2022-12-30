#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
typedef map<string,int> mapType;
mapType populationMap;
populationMap.insert(pair<string, int>("Maharashtra", 902534));
populationMap.insert(pair<string, int>("Rajasthan", 324569));
populationMap.insert(pair<string, int>("Karanataka", 123569));
populationMap.insert(pair<string, int>("Punjab", 753226));
populationMap.insert(pair<string, int>("West Bengal", 123567));
mapType::iterator iter;
cout<<"========Population of states in India==========\n";
cout<<"\n Size of populationMap"<<populationMap.size()<<"\n";
string state_name;
cout<<"\n Enter name of the state :";
cin>>state_name;
iter = populationMap.find(state_name);
if( iter!= populationMap.end() )
 cout<<state_name<<" 's population is "
 <<iter->second ;
else
cout<<"Key is not populationMap"<<"\n";
populationMap.clear();
}
