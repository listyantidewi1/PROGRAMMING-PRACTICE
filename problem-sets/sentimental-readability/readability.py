# TODO

from cs50 import get_string

# getting user input

text = get_string("Text: ")

# count the number of letters
num_letters = len(text)
# print(num_letters)

# count the number of words
num_words = len(text.split())
# print(num_words)

# count the number of sentences
num_sentences = text.count('.')
# print(num_sentences)

# compute L

l = num_letters / num_words * 100
print(l)
s = num_sentences / num_words * 100
print(s)
index = 0.0588 * l - 0.296 * s - 15.8
print(index)

if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print("Grade ", (round(index, 0)))