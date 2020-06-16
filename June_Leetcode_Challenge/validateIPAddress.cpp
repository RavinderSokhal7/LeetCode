/*
Validate IP Address

Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string. 
*/
class Solution {
public:
    string validIPAddress(string IP) {
//         we will use cstring and string tokenizer.
        if(IP=="") return "Neither";
        if(IP[IP.size()-1]=='.' || IP[IP.size()-1]==':') return "Neither";
        const char * ipc = IP.c_str();
        char* ip = new char[IP.size()+1];
        strcpy(ip,ipc);
        bool c4=false;
        int n=0;
        char* tok = strtok(ip,".");
        while(tok!=NULL){
            n++;
            int l=strlen(tok);
            if(l>3) break;
            if(tok[0] == '0' && l>1) break;
            for(int i=0;i<l;i++){
                if(!isdigit(tok[i])){
                    c4=true;break;
                }
            }
            if(c4) break;
            if(n>4) break;
            int num = stoi(tok);
            if(num<0 || num>255) break;
            if(num==0){
                if(l>1) break;
            }
            tok = strtok(NULL,".");
        }
        if(!tok && n==4) return "IPv4";
        for(int i=0;i<IP.size()-1;i++){
            if(IP[i]==IP[i+1] && IP[i] == ':') return "Neither";
        }
        tok = strtok(ip,":");
        bool c6=false;
        n=0;
        while(tok!=NULL){
            n++;
            int l=strlen(tok);
            for(int i=0;i<l;i++){
                if(!isdigit(tok[i]) && (tok[i]<'a'|| tok[i]>'f') && (tok[i]<'A'||tok[i]>'F')){
                    c6=true;break;
                }
            }
            if(c6) break;
            if(n>8) break;
            if(l>4 || l==0) break;
            tok = strtok(NULL,":");
        }
        if(!tok && n==8)
            return "IPv6";
        return "Neither";
    }
};
