class Solution {
public:
    int MAX_WIDTH;

    string makeLine(int i,int j,int eachSlotsSpace,int extraSpaces, vector<string>& words)
    {
        string line;

        for(int k=i;k<j;k++)
        {
            line += words[k];

            if(k == j-1) continue;

            int spaces = eachSlotsSpace;
            while(spaces--) line += " ";

            if(extraSpaces > 0)
            {
                line += " ";
                extraSpaces--;
            }
        }

        while(line.size() < MAX_WIDTH) 
            line += " ";

        return line;
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {

        MAX_WIDTH = maxWidth;

        int i = 0;
        int n = words.size();

        vector<string> result;

        while(i < n)
        {
            int lettersCount = words[i].size();

            int j = i + 1;
            int slots = 0;

            while(j < n && words[j].size() + slots + lettersCount + 1 <= maxWidth)
            {
                lettersCount += words[j].size();
                slots++;
                j++;
            }

            int remainingSpace = maxWidth - lettersCount;

            int eachSlotsSpace = (slots == 0 ? 0 : remainingSpace / slots);
            int extraSpaces   = (slots == 0 ? 0 : remainingSpace % slots);

            if(j == n)
            {
                eachSlotsSpace = 1;
                extraSpaces = 0;
            }

            string line = makeLine(i, j, eachSlotsSpace, extraSpaces, words);
            result.push_back(line);

            i = j; 
        }

        return result;
    }
};
