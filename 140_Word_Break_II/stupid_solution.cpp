class Solution {
public:

    struct TreeNode {
        std::string& word;
        TreeNode *next;
        TreeNode(string& str) : word(str), next(nullptr) {}
    };

    // ascend
    vector<string>& sortWordDict(vector<string>& wordDict) {

        TreeNode *root = new TreeNode(wordDict[0]);
        TreeNode *tmpNode = nullptr, *preNode = nullptr;
        for (int i = 1; i < wordDict.size(); ++i) {

            tmpNode = root;
            if (root->word.compare(wordDict[i]) > 0) {
                root = new TreeNode(wordDict[i]);
                root->next = tmpNode;
            } else {
                preNode = tmpNode;
                bool inserted = false;
                while (tmpNode=tmpNode->next) {

                    if (tmpNode->word.compare(wordDict[i]) > 0) {

                        TreeNode *newNode = new TreeNode(wordDict[i]);
                        preNode->next = newNode;
                        newNode->next = tmpNode;
                        inserted = true;
                        break;
                    }

                    preNode = tmpNode;
                }

                if (!inserted) {
                    preNode->next = new TreeNode(wordDict[i]);
                }
            }
        }

        tmpNode = root;
        vector<string>* newVec = new vector<string>();
        while (tmpNode) {
            newVec->push_back(tmpNode->word);
            tmpNode = tmpNode->next;
        }

        tmpNode = root;
        while (tmpNode) {

            preNode = tmpNode;
            tmpNode = tmpNode->next;
            delete preNode;
        }
        root = nullptr;

        return *newVec;
    }


    bool prefixMatched(string& s, vector<string>& sortedVec, int start, int end, bool &equal) {

        if (start < 0 || end >= sortedVec.size() || start > end) {
            return false;
        }

        int pivot = (start + end) / 2;
        int ret = s.compare(sortedVec[pivot]);
        if (ret == 0) {
            equal = true;
            return true;
        } else if (ret > 0) {
            return prefixMatched(s, sortedVec, pivot+1, end, equal);
        } else {

            bool prefixMatch = false;
            bool check = false;
            if (sortedVec[pivot].find(s) != string::npos) {
                prefixMatch = true;
            }

            // The following check is just to check if there are some words equal.
            check = prefixMatched(s, sortedVec, start, pivot-1, equal); 
            return !check ? prefixMatch : check;
        }
    }

    bool isPrefixMatch(string& s, vector<string>& sortedVec, bool &equal) {

        return prefixMatched(s, sortedVec, 0, sortedVec.size()-1, equal);
    }

    string wordBreak(string s, vector<int>& indexVec) {

        string result;

        int prevIndex = 0;
        for (auto index : indexVec) {

            result += s.substr(prevIndex, index-prevIndex);
            result += " ";
            prevIndex = index;
        }

        // Last word.
        result += s.substr(prevIndex);
        return result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        if (wordDict.size() == 0) {
            return wordDict;
        }

        vector<string>& newWordDict = sortWordDict(wordDict);
        vector<string> sentences;
        stack<vector<int>> wordStack;

        vector<int> mainIndexVec;

        bool equal, prefixMatch;

        int startIndex = 0;
        for (int i = startIndex+1; startIndex < s.length() && i <= s.length(); ++i) {

            string subStr = s.substr(startIndex, i-startIndex);

            equal = false;
            prefixMatch = isPrefixMatch(subStr, newWordDict, equal);

            // Partial match, continue;
            if (prefixMatch && !equal) {

                if (i != s.length()) {
                    continue;
                }
            }

            if (equal) {
                if (i < s.length()) {
                    // Push the matched string position to a new vector and also
                    // save the current list to the stack for later traversal.
                    vector<int> indexVec = mainIndexVec;
                    indexVec.push_back(i);
                    wordStack.push(indexVec);

                    // Although we matched one word, we need continue to see if a longer word can be matched. 
                    continue;
                } else {
                    // Save the whole sentence once this pass is successful.
                    sentences.push_back(wordBreak(s, mainIndexVec));
                }
            }

            if (wordStack.size() == 0) {
                break;
            }

            mainIndexVec = wordStack.top();
            wordStack.pop();
            startIndex = mainIndexVec.back();
            i = startIndex;
        }

        return sentences;
    }
};
