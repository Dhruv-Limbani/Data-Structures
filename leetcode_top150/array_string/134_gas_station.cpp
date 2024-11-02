#include <bits/stdc++.h>
using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int curr_gas = -1, total_gas = 0, total_gas_from_0th, start;

    /*
        total_gas_from_0th at iteration i, will keep track of gas remaining after travelling from 0th to ith station 
        (but it does not include gas refilled at ith station)

        we will store this value only for those starting stations where is a journey is started, the gas is not exhausted
    */ 
    for(int i=0; i<gas.size(); i++){
        // total_gas at 0th station 
        if(i>0) total_gas += (gas[i-1] - cost[i-1]);
        if(curr_gas<0){
            start = i;
            curr_gas = gas[i] - cost[i];
            total_gas_from_0th = total_gas;
        }
        else curr_gas += (gas[i]-cost[i]);
    }
    if(curr_gas+total_gas_from_0th>=0) return start;
    return -1;
}