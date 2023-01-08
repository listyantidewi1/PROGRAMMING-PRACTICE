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
num_sentences = len(text.split('.'))
print(num_sentences)