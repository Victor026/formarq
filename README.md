```
# Welcome to Formarq!
```

### What is it?
Formarq is developed to encrypt files.

### How to use it?
The user should input the file path that is going to be encrypted and the key, both via terminal.

### How does it work?
The program makes a "exclusive or" between every word of the file and the key generating a new file with the same name as the old one but with the extension .crp
If the file is already encrypted (it has .crp as extension) it will generate a .drp file with the content of the original file.

**Note that the user has to input the same key in the encrypted file in order to obtain the desirable result.

### Usage example
Compile the formarq.c file and open the terminal where the executable file is located and then input:
./formarq file-that-is-going-to-be-encrypted key (for unix-like operating systems)
```
Example: ./formarq ~/Documents/test.txt house
```
The above example encrypts the test.txt file using the key "house".
