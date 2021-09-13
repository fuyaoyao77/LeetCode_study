//整数高精度乘法
#include<iostream>
#include<string>

using namespace std;

int compare(string str1,string str2)   //比较字符串型的“数字”大小，相等返回0，大于返回1，小于返回-1
{
    if (str1.length() > str2.length()) return 1; //长度长的整数大于长度小的整数
    else if (str1.length() < str2.length()) return -1;
    else    return str1.compare(str2); //若长度相等，则头到尾按位比较
}


string SUB_INT(string str1,string str2);
string ADD_INT(string str1,string str2);


string ADD_INT(string str1,string str2) {//高精度加法
    int sign = 1; //sign 为符号位
    string str;
    if (str1[0] == '-') //如果其中一个是负数，那么可以转化成高精度减法；如果都是负数，那么确定下结果为负数，然后擦除负号后相加
    {
        if (str2[0] == '-') 
        {
            sign = -1;
            str = ADD_INT(str1.erase(0,1),str2.erase(0,1));
        } 
        else 
        {
            str = SUB_INT(str2,str1.erase(0,1));
        }
    } 
    else
    {
        if (str2[0] == '-') 
        {
            str = SUB_INT(str1,str2.erase(0,1));
        }
        else 
        { 
            int L1,L2;
            L1 = str1.length();
            L2 = str2.length();
            if (L1 < L2)              //在长度小的前面加0补齐，使得两数对齐 
            {
                for (int i = 1;i <= L2-L1; i++) str1="0"+str1;
            } 
            else 
            {
                for (int i = 1;i <= L1-L2; i++) str2="0"+str2;
            }
            int int1 = 0,carry = 0; //carry 记录进位
            for (int i = str1.length()-1;i >= 0; i--) 
            {
                int1 = (int(str1[i])-'0'+ int(str2[i])-'0'+carry) % 10;
                carry = (int(str1[i])-'0'+ int(str2[i])-'0'+carry) / 10;
                str = char(int1 + '0') + str;
            }
            if (carry != 0) str = char(carry+'0') + str;
        }
    }
    
    if ((sign==-1)&&(str[0]!='0')) str="-"+str;    //处理符号位
    return str;
}
string SUB_INT(string str1,string str2) {//高精度减法
    int sign=1; //sign 为符号位
    string str;
    int i,j;
    if (str2[0] == '-')    //减一个负数等于加上它的相反数 
    {
        str = ADD_INT(str1,str2.erase(0,1));
    } 
    else 
    {
        if (str1[0] == '-')           //负数减去正数 
        {
            sign = -1;
            str = ADD_INT(str1.erase(0,1),str2);
        }
        else
        {
            int res = compare(str1,str2);
            if (res == 0) return "0";      //两数相等则结果是0 
            if (res < 0)                   //被减数比较小，则符号先确定为负 
            {
                sign = -1;
                string temp = str1;
                str1 = str2;
                str2 = temp;
            }
            int tempint;
            tempint=str1.length()-str2.length();
            for (i=str2.length()-1;i>=0;i--) 
            {
                if (str1[i+tempint]<str2[i])   //需要向前借位的情况 
                {
                    j=1;
                    while (1) 
                    {
                        if (str1[i+tempint-j]=='0')   //被借的位如果是 0 ，那么继续借位，并把当前的 0 变成 9 
                        {
                            str1[i+tempint-j]='9';
                            j++;
                        } 
                        else 
                        {
                            str1[i+tempint-j]=char(int(str1[i+tempint-j])-1);  // 被借的位如果不是 0 ，那么减去 1
                            break;
                        }
                    }
                    str=char(str1[i+tempint]-str2[i]+'0'+10)+str;
                } 
                else 
                {
                    str=char(str1[i+tempint]-str2[i]+'0')+str;
                }
            }
            for (i=tempint-1;i>=0;i--) str=str1[i]+str;
        }
    }
    //去除结果中多余的前导0
    str.erase(0,str.find_first_not_of('0'));
    if (str.empty()) str="0";
    if ((sign==-1) && (str[0]!='0')) str ="-"+str;
    return str;
}


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

int main() {
      string str1,n;
      while (cin>>str1>>n) {
         int i=1,p;
         for (;i<str1.size();i++)
             if (r[i]=='.')
                 p=i;//找出小数点所在
         str1.erase(p,1);//先去掉小数点
         
         //大数乘法
         string ans = "1.0000000000000";
         int d;
         while(n != 0){
             d = n%2;
             n = n >> 1;
             if(d == 0) ans = MUL_INT(ans,str1);
             str1 = MUL_INT(str1,str1);
         }
        
         ans.insert(n*(str1.size() - p), 1, '.');//插入小数点
         int k=l;
         while (ans[k] == 0) --k;
         int j=0;
         while (ans[j] == 0) ++j;//去掉首尾多余的零
         if (ans[j]=='.') ++j;//去掉多余的小数点
         for (;k>=j;k--)ans[k]=='.'?cout<<'.':cout<<ans[k]-0;//最后正序输出
         cout<<endl;
     }
     return 0;
 }