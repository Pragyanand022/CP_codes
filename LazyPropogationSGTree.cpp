class LSTree{
private:
    vector<int> seg, lazy;
public:

    LSTree(int n){
        seg.resize(4*n);
        lazy.resize(4*n);
    }

    void build(int ind, int low, int high, vector<int> &arr){
        if(low == high){
            seg[ind] = arr[low];
            return;
        }

        int mid = (low+high)>>1;
        build(ind*2+1, low, mid, arr);
        build(ind*2+2, mid+1, high, arr);

        seg[ind] = seg[ind*2+1] + seg[ind*2+2];
    }

    void update(int ind, int low, int high, int l, int r, int val){
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1) * lazy[ind];
            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }

        if(r<low || high<l){
            return;
        }
        if(l<=low && r>=high){
            seg[ind] += (high-low+1) * val;
            if(low!=high){
                lazy[2*ind+1] += val;
                lazy[2*ind+2] += val;
            }
            lazy[ind] = 0;
            return;
        }

        int mid = (low+high)>>1;
        update(ind*2+1, low, mid, l, r, val);
        update(ind*2+2, mid+1, high, l, r, val);
        seg[ind] = seg[ind*2+1] + seg[ind*2+2];
    }

    int query(int ind, int low, int high, int l, int r){
        if(lazy[ind]!=0){
            seg[ind] += (high-low+1) * lazy[ind];
            if(low!=high){
                lazy[2*ind+1] += lazy[ind];
                lazy[2*ind+2] += lazy[ind];
            }
            lazy[ind] = 0;
        }
        if(r<low || high<l) return 0;
        if(l<=low && r>=high) return seg[ind];

        int mid = (low+high)/2;
        query(ind*2+1, low, mid, l, r);
        query(ind*2+2, mid+1, high, l, r);
        return (seg[ind*2+1] + seg[ind*2+2]);        
    }
};
