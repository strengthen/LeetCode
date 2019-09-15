__________________________________________________________________________________________________
class Solution {
   public int maxNumberOfBalloons(String text) {
int count = 0;
int b=0,a=0,l=0,o=0,n=0;
char cb='b',ca='a',cl='l',co='o',cn='n';
//text = text.toLowerCase();
char[] arr = text.toCharArray();
for(char c: arr){
if(c==cb){
b++;
} else if(c==ca){
a++;
} else if(c==cl){
l++;
} else if(c==co){
o++;
} else if(c==cn){
n++;
}
}
if((b==0 || a==0 || n==0) || ( o<2 || l<2) ){
return 0;
} else{
while((b>0 && a>0 && n>0 && o>=2 && l>=2)){
count++;
b--;
a--;
l=l-2;
o=o-2;
n--;
}
return count;
}

}
}
__________________________________________________________________________________________________

__________________________________________________________________________________________________
