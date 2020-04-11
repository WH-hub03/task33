#include<stdio.h>
#include<iostream>
#include<string>
#include<stdint.h>
#include<string.h>
using namespace std;
int strcmpp(char a[],char b[],int c){
	if(c!=strlen(b))
		return 1;
	for(int i=0;i<c;i++){
		if(a[i]!=b[i])
			return 1;
	}
	return 0;
}
string StringType(char arr[99],int n){
	if(strcmpp(arr,"void",n)==0){
		return "3";
	}
	if(strcmpp(arr,"int",n)==0){
		return "4";
	}
	if(strcmpp(arr,"float",n)==0){
		return "5";
	}
	if(strcmpp(arr,"char",n)==0){
		return "6";
	}
	if(strcmpp(arr,"if",n)==0){
		return "7";
	}
	if(strcmpp(arr,"else",n)==0){
		return "8";
	}
	if(strcmpp(arr,"while",n)==0){
		return "9";
	}
	if(strcmpp(arr,"do",n)==0){
		return "10";
	}
	if(strcmpp(arr,"for",n)==0){
		return "11";
	}
	if(strcmpp(arr,"return",n)==0){
		return "12";
	}
	if(strcmpp(arr,"main",n)==0){
		return "13";
	}
	if(strcmpp(arr,"+",n)==0){
		return "14";
	}
	if(strcmpp(arr,"-",n)==0){
		return "15";
	}
	if(strcmpp(arr,"*",n)==0){
		return "16";
	}
	if(strcmpp(arr,"/",n)==0){
		return "17";
	}
	if(strcmpp(arr,"%",n)==0){
		return "18";
	}
	if(strcmpp(arr,"<",n)==0){
		return "19";
	}
	if(strcmpp(arr,"<=",n)==0){
		return "20";
	}
	if(strcmpp(arr,">",n)==0){
		return "21";
	}
	if(strcmpp(arr,">=",n)==0){
		return "22";
	}
	if(strcmpp(arr,"==",n)==0){
		return "23";
	}
	if(strcmpp(arr,"!=",n)==0){
		return "24";
	}
	if(strcmpp(arr,"&&",n)==0){
		return "25";
	}
	if(strcmpp(arr,"||",n)==0){
		return "26";
	}
	if(strcmpp(arr,"=",n)==0){
		return "27";
	}
	if(strcmpp(arr,"(",n)==0){
		return "28";
	}
	if(strcmpp(arr,")",n)==0){
		return "29";
	}
	if(strcmpp(arr,"[",n)==0){
		return "30";
	}
	if(strcmpp(arr,"]",n)==0){
		return "31";
	}
	if(strcmpp(arr,"{",n)==0){
		return "32";
	}
	if(strcmpp(arr,"}",n)==0){
		return "33";
	}
	if(strcmpp(arr,";",n)==0){
		return "34";
	}
	if(strcmpp(arr,",",n)==0){
		return "35";
	}
	
	
	if(strcmpp(arr,"\n",n)==0) return "\n";

	if(strcmpp(arr,"err",n)==0) return "0";
	//判断是否是整数
	for (int i=0;i<n;i++){
		if(arr[i]>'9'||arr[i]<'0')
			break;
		if(i==n-1)
			return "2";
	}
	//判断是否是规则的词法，不是返回报错
	int nn=0;
	if(arr[0]<='9'&&arr[0]>='0'){	
		for (int i=0;i<n;i++){
			if(arr[i]>'9'||arr[i]<'0')
				 nn=1;
		}
	if(nn==1) return "LexicalError";
	}
	//上述条件不符，则是标识符
	return "1";
}	



int main(){
	int i,j;
	char arr[999][99];
	for(i=0;i<999;i++)
		for(j=0;j<99;j++)
			arr[i][j]='@';
	
	//把代码变成一个个字符串并分流
	for(j=0,i=0;;j++){
		char ch;
		scanf("%c",&ch);
		if(ch=='#')
			break;
		
		if(ch=='\n'){
	        if(arr[i][0]=='@'){
				arr[i][0]='\n';
				i++;
				j=-1;
				continue;
			}
			else{
				i++;
				arr[i][0]='\n';
				i++;
				j=-1;
				continue;
			}
		}

		if(ch==' '){
			if(arr[i][0]=='@') {	
				j=-1;
				continue;
			}
			else{			
				i++;
				j=-1;
				continue;
			}
		}



		if(ch=='/'){
			if(arr[i][0]!='@')
			i++;
			char cc;
			scanf("%c",&cc);
			if(cc=='/'){
				while(1){
					char in;
					scanf("%c",&in);
					if(in=='\n') break;
				}				
				j=-1;
				continue;
			}
			else if(cc=='*'){
				char old=' ',now;
				while(1){
					scanf("%c",&now);
					if(now=='/'&&old=='*') break;
					old=now;
				}			
				j=-1;
				continue;
			}
			else{
				arr[i][0]='/';
				i++;
				if(cc!=' '){
					arr[i][0]=cc;
					j=0;
				}
				else{
					j=-1;
				}
				continue;
			}
		}
		if(ch=='<'){
			if(arr[i][0]!='@')
			i++;
			char cc;
			scanf("%c",&cc);
			if(cc=='='){
				arr[i][0]=ch;
				arr[i][1]=cc;
				i++;
				j=-1;
				continue;
			}
			else{
				arr[i][0]=ch;
				i++;
				if(cc!=' '){
					arr[i][0]=cc;
					j=0;
				}
				else{
					j=-1;
				}
				continue;
			}
		}
		

		if(ch=='>'){
			if(arr[i][0]!='@')
			i++;
			char cc;
			scanf("%c",&cc);
			if(cc=='='){
				arr[i][0]=ch;
				arr[i][1]=cc;
				i++;
				j=-1;
				continue;
			}
			else{
				arr[i][0]=ch;
				i++;
				if(cc!=' '){
					arr[i][0]=cc;
					j=0;
				}
				else{
					j=-1;
				}
				continue;
			}
		}

		if(ch=='='){
			if(arr[i][0]!='@'){
				
				i++;
				
			}
			char cc;
			scanf("%c",&cc);
			if(cc=='='){
				arr[i][0]=ch;
				arr[i][1]=cc;
				i++;
				j=-1;
				continue;
			}
			else{
				arr[i][0]=ch;
				i++;
				if(cc!=' '){
					arr[i][0]=cc;
					j=0;
					
				}
				else{
					
					j=-1;
				}
				continue;
			}
		}
		
		if(ch=='!'){
			if(arr[i][0]!='@')
				i++;
			char cc;
			scanf("%c",&cc);
			if(cc=='='){
				arr[i][0]=ch;
				arr[i][1]=cc;
				i++;
				j=-1;
				continue;
			}
			else{
				arr[i][0]=ch;
				i++;
				if(cc!=' '){
					arr[i][0]=cc;
					j=0;
				}
				else{
					j=-1;
				}
				continue;
			}
		}
		if(ch=='|'||ch=='&'){
			
			if(arr[i][0]!=' ')
				{
					
					i++;
					j=-1;
			}
			char cc;
			scanf("%c",&cc);
			arr[i][0]=ch;
			arr[i][1]=cc;
			i++;
			j=-1;
			continue;			
		}		
		if(ch=='+'||ch=='-'||ch=='*'||ch=='%'||ch=='('||ch==')'||ch=='['||ch==']'||ch=='{'||ch=='}'||ch==';'||ch==','){
			if(j==0){
				arr[i][0]=ch;
				i++;
				j=-1;
				continue;
			}
			else{
				i++;
				arr[i][0]=ch;
				i++;
				j=-1;
				continue;
			}
		}
		arr[i][j]=ch;

	}
	
	int sayerr[10]={0};
	int tt=0;
	for(int n=0,number=0;n<i;n++){ 
         if(arr[n][0]=='@')
            continue;
		for(j=0;;j++){
			if(arr[n][j]=='@')break;//判断一个字符串长度
			
		}
		if(arr[n][0]=='\n'){  
			number++;
			cout<<"\n";
			if(arr[n+1][0]=='\n'){
				if(arr[n+2][0]=='\n'){
					n+=3;
				}
				else n++;
			}
			
		}
		else if(StringType(arr[n],j)=="LexicalError"){
			cout<<"LexicalError,";
			sayerr[tt]=number+1;  //报错行数
			tt++;
		}
		else{
			cout<<"<";
			cout<<StringType(arr[n],j);
			cout<<",";
			if(StringType(arr[n],j)=="1"||StringType(arr[n],j)=="2")
				for(j=0;;j++){
					if(arr[n][j]=='@')break;
				
				    cout<<arr[n][j];
			
				}
			else cout<<"-";
			cout<<">,";


			
		}

	}
	//输出报错行数
	if (sayerr[0]!=0)cout<<"LexicalError(s) on line(s) ";
	for(i=0;;i++){
		if(sayerr[i]==0)break;
		cout<<sayerr[i];
		cout<<",";
	}

	
}






