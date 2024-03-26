#include <bits/stdc++.h>

class SGTree{
private:
    vector<int> seg;
public:
    SGTree(){
        seg.resize(30000);
    }
    
    void reSize(int n){
        seg.resize(n*4);
    }

    int build(int ind, int low, int high, vector<int> &arr){
        if(low == high) return seg[ind] = arr[low];
        int mid = (high+low)/2;
        build(ind*2+1, low, mid, arr);
        build(ind*2+2, mid+1, high, arr);
        return seg[ind] = seg[ind*2+1] + seg[ind*2+2];
    }

    int query(int ind, int l, int h, int low, int high){
        // type l h low high l h
        if(h<low || l> high) return 0;
        
        // type l low high h
        if(l<= low && high <= h) return seg[ind];

        // type other
        int mid = (low+high)/2;
        int q1 = query(ind*2+1, l, h, low, mid);
        int q2 = query(ind*2+2, l, h, mid+1, high);
        return q1 + q2;
    }

    void update(int ind, int low, int high, int pos, int val){
        if(low == high && low == pos){
            seg[ind] = val;
            return;
        }

        int mid = (low+high)/2;
        if(pos<=mid) update(ind*2+1, low, mid, pos, val);
        else update(ind*2+2, mid+1, high, pos, val);

        seg[ind] = seg[ind*2+1] + seg[ind*2+2];
    }
};