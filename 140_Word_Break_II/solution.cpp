class Solution {
public:

    map<string, vector<string>> cache;

    vector<string> wordBreak(string s, set<string>& wordSet) {

        if (s.length() == 0) return {};
        if (cache.count(s)) return cache.at(s);

        vector<string> sentences;

        for (int i = 1; i <= s.length(); ++i) {

            string subStr = s.substr(0, i);
            if (wordSet.count(subStr) > 0) {

                if (i == s.length()) {
                    sentences.push_back(subStr);
                    break;
                }

                const vector<string>& tmpSentences = wordBreak(s.substr(i), wordSet);
                for (auto& tmp: tmpSentences) {
                    sentences.push_back(subStr + ' ' + tmp);
                }
            }
        }

        cache.insert({s, sentences});
        return sentences;
    }

	// 12 ms solution.
    vector<string> wordBreak(string s, vector<string>& wordDict) {

        if (wordDict.size() == 0) return wordDict;

        set<string> wordSet {wordDict.begin(), wordDict.end()};
        const vector<string>& sentences = wordBreak(s, wordSet);
        return sentences;
    }
};
