//
// Created by László Molnár on 2017-11-15.
//

#ifndef CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
#define CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP

#include <vector>

class LightningWordFinder
{
public:
    std::string getLongestWord(const std::string& text)
    {
//        std::vector<size_t> indexes;
//        size_t prevIdx = 0;
//        size_t currentIdx = text.find(' ', prevIdx);
//        while (currentIdx != -1) { // std::string::npos
//            indexes.emplace_back(currentIdx);
//            prevIdx = ++currentIdx;
//            currentIdx = text.find(' ', prevIdx);
//        }

        size_t textLen = text.size();
        size_t baseIdx = 0;
        size_t longestIdx = 0;
        size_t longestLen = 0;
        char currentChar = '.';
        char nextChar = '.';
        size_t currentSize = 0;

        while (baseIdx < textLen) {
            currentChar = text[baseIdx];
            if (isLetter(currentChar)) {
                currentSize = 1;

                size_t nextIdx = baseIdx + 1;
                nextChar = text[nextIdx];
                while (isLetter(nextChar)) {
                    ++currentSize;
                    nextChar = text[++nextIdx];
                }
                if (currentSize > longestLen) {
                    longestIdx = baseIdx;
                    longestLen = currentSize;
                }
                baseIdx = nextIdx + 1;
            } else {
                ++baseIdx;
            }
        }

        return text.substr(longestIdx, longestLen);
    }

private:
    inline bool isLetter(const char& character) {
        return (character > 64 && character < 91) || (character > 96 && character < 123);
    }
};
#endif //CPP_LIGHTNING_FAST_WORD_FINDER_DOJO_LIGHTNINGWORDFINDER_HPP
