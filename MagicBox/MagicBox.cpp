
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

bool compare(int array1[], int array2[]){

    if((array1[0] != array2[0])||
       (array1[1] != array2[1])||
       (array1[2] != array2[2]))
        return false;
    return true;
}

int main() {
    
    int max = 0, tmp = 0, cr = 0, cy = 0, cb = 0;
    int xyz[3] = {0}, currCount[3] = {0}, diff[3] = {0};
    
    string s;
    cin>>xyz[0]>>xyz[1]>>xyz[2];
    sort(xyz, xyz + 3);
    cin>>s;
    
    for(int i = 0; i < s.size(); i++){
    
        if(s[i] == 'R')  cr++;
        else if(s[i] == 'Y') cy++;
        else if(s[i] == 'B') cb++;
        
        currCount[0] = cr;
        currCount[1] = cy;
        currCount[2] = cb;
        
        sort(currCount, currCount + 3);
        diff[0] = currCount[1] - currCount[0];
        diff[1] = currCount[2] - currCount[1];
        diff[2] = currCount[2] - currCount[0];
        sort(diff, diff + 3);
        
        if(!compare(xyz, diff)){
        
            tmp++;
            if(tmp > max) max = tmp;
        }
        
        else{
            
            tmp++;
            if(tmp > max) max = tmp;
            tmp = 0;
            cr = 0;
            cy = 0;
            cb = 0;
        }
    }
    
    cout<<max;
    
    return 0;
}