Given two binary strings, return their sum (also a binary string).
The input strings are both non-empty and contains only characters 1 or 0.
Example 1:
Input: a = "11", b = "1"
Output: "100"
Example 2:
Input: a = "1010", b = "1011"
Output: "10101"

class Solution {
public:
    string addBinary(string a, string b) {
     
        int ab[2000];
        
        int aSize=a.size(),
            bSize=b.size();
        int carryOver=0;
        int abi=0,ai=aSize-1,bi=bSize-1;
        while(ai>-1 || bi>-1)
        {
            int aVal,
                bVal;
            if(ai<0) aVal=0;
            else aVal= (int)a[ai]-48; // subtracting the ASCII value diff
            if(bi<0) bVal=0;
            else bVal=(int)b[bi]-48;
                        
            int val=aVal+bVal+carryOver;
            if(val==0)
            {
                ab[abi]=0;
                carryOver=0;                
            }
            else if(val==1) 
            { 
                ab[abi]=1;
                carryOver=0;
            }else if(val==2)
            {
                ab[abi]=0;
                carryOver=1;
            }else if(val==3)
            {
                ab[abi]=1;
                carryOver=1;
            }
            ai--;
            bi--;
            abi++;
        }
// adding the carryover
        if(carryOver==1)
            ab[abi++]=carryOver;
        string str="";
        int i,
            j=0;
        
        // reverse the values, as sum started with endIndex
        for(i=abi-1,j=0;i>-1;i--,j++)
        {
            str=str + (char)(ab[i]+48);
        }
        return str;
    }
};
