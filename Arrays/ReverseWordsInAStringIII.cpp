class Solution {
public:
    string reverseWords(string s) {
        int spaces = 0;
        int p = 0;
        int q = 0;
        int j = 0;
        
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == ' ') spaces++;
        }
        
        for (int k = 0; k <= spaces; k++) {
            // advance j to the kth word last character
            while (j < s.length() && s[j] != ' ') {
                j++;
            }   
            
            // j is blank space or overflow index, so reset to the kth word last
            // character
            q = j; // save the blank space position
            j--;
            
            // reversing word characters
            while (p < j) {
                char tmp = s[p];
                s[p] = s[j];
                s[j] = tmp;
                
                p++;
                j--;
            }
            
            // advance to the next word
            j = q + 1;
            p = j;
        }
        
        return s;
    }
};
