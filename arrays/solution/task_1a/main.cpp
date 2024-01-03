#include <iostream>

using namespace std;

int main()
{ string classes[]= {"Math","English","Science","Social Studies","Spanish"};
classes[4]= "French";
cout<<classes[0]<<endl;
for(int i =0;i<3;i++){
    cout<<classes[i]<<endl;

}
string e= "Science";
int j = 0;
while(j<sizeof(classes)){
      if(classes[j]== e){
        break;
        }
        j++;
}
cout<< "The index of " << e << " is " << j <<endl;

    return 0;
}
