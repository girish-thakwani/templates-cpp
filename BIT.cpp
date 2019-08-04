#include <bits/stdc++.h> 
using namespace std; 
#define ull unsigned long long
ull getSum(ull BITree[], ull index) 
{ 
    ull sum = 0; 
    index = index + 1; 
    while (index>0) 
    {  
        sum += BITree[index]; 
        index -= index & (-index); 
    } 
    return sum; 
} 
void updateBIT(ull BITree[], ull n, ull index, ull val) 
{ 
    index = index + 1; 
    while (index <= n) 
    {         
        BITree[index] += val; 
        index += index & (-index); 
    } 
}  
ull sum(ull x, ull BITTree1[], ull BITTree2[]) 
{ 
    return (getSum(BITTree1, x) * x) - getSum(BITTree2, x); 
} 
  
  
void updateRange(ull BITTree1[], ull BITTree2[], ull n, 
                 ull val, ull l, ull r) 
{ 
    updateBIT(BITTree1,n,l,val); 
    updateBIT(BITTree1,n,r+1,-val);  
    updateBIT(BITTree2,n,l,val*(l-1)); 
    updateBIT(BITTree2,n,r+1,-val*r); 
} 
  
ull rangeSum(ull l, ull r, ull BITTree1[], ull BITTree2[]) 
{ 
    return sum(r, BITTree1, BITTree2) - 
           sum(l-1, BITTree1, BITTree2); 
} 
  
  
ull *constructBITree(ull n) 
{ 
ull *BITree = new ull[n+1]; 
    for (ull i=1; i<=n; i++) 
        BITree[i] = 0; 
  
    return BITree; 
} 
 
int main() 
{ 
    ull n = 5; 
    ull *BITTree1, *BITTree2; 
    BITTree1 = constructBITree(n); 
    BITTree2 = constructBITree(n); 
    ull l = 0 , r = 4 , val = 5; 
    updateRange(BITTree1,BITTree2,n,val,l,r); 
    l = 2 , r = 4 , val = 10; 
    updateRange(BITTree1,BITTree2,n,val,l,r); 
    l = 1 , r = 4; 
    cout << rangeSum(l,r,BITTree1,BITTree2) << "\n"; 
    return 0; 
} 
