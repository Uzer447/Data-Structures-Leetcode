class Solution:
    def answerString(self, word: str, numFriends: int) -> str:
        n = len(word)
        if numFriends == 1:
        # Only one friend, the entire word is collected
            return word
        elif numFriends == n:
        # Each friend gets one character; return the lex largest character
            return max(word)
        else:
            L = n - numFriends + 1  # Maximum possible length of a part
        # Find the lex largest character in the word
            max_char = max(word)
            max_substring = ''
        # Positions where the character is equal to the max character
            positions = [i for i, c in enumerate(word) if c == max_char]
            for i in positions:
            # Maximum possible end index for the substring
                end = min(i + L, n)
            # Extract the substring starting at position i with length up to L
                s = word[i:end]
                if s > max_substring:
                    max_substring = s
            return max_substring