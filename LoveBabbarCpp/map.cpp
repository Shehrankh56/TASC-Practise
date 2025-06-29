#include<bits/stdc++.h>
using namespace std;
int main(){
    //creation 
    unordered_map<string,int>mapping;
    //insertion
    pair<string ,int>p=make_pair("love",25);
    pair<string,int>q("Shehran",20);
    pair<string,int>r;
    r.first="Arham";
    r.second=34;
    //insert to map
    mapping.insert(p);
    mapping.insert(q);
    mapping.insert(r);
    
    cout<<"Size of Map:"<<mapping.size()<<endl;
    //Access
    cout<<mapping.at("love")<<endl;
    cout<<mapping["Shehran"]<<endl;
    //searching
    cout<<mapping.count("love")<<endl;
    cout<<mapping.count("sheraa")<<endl;
    if(mapping.find("Shehran")!=mapping.end()){
        cout<<"Found"<<endl;
    }else{
        cout<<"Not Found"<<endl;
    }
    cout<<"Size of Map:"<<mapping.size()<<endl;
    cout<<mapping["Khan"]<<endl;
    cout<<"Size of Map:"<<mapping.size()<<endl;
    cout<<mapping["Khan"]<<endl;
    // string str="shehran";
    // sort(str.begin(),str.end());
    // cout<<str;


}