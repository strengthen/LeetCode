__________________________________________________________________________________________________
4ms
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int l) {
        vector<string> res;
        int i=0;
        while(i<words.size()){
            int j=i,len=0;
            while(j<words.size() && (len+words[j].size()+j-i)<=l)
                len+=words[j++].size();
            string out;
            int space=l-len;
            for(int k=i;k<j;++k){ 
                out += words[k];
                //int t=0;
                if(space>0){
                    int t=0;
                    if(j==words.size()){//last row
                        if(j-k==1)
                            t=space;
                        else
                            t=1;
                    }
                    else{//no last row
                        if(j-k-1>0){//last word
                            if(space%(j-k-1)==0) t=space/(j-k-1);
                            else t=space/(j-k-1)+1;
                        }
                        else
                            t=space;
                    }
                    space-=t;
                    out.append(t,' ');
                }
            }
            res.push_back(out);
            i=j;
        }
        return res;
    }
};
__________________________________________________________________________________________________
8828 kb 
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> justifiedText;

        unsigned int i=0;
        while(i < words.size())
        {
            int j;
            int lineWordsLength = 0; 
            
            //Keep adding words until maxwidth or words end is reached. 
            for (j = i; 
                 j < words.size() && lineWordsLength + words[j].size() + (j - i) <= maxWidth; 
                 j++)
            {
                //in the above, checking with (j-i) is for adding spaces.
                //j is the current index of words, i is the start and 
                //(j-i) will be the spaces
                lineWordsLength += words[j].size();
            }
                
            //If we don't need justification, we could stop here and add all the words
            //from i to j-1;

            //We have found the words needed. Next, find the spaces needed
            string line = words[i];
            for (unsigned k = i + 1; k < j; ++k)
            {
                int paddingSize = 1;
                if (j < words.size())
                {
                    int total_spaces_length = (maxWidth - lineWordsLength);
                    int total_words = (j - k);
                        
                    paddingSize = (total_spaces_length/total_words); 
                    if((total_spaces_length % total_words) != 0)
                        paddingSize += 1; 
                    lineWordsLength += paddingSize;
                }

                line.append(paddingSize, ' ').append(words[k]);
            }

            line.append(maxWidth - line.size(), ' ');
            justifiedText.push_back(line);
            i=j;
            
        }

        return justifiedText;
    }
};
__________________________________________________________________________________________________
