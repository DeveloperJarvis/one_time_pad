# ONE TIME PAD

A microproject to create one time pad application. Developed using C language.
It is a very strong encryption technique.

### Install GCC

For Ubuntu:

```bash
sudo apt install gcc -y
```

## Compile using gcc

```bash
gcc -g -Wall -Wextra -o encrypt.out encrypt.c
gcc -g -Wall -Wextra -o decrypt.out decrypt.c
```

## Execute the object file

1. Simple execute

```bash
./encrypt.out secret.txt
./decrypt.out crypt.bin key.bin
```

## For Windows:

**NOTE** Clang will throw error for fopen is deprecated

### Install clang

1. Install Microsoft Visual Studio
2. Add to your windows path:
3. Win+ R > sysdm.cpl
4. Advanced > Environment Variables
5. System variables > Path > Edit
6. Add (C:\Program Files\Microsoft Visual Studio\18\<Version>\VC\Tools\Llvm\bin
   )

### Compile using gcc

```bash
# encryption
clang -c encrypt.c -o encrypt.o
clang encrypt.o -o encrypt_x64.exe
# decryption
clang -c decrypt.c -o decrypt.o
clang decrypt.o -o decrypt_x64.exe
```

### Execute the object file

1. Simple execute

```bash
# encrypting
encrypt_x64.exe secret.txt
# decrypting
decrypt_x64.exe crypt.bin key.bin
```

## Creating tag

```bash
# 1. Check existing tags
git tag
# 2. Create a valid tag
git tag -a v1.0.0 -m "Release version 1.0.0"
# or lightweight tag
git tag v1.0.0
# push tag to remote
git push origin v1.0.0
```
