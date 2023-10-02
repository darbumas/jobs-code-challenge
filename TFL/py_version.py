#!/usr/bin/python3
"""
Script to replace the middle parts of words with count of vowels in the word.

Autho: B. Bwashi <github.com/darbumas>
"""

class WordReplacer:
    """ Class to replace the middle parts of words with count of vowels in the word."""
    def __init__(self):
        self.vowels = 'aeiou'

    def replace(self, text):
        """ Replaces the middle parts of words with count of vowels in the word."""
        words = text.split()
        new_words = []

        for word in words:
            if len(word) < 3:
                new_words.append(word)
                continue

            num_vowels = self.count_vowels(word)
            new_word = self.replace_middle(word, num_vowels)
            new_words.append(new_word)

        return ' '.join(new_words)

    def count_vowels(self, word):
        """ Counts the number of vowels in a word."""
        return sum(c.lower() in self.vowels for c in word)

    def replace_middle(self, word, vowel_count):
        """ Replaces the middle parts of words with count of vowels in the word."""
        return word[0] + str(vowel_count) + word[-1]

replacer = WordReplacer()
text = input('Enter text: ')
print(replacer.replace(text))
