#include<bits/stdc++.h>
using namespace std;

struct banker{
 int id;
 int maxNeed;
 int allocation;
 int currentNeed;
 bool isCompleted = false;
};

void bankerAlgo(struct banker b[],int total_resources, int total_processes){
  // 1 Calculate current need of all process
  for(int i = 0;i<total_processes;i++) b[i].currentNeed = b[i].maxNeed - b[i].allocation;
  // 2 Calculate available resource for starting
  int totalAllocation = 0;
  for(int i = 0;i<total_processes;i++) totalAllocation += b[i].allocation;
  int remainingResources = total_resources - totalAllocation;
  // 3 Calulate the process and if increment the remaining resources after
  // executing a process
  bool flag = true;
  while(flag){
    bool processFound = false;
    for(int i = 0;i<total_processes;i++){
        if(b[i].currentNeed<=remainingResources && b[i].isCompleted == false){
           processFound = true;
           b[i].isCompleted = true;
           remainingResources += b[i].allocation;
           cout<<"P"<<b[i].id<<"->";
           break;
        }
    }
    if(processFound == false) flag = false;
  }
  bool isSafeSequence;
  for(int i = 0;i<total_processes;i++){
    if(b[i].isCompleted == false){
        isSafeSequence = false;
    }
  }
  if(isSafeSequence) cout<< "\nSafe Sequence"<<endl;
  else cout<<"\nUnsafe Sequence"<<endl;
}


int main(){
    int total_resources;
    int total_processes;
    cout<<"\nEnter the total process = ";
    cin>> total_processes;
    cout<<"\nEnter the total resourse = ";
    cin>>total_resources;

    struct banker b[total_processes];
    

    for(int i = 0;i<total_processes;i++){
        cout<<endl;
        int p,a;
        cout<<"Enter the P"+to_string(i+1)+" Max Allocation = ";
        cin>>p;
        cout<<"Enter the P"+to_string(i+1)+" Allocation = ";
        cin>>a;
        b[i].maxNeed = p;
        b[i].allocation = a;
        b[i].id = i+1;
    }
    bankerAlgo(b,total_resources,total_processes);
    
}

