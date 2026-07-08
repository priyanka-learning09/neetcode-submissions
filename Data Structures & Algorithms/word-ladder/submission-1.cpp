class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) 
    {
        queue<string> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        if(!s.count(endWord))
        {
            return 0;
        }
        q.push(beginWord);
        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            

            

            while(size--)
            {
            string word=q.front();

                q.pop();
                if(word==endWord)
            {
                return level;
            }
                for(int i=0;i<word.size();i++)
                {
                    string original=word;
                    for(char j='a';j<='z';j++)
                    {
                        original[i]=j;
                        if(s.count(original))
                        {
                            q.push(original);
                            s.erase(original);
                        }
                    }
                    
                }

            }
                level++;

            
        }

        
     return 0;   
    }
};
