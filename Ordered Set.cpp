
//Ordered Set
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
 
using namespace std;
namespace __gnu_pbds{
    typedef tree<long long ,null_type,less_equal<long long >,rb_tree_tag,tree_order_statistics_node_update> oset;
}
using namespace __gnu_pbds;

//this function inserts one more occurrence of (x) into the set.
void Insert(oset &s,long long x){
     s.insert(x);
}

//this function checks weather the value (x) exists in the set or not.
bool Exist(oset &s,long long x){ 
     if((s.upper_bound(x))==s.end())
        return 0;
     return ((*s.upper_bound(x))==x);
}
 
//this function erases one occurrence of the value (x).
void Erase(oset &s,long long x){
     if(Exist(s,x))
        s.erase(s.upper_bound(x));
}
 
//this function returns the first index of the value (x)..(0 indexing).
long long FirstIdx(oset &s,long long x){
    if(!Exist(s,x))
        return -1;
    return (s.order_of_key(x));
}

//this function returns the value at the index (idx)..(0 indexing).
long long Value(oset &s,long long idx){ 
   return (*s.find_by_order(idx));
}
 
//this function returns the last index of the value (x)..(0 indexing).
long long LastIdx(oset &s,long long x){
    if(!Exist(s,x))
        return -1;
    if(Value(s,(int)s.size()-1)==x)
        return (int)(s.size())-1;
    return FirstIdx(s,*s.lower_bound(x))-1;
}

//this function returns the number of occurrences of the value (x).
long long Count(oset &s,long long x){ 
     if(!Exist(s,x))
        return 0;
     return LastIdx(s,x)-FirstIdx(s,x)+1;
}
