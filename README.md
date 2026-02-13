# Shift-Cipher-CLI
A C++ command-line tool that encrypts and decrypts text files using a printable ASCII Shift/Caesar cipher.


# **Caesar Cipher CLI (C++)**

A command-line tool written in C++ that encrypts and decrypts text files using a printable ASCII Caesar (shift) cipher. 
The original Caesar cypher had 26 elements, but this implementation considers all printable ascii characters.

This project applies modular arithmetic to perform character shifting over the 94 printable ASCII characters ('!' to '~').

***I built it for fun and as a type of exercise for file I/O, command line interface handling, modular arithmetic.**



## Main Idea:

Read a text file and create a new version of that file but encrypted. Encryption and Decryption are done with the same integer key which also makes this cipher implementation a **symmetic type cipher**. 
The encryption/decryption itself is done with shifting the value of the letters by some fixed integer value of the key.This means that each letter of the original plaintext will be mapped to a unique letter in the cyphertext ( which also makes this a **mono-alphabetic cipher.**

## I learned:

I reinforced my understanding of file I/O, working with ACII charachters and modular arithmetic. 

I also learned that the words cypher and cipher are interchangable and have the same meaning.

## How to build:
Compile using:
> ```
> g++ -std=c++17 main.cpp -o caesar
> ```

Then,
> ```
> ./caesar <encrypt/decrypt> <filepath> <key>
> ```

Example:
>
>```
>(The following line will create the file encrypted.txt)
>
>./caesar encrypt input.txt 13
>
>(Then we can decrypt encrypted.txt with same key to get decrypted.txt)
>
>./caesar decrypt encrypted.txt 13
>```

## Limitations:

- This cipher is not cryptographically secure

- Only shifts printable ASCII characters

- Uses line-based processing (std::getline)

- Always writes output to encrypted.txt or decrypted.txt
