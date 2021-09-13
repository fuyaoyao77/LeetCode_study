//整数高精度乘法
#include<iostream>
#include<string>

using namespace std;

string MUL_INT(string str1,string str2) {   //高精度乘法
    int sign = 1;   //sign 为符号位
    string str;
    if (str1[0]=='-') 
    {         //确定结果正负 
        sign *= -1;
        str1 = str1.erase(0,1);
    }
    if (str2[0]=='-') 
    {
        sign *= -1;
        str2 = str2.erase(0,1);
    }
    int L1,L2;
    L1 = str1.length();
    L2 = str2.length();
    for (int i = L2-1;i >= 0;i--) //模拟手工乘法竖式
    { 
        string temps;              //temps存当前str2某一位乘于str1的结果    
        int int_res=0,carry=0,int2=str2[i]-'0';  //carry存进位的数量，int2存str2的某一位 
        if (int2 != 0) 
        {
            for (int j = 1;j <= L2-1-i; j++) temps = "0"+temps;   //这里就是上面所说的加上相应位数的 0 的操作 
            for (int j = L1-1;j >= 0;j--) 
            {
                int_res = (int2 * (int(str1[j]) - '0') + carry) % 10;
                carry = (int2 *(int(str1[j]) - '0') + carry) / 10;
                temps = char(int_res + '0') + temps;
            }
            if (carry != 0) temps = char(carry +'0') + temps;
        }
        str = ADD_INT(str,temps);         //这里就是上面所说的乘法是基于加法的 
    }
    //去除结果中的前导0
    str.erase(0,str.find_first_not_of('0'));
    if (str.empty()) str = "0";
    if ((sign==-1) && (str[0]!='0')) str = "-" + str;
    return str;
}