class Solution {
public:
string find(int i, int j, int divide, int extra, vector<string>&words,int maxWidth)
{
    string line;
    for(int k=i; k<j; k++)
    {
        line+=words[k];
     if(k==j-1) break;
    for(int x=1; x<=divide; x++) line+=" ";
    if(extra>0)
    {
        line+=" ";
        extra--;
    }
  
    }
    while(line.length()<maxWidth)line+=" ";
    return line;
}
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
       int n=words.size();
       int i=0,j=0;
       vector<string>res;
     while(i<n)
     {
        int charcnt=words[i].size();
        int space=0;
        j=i+1;
    while(j<n and words[j].size()+1+charcnt+space<=maxWidth)
    {
        charcnt+=words[j].size();
        space++;
        j++;
    }
    int remainspace=maxWidth-charcnt;
    int divide=space==0?0:remainspace/space;
    int extra =space==0?0:remainspace%space;

    if(j==n)
    {
        divide=1;
        extra=0;
    }
    res.push_back(find(i,j,divide,extra,words,maxWidth));
    i=j;
     } 
     return res;
    }
};