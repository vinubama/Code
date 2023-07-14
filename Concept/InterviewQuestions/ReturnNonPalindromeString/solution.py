i
str1 = "Mom speaks malayalam"
str2 = "He did a good deed"

def is_palindrome(str):
    a = str[::-1]
    if (a.lower() == str.lower()):
        return True
    return False

def return_non_palindrome_string(str):
    split_str = str.split()
    non_p_str=[str for str in split_str if not is_palindrome(str)]
    return " ".join(non_p_str)

print(return_non_palindrome_string(str1))
print(return_non_palindrome_string(str2))
