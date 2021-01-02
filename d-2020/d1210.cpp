//
// Created by akio on 2020/12/10.
//
#include <vector>
using namespace std;
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0,ten = 0;
        for(const int &b:bills){
            if(b==5){
                ++five;
            }else if(b==10){
                if(five>0){
                    --five;
                }else
                    return false;
                ++ten;
            }else if(b==20){
                if(ten>0 & five > 0){
                    --ten;
                    --five;
                }else if(five>2){
                    five -=3;
                }else
                    return false;
            }
        }
        return true;
    }
};