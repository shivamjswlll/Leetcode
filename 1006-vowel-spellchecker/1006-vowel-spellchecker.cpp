#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <cctype>
using namespace std;

class Solution {
    // Convert string to lowercase
    string to_lower_str(const string &s) {
        string res = s;
        transform(res.begin(), res.end(), res.begin(),
                  [](unsigned char c){ return tolower(c); });
        return res;
    }

    // Convert lowercase string vowels to '*'
    string devowel(const string &s) {
        string res = to_lower_str(s);
        for (char &c : res) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return res;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact; // For exact matches
        unordered_map<string, string> lookup; // Single map for case-insensitive + vowel-insensitive

        // Preprocess wordlist
        for (const string &word : wordlist) {
            exact.insert(word);

            string lowerWord = to_lower_str(word);
            string devowelWord = devowel(word);

            // Store the first occurrence only
            if (!lookup.count(lowerWord))
                lookup[lowerWord] = word;

            if (!lookup.count(devowelWord))
                lookup[devowelWord] = word;
        }

        vector<string> result;
        result.reserve(queries.size());

        // Process queries
        for (const string &q : queries) {
            if (exact.count(q)) {
                result.push_back(q); // Exact match
                continue;
            }

            string lowerQ = to_lower_str(q);
            string devowelQ = devowel(q);

            if (lookup.count(lowerQ)) {
                result.push_back(lookup[lowerQ]); // Case-insensitive match
            }
            else if (lookup.count(devowelQ)) {
                result.push_back(lookup[devowelQ]); // Vowel-insensitive match
            }
            else {
                result.push_back(""); // No match
            }
        }

        return result;
    }
};
