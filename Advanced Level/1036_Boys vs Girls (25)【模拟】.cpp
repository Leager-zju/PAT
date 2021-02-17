#include<string>
#include<iostream>
using namespace std;

struct info{
    string name,id;
    int grade;
    char gender;
}male,female,temp;

int minmale=101;
int maxfemale=-1;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>temp.name>>temp.gender>>temp.id>>temp.grade;
        if(temp.gender=='M'){
            if(temp.grade<minmale){
                minmale=temp.grade;
                male=temp;
            }
        }
        else if(temp.gender=='F'){
            if(temp.grade>maxfemale){
                maxfemale=temp.grade;
                female=temp;
            }
        }
    }
    
    if(maxfemale==-1) cout<<"Absent"<<endl;
    else cout<<female.name<<" "<<female.id<<endl;
    if(minmale==101) cout<<"Absent"<<endl;
    else cout<<male.name<<" "<<male.id<<endl;
    if(maxfemale==-1||minmale==101) cout<<"NA";
    else cout<<maxfemale-minmale;
}
